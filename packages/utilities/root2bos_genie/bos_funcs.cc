#include "cpp_headers.hh"
#include "bos_interface.hh"
#include "dvect.hh"


int open_wbos(int lun, string fname)
{
  int ir = 0;
  stringstream ss; ss.str("");
  ss << "OPEN BOSOUTPUT UNIT="<< lun << 
        " FILE=\"" << fname << 
        "\" ACTION=WRITE STATUS=NEW RECL=32760";

  fparm_(ss.str().c_str(), ss.str().size());

  int one = 1;
  string msg; for(int i=0; i<80; i++) msg += " ";
  fermes_(msg.c_str(), &one, msg.size());
  if(msg[0] != ' ')
  {
    cout<<"Fail to open bos file"<<endl;
    ir = 0;
  }
  else
  {
    cout<<"bos file opened successfuly"<<endl;
    ir = 1;
  }
  return ir;
}


void init_bos()
{
  int max   =   1000;
  int nbcs  = 700000;
  int nwbcs = 700000; //NDIM

  bnames_(&max);
  bos_(bcs_.iw, &nbcs);
  bos_(wcs_.iw, &nwbcs);
}


void map_banks()
{
  map <string,string> mapBank;

  mapBank["BMPR"] = "4F";
  mapBank["BREP"] = "36F";
  mapBank["CALL"] = "B16";
  mapBank["CC  "] = "B16";
  mapBank["CC01"] = "I,2F";
  mapBank["CC1 "] = "B16";
  mapBank["CCDI"] = "5I";
  mapBank["CCH "] = "6I,6F";
  mapBank["CCMT"] = "2I";
  mapBank["CCPB"] = "I,4F,I";
  mapBank["CCPE"] = "3I";
  mapBank["CCRC"] = "12I";
  mapBank["CCS "] = "96I";
  mapBank["CHI2"] = "2F,2I";
  mapBank["CL01"] = "2I,F,I,F,I,F,I,4F";
  mapBank["CLST"] = "I";
  mapBank["CPED"] = "3I,F,I";
  mapBank["DC0 "] = "B16";
  mapBank["DC1 "] = "I,F";
  mapBank["DCDW"] = "I,F,I";
  mapBank["DCGM"] = "11F,2I,7F,I";
  mapBank["DCGW"] = "8F";
  mapBank["DCH "] = "10F,3I";
  mapBank["DCPB"] = "I,11F,I";
  mapBank["DCV1"] = "5F";
  mapBank["DCV2"] = "14F";
  mapBank["DCV3"] = "5F";
  mapBank["DDLY"] = "I,F,I";
  mapBank["DGEO"] = "2I,6F";
  mapBank["DHCL"] = "B08";
  mapBank["DITM"] = "I";
  mapBank["DOCA"] = "B16";
  mapBank["DPCP"] = "2I,F,I,F,I,F,I,F,I,F,I,F";
  mapBank["DPSP"] = "2I,F";
  mapBank["DSPC"] = "B16";
  mapBank["DSPS"] = "B16";
  mapBank["DSTC"] = "B16";
  mapBank["DTCP"] = "2I,F,I,F,I,F,I,F,I,F,I,F,I,F";
  mapBank["DTRK"] = "3F";
  mapBank["EC  "] = "B16";
  mapBank["EC01"] = "I,2F";
  mapBank["EC1 "] = "B16";
  mapBank["EC1P"] = "4F";
  mapBank["EC1R"] = "24F,4I,16F,3I,2F,I";
  mapBank["ECCA"] = "I,6F,I";
  mapBank["ECCL"] = "I,6F,I";
  mapBank["ECCT"] = "I,10F,I";
  mapBank["ECDI"] = "5I";
  mapBank["ECG "] = "8F,I,13F";
  mapBank["ECH "] = "7F,I,3F";
  mapBank["ECHB"] = "I,29F,4I,F,I,F,I";
  mapBank["ECMT"] = "6I";
  mapBank["ECP "] = "7F";
  mapBank["ECP1"] = "2I,F,I,F";
  mapBank["ECPB"] = "I,11F,2I,F,I";
  mapBank["ECPC"] = "I,2F";
  mapBank["ECPE"] = "2I,F";
  mapBank["ECPI"] = "3I,6F";
  mapBank["ECPO"] = "7I";
  mapBank["ECRB"] = "48F,I";
  mapBank["ECS "] = "96I";
  mapBank["EID0"] = "4I";
  mapBank["EPIC"] = "F,8A";
  mapBank["EVNT"] = "I,2F,I,7F,7I";
  mapBank["FBPM"] = "B16";
  mapBank["G1SL"] = "64I";
  mapBank["G2SL"] = "64I";
  mapBank["G3SL"] = "64I";
  mapBank["G4SL"] = "64I";
  mapBank["GCPB"] = "I,12F,I,4F,I,F";
  mapBank["GGEO"] = "I,6F";
  mapBank["GPAR"] = "F,I,5A";
  mapBank["GPID"] = "I,7F,4I,2F,I,2F,I,3F,I,3F,3I";
  mapBank["HBER"] = "21F,2I";
  mapBank["HBID"] = "2I,2F,2I,4F,2I,4F,2I,4F,2I,4F,2I,4F";
  mapBank["HBLA"] = "I,7F,3I,5F";
  mapBank["HBTB"] = "10I";
  mapBank["HBTR"] = "8F,I";
  mapBank["HCAL"] = "5I";
  mapBank["HDPL"] = "I,7F";
  mapBank["HEAD"] = "8I";
  mapBank["HELC"] = "2I";
  mapBank["HEVT"] = "6I,9F,I";
  mapBank["HLB "] = "B32";
  mapBank["HLS "] = "B32";
  mapBank["IC  "] = "B16";
  mapBank["ICHB"] = "F,F,F,F,F,F,F,F,F,F,F,F,F,I";
  mapBank["ICPB"] = "F,F,F,F,F,F,F,F,F,I";
  mapBank["SH  "] = "B16";
  mapBank["SHHB"] = "I,F,F,F,F,F,I";
  mapBank["SHPB"] = "I,F,F,F,F,F,I";
  mapBank["KFIT"] = "46F";
  mapBank["L1PG"] = "A";
  mapBank["L2H "] = "B16";
  mapBank["L2S "] = "B16";
  mapBank["LASR"] = "4I";
  mapBank["LCDI"] = "4I";
  mapBank["LCPB"] = "I,7F,I,F";
  mapBank["MCEV"] = "2I";
  mapBank["MCHD"] = "5I,11F";
  mapBank["MCTK"] = "6F,5I";
  mapBank["MCVX"] = "4F,I";
  mapBank["MTRK"] = "7I";
  mapBank["MVRT"] = "I,11F,I";
  mapBank["LOWQ"] = "I,9F,I";
  mapBank["PART"] = "I,8F,I,2F,I";
  mapBank["PCO "] = "7F,I";
  mapBank["PRTM"] = "I";
  mapBank["PSO "] = "I,2F,I";
  mapBank["PTDB"] = "11I";
  mapBank["RCST"] = "15I";
  mapBank["RC26"] = "B32";
  mapBank["RF  "] = "3F";
  mapBank["RGLK"] = "I,8F,I";
  mapBank["RNLG"] = "A";
  mapBank["RNPE"] = "I,A";
  mapBank["RTSL"] = "64I";
  mapBank["RUNC"] = "I,F,I,F,I,F,I,F,I,F,I,F,I";
  mapBank["RTPC"] = "5I,12F,I";
  mapBank["S1ST"] = "17I";
  mapBank["SC  "] = "B16";
  mapBank["SC1 "] = "I,8F";
  mapBank["SCC "] = "4I,44F";
  mapBank["SCDI"] = "5I";
  mapBank["SCG "] = "2I,9F";
  mapBank["SCGD"] = "I,9F";
  mapBank["SCH "] = "7F,2I";
  mapBank["SCMD"] = "2I,11F";
  mapBank["SCMT"] = "I";
  mapBank["SCMW"] = "I";
  mapBank["SCP "] = "16F";
  mapBank["SCPB"] = "I,4F,I";
  mapBank["SCPE"] = "2I,F,I,F";
  mapBank["SCPS"] = "3I,13F";
  mapBank["SCR "] = "I,8F,I,2F";
  mapBank["SCRC"] = "I,10F,I";
  mapBank["SCS "] = "192I";
  mapBank["SGMP"] = "7I";
  mapBank["SPAR"] = "4I";
  mapBank["SPIN"] = "3I";
  mapBank["ST  "] = "B16";
  mapBank["ST1 "] = "2I,4F";
  mapBank["STH "] = "7F,2I,F";
  mapBank["STPB"] = "I,2F,2I";
  mapBank["STPE"] = "2I,F";
  mapBank["STR "] = "2I,3F,I";
  mapBank["STRE"] = "2I,3F,I,2F";
  mapBank["STS "] = "16I";
  mapBank["SYNC"] = "B16";
  mapBank["TACO"] = "I,8F,I";
  mapBank["TAGE"] = "B16";
  mapBank["TAGI"] = "I,2F,I,4F";
  mapBank["TAGM"] = "3F,3I";
  mapBank["TAGR"] = "3F,3I";
  mapBank["TAGT"] = "B16";
  mapBank["TBER"] = "21F,2I";
  mapBank["TBID"] = "2I,2F,2I,4F,2I,4F,2I,4F,2I,4F,2I,4F";
  mapBank["TBLA"] = "I,7F,3I,6F";
  mapBank["TBTR"] = "8F,2I";
  mapBank["TCSB"] = "6F";
  mapBank["TDPL"] = "I,7F";
  mapBank["TGBI"] = "B32";
  mapBank["TGPB"] = "I,3F";
  mapBank["TGS "] = "192I";
  mapBank["TRGS"] = "64I";
  mapBank["TRKS"] = "I,5F,4I";
  mapBank["TRL1"] = "3I,7F";
  mapBank["TRPB"] = "I,7F";
  mapBank["TSPR"] = "B32";
  mapBank["TSRG"] = "B32";
  mapBank["UNUS"] = "8I";
  mapBank["VERT"] = "3I,4F";
  mapBank["CLST"] = "I";
  mapBank["CPED"] = "3I,F,I";
  mapBank["DC0 "] = "B16";
  mapBank["DC1 "] = "I,F";
  mapBank["DCDW"] = "I,F,I";
  mapBank["DCGM"] = "11F,2I,7F,I";
  mapBank["DCGW"] = "8F";
  mapBank["DCH "] = "10F,3I";
  mapBank["DCPB"] = "I,11F,I";
  mapBank["DCV1"] = "5F";
  mapBank["DCV2"] = "14F";
  mapBank["DCV3"] = "5F";
  mapBank["DDLY"] = "I,F,I";
  mapBank["DGEO"] = "2I,6F";
  mapBank["DHCL"] = "B08";
  mapBank["DITM"] = "I";
  mapBank["DOCA"] = "B16";
  mapBank["DPCP"] = "2I,F,I,F,I,F,I,F,I,F,I,F";
  mapBank["DPSP"] = "2I,F";
  mapBank["DSPC"] = "B16";
  mapBank["DSPS"] = "B16";
  mapBank["DSTC"] = "B16";
  mapBank["DTCP"] = "2I,F,I,F,I,F,I,F,I,F,I,F,I,F";
  mapBank["DTRK"] = "3F";
  mapBank["EC  "] = "B16";
  mapBank["EC01"] = "I,2F";
  mapBank["EC1 "] = "B16";
  mapBank["EC1P"] = "4F";
  mapBank["EC1R"] = "24F,4I,16F,3I,2F,I";
  mapBank["ECCA"] = "I,6F,I";
  mapBank["ECCL"] = "I,6F,I";
  mapBank["ECCT"] = "I,10F,I";
  mapBank["ECDI"] = "5I";
  mapBank["ECG "] = "8F,I,13F";
  mapBank["ECH "] = "7F,I,3F";
  mapBank["ECHB"] = "I,29F,4I,F,I,F,I";
  mapBank["ECMT"] = "6I";
  mapBank["ECP "] = "7F";
  mapBank["ECP1"] = "2I,F,I,F";
  mapBank["ECPB"] = "I,11F,2I,F,I";
  mapBank["ECPC"] = "I,2F";
  mapBank["ECPE"] = "2I,F";
  mapBank["ECPI"] = "3I,6F";
  mapBank["ECPO"] = "7I";
  mapBank["ECRB"] = "48F,I";
  mapBank["ECS "] = "96I";
  mapBank["EID0"] = "4I";
  mapBank["EPIC"] = "F,8A";
  mapBank["EVNT"] = "I,2F,I,7F,7I";
  mapBank["FBPM"] = "B16";
  mapBank["G1SL"] = "64I";
  mapBank["G2SL"] = "64I";
  mapBank["G3SL"] = "64I";
  mapBank["G4SL"] = "64I";
  mapBank["GPAR"] = "F,I,5A";
  mapBank["HBER"] = "21F,2I";
  mapBank["HBID"] = "2I,2F,2I,4F,2I,4F,2I,4F,2I,4F,2I,4F";
  mapBank["HBLA"] = "I,7F,3I,5F";
  mapBank["HBTB"] = "10I";
  mapBank["HBTR"] = "8F,I";
  mapBank["HCAL"] = "5I";
  mapBank["HDPL"] = "I,7F";
  mapBank["HEAD"] = "8I";
  mapBank["HEVT"] = "6I,9F,I";
  mapBank["HLS "] = "B32";
  mapBank["KFIT"] = "46F";
  mapBank["L1PG"] = "A";
  mapBank["L2H "] = "B16";
  mapBank["L2S "] = "B16";
  mapBank["LASR"] = "4I";
  mapBank["LCDI"] = "4I";
  mapBank["LCPB"] = "I,7F,I,F";
  mapBank["MCEV"] = "2I";
  mapBank["MCHD"] = "5I,11F";
  mapBank["MCTK"] = "6F,5I";
  mapBank["MCVX"] = "4F,I";
  mapBank["MTRK"] = "7I";
  mapBank["MVRT"] = "I,11F,I";
  mapBank["PART"] = "I,8F,I,2F,I";
  mapBank["PCO "] = "7F,I";
  mapBank["PRTM"] = "I";
  mapBank["PSO "] = "I,2F,I";
  mapBank["PTDB"] = "11I";
  mapBank["RCST"] = "15I";
  mapBank["RF  "] = "3F";
  mapBank["RGLK"] = "I,8F,I";
  mapBank["RNLG"] = "A";
  mapBank["RNPE"] = "I,A";
  mapBank["RTSL"] = "64I";
  mapBank["RUNC"] = "I,F,I,F,I,F,I,F,I,F,I,F,I";
  mapBank["S1ST"] = "17I";
  mapBank["SC  "] = "B16";
  mapBank["SC1 "] = "I,8F";
  mapBank["SCC "] = "4I,44F";
  mapBank["SCDI"] = "5I";
  mapBank["SCG "] = "2I,9F";
  mapBank["SCGD"] = "I,9F";
  mapBank["SCH "] = "7F,2I";
  mapBank["SCMD"] = "2I,11F";
  mapBank["SCMT"] = "I";
  mapBank["SCMW"] = "I";
  mapBank["SCP "] = "16F";
  mapBank["SCPB"] = "I,4F,I";
  mapBank["SCPE"] = "2I,F,I,F";
  mapBank["SCPS"] = "3I,13F";
  mapBank["SCR "] = "I,8F,I,2F";
  mapBank["SCRC"] = "I,10F,I";
  mapBank["SCS "] = "192I";
  mapBank["SGMP"] = "7I";
  mapBank["SPAR"] = "4I";
  mapBank["SPIN"] = "3I";
  mapBank["ST  "] = "B16";
  mapBank["ST1 "] = "2I,4F";
  mapBank["STH "] = "7F,2I,F";
  mapBank["STPB"] = "I,2F,2I";
  mapBank["STPE"] = "2I,F";
  mapBank["STR "] = "2I,3F,I";
  mapBank["STS "] = "16I";
  mapBank["SYNC"] = "B16";
  mapBank["TACO"] = "I,8F,I";
  mapBank["TAGE"] = "B16";
  mapBank["TAGI"] = "I,2F,I,4F";
  mapBank["TAGR"] = "3F,3I";
  mapBank["TAGT"] = "B16";
  mapBank["TBER"] = "21F,2I";
  mapBank["TBID"] = "2I,2F,2I,4F,2I,4F,2I,4F,2I,4F,2I,4F";
  mapBank["TBLA"] = "I,7F,3I,6F";
  mapBank["TBTR"] = "8F,2I";
  mapBank["TCSB"] = "6F";
  mapBank["TDPL"] = "I,7F";
  mapBank["TESC"] = "1F";
  mapBank["TGBI"] = "B32";
  mapBank["TGPB"] = "I,3F";
  mapBank["TGS "] = "192I";
  mapBank["TPC "] = "B16";
  mapBank["TRGS"] = "64I";
  mapBank["TRKS"] = "I,5F,4I";
  mapBank["TRL1"] = "3I,7F";
  mapBank["TRPB"] = "I,7F";
  mapBank["TSPR"] = "B32";
  mapBank["TSRG"] = "B32";
  mapBank["UNUS"] = "8I";
  mapBank["VERT"] = "3I,4F";

  map<string, string>::iterator iter;
  for (iter = mapBank.begin(); iter != mapBank.end(); iter++)
  {
    mkfmt_(bcs_.iw, iter->first.c_str(), iter->second.c_str(), iter->first.size(), iter->second.size());
  }
}


