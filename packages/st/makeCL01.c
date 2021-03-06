#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <ntypes.h>
#include <bostypes.h>
#include <map_manager.h>
#include <call.h>
#include <math.h>

#define FACTOR 10000

call_const_t call_calib;
float rf_offset = 0;
int i, status = 1;
int warning_msg_count = 0;
/*typedef struct{
  float low;
  float high;
  float p0;
  float p1;
  float p2;
  float p3;
  } F_t;*/

F_t f[4];

int make_cl01_bank_(){
  make_CL01_bank();
}

int make_cl01_bank_using(int use_rf) { /* select raw RF: 1=CALL6 2=CALL7 3=RFT6 4=RFT7 */
  int save_status = status;
  status = use_rf;
  make_CL01_bank();
  status = save_status;
}

int make_CL01_bank(){
  /*input: Call bank, calibration constants (must run initCL01)
    output: CL01 bank */
  clasCALL_t *CALL = NULL;
  clasCL01_t *CL01 = NULL;
  clasRFT_t  *RFT  = NULL;
  cl01_t cl01;
  int n_region = 0, rf_region = 0;
  float pol4 = 0;

  cl01.ac_amp = cl01.fc_diode_amp = cl01.nc_diode_amp = 
    cl01.sc_diode_amp = cl01.sf_diode_amp = NO_CL01_HIT;
  cl01.fc_diode_t = cl01.nc_diode_t = cl01.sc_diode_t = 
    cl01.sf_diode_t = cl01.rf1 = cl01.rf2 = NO_CL01_HIT;

  float rf_selct[4] = { NO_CL01_HIT, NO_CL01_HIT, NO_CL01_HIT, NO_CL01_HIT}; 
  float rf_first[4] = { NO_CL01_HIT, NO_CL01_HIT, NO_CL01_HIT, NO_CL01_HIT}; 
  int   rf_found[4] = { 0, 0, 0, 0};

  if ( RFT = getBank(&bcs_, "RFT ")) {
    int i, ir, ic;
    float t_ns;
    for (i=0; i < RFT->bank.nrow; i++) {
      switch (RFT->rft[i].id) {
      case RF1:  /* RFT raw bank uses same id=6,7 coding as CALL */
      case RF2:
	ir = RFT->rft[i].id - 4;    /* store result     -> 2,3  */
	ic = RFT->rft[i].id + 3;    /* calib. constants -> 9,10 */ 
	t_ns = getCL01time(ic, RFT->rft[i].tdc);
	if (rf_found[ir]) { 
	  /* mean of multihit entries */
	  rf_selct[ir] = rf_found[ir]*rf_selct[ir] + time2rfregion(t_ns, rf_first[ir]);
	                  /* -----------------------------------------------------*/
	  rf_selct[ir] /=                        rf_found[ir] + 1.;
	}
	else {
	  rf_first[ir] = rf_selct[ir] = t_ns;
	}
	rf_found[ir]++;
      }
    }
  }
  
  if ( CALL = getBank(&bcs_, "CALL")){
    int i;
    /* printCALLbank(stderr,CALL); */
    for (i=0; i < CALL->bank.nrow; i++){
      switch ((int)CALL->call[i].id){
      case AC60HZ:
	cl01.ac_amp = getCL01adc(AC60HZ, CALL->call[i].adc);
	break;
      case FWD_DIODE:
	cl01.fc_diode_amp = getCL01adc(FWD_DIODE, CALL->call[i].adc);
	cl01.fc_diode_t = getCL01time(FWD_DIODE, CALL->call[i].tdc);
	break;
      case N_CLMSH_DIODE:
	cl01.nc_diode_amp = getCL01adc(N_CLMSH_DIODE, CALL->call[i].adc);
	cl01.nc_diode_t = getCL01time(N_CLMSH_DIODE, CALL->call[i].tdc);
	break;
      case S_CLMSH_DIODE:
	cl01.sc_diode_amp = getCL01adc(S_CLMSH_DIODE, CALL->call[i].adc);
	cl01.sc_diode_t = getCL01time(S_CLMSH_DIODE, CALL->call[i].tdc);
	break;
      case SPCFM_DIODE:
	cl01.sf_diode_amp = getCL01adc(SPCFM_DIODE, CALL->call[i].adc);
	cl01.sf_diode_t = getCL01time(SPCFM_DIODE, CALL->call[i].tdc);
	break;
      case RF1:
	rf_selct[0] = cl01.rf1 = getCL01time(RF1, CALL->call[i].tdc);
	rf_found[0]++;
	break;
      case RF2:
	rf_selct[1] = cl01.rf2 = getCL01time(RF2, CALL->call[i].tdc);
	rf_found[1]++;
	break;
      }
    }
  }   

  /* good RF */

  cl01.rf = 0.0; /* initialization */      

  if (status < 1 || status > 4) {
    if (warning_msg_count < 3) {  
      fprintf (stderr, 
	       "WARNING: RF status is set to %d (valid choices 1..4), no RF correction done\n",
	       status);
      warning_msg_count++;
    }
  }
  else { /* status OK */
    if (rf_found[status-1]) { /* raw RF (1..4) found ? */
      
      /* 4th deg. polynomial correction for CALL TDC */
      if (status <= 2) {
	
	for(i=0; i < 4; i++) {  /* find region */
	  if (rf_selct[status-1] >= f[i].low && rf_selct[status-1] < f[i].high) {
	    rf_region = i;
	    n_region++;
	  }
	}
	
	switch (n_region) {
	case 0:  /* outside of any region*/ 
	  break;
	case 1:
	  if (rf_region < 0 || rf_region >= 4) { /* impossible unless code changed */
	    fprintf (stderr, "makeCL01 programming error\n"); exit(-1);
	  }
	  pol4 =  f[rf_region].p0
	    +     f[rf_region].p1 * rf_selct[status-1]
	    +     f[rf_region].p2 * rf_selct[status-1] * rf_selct[status-1]
	    +     f[rf_region].p3 * rf_selct[status-1] * rf_selct[status-1] * rf_selct[status-1]; 
	  rf_selct[status-1] += rf_offset + pol4;
	  break;
	default: /* RF value found in more than one region */
	  fprintf(stderr,
		  "WARNING: no RF%d correction at %f2 ns. Overlapping calibration regions: %d \n",
		  status, rf_selct[status-1], n_region); 
	}
      }
      
      /* no correction for RFT TDC */
      else {
	rf_selct[status-1] += rf_offset;
      }
      
      cl01.rf = rf_selct[status-1];
    }
  }
  
  if (CALL || rf_found[status-1]) {
    if (CL01 = makeBank(&bcs_, "CL01", 0, sizeof(cl01_t)/4, 1)){
      CL01->cl01[0] = cl01;
    } 
  }
}

