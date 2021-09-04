      SUBROUTINE CCM_GET_GEOM
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_get_geom.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_GET_GEOM
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
#include "ccm_geom.inc"
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
      PARAMETER (CFILE = '$RCSfile: ccm_get_geom.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO = '$Author: kossov $')
      DATA CRCSID
     +/'$Id: ccm_get_geom.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='ccm_get_geom')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER IFIRST,i
      data IFIRST /0/
      CHARACTER*(*) clas_parms
      CHARACTER*120 filename
      PARAMETER (clas_parms  = 'CLAS_PARMS')
      INTEGER unit,iret,nseg
c_end_var
c
c  executable code for routine CC_GET_GEOM:
c----6----------------------------------------------------------------72
c
      IF (IFIRST .LT. 1) THEN
        WRITE(CRMESS,*)'First call'
        CALL RECMES(CRNAME,'I',CRMESS)
        IFIRST = IFIRST + 1

      ENDIF
C
      CALL REVINM(clas_parms,'ccg.dat',filename)
      CALL RESLUN(CRNAME,unit,iret)
      IF (iret .EQ. -1) CALL RECMES(CRNAME,'F',
     &    'unable to reserve fortran unit')
c
      CALL REOPEN(filename,unit,'old',iret)
      IF (iret .EQ. -1) CALL RECMES(CRNAME,'F',
     &     'unable to open ccg.dat geometry file')
      DO i=1,18
 11     READ(unit,*,ERR=11,END=14) nseg,thetm(i),
     +  dthet(i),lbl(i),dep(i),hlp(i)
c
c        WRITE(CRMESS,*)'R:',nseg,thetm(i),dthet(i),lbl(i),dep(i),hlp(i)
c        CALL RECMES(CRNAME,'I',CRMESS)
c
        IF (nseg .NE. i) THEN
          WRITE(CRMESS,*)'order is wrong i=',i,', nseg=',nseg
          CALL RECMES(CRNAME,'I',CRMESS)
        ENDIF 
      ENDDO
      CLOSE (unit)
      CALL RESLUN(CRNAME,-unit,iret)
      CALL RECMES(CRNAME,'I','EC1 geometry was read normally')
      RETURN
c
 14   WRITE(CRMESS,*)'**** EOF is reached in EC1 file @#seg=',i
      CALL RECMES(CRNAME,'I',CRMESS)
c
      RETURN
      END
c
c-----------------------------------------------------------------------