void bankList(BOSbank *bcs, string list, string banklist)
{
  blist_(bcs->iw, list.c_str(), banklist.c_str(), list.size(), banklist.size());
}


void *makeBank(BOSbank *bcs, string bankname, int banknum, int ncol, int nrow)
{
  int ind = 0;
  ind = mbank_(bcs->iw, bankname.c_str(), &banknum, &ncol, &nrow, bankname.size());
  return( ind ? (void *) &bcs->iw[ind - 6] : NULL);
}


void fill_header(clasHEAD_t *Head,int i)
{
  time_t secs;
  time(&secs);
  Head->head[0].version = 2;
  Head->head[0].nrun    = 0;
  Head->head[0].nevent  = i;
  Head->head[0].time    = secs;
  Head->head[0].type    = -2;
  Head->head[0].roc     = 0;
  if(i==0)
  {
    Head->head[0].evtclass= 17;
  }
  else
  {
    Head->head[0].evtclass= 15;
  }
  //  Head->head[0].weight  = 1;  Weight no longer stored in head bank.
}


void fill_part(clasPART_t *PART,int i,dvec p,double E,int charge,int id)
{
  PART->part[i].pid       = id;
  PART->part[i].vert.x    = 0.;
  PART->part[i].vert.y    = 0.;
  PART->part[i].vert.z    = 0.;
  PART->part[i].p.t       = (float)E;
  PART->part[i].p.space.x = (float)p.x();
  PART->part[i].p.space.y = (float)p.y();
  PART->part[i].p.space.z = (float)p.z();
  PART->part[i].q         = (float)charge;
  PART->part[i].trkid     = 0;
  PART->part[i].qpid      = 0.;
  PART->part[i].qtrk      = 0.;
  PART->part[i].flags     = 0;
}


