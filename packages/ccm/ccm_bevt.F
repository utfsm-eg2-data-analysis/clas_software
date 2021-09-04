      SUBROUTINE CCM_BEVT
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_bevt.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_BEVT similar to CC_BEVT (A.V.)
c
c  Purpose:   Reading and unpacking the CC bank for following
c  --------   reconstraction procedure
c
c   Input Parameters :    none
c  ----------------
c
c   Output Parameters:    /ccm_revt/ filling
c  -----------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov    Created:  Mon May 12 18:16:11 EDT 1997
c  -------
c
c  Major revisions:
c  ----------------
c     
c
c_end_doc
c
      IMPLICIT NONE
      SAVE
c
c_begin_inc
c  include files :
c  ---------------------
c BOS common block 
#include "bcs.inc"
#include "user_general.inc"
c ------- CC common blocks
#include "ccm_control.inc"
#include "ccm_revt.inc"
c 
c_end_inc
c
c_begin_var
c  input/output variables:
c  -----------------------
c
c  Local pre-defined variables:
c  ---------------------------
c  RCS information: 
      CHARACTER*132  CFILE, CREVIS, CSTATE, CDATE, CAUTHO, CRCSID
      PARAMETER (CFILE = '$RCSfile: ccm_bevt.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO = '$Author: kossov $')
      DATA CRCSID/   
     & '$Id: ccm_bevt.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='ccm_bevt')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER IFIRST
      INTEGER ind, i, j, k, ia, is, it, name_i, NROW, NSECT
      INTEGER NAMIND
      DATA IFIRST /0/
c_end_var
c
c  executable code for routine USER_BEVT:
c
c----6----------------------------------------------------------------72
c
      IF (IFIRST .EQ. 0) THEN
        WRITE(CRMESS,*)'First call'
        CALL RECMES(CRNAME,'I',CRMESS)
        name_i = NAMIND(CC_SIM_BANK) ! get the first pointer to CC BOS bank
        IF (name_i.EQ.0) THEN
          CRMESS='No CC BOS bank registered'
          CALL RECMES(CRNAME,'I',CRMESS)
          RETURN
        ENDIF
        IFIRST = 1
      ENDIF
c
      IF (CCM_Dbg_hist .GT. 0) CALL HCDIR('//PAWC/CCM',' ')
c
      CALL VZERO(n_hits_CC,6)
c
      ind = iw(name_i) ! first pointer to the CC information
c
c --- Cycle on "hits" in CC ( "Hit" here is like DIGI from GSIM )
c
      DO WHILE (ind .NE. 0)
c
        NSECT = iw(ind - 2) ! a sector #
        NROW  = iw(ind - 4) ! a#of rows
c
        k = 2*ind
        DO i = 1, NROW
c
          j=n_hits_CC(NSECT)+1
          n_hits_CC(NSECT)=j      ! increment a#of hits in the CC sector
          is = iw16(k + 1)
          n_CC_hit (j,NSECT) = is ! put section # in COMMON
          it = iw16(k + 2)
          I_TDC_CC (j,NSECT) = it ! put TDC value in COMMON
          ia = iw16(k + 3)
          I_ADC_CC (j,NSECT) = ia ! put ADC value in COMMON
c
          IF (CCM_Dbg_hist .GT. 0) THEN
            IF (it .GT. 0) CALL HFILL(201,FLOAT(is),FLOAT(NSECT),1.)
            IF (ia .GT. 0) CALL HFILL(202,FLOAT(is),FLOAT(NSECT),1.)
          ENDIF
c
          k = k + 3 ! increment the pointer
        ENDDO
c
        ind = iw(ind-1) ! the next set of hits in the event
c
      ENDDO
c
C --- Update a BITMAP for the event
      DO NSECT=1,6
        IF (n_hits_CC(NSECT) .GT. 0) bitmap(4,NSECT) = 2
      ENDDO
c
c=========>   CC_HRB block filling (CC hits bank )
c
      IF (CCM_Sim_bank .GT. 0) CALL CCM_HRBF
c
c=========>
c
      IF (CCM_Dbg_hist .GT. 0) CALL HCDIR('//PAWC',' ')
c
      RETURN
      END
c
c------------------------------------------------------------------------
