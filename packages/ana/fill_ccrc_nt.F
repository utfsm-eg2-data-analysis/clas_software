      SUBROUTINE FILL_CCRC_NT (ierr)
c
c_begin_doc
c  RCS ID string
c  $Id: fill_ccrc_nt.F,v 1.2 1997/06/24 04:05:26 stepanya Exp $
c
c  Documentation for subroutine FILL_CCRC_NT
c
c  Purpose:
c  --------
c
c  Input Parameters: ierr - integer - returnes 1 if there was(were) 
c                     hit(s) in CC
c
c  Output Parameters:  (Name - Type - Meaning)
c  -----------------
c
c  Other routines:
c  ---------------
c
c  Notes:
c  ------
c
c  Author:   S. Stepanyan      Created:  Sun Feb 16 13:26:24 EST 1997
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
#include "bcs.inc"
#include "ccrc_nt.inc"
c_end_inc
c
c_begin_var
c  input/output variables:
c  -----------------------
      INTEGER ierr
c
c  Local pre-defined variables:
c  ---------------------------
c  RCS information: 
      CHARACTER*132  CFILE, CREVIS, CSTATE, CDATE, CAUTHO, CRCSID
      PARAMETER (CFILE = '$RCSfile: fill_ccrc_nt.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.2 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1997/06/24 04:05:26 $')
      PARAMETER (CAUTHO = '$Author: stepanya $')
      DATA CRCSID/   
     1'$Id: fill_ccrc_nt.F,v 1.2 1997/06/24 04:05:26 stepanya Exp $'   
     2/   
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='FILL_CCRC_NT')
      PARAMETER (CRAUTH='Stepan Stepanyan')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE
      INTEGER ind,indx,ix,nd,ncol,iccrc
      INTEGER mamind
c_end_var
c
c  executable code for routine FILL_CCRC_NT:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='This routine fills CC N-tuple'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
      IF(ICCRC.eq.0)ICCRC=MAMIND(IW,'CCRC')
      ind=0
      nCCR=0
      if(iCCRC.ne.0) IND=IW(iCCRC)
      IF(IND.NE.0) THEN
         ND=IW(IND)
         ncol=IW(ind-5)
         DO ix = 1, ND, ncol
            INDX=IND+IX-1
            if(nCCR.lt.maxCCR) then
               nCCR=nCCR+1
               CCR_sect(nCCR) = IW(INDX+1)
               CCR_seg (nCCR) = IW(INDX+2)   
               CCR_segx(nCCR) = IW(INDX+3)
               CCR_segn(nCCR) = IW(INDX+4) 
               CCR_phe (nCCR) = IW(INDX+5)
               CCR_t   (nCCR) = IW(INDX+6) 
               CCR_th  (nCCR) = IW(INDX+7)
               CCR_dth (nCCR) = IW(INDX+8)
               CCR_ph  (nCCR) = IW(INDX+9)
               CCR_iec (nCCR) = IW(INDX+10)
               CCR_diec(nCCR) = IW(INDX+11)
               CCR_stat(nCCR) = IW(INDX+12)
            endif
         ENDDO
      ENDIF

      RETURN
      END
c
c------------------------------------------------------------------------------




