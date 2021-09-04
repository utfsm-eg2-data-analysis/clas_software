c      include file CCM_REVT
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_revt.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file CCM_REVT
c
c  Purpose:
c  --------
c
c  Used in routines:
c  ----------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov    Created:  Fri May 09 18:41:47 EDT 1997
c  -------
c
c  Major revisions:
c  ----------------
c
c_end_doc
c
c_begin_var
c  variables for include file CCM_REVT:
c  -----------------------------------
c  RCS information: 
      CHARACTER*(132)  CICC_REVT
      DATA CICC_REVT/
     1'$Id: ccm_revt.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c----6----------------------------------------------------------------72
c  
C===COMMON/ccm_revt/======================================================
C
C   Unpacked EVENT for RECONSTRACTION procedure.
C   Originally created by Alexander Vlassov 06/05/96 as "cc_revt.inc"
C=======================================================================
C
C -- Arrays in the COMMON/ccm_revt/
C
C  max_n_hit_CC - Maximun number of hitted tracks in one sector (27)
C  n_hits_CC  (6) - a#of of hits in a sector
C  n_CC_hit  (,6) - CC_segment #
C                   (+ rigth; - left from MIDDLE plane, view from target)
C  I_TDC_CC  (,6) - Total time of flight from target to CC_PMT in 50 ps/ch
C  I_ADC_CC  (,6) - NUMBER of registered photo-electrons in PMT (1 ph_e/ch)
C  CM_TO_CH       - Scale factor for TOF calculation (per channel) (50 ps)
C=======================================================================
C
      INTEGER max_n_hit_CC, n_hits_CC,  n_CC_hit
      INTEGER I_TDC_CC, I_ADC_CC
      REAL CM_TO_CH
C
      PARAMETER (max_n_hit_CC = 27)
      PARAMETER (CM_TO_CH = 0.667128190396)
C
      COMMON /ccm_revt/   n_hits_CC(6),
     &                    n_CC_hit (max_n_hit_CC,6),
     &                    I_TDC_CC (max_n_hit_CC,6),
     &                    I_ADC_CC (max_n_hit_CC,6)
C
      CHARACTER*4 CC_SIM_BANK
      DATA CC_SIM_BANK /'CC  '/
C--- End of ccm_revt common
C
c_end_var
c




