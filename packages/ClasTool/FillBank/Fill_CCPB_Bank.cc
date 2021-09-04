//////////////////////////////////////////////////////////////
//
//   File Fill_CCPB_Bank.cc
//
//   This procedure Fills TCCPBClass class from BOS Bank 
//
//  Author :  Gagik Gavalian   UNH  11/10/1999
//
//
//  This file was automaticaly Generated on : 
//	Tue Nov 23 18:21:56 EST 1999 
//////////////////////////////////////////////////////////////


#include "TROOT.h"
#include "TCCPBClass.h"

#include "clasbanks.h"
#include "tree_str.h"

// Function Prototype 
void  Fill_CCPB_Bank(TCCPBClass *gcCCPB,CCPB *pCCPB , int nrow);
void  Fill_CCPB_Bank(TCCPBClass *gcCCPB, tree_str* pCCPB, int nrow);

void  Fill_CCPB_Bank(TCCPBClass *gcCCPB, CCPB *pCCPB , int nrow){
gcCCPB->Scsght  = pCCPB->get_ScSgHt(nrow);
gcCCPB->Nphe  = pCCPB->get_Nphe(nrow);
gcCCPB->Time  = pCCPB->get_Time(nrow);
gcCCPB->Path  = pCCPB->get_Path(nrow);
gcCCPB->Chi2cc  = pCCPB->get_Chi2CC(nrow);
gcCCPB->Status  = pCCPB->get_Status(nrow);

}

void  Fill_CCPB_Bank(TCCPBClass *gcCCPB, tree_str* pCCPB, int nrow){
gcCCPB->Scsght  = pCCPB->cc_sect[nrow]*10000 +  pCCPB->cc_segm[nrow]*100 + pCCPB->cc_hit[nrow] ; //100*sector + Cluster # in CCRC. Not sure.
gcCCPB->Nphe  =  pCCPB->nphe[nrow];
gcCCPB->Time  = pCCPB->cc_t [nrow];
gcCCPB->Path  = pCCPB->cc_r [nrow];
gcCCPB->Chi2cc  = pCCPB->cc_c2 [nrow];
gcCCPB->Status  = pCCPB->cc_segm [nrow]*10 + 1000*(1+((pCCPB->cc_sect[nrow]%2)?1:-1));/*! Status word - now 10*(CC segment number) 
                                             ! + 1000*( 1 + phy_index).
                                             ! PHY_INDEX = -1 : left  PMT (1,3,5...35)
                                             ! PHY_INDEX = +1 : right PMT (2,4,6...36). Not sure*/

}

////////////////////////////////////////////////////////////////////////////////////////
//     End Of File  Fill_CCPB_Bank.cc
//////////////////////////////////////////////////////////////////////////////////////

