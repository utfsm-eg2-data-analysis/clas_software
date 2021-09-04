      SUBROUTINE CCM_LAST
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_last.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_LAST
c
c  Purpose:  USER supplied routined called ONCE at the end of job.
c  --------  do your end job processing HERE.  Lines commented with
c            the phrase `chbook' are used to close the HBOOK file at the
c            end of a job.  The user should perform a global delete of
c            the phrase `chbook' if they want to close the HBOOK file
c            opened in USER_INIT.
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
c  Called by: user_last
C  ----------
C
c  Other routines:
c  ---------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov      Created:  Fri May  9 14:01:36 EST 1997
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
      PARAMETER (CFILE=  '$RCSfile: ccm_last.F,v $')
      PARAMETER (CREVIS= '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE= '$State: Exp $')
      PARAMETER (CDATE=  '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO= '$Author: kossov $')
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='CCM_LAST')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE
c_end_var
c
c  executable code for routine CCM_LAST:
c  -------------------------------------
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='This is a CCM the LAST subroutine'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
C
C
      RETURN
      END
c
c------------------------------------------------------------------------------




