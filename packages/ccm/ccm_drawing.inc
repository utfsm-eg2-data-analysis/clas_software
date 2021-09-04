c      include file ccm_drawing
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_drawing.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file CCM_DRAWING
c
c  Purpose: Arrays for the CCM drawing
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
c  variables for include file CCM_DRAWING:
c  ----------------------------------------
c  RCS information: 
      CHARACTER*(132)  CICCM_DRAWING
      DATA CICCM_DRAWING/
     &'$Id: ccm_drawing.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c----6----------------------------------------------------------------72
c  
c  Variables contained in CCM_DRAWING
c  ---------------------------------------------------------------------
c
C-----------------------------------------------------------------------

      INTEGER*2 ccm_xyt(2,5,18),ccm_xyb(2,5,18),ccm_xyh(2,5,36),
     + ccm_xyl(2,5,36)
      REALccm_rxyh(2,2,36),ccm_rxyl(2,2,36)
      COMMON/CCM_DRAWING/ccm_xyt,ccm_xyb,ccm_xyh,ccm_xyl,
     + ccm_rxyh,ccm_rxyl

      SAVE  /CCM_DRAWING/
c
c_end_var
c
c----6----------------------------------------------------------------72
