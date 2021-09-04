c      include file CCM_CALIB
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_calib.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file CCM_CALIB as CCCALB (A.V.)
c
c  Purpose:  Stored calibration constants   
c  --------
c
c  Author:   Mikhail Kossov    Created:  Mon May  9 16:40:14 EDT 1997
c  -------
c
c  Major revisions:
c  ----------------
c
c_end_doc
c_begin_var
c  variables for include file CCCALB:
c  -----------------------------------
c  RCS information: 
      CHARACTER*(132)  CICCM_CALIB
      DATA CICCM_CALIB/
     1'$Id: ccm_calib.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c----6----------------------------------------------------------------72
c  
c  Variables contained in CCM_CALIB common block:
c  ----------------------------------------------
c
      INTEGER mccsegm,   ! Max number of CC segments
     &        kcciden,   ! 1000*Sector + Segment (1-36)
     &        kccpmtn,   ! Unique PMT number
     &        kccrunn    ! Calibration run number
      REAL    xcct2ch,   ! Time to chann. coeff. ( ~ 0.05 )
     &        opheamp,   ! One ph.e. amplitude
     &        dpheamp,   ! One ph.e. amplitude dispersion
     &        ccpedes,   ! Amplitude pedestal
     &        acctime,   ! Additive time constant
     &        dcctime,   ! Additive time constant dispersion
     &        rccsens    ! Normalized PMT sensib. for Cerenkov photons
c
      PARAMETER ( mccsegm = 36 )   !  Number of CC segments
c
c_end_var
c
      COMMON /CCM_CALIB/   kcciden(6,mccsegm), xcct2ch(6,mccsegm),
     & opheamp(6,mccsegm), dpheamp(6,mccsegm), ccpedes(6,mccsegm),
     & acctime(6,mccsegm), dcctime(6,mccsegm), kccpmtn(6,mccsegm),
     & rccsens(6,mccsegm), kccrunn(6,mccsegm)
      SAVE /CCM_CALIB/
c    
c =========================================================




