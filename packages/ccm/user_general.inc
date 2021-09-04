c      include file user_general
c
c_begin_doc
c  RCS ID string
c  $Id: user_general.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file USER_GENERAL
c
c  Purpose: General arrays for the DCM package
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
c  variables for include file USER_GENERAL:
c  ----------------------------------------
c  RCS information: 
      CHARACTER*(132)  CIUSER_GENERAL
      DATA CIUSER_GENERAL/
     +'$Id: user_general.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'
     +/
c----6----------------------------------------------------------------72
c  
c  Variables contained in USER_GENERAL
c  -----------------------------------
c
C- S - sector number
C- bitmap(6:T,S,D,C,E,L;6-sectors) - busy BOS bank FLAGS
C  0 - no info, 1 - exists, 2 - read, 3 - reconstructed, 4 - second loop
C- evmask(10): 1 - TAGT counters  ('TAGT')
C              2 - TAGE counters  ('TAGE')
C              3 - STart counters ('ST  ')
C              4 - Scint Counters ('SC  ')
C              5 - Drift Chambers ('DC0 ')
C              6 - Ceren Counters ('CC  ')
C              7 - El.forw. Call. ('EC  ')
C              8 - El.lang. Call. ('EC1 ')
C              9 - 'EC  ' .OR. 'EC1 ' combination (not realized yet)
C             10 - 'ST  ' .OR. 'SC  ' combination (not realized yet)
C-----------------------------------------------------------------------
      INTEGER bitmap(6,6), evmask(10), S
C
      COMMON/USER_GENERAL/ S, bitmap, evmask
C
      SAVE  /USER_GENERAL/
c
c_end_var
c
c----6----------------------------------------------------------------72
