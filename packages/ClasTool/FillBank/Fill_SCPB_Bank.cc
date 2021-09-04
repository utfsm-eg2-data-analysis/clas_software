//////////////////////////////////////////////////////////////
//
//   File Fill_SCPB_Bank.cc
//
//   This procedure Fills TSCPBClass class from BOS Bank 
//
//  Author :  Gagik Gavalian   UNH  11/10/1999
//
//
//  This file was automaticaly Generated on : 
//	Tue Nov 23 18:21:50 EST 1999 
//////////////////////////////////////////////////////////////


#include "TROOT.h"
#include "TSCPBClass.h"

#include "clasbanks.h"
#include "tree_str.h"

// Function Prototype 
void  Fill_SCPB_Bank(TSCPBClass *gcSCPB,SCPB *pSCPB , int nrow);
void  Fill_SCPB_Bank(TSCPBClass *gcSCPB, tree_str* pSCPB, int nrow);

void  Fill_SCPB_Bank(TSCPBClass *gcSCPB, SCPB *pSCPB , int nrow){
gcSCPB->Scpdht  = pSCPB->get_ScPdHt(nrow);
gcSCPB->Edep  = pSCPB->get_Edep(nrow);
gcSCPB->Time  = pSCPB->get_Time(nrow);
gcSCPB->Path  = pSCPB->get_Path(nrow);
gcSCPB->Chi2sc  = pSCPB->get_Chi2SC(nrow);
gcSCPB->Status  = pSCPB->get_Status(nrow);

}

void  Fill_SCPB_Bank(TSCPBClass *gcSCPB, tree_str* pSCPB, int nrow){
gcSCPB->Scpdht  = pSCPB->sc_sect[nrow]*10000 + pSCPB->sc_pd[nrow]*100 + pSCPB->sc_hit[nrow]; // 1 ScPdHt !10000*sector+100*SC_PD_ID+Hit_ID in SCR
gcSCPB->Edep  = pSCPB->edep [nrow];
gcSCPB->Time  = pSCPB->sc_t [nrow];
gcSCPB->Path  = pSCPB->sc_r [nrow];
gcSCPB->Chi2sc  = pSCPB->sc_c2 [nrow];
gcSCPB->Status  = pSCPB->sc_stat [nrow];

}


////////////////////////////////////////////////////////////////////////////////////////
//     End Of File  Fill_SCPB_Bank.cc
//////////////////////////////////////////////////////////////////////////////////////