int initcl01_(int *runno){
  initCL01(*runno);
}

int CL01_begin_run(int runno){
  clasHEAD_t *HEAD = getBank(&bcs_, "HEAD");

  if (HEAD){
    if (HEAD->head[0].type >= 0) {
      /* data */
      initCL01(runno);
    } else {
      /*monte carlo - do something else */
      initCL01(1);
    }
  }
}

int initCL01(int runno){
  char *dir,map[128], rfmap[128];
  int  i,firsttime;

  dir=getenv("CLAS_PARMS");
  sprintf(map,"%s/Maps/CALL_CALIB.map",dir);
  sprintf(rfmap, "%s/Maps/RF_OFFSETS.map", dir);
  /*  dir=getenv("TOP_DIR");
  sprintf(map,"%s/st/CALL_CALIB.map",dir); */ 
  map_get_float(map,"T0","value",CALL_IDS,call_calib.t0,runno,&firsttime);    
  map_get_float(map,"T1","value",CALL_IDS,call_calib.t1,runno,&firsttime); 
  map_get_float(map,"T2","value",CALL_IDS,call_calib.t2,runno,&firsttime); 
  map_get_float(map,"pedestals","value",CALL_IDS,call_calib.ped,runno,&firsttime); 
  map_get_float(rfmap, "offset", "value", 1, &rf_offset, runno, &firsttime);
  map_get_int(rfmap, "status", "value", 1, &status, runno, &firsttime);

for(i=0; i < 4; i++){
  if(i==0){
    map_get_float(rfmap, "F1", "low",1,&f[i].low,runno,&firsttime);
    map_get_float(rfmap, "F1", "high",1,&f[i].high,runno,&firsttime);
    map_get_float(rfmap, "F1", "p0",1,&f[i].p0,runno,&firsttime);
    map_get_float(rfmap, "F1", "p1",1,&f[i].p1,runno,&firsttime);
    map_get_float(rfmap, "F1", "p2",1,&f[i].p2,runno,&firsttime);
    map_get_float(rfmap, "F1", "p3",1,&f[i].p3,runno,&firsttime);
  }else if(i==1){
    map_get_float(rfmap, "F2", "low",1,&f[i].low,runno,&firsttime);
    map_get_float(rfmap, "F2", "high",1,&f[i].high,runno,&firsttime);
    map_get_float(rfmap, "F2", "p0",1,&f[i].p0,runno,&firsttime);
    map_get_float(rfmap, "F2", "p1",1,&f[i].p1,runno,&firsttime);
    map_get_float(rfmap, "F2", "p2",1,&f[i].p2,runno,&firsttime);
    map_get_float(rfmap, "F2", "p3",1,&f[i].p3,runno,&firsttime);
  }else if(i==2){
    map_get_float(rfmap, "F3", "low",1,&f[i].low,runno,&firsttime);
    map_get_float(rfmap, "F3", "high",1,&f[i].high,runno,&firsttime);
    map_get_float(rfmap, "F3", "p0",1,&f[i].p0,runno,&firsttime);
    map_get_float(rfmap, "F3", "p1",1,&f[i].p1,runno,&firsttime);
    map_get_float(rfmap, "F3", "p2",1,&f[i].p2,runno,&firsttime);
    map_get_float(rfmap, "F3", "p3",1,&f[i].p3,runno,&firsttime);
  }else if(i==3){
    map_get_float(rfmap, "F4", "low",1,&f[i].low,runno,&firsttime);
    map_get_float(rfmap, "F4", "high",1,&f[i].high,runno,&firsttime);
    map_get_float(rfmap, "F4", "p0",1,&f[i].p0,runno,&firsttime);
    map_get_float(rfmap, "F4", "p1",1,&f[i].p1,runno,&firsttime);
    map_get_float(rfmap, "F4", "p2",1,&f[i].p2,runno,&firsttime);
    map_get_float(rfmap, "F4", "p3",1,&f[i].p3,runno,&firsttime);
  }
}
  fprintf(stderr,"Reading CALL calibration constants for run %d.\n",runno);
                
}


