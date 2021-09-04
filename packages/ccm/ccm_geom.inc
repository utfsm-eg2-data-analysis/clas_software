c      include file ccm_geom
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_geom.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file CCM_GEOM
c
c  Purpose: Arrays for the CCM geometry
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
c  variables for include file CCM_GEOM:
c  ----------------------------------------
c  RCS information: 
      CHARACTER*(132)  CICCM_GEOM
      DATA CICCM_GEOM/
     & '$Id: ccm_geom.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c----6----------------------------------------------------------------72
c  
c  Variables contained in CCM_GEOM
c  ---------------------------------------------------------------------
c
C-----------------------------------------------------------------------
C
c
C
      REAL thetm(18),dthet(18),lbl(18),dep(18),hlp(18)
      COMMON/CCM_GEOM/thetm,dthet,lbl,dep,hlp
C
      SAVE  /CCM_GEOM/
c
c_end_var
c
c----6----------------------------------------------------------------72