void fill_mctk(clasMCTK_t *MCTK,int i,dvec p,double mass,int charge,int id)
{
  MCTK->mctk[i].cx      = (float)(p.x()/p.mag());
  MCTK->mctk[i].cy      = (float)(p.y()/p.mag());
  MCTK->mctk[i].cz      = (float)(p.z()/p.mag());
  MCTK->mctk[i].pmom    = (float)p.mag();
  MCTK->mctk[i].mass    = (float)mass;
  MCTK->mctk[i].charge  = (float)charge;
  MCTK->mctk[i].id      = id;
  MCTK->mctk[i].flag    = 1;
  MCTK->mctk[i].beg_vtx = 1;
  MCTK->mctk[i].end_vtx = 0;
  MCTK->mctk[i].parent  = 0;
}


void fill_mcvx(clasMCVX_t *MCVX, int i, double x, double y, double z, double time)
{
  MCVX->mcvx[i].x    = (float)x;
  MCVX->mcvx[i].y    = (float)y;
  MCVX->mcvx[i].z    = (float)z;
  MCVX->mcvx[i].tof  = (float)time;
  MCVX->mcvx[i].flag = 0;
}


int putBOS(BOSbank *bcs, int lun, string list)
{
  int ierr = 0;
  fwbos_(bcs->iw, &lun, list.c_str(), &ierr, list.size());
  return(!ierr);
}


void *dropBank(BOSbank *bcs, string bankname, int banknum)
{
  int ind = 0;
  ind = mdrop_(bcs->iw, bankname.c_str(), &banknum, bankname.size());
  return( ind ? (void *) &bcs->iw[ind - 6] : NULL);
}


void dropAllBanks(BOSbank *bcs, string list)
{
  bdrop_(bcs->iw, list.c_str(), list.size());
}


void cleanBanks(BOSbank *bcs)
{
  bgarb_(bcs->iw);
}


int close_bos(int lun)
{
  int ir=1;
  stringstream ss; ss.str("");
  ss<<"CLOSE BOSOUTPUT UNIT="<<lun;

  fparm_(ss.str().c_str(), ss.str().size());

  int one = 1;
  string msg; for(int i=0; i<80; i++) msg += " ";
  fermes_(msg.c_str(), &one, msg.size());
  if(msg[0] != ' ')
  {
    ir =0;
    cout << "Cannot close bosfile."<<endl;
  }
  return ir;
}
