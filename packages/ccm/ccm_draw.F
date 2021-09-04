      SUBROUTINE CCM_DRAW
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_draw.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_DRAW
c
c  Purpose: CCM drawing in the begin of the event
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
#include "user_general.inc"
#include "draw_general.inc"
#include "ccm_drawing.inc"
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
      PARAMETER (CFILE=  '$RCSfile: ccm_draw.F,v $')
      PARAMETER (CREVIS= '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE= '$State: Exp $')
      PARAMETER (CDATE=  '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO= '$Author: kossov $')
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='ccm_draw')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE,i
c_end_var
c
c  executable code for routine CCM_DRAW:
c  -------------------------------------
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='First call'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
c
      DO i=1,18
        IF (S .EQ. tops) THEN
          CALL IXLINE (5,ccm_xyt(1,1,i))
          ELSEIF (S .EQ. bots .OR. S .EQ. -1) THEN
          CALL IXLINE (5,ccm_xyb(1,1,i))
        ENDIF
      ENDDO
      CALL IXUPDWI (0)                    ! Flush the picture
c
      RETURN
      END
c
c------------------------------------------------------------------------------




