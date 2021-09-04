      SUBROUTINE BOOK_CCRC_NT(NTID)
c
c_begin_doc
c  RCS ID string
c  $Id: book_ccrc_nt.F,v 1.1 1997/06/11 04:41:28 stepanya Exp $
c
c  Documentation for subroutine BOOK_CCRC_NT
c
c  Purpose:
c  --------
c
c  Input Parameters:  (Name - Type - Meaning)
c  ----------------
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
c  Author:   S. Stepanyan      Created:  Sun Feb 16 13:18:30 EST 1997
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
#include "ccrc_nt.inc"
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
      PARAMETER (CFILE = '$RCSfile: book_ccrc_nt.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.1 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1997/06/11 04:41:28 $')
      PARAMETER (CAUTHO = '$Author: stepanya $')
      DATA CRCSID/   
     1'$Id: book_ccrc_nt.F,v 1.1 1997/06/11 04:41:28 stepanya Exp $'   
     2/   
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='BOOK_CCRC_NT')
      PARAMETER (CRAUTH='Stepan Stepanyan')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE,NTID
c_end_var
c
c  executable code for routine BOOK_CCRC_NT:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='This routine booking a N-tuple for CC hits'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF

c Ntuple block for CCRC raw information
       call hbname(NTID,'CCRC',nCCR,
     +'nCCR[0,30]:I,CCR_sect(nCCR)[1,6]:I,CCR_seg(nCCR)[0,360]:I,'//
     +'CCR_segx(nCCR)[0,360]:I,CCR_segn(nCCR)[0,360]:I,'//
     +'CCR_phe(nCCR):I,CCR_t(nCCR):I,CCR_th(nCCR):I,CCR_dth(nCCR):I,'//
     +'CCR_ph(nCCR):I,CCR_iec(nCCR):I,CCR_diec(nCCR):I,'//
     +'CCR_stat(nCCR):I')

      RETURN
      END
c
c------------------------------------------------------------------------------




