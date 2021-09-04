c      include file draw_control
c
c_begin_doc
c  RCS ID string
c  $Id: draw_control.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file DRAW_CONTROL
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
c  variables for include file DRAW_CONTROL:
c  ----------------------------------------
c  RCS information: 
      CHARACTER*(132)  CIDRAW_CONTROL
      DATA CIDRAW_CONTROL/
     +'$Id: draw_control.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'
     +/
c----6----------------------------------------------------------------72
c  
c  Variables contained in DRAW_CONTROL
c  -----------------------------------
c
C--------------------------------------------------------
C RED_let_draw - Permition for the Raw Information collection from ROC's
C RED_drw_tops - Top sectors (1-3) preferably 1 & 2
C RED_drw_bots - Bottom sectors (4-6) preferably 5 & 6
C RED_disp_adr - address (name) of X-terminal
C RED_disp_len - length of the X-terminal name
C-----------------------------------------------------------------------
C
      CHARACTER*16 RED_disp_adr
C
      INTEGER RED_let_draw, RED_drw_tops, RED_drw_bots, RED_disp_len
C
      COMMON/DRAW_CONTROL/ RED_disp_adr,
C - INTEGER parameters
     &       RED_drw_tops, RED_drw_bots, RED_disp_len, RED_let_draw

C
      SAVE  /DRAW_CONTROL/
c
c_end_var
c
c----6----------------------------------------------------------------72
