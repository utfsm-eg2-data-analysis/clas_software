      SUBROUTINE FILL_EPICS_NT(ierr)
c
c_begin_doc
c  RCS ID string
c  $Id: fill_epics_nt.F,v 1.3 2005/08/09 19:18:17 stepanya Exp $
c
c  Documentation for subroutine FILL_EPICS_NT.F
c
c  Purpose:
c  --------
c
c  Input Parameters: Non (Name - Type - Meaning)
c  ----------------
c
c  Output Parameters:Non  (Name - Type - Meaning)
c  -----------------
c
c  Other routines:
c  ---------------
c
c  Notes:
c  ------
c
c  Author:  S. Stepanyan       Created:  2004
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
#include "clasmdl.inc"
#include "epics_nt.inc"
#include "epics.inc"
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
      PARAMETER (CFILE = '$RCSfile: fill_epics_nt.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.3 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 2005/08/09 19:18:17 $')
      PARAMETER (CAUTHO = '$Author: stepanya $')
      DATA CRCSID/   
     1'$Id: fill_epics_nt.F,v 1.3 2005/08/09 19:18:17 stepanya Exp $'   
     2/   
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='FILL_EPICS_NT.F')
      PARAMETER (CRAUTH='Stepan Stepanyan')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE, ierr,i, ITGBI,ind,MAMIND
      DATA ITGBI/0/
      integer gtime(9),flag
      logical first
      character*99 fname
      external mamind
      data first/.true./
c_end_var
c
c  executable code for routine FILL_EPICS_NT.F:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='Filling a N-tuple for EPICS hits'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
      run=NCCRUN
      if(first) then
         call revinm('CLAS_PARMS','Maps/RUN_CONTROL.map',fname)
         call map_get_float(fname,'beam','energy',1,ebad,run,flag)
         first=.false.
      endif
      event=nevent
      call gmtimef(evtime,gtime)
      evntime=((gtime(4)-17)*24+gtime(3))*3600+gtime(2)*60+gtime(1)
      ebsya=epics_value(1)
      ebsyb=epics_value(2)
      etiefa=epics_value(111)
      if(epics_value(81).ne.0.)ierr=1
c magnet settings
      pscurrent=epics_value(146)
      psprobe=epics_value(150)
      taggerprobe=epics_value(149)
      taggercurrent=epics_value(28)
c BPMs
      x2c21a=epics_value(79)
      y2c21a=epics_value(80)
      c2c21a=epics_value(81)
      x2c24a=epics_value(70)
      y2c24a=epics_value(71)
      c2c24a=epics_value(72)
      x2h01a=epics_value(61)
      y2h01a=epics_value(62)
      c2h01a=epics_value(63)
c target type, target position, NMR P, LHe, Fcup, 1/2 wave plate
      target_type=epics_value(158)
      target_position=epics_value(161)
      polarization=epics_value(165)
      he_level=epics_value(166)
      fcup=epics_value(48)
      half_wave=epics_value(33)

c     print *, '!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!!'

      IF(ITGBI.eq.0)ITGBI=MAMIND(IW,'TGBI')      
      if(iTGBI.gt.0)ind=IW(ITGBI)
      intt=rw(ind+3)
      epics_value(81)=0.
      RETURN
      END
c
c------------------------------------------------------------------------------




