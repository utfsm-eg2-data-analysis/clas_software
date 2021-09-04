c      include file ccm_control
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_control.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file CCM_CONTROL
c
c  Purpose: CONTROL KEYS for the DCM package (draft is similar to SDA)
c  -------- 
c
c  Used in routines:
c  ----------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov      Created:  Fri May  9 10:29:00 EST 1997
c  -------
c
c  Major revisions:
c  ----------------
c
c_end_doc
c
c
c  Remember NO NESTED INCLUDES
c
c  COMMON BLOCK NAME should be the same as include file name!
c
c_begin_var
c  variables for include file CCM_CONTROL:
c  ----------------------------------------
c  RCS information: 
      CHARACTER*(132)  CICCM_CONTROL
      DATA CICCM_CONTROL/
     +'$Id: ccm_control.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c----6----------------------------------------------------------------72
c  
c  Variables contained in CCM_CONTROL
c  -----------------------------------
c
C--------------------------------------------------------
C CCM_Dbg_hist - book & fill Debugging histograms
C CCM_Sim_bank - permission to read additional simulation banks for CC
C CCM_BOSb_out - permission to wright BOS output bank CCRC
C-----------------------------------------------------------------------
C
      INTEGER CCM_Dbg_hist, CCM_Sim_bank, CCM_BOSb_out
C
      COMMON/CCM_CONTROL/
     &        CCM_Dbg_hist, CCM_Sim_bank, CCM_BOSb_out
C
      SAVE  /CCM_CONTROL/
c
c_end_var
c
c----6----------------------------------------------------------------72