void rf_numbers_(float *rf1, float *rf2, float *good_rf, float *rf_corr){
  clasCL01_t *CL01 = getBank(&bcs_, "CL01");
  if (CL01){
    *rf1 = CL01->cl01[0].rf1;
    *rf2 = CL01->cl01[0].rf2;
    *good_rf = CL01->cl01[0].rf;
    *rf_corr = fmod((- (*good_rf) + FACTOR*RF_STRUCTURE), RF_STRUCTURE) 
      - RF_STRUCTURE/2.0;
  } else {
    *rf1 = *rf2 = *good_rf = *rf_corr = 0.0;
  } 
} 

float rf_corr_time_(float *time){
  return (rf_corr_time(*time));
}

float rf_corr_time(float time){
  clasCL01_t *CL01 = getBank(&bcs_, "CL01");
  float rf_st_time = time;

  if (CL01){ 
    rf_st_time = time - rf_correction(time, CL01->cl01[0].rf);
  } 
  return rf_st_time;
}

float rf_corr_time_center(float time){
  clasCL01_t *CL01 = getBank(&bcs_, "CL01");
  float rf_st_time = time;

  if (CL01){ 
    rf_st_time = time - rf_correction_center(time, CL01->cl01[0].rf);
  } 
  return rf_st_time;
}


float rf_correction(float time, float rf){
  float del_time = 0;
  
  if (rf <= 0.) return 0.;

  del_time = time - rf + FACTOR*RF_STRUCTURE;
  return (fmod(del_time,RF_STRUCTURE) - 0.5 * RF_STRUCTURE);
}

float rf_correction_center(float time, float rf){
  float  del_time;

  if (rf <= 0.) return 0.;

  del_time = time - rf + (FACTOR+0.5)*RF_STRUCTURE;
  return (fmod(del_time,RF_STRUCTURE) - 0.5 * RF_STRUCTURE);
}

float time2rfregion(float time, float rf) {
  return rf + rf_correction_center(time, rf);
}

float getCL01time(int ind_cl01, int tdc){
  float t0 = call_calib.t0[ind_cl01-1];
  float t1 = call_calib.t1[ind_cl01-1];
  float t2 = call_calib.t2[ind_cl01-1];
  return ( t0 + t1*tdc + t2*tdc*tdc);
} 

int getCL01adc(int ind_cl01, int adc){
  extern call_const_t call_calib;
  int ped = (int)call_calib.ped[ind_cl01-1];
  return ((int)(adc - ped));
}

int get_diode_id(int id,int sec){
  if (id<24) return FWD_DIODE;
  if (id<43&&sec>=2&&sec<=5) return N_CLMSH_DIODE;
  if (id<43) return S_CLMSH_DIODE;
  if (id<49) return SPCFM_DIODE;
  return -1;
}


float get_diode_time(cl01_t cl01,int id,int sec){
  if (id<24) return cl01.fc_diode_t;
  if (id<43&&sec>=3&&sec<=5) return cl01.nc_diode_t;
  if (id<43) return cl01.sc_diode_t;
  if (id<49) return cl01.sf_diode_t;
  return 0.0;
}




