c      include file CCRC_NT
c
c_begin_doc
c  RCS ID string
c  $Id: ccrc_nt.inc,v 1.1 1997/06/11 04:46:17 stepanya Exp $
c
c  Documentation for include file CCRC_NT
c
c  Purpose:
c  --------
c
c  Used in routines:
c  ----------------
c
c  Notes:
c  ------
c
c  Author:   S. Stepanyan      Created:  Sun Feb 16 13:12:51 EST 1997
c  -------
c
c  Major revisions:
c  ----------------
c
c_end_doc
c
c
c  Remember NO NESTED INCLUDES
c
c  COMMON BLOCK NAME should be the same as include file name!
c
c_begin_var
c  variables for include file CCRC_NT:
c  -----------------------------------
c  RCS information: 
      CHARACTER*(132)  CICCRC_NT
      DATA CICCRC_NT/
     1'$Id: ccrc_nt.inc,v 1.1 1997/06/11 04:46:17 stepanya Exp $'/
c----6----------------------------------------------------------------72
c  
c  Variables contained in CCRC_NT common block
c  --------------------------------------------
      integer maxCCR
      parameter(MaxCCR=30)
      integer nCCR
      integer CCR_sect(MaxCCR)          ! Sector 
      integer CCR_seg(MaxCCR)           ! 10 * Mean segment 
      integer CCR_segx(MaxCCR)          ! 10 * Max segment  in the cluster
      integer CCR_segn (MaxCCR)         ! 10 * Min segment  in the cluster
      integer CCR_phe(MaxCCR)           ! Number of photoelectrons obtained
      integer CCR_t(MaxCCR)             ! TOF in channels (50psec/channel)
      integer CCR_th(MaxCCR)            ! Estimated angle Theta
      integer CCR_dth(MaxCCR)           ! Estimated error of angle Theta
      integer CCR_ph(MaxCCR)            ! Phy index  ( -1 if Phy < 0 ; 1 if Phy > 0 ; 0 if Phy ~ 0)
      integer CCR_iec(MaxCCR)           ! Estimated i-coordinate in EC
      integer CCR_diec(MaxCCR)          ! Estimated error of i-coord. in EC
      integer CCR_stat(MaxCCR)          ! Status  word (yet unclear)
      COMMON/CCRC_nt/nCCR,CCR_sect,CCR_seg,CCR_segx,CCR_segn,CCR_phe,
     + CCR_t,CCR_th,CCR_dth,CCR_ph,CCR_iec,CCR_diec,CCR_stat

c----6----------------------------------------------------------------72
