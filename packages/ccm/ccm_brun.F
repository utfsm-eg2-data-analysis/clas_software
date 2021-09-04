      SUBROUTINE CCM_BRUN
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_brun.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_BRUN (follows to CC_BRUN of Vlassov)
c
c  Purpose:   Some action before the run ( NOTHING NOW - should be geometry)
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
c  Author:   Mikhail Kossov      Created:  Fri May 9 18:13:28 EDT 1997
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
c BOS common block  uncomment the next line for BOS include file
c#include "bcs.inc"
#include "user_general.inc"
#include "ccm_control.inc"
#include "draw_control.inc"
#include "draw_general.inc"
#include "ccm_calib.inc"
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
      PARAMETER (CFILE = '$RCSfile: ccm_brun.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO = '$Author: kossov $')
      DATA CRCSID
     +  /'$Id: ccm_brun.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='ccm_brun')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      CHARACTER*80 filename
      INTEGER i,LUNC,ires,isect
      INTEGER IFIRST
      data IFIRST /0/
c
c_end_var
c
c  executable code for routine CC_BRUN:
c----6----------------------------------------------------------------72
c
      IF (IFIRST .LT. 1) THEN
        CRMESS='CCM_BRUN is called before the run'
        CALL RECMES(CRNAME,'I',CRMESS)
        IFIRST = IFIRST + 1
      ENDIF
C
      CALL SET_LOG(.TRUE.)
c
c  Register CC package with job database....
c
c      CALL REVINI('CCRC',CREVIS,CDATE)
c     Reading calibration constants. (From a file now)
c
      CALL REVINM('CLAS_PARMS','cccb.dat',filename)
      CALL RESLUN(CRNAME,LUNC,ires)
      IF (ires .EQ. -1) CALL RECMES(CRNAME,'F',
     &  'unable to reserve fortran unit')
      WRITE(CRMESS,*) ' CCCB.dat lun', LUNC
      CALL RECMES(CRNAME,'I',CRMESS)
      CALL REOPEN(filename,LUNC,'old',ires)
      IF (ires .EQ. -1) CALL RECMES(CRNAME,'F',
     &     'unable to open CC calibration file')
c
    1 CONTINUE
c     ========>  File reading cycle
      READ(LUNC,*,ERR=2) isect, i, kcciden(isect,i), xcct2ch(isect,i),
     &             opheamp(isect,i), dpheamp(isect,i), ccpedes(isect,i),
     &             acctime(isect,i), dcctime(isect,i), kccpmtn(isect,i),
     &             rccsens(isect,i), kccrunn(isect,i)
      IF (isect .LT. 1 .OR. isect .GT. 6) GOTO 33   !  Error !
      IF (    i .LT. 1 .OR.     i .GT. 36) GOTO 33   !  Error !
      GOTO 1
    2 CONTINUE
c     ========>  END of file reading cycle
c
      WRITE(CRMESS,*) ' CC calibration data are readed'
      CALL RECMES(CRNAME,'I',CRMESS)
      CLOSE (LUNC)
      CALL RESLUN(CRNAME,-LUNC,ires)
c
c
      CALL RECMES(CRNAME,'I',CRMESS)
C
C___ Here the run geometry for CC should be added
      CALL CCM_GET_GEOM
      IF (RED_let_draw .NE. 0) CALL CCM_PREDRAW
c
      RETURN
c      
   33 CONTINUE
c     ========>   Error in data file
c
      WRITE(CRMESS,*) ' Wrong numbers of sector/segment :',isect,i
      CALL RECMES(CRNAME,'F',CRMESS)
c
      RETURN
      END
c
c-----------------------------------------------------------------------




