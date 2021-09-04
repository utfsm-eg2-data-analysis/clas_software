      SUBROUTINE CCM_PREDRAW
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_predraw.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_PREDRAW
c
c  Purpose: Preparation for the CCM drawing at the begining of RUN
c  --------
c
c  Calling Sequence:
c  ----------------
c
c  Input Parameters:  NONE
c  ----------------
c
c  Output Parameters:  NONE
c  -----------------
c
c  Called from:
c  ------------
c
c  Other routines:
c  ---------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov      Created:  Mon May 12 14:01:12 EST 1997
c  -------
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
#include "draw_general.inc"
#include "ccm_drawing.inc"
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
      CHARACTER*(*)  CFILE, CREVIS, CSTATE, CDATE, CAUTHO 
      PARAMETER (CFILE=  '$RCSfile: ccm_predraw.F,v $')
      PARAMETER (CREVIS= '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE= '$State: Exp $')
      PARAMETER (CDATE=  '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO= '$Author: kossov $')
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='ccm_predraw')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE,i,j,k
      REAL dgr
c_end_var
c
c  executable code for routine CCM_PREDRAW:
c  ----------------------------------------
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        WRITE(CRMESS,*)'First call'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
c
      dgr = acos(0.)/90.
c
      DO i=1,18
        ccm_xyt(1,5,i)=lbl(i)*COS((thetm(i)-dthet(i))*dgr)+draw_zshift
        ccm_xyb(1,5,i)=lbl(i)*COS((thetm(i)-dthet(i))*dgr)+draw_zshift
        ccm_xyt(2,5,i)=draw_xshift-lbl(i)*SIN((thetm(i)-dthet(i))*dgr)
        ccm_xyb(2,5,i)=draw_xshift+lbl(i)*SIN((thetm(i)-dthet(i))*dgr)
        ccm_xyt(1,1,i)=lbl(i)*COS((thetm(i)-dthet(i))*dgr)+draw_zshift
        ccm_xyb(1,1,i)=lbl(i)*COS((thetm(i)-dthet(i))*dgr)+draw_zshift
        ccm_xyt(2,1,i)=draw_xshift-lbl(i)*SIN((thetm(i)-dthet(i))*dgr)
        ccm_xyb(2,1,i)=draw_xshift+lbl(i)*SIN((thetm(i)-dthet(i))*dgr)
        ccm_xyt(1,4,i)=lbl(i)*COS((thetm(i)+dthet(i))*dgr)+draw_zshift
        ccm_xyb(1,4,i)=lbl(i)*COS((thetm(i)+dthet(i))*dgr)+draw_zshift
        ccm_xyt(2,4,i)=draw_xshift-lbl(i)*SIN((thetm(i)+dthet(i))*dgr)
        ccm_xyb(2,4,i)=draw_xshift+lbl(i)*SIN((thetm(i)+dthet(i))*dgr)
        ccm_xyt(1,3,i)=(dep(i)+lbl(i))*COS((thetm(i)+dthet(i))*dgr)+
     +   draw_zshift
        ccm_xyb(1,3,i)=(dep(i)+lbl(i))*COS((thetm(i)+dthet(i))*dgr)+
     +   draw_zshift
        ccm_xyt(2,3,i)=draw_xshift-(dep(i)+lbl(i))*SIN((thetm(i)+
     +     dthet(i))*dgr)
        ccm_xyb(2,3,i)=draw_xshift+(dep(i)+lbl(i))*SIN((thetm(i)+
     +     dthet(i))*dgr)
        ccm_xyt(1,2,i)=(dep(i)+lbl(i))*COS((thetm(i)-dthet(i))*dgr)+
     +   draw_zshift
        ccm_xyb(1,2,i)=(dep(i)+lbl(i))*COS((thetm(i)-dthet(i))*dgr)+
     +   draw_zshift
        ccm_xyt(2,2,i)=draw_xshift-(dep(i)+lbl(i))*SIN((thetm(i)-
     +     dthet(i))*dgr)
        ccm_xyb(2,2,i)=draw_xshift+(dep(i)+lbl(i))*SIN((thetm(i)-
     +     dthet(i))*dgr)
      ENDDO
c
      DO i=1,18
        DO k=1,2
          DO j=1,5
            ccm_xyh(k,j,i+i)=ccm_xyt(k,j,i)
            ccm_xyl(k,j,i+i)=ccm_xyb(k,j,i)
            ccm_xyh(k,j,i+i-1)=ccm_xyt(k,j,i)
            ccm_xyl(k,j,i+i-1)=ccm_xyb(k,j,i)
          ENDDO
          ccm_xyh(k,1,i+i)=(ccm_xyt(k,1,i)+ccm_xyt(k,4,i))/2.+.5
          ccm_xyl(k,1,i+i)=(ccm_xyb(k,1,i)+ccm_xyb(k,4,i))/2.+.5
          ccm_xyh(k,5,i+i)=(ccm_xyt(k,1,i)+ccm_xyt(k,4,i))/2.+.5
          ccm_xyl(k,5,i+i)=(ccm_xyb(k,1,i)+ccm_xyb(k,4,i))/2.+.5
          ccm_xyh(k,2,i+i)=(ccm_xyt(k,2,i)+ccm_xyt(k,3,i))/2.+.5
          ccm_xyl(k,2,i+i)=(ccm_xyb(k,2,i)+ccm_xyb(k,3,i))/2.+.5
          ccm_xyh(k,4,i+i-1)=(ccm_xyt(k,1,i)+ccm_xyt(k,4,i))/2.+.5
          ccm_xyl(k,4,i+i-1)=(ccm_xyb(k,1,i)+ccm_xyb(k,4,i))/2.+.5
          ccm_xyh(k,3,i+i-1)=(ccm_xyt(k,2,i)+ccm_xyt(k,3,i))/2.+.5
          ccm_xyl(k,3,i+i-1)=(ccm_xyb(k,2,i)+ccm_xyb(k,3,i))/2.+.5
        ENDDO
      ENDDO
c
      DO i=1,36
        DO k=1,2
          ccm_rxyh(k,1,i)=(ccm_xyh(k,2,i)-ccm_xyh(k,1,i))/20.
          ccm_rxyh(k,2,i)=(ccm_xyh(k,3,i)-ccm_xyh(k,4,i))/20.
          ccm_rxyl(k,1,i)=(ccm_xyl(k,2,i)-ccm_xyl(k,1,i))/20.
          ccm_rxyl(k,2,i)=(ccm_xyl(k,3,i)-ccm_xyl(k,4,i))/20.
        ENDDO
      ENDDO
c
      RETURN
      END
c
c------------------------------------------------------------------------------




