      SUBROUTINE CCM_BOS_FILL
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_bos_fill.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_BOS_FILL as CC_BOS_FILL (A.V.)
c
c  Purpose: Filling CC reconstruction bank CCRC
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
c  Author:   Mikhail Kossov    Created:  Mon May 12 10:54:14 EDT 1997
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
#include "user_general.inc"
#include "ccm_rc.inc"
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
      PARAMETER (CFILE = '$RCSfile: ccm_bos_fill.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO = '$Author: kossov $')
      DATA CRCSID/   
     1'$Id: ccm_bos_fill.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*300  CRMESS
      PARAMETER (CRNAME='CCM_BOS_FILL')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE
c
      INTEGER i, k, icc
      LOGICAL LOCBNK
      INTEGER NCOL
      CHARACTER*256 CFMT
      CHARACTER*8 CDISC(100)
c
      INTEGER nbank
c_end_var
c
c  executable code for routine CCM_BOS_FILL:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='CCM_BOS_FILL was called'
        CALL RECMES(CRNAME,'I',CRMESS)
c
        LOCBNK = .false.
        CALL BNKTST('CCRC',LOCBNK,NCOL,CFMT,CDISC)
        IF (LOCBNK) THEN
          write(CRMESS,*) ' CCRC bank exists'
          CALL RECMES(CRNAME,'I',CRMESS)
c          write(CRMESS,*) 'Number of columns :',NCOL
c          call recmes(CRNAME,'I',CRMESS)
c          write(CRMESS,*) 'Bank format : ',CFMT
c          call recmes(CRNAME,'I',CRMESS)
          IF (NCOL .NE. 12) THEN
            WRITE (CRMESS,*) 'Wrong number of columns in bank CCRC :', 
     +      NCOL,'  (should be 12 )'
            CALL RECMES(CRNAME,'E',CRMESS)
          ENDIF
        ELSE
          WRITE (CRMESS,*) ' Can not access the bank CCRC'
          CALL recmes(CRNAME,'E',CRMESS)
          RETURN
        ENDIF
      ENDIF
c
c  filling BOS bank 'CCRC'
c
      IF (nrclust .GT. maxcrec) THEN
        WRITE(CRMESS,*)'#of clust=',nrclust,' > ',maxcrec,' in CC sec#',S
        CALL RECMES(CRNAME,'I',CRMESS)
        nrclust=maxcrec
      ENDIF 
      icc = nbank('CCRC',S,NCOL,nrclust)

      DO i = 1 , nrclust
        k = icc + NCOL*(i-1)
        iw( k +  1 )  =  S
        iw( k +  2 )  =  nrsegm(i)
        iw( k +  3 )  =  nrsegm_p(i)
        iw( k +  4 )  =  nrsegm_m(i)
        iw( k +  5 )  =  nrphe(i)
        iw( k +  6 )  =  nrtime(i)
        iw( k +  7 )  =  nrthet(i)
        iw( k +  8 )  =  nrdthet(i)
        iw( k +  9 )  =  nrphy(i)
        iw( k + 10 )  =  nriec(i)
        iw( k + 11 )  =  nrdiec(i)
        iw( k + 12 )  =  nrstat(i)
      ENDDO

      IF (NWRITE .EQ. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='CCM_BOS_FILL end'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF

      RETURN
      END
c
c-----------------------------------------------------------------------
