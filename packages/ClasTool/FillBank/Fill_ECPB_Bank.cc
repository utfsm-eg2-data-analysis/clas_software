//////////////////////////////////////////////////////////////
//
//   File Fill_ECPB_Bank.cc
//
//   This procedure Fills TECPBClass class from BOS Bank 
//
//  Author :  Gagik Gavalian   UNH  11/10/1999
//
//
//  This file was automaticaly Generated on : 
//	Tue Nov 23 18:21:47 EST 1999 
//////////////////////////////////////////////////////////////


#include "TROOT.h"
#include "TECPBClass.h"

#include "clasbanks.h"
#include "tree_str.h"

// Function Prototype 
void  Fill_ECPB_Bank(TECPBClass *gcECPB,ECPB *pECPB , int nrow);
void  Fill_ECPB_Bank(TECPBClass *gcECPB, tree_str* pECPB, int nrow);

void  Fill_ECPB_Bank(TECPBClass *gcECPB, ECPB *pECPB , int nrow){
gcECPB->Scht  = pECPB->get_ScHt(nrow);
gcECPB->Etot  = pECPB->get_Etot(nrow);
gcECPB->Ein  = pECPB->get_Ein(nrow);
gcECPB->Eout  = pECPB->get_Eout(nrow);
gcECPB->Time  = pECPB->get_Time(nrow);
gcECPB->Path  = pECPB->get_Path(nrow);
gcECPB->X  = pECPB->get_X(nrow);
gcECPB->Y  = pECPB->get_Y(nrow);
gcECPB->Z  = pECPB->get_Z(nrow);
gcECPB->M2_hit  = pECPB->get_M2_hit(nrow);
gcECPB->M3_hit  = pECPB->get_M3_hit(nrow);
gcECPB->M4_hit  = pECPB->get_M4_hit(nrow);
gcECPB->Innstr  = pECPB->get_InnStr(nrow);
gcECPB->Outstr  = pECPB->get_OutStr(nrow);
gcECPB->Chi2ec  = pECPB->get_Chi2EC(nrow);
gcECPB->Status  = pECPB->get_Status(nrow);

}

void  Fill_ECPB_Bank(TECPBClass *gcECPB, tree_str* pECPB, int nrow){
gcECPB->Scht  = pECPB->ec_sect[nrow]*100 + pECPB->ec_whol[nrow]; //100*sector+Whole_Hit_ID in ECHB 
gcECPB->Etot  = pECPB->etot[nrow];
gcECPB->Ein  = pECPB->ec_ei[nrow];
gcECPB->Eout  = pECPB->ec_eo[nrow];
gcECPB->Time  = pECPB->ec_t[nrow];
gcECPB->Path  = pECPB->ec_r[nrow];
gcECPB->X  = pECPB->ech_x[nrow];
gcECPB->Y  = pECPB->ech_y[nrow];
gcECPB->Z  = pECPB->ech_z[nrow];
gcECPB->M2_hit  = pECPB->ec_m2[nrow];
gcECPB->M3_hit  = pECPB->ec_m3[nrow];
gcECPB->M4_hit  = pECPB->ec_m4[nrow];
gcECPB->Innstr  = pECPB->ec_inst[nrow];
gcECPB->Outstr  = pECPB->ec_oust[nrow];
gcECPB->Chi2ec  = pECPB->ec_c2[nrow];
gcECPB->Status  = pECPB->ec_stat[nrow];

}


////////////////////////////////////////////////////////////////////////////////////////
//     End Of File  Fill_ECPB_Bank.cc
//////////////////////////////////////////////////////////////////////////////////////

