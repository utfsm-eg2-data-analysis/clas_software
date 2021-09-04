//////////////////////////////////////////////////////////////
//
//   File Fill_DCPB_Bank.cc
//
//   This procedure Fills TDCPBClass class from BOS Bank 
//
//  Author :  Gagik Gavalian   UNH  11/10/1999
//
//  Modified: Maurik Holtrop UNH 3/4/00 - DCPB was modified by Stepan.
//
//  This file was automaticaly Generated on : 
//	Tue Nov 23 18:21:53 EST 1999 
//////////////////////////////////////////////////////////////


#include "TROOT.h"
#include "TDCPBClass.h"

#include "clasbanks.h"
#include "tree_str.h"

// Function Prototype 
void  Fill_DCPB_Bank(TDCPBClass *gcDCPB,DCPB *pDCPB , int nrow);
void  Fill_DCPB_Bank(TDCPBClass *gcDCPB, tree_str* pDCPB, int nrow);

void  Fill_DCPB_Bank(TDCPBClass *gcDCPB, DCPB *pDCPB , int nrow){
gcDCPB->Sctr  = pDCPB->get_ScTr(nrow);
gcDCPB->X_sc  = pDCPB->get_x_SC(nrow);
gcDCPB->Y_sc  = pDCPB->get_y_SC(nrow);
gcDCPB->Z_sc  = pDCPB->get_z_SC(nrow);
gcDCPB->Cx_sc  = pDCPB->get_CX_SC(nrow);
gcDCPB->Cy_sc  = pDCPB->get_CY_SC(nrow);
gcDCPB->Cz_sc  = pDCPB->get_CZ_SC(nrow);
gcDCPB->X_ec  = pDCPB->get_X_v(nrow); // Mod(3/4/00) MWH - DCPB was changed by Stepan.
gcDCPB->Y_ec  = pDCPB->get_Y_v(nrow);
gcDCPB->Z_ec  = pDCPB->get_Z_v(nrow);
gcDCPB->Th_cc  = pDCPB->get_R_v(nrow);
gcDCPB->Chi2  = pDCPB->get_Chi2(nrow);
gcDCPB->Status  = pDCPB->get_Status(nrow);

}

void  Fill_DCPB_Bank(TDCPBClass *gcDCPB, tree_str* pDCPB, int nrow){
gcDCPB->Sctr  = pDCPB->dc_sect[nrow]*100 + pDCPB->dc_trk[nrow];//100*sector+track_ID in *BTR 
gcDCPB->X_sc  = pDCPB->dc_xsc [nrow];
gcDCPB->Y_sc  = pDCPB->dc_ysc [nrow];
gcDCPB->Z_sc  = pDCPB->dc_zsc [nrow];
gcDCPB->Cx_sc  = pDCPB->dc_cxsc [nrow];
gcDCPB->Cy_sc  = pDCPB->dc_cysc [nrow];
gcDCPB->Cz_sc  = pDCPB->dc_czsc [nrow];
gcDCPB->X_ec  = pDCPB->dc_vx [nrow]; // Mod(3/4/00) MWH - DCPB was changed by Stepan.
gcDCPB->Y_ec  = pDCPB->dc_vy [nrow];
gcDCPB->Z_ec  = pDCPB->dc_vz [nrow];
gcDCPB->Th_cc  = pDCPB->dc_vr [nrow];
gcDCPB->Chi2  = pDCPB->dc_c2 [nrow];
gcDCPB->Status  = pDCPB->dc_stat[nrow];

}


////////////////////////////////////////////////////////////////////////////////////////
//     End Of File  Fill_DCPB_Bank.cc
//////////////////////////////////////////////////////////////////////////////////////

