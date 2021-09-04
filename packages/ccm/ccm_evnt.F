      SUBROUTINE CCM_EVNT
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_evnt.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_EVNT similar to CC_EVNT of A.V.
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
c  Author:   Mikhail Kossov      Created:  Fri May  9 18:23:45 EDT 1997
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
#include "draw_control.inc"
#include "draw_general.inc"
#include "ccm_control.inc"
#include "ccm_revt.inc"
#include "ccm_drawing.inc"
#include "ccm_rc.inc"
#include "ccm_hrb.inc"
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
      PARAMETER (CFILE = '$RCSfile: ccm_evnt.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO = '$Author: kossov $')
      DATA CRCSID/   
     1'$Id: ccm_evnt.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='ccm_evnt')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE, x3, y3, x2, y2
      INTEGER i,j,NCC,INCC,nphe,iped, ncchit, ITDC, NCC10
      REAL a_cal,ANCC,Ee,theta,dtheta,riec,rdiec,rxec,drxec,sc
      REAL thet_cc(18)
c
      DATA Ee /1.0/
      DATA thet_cc /  7.72,  9.44, 11.17, 12.93, 14.69, 16.47, 18.29,
     * 20.15, 22.03, 24.00, 26.04, 28.18, 30.48, 32.94, 35.44, 37.97,
     * 40.51, 43.11/
      DATA NWRITE /0/
c_end_var
c
c  executable code for routine CCM_EVNT:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 2
        WRITE(CRMESS,*)'First call with sector #',S
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
c
      IF (RED_let_draw .EQ. 1) CALL CCM_DRAW
c
      nrclust = 0
      CALL VZERO(nrstat,maxcrec)
      CALL VZERO(nrsegm,maxcrec)
      CALL VZERO( nrphe,maxcrec)
      CALL VZERO(nrtime,maxcrec)
      CALL VZERO(nrthet,maxcrec)
      CALL VZERO( nrphy,maxcrec)
c
      DO 100 i = 1, n_hits_CC(S)
c
        ncchit = n_CC_hit(i,S)
        ITDC = I_TDC_CC(i,S)
        nphe = 0
        a_cal = opheamp(S,ncchit)
        iped  = ccpedes(S,ncchit) + 0.5
        IF (a_cal .GE. 1.) THEN
          nphe  = 10 * (I_ADC_CC(i,S) - iped)/ a_cal + 0.5
        ELSE
          WRITE(CRMESS,*) 'WRONG calibration parameters for sector',
     &     S,', Segment:',ncchit
          CALL RECMES(CRNAME,'F',CRMESS)
        ENDIF
c
c ---- Drawing M.K.
        IF (RED_let_draw .EQ. 1) THEN
          CALL IXSETFC (green) ! Area color is green (raw) M.K.
          IF (S .EQ. bots) THEN
            CALL IXFLARE (5, ccm_xyl(1,1,ncchit)) ! fill green
            CALL IXSETFC (red) ! Area color is red (good) M.K.
            IF (nphe .GT. 0) THEN
              IF (nphe .GE. 20) THEN
                sc=FLOAT(nphe)/20. ! 20. Now HARDWIRED. Make par.(in PREDRAW)
                x2=ccm_xyl(1,2,ncchit)
                y2=ccm_xyl(2,2,ncchit)
                x3=ccm_xyl(1,3,ncchit)
                y3=ccm_xyl(2,3,ncchit)
             ccm_xyl(1,2,ncchit)=ccm_xyl(1,1,ncchit)+
     +        sc*ccm_rxyl(1,1,ncchit)+.5
             ccm_xyl(2,2,ncchit)=ccm_xyl(2,1,ncchit)+
     +        sc*ccm_rxyl(2,1,ncchit)+.5
             ccm_xyl(1,3,ncchit)=ccm_xyl(1,4,ncchit)+
     +        sc*ccm_rxyl(1,2,ncchit)+.5
             ccm_xyl(2,3,ncchit)=ccm_xyl(2,4,ncchit)+
     +        sc*ccm_rxyl(2,2,ncchit)+.5
                CALL IXFLARE (5, ccm_xyl(1,1,ncchit))
                ccm_xyl(1,2,ncchit)=x2
                ccm_xyl(2,2,ncchit)=y2
                ccm_xyl(1,3,ncchit)=x3
                ccm_xyl(2,3,ncchit)=y3
              ELSE
                CALL IXFLARE (5, ccm_xyl(1,1,ncchit))
              ENDIF
            ENDIF
          ELSEIF (S .EQ. tops) THEN
            CALL IXFLARE (5, ccm_xyh(1,1,ncchit)) ! fill green
            CALL IXSETFC (red) ! Area color is red (good) M.K.
            IF (nphe .GT. 0) THEN
              IF (nphe .GE. 20) THEN
                sc=FLOAT(nphe)/20. ! 20. Now HARDWIRED. Make par.(in PREDRAW)
                x2=ccm_xyh(1,2,ncchit)
                y2=ccm_xyh(2,2,ncchit)
                x3=ccm_xyh(1,3,ncchit)
                y3=ccm_xyh(2,3,ncchit)
             ccm_xyh(1,2,ncchit)=ccm_xyh(1,1,ncchit)+
     +        sc*ccm_rxyh(1,1,ncchit)+.5
             ccm_xyh(2,2,ncchit)=ccm_xyh(2,1,ncchit)+
     +        sc*ccm_rxyh(2,1,ncchit)+.5
             ccm_xyh(1,3,ncchit)=ccm_xyh(1,4,ncchit)+
     +        sc*ccm_rxyh(1,2,ncchit)+.5
             ccm_xyh(2,3,ncchit)=ccm_xyh(2,4,ncchit)+
     +        sc*ccm_rxyh(2,2,ncchit)+.5
                CALL IXFLARE (5, ccm_xyh(1,1,ncchit))
                ccm_xyh(1,2,ncchit)=x2
                ccm_xyh(2,2,ncchit)=y2
                ccm_xyh(1,3,ncchit)=x3
                ccm_xyh(2,3,ncchit)=y3
              ELSE
                CALL IXFLARE (5, ccm_xyh(1,1,ncchit))
              ENDIF
            ENDIF
          ENDIF
        ENDIF
c
        IF (nphe .LT. 1) GOTO 100
c
        NCC =  (ncchit+1)/2
        NCC10 = NCC*10
        INCC = 1 - 2*mod(ncchit,2)
c
        IF (nrclust .GE. maxcrec) THEN
          write(CRMESS,*)'nclust=',nrclust,' > ',maxcrec,
     &    ' HITS during reconstruction !!!'
          GOTO 100                     ! Enough hits ?
        ENDIF
c
        IF (nrclust .EQ. 0) THEN
c
          nrclust = 1
          nrsegm(nrclust)   = NCC10
          nrsegm_p(nrclust) = NCC10  
          nrsegm_m(nrclust) = NCC10  
c
          nrphe (nrclust) = nphe
c            
          nrtime(nrclust) = ITDC
c         =============================> Also should be changed, but... 
          nrphy (nrclust) = INCC
          ANCC = 0.1 * nrsegm(nrclust)
          CALL CCM_NCC2THET(ANCC,Ee,theta,dtheta)          
          nrthet(nrclust) = theta + 0.5
          nrdthet(nrclust) = dtheta + 0.5 
          CALL CCM_NCC2IEC (ANCC,Ee,riec,rdiec)         
          nriec(nrclust) = riec + 0.5
          nrdiec(nrclust) = rdiec + 0.5
          CALL CCM_N2XEC(ANCC,rxec,drxec) 
          nrxec(nrclust) = rxec + 0.5
          nrdxec(nrclust) = drxec + 0.5
c
        ELSE
c
          DO j = 1, nrclust
c  
            IF ( ABS(nrsegm(j) - NCC10) .LE. isgmdiff ) THEN ! same cluster
c - Weighted CC #
            nrsegm(j)=(nrphe(j)*nrsegm(j)+nphe*NCC10)/(nrphe(j)+nphe)+.5
            IF (NCC10 .GE. nrsegm_p(j)) nrsegm_p(j) = NCC10
            IF (NCC10 .LE. nrsegm_m(j)) nrsegm_m(j) = NCC10
c
              nrphe(j) = nrphe(j) + nphe
              IF (ITDC .LE. nrtime(j)) nrtime(j) = ITDC
c         =============================> Also should be changed, but... 
              IF (nrphy (j) .NE. INCC) THEN 
                nrphy (j) = 0
              ENDIF
c
              ANCC = 0.1*nrsegm(j)
              CALL CCM_NCC2THET(ANCC,Ee,theta,dtheta)          
              nrthet(j) = theta + 0.5
              nrdthet(j) = dtheta + 0.5 
              CALL CCM_NCC2IEC (ANCC,Ee,riec,rdiec)         
              nriec(j) = riec + 0.5
              nrdiec(j) = rdiec + 0.5 
              CALL CCM_N2XEC (ANCC,rxec,drxec) 
              nrxec(j) = rxec + 0.5
              nrdxec(j) = drxec + 0.5
c
              GOTO 100
            ENDIF 
c
          ENDDO
c
c ======> new cluster
c
          nrclust = nrclust + 1
          nrsegm(nrclust)   = NCC10
          nrsegm_p(nrclust) = NCC10  
          nrsegm_m(nrclust) = NCC10
c  
          nrphe (nrclust) = nphe
c            
          nrtime(nrclust) = ITDC 
c         =============================> Also should be changed, but... 
          ANCC = 0.1 * nrsegm(nrclust)
          CALL CCM_NCC2THET(ANCC,Ee,theta,dtheta)
          nrthet(nrclust) = theta + 0.5
          nrdthet(nrclust) = dtheta + 0.5 
          CALL CCM_NCC2IEC (ANCC,Ee,riec,rdiec)         
          nriec(nrclust) = riec + 0.5
          nrdiec(nrclust) = rdiec + 0.5 
          CALL CCM_N2XEC(ANCC,rxec,drxec) 
          nrxec(nrclust) = rxec + 0.5
          nrdxec(nrclust) = drxec + 0.5
          nrphy (nrclust) = INCC
c
        ENDIF
c
  100 CONTINUE
c
      IF(RED_let_draw .EQ. 0) CALL IXUPDWI (0) ! Flush the raw picture
c
      IF (nrclust .GE. 1 .AND. CCM_BOSb_out .GT. 0) THEN
c
        CALL CCM_BOS_FILL
c       ================>  filling BOS bank CCRC !! Seporated by sectors M.K.!!
c
      ENDIF
c
      RETURN
      END
c
c-----------------------------------------------------------------------




