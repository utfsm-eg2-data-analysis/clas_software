//////////////////////////////////////////////////////////////
//
//   File Fill_LCPB_Bank.cc
//
//   This procedure Fills TLCPBClass class from BOS Bank 
//
//  Author :  Gagik Gavalian   UNH  11/10/1999
//
//
//  This file was automaticaly Generated on : 
//	Tue Nov 23 18:21:58 EST 1999 
//////////////////////////////////////////////////////////////


#include "TROOT.h"
#include "TLCPBClass.h"

#include "clasbanks.h"
#include "tree_str.h"

// Function Prototype 
void  Fill_LCPB_Bank(TLCPBClass *gcLCPB,LCPB *pLCPB , int nrow);
void  Fill_LCPB_Bank(TLCPBClass *gcLCPB, tree_str* pLCPB, int nrow);

void  Fill_LCPB_Bank(TLCPBClass *gcLCPB, LCPB *pLCPB , int nrow){
gcLCPB->Scht  = pLCPB->get_ScHt(nrow);
gcLCPB->Etot  = pLCPB->get_Etot(nrow);
gcLCPB->Time  = pLCPB->get_Time(nrow);
gcLCPB->Path  = pLCPB->get_Path(nrow);
gcLCPB->X  = pLCPB->get_X(nrow);
gcLCPB->Y  = pLCPB->get_Y(nrow);
gcLCPB->Z  = pLCPB->get_Z(nrow);
gcLCPB->Chi2lc  = pLCPB->get_Chi2LC(nrow);
gcLCPB->Status  = pLCPB->get_Status(nrow);
gcLCPB->Ein  = pLCPB->get_Ein(nrow);

}

void  Fill_LCPB_Bank(TLCPBClass *gcLCPB, tree_str* pLCPB, int nrow){
gcLCPB->Scht  = pLCPB->lec_sect [nrow]*100 + pLCPB->lec_hit [nrow]; //100*sector+Hit_ID in EC1R
gcLCPB->Etot  = pLCPB->lec_etot [nrow];
gcLCPB->Time  = pLCPB->lec_t[nrow];
gcLCPB->Path  = pLCPB->lec_r [nrow];
gcLCPB->X  = pLCPB->lec_x [nrow];
gcLCPB->Y  = pLCPB->lec_y [nrow];
gcLCPB->Z  = pLCPB->lec_z [nrow];
gcLCPB->Chi2lc  = pLCPB->lec_c2 [nrow];
gcLCPB->Status  = pLCPB->lec_stat [nrow];
gcLCPB->Ein  = pLCPB->lec_ein [nrow];

}

////////////////////////////////////////////////////////////////////////////////////////
//     End Of File  Fill_LCPB_Bank.cc
//////////////////////////////////////////////////////////////////////////////////////

