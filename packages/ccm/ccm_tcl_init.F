      SUBROUTINE CCM_TCL_INIT
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_tcl_init.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_TCL_INIT
c
c  Purpose:  CCM routine for initializing runtime variables
c  --------
c
c  Input Parameters:  none
c  ----------------
c
c  Output Parameters:  none
c  -----------------
c
c  Other routines:
c  ---------------
c
c  Notes:
c  ------
c
c  Author:  Mikhail Kossov     Created:  Mon May  9 17:04:06 EST 1997
C  -------
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
c BOS common block  uncomment the next line for BOS include file
#include "ccm_control.inc"
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
      PARAMETER (CFILE = '$rcsRCSfile$')
      PARAMETER (CREVIS = '$rcsRevision$')
      PARAMETER (CSTATE = '$rcsState$')
      PARAMETER (CDATE = '$rcsDate$')
      PARAMETER (CAUTHO = '$rcsAuthor$')
      DATA CRCSID/   
     1'$Id: ccm_tcl_init.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='ccm_tcl_init')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE
      INTEGER ITCL_INT, ITCL_STRING, ITCL_INT_READ
      DATA ITCL_INT, ITCL_STRING, ITCL_INT_READ/1,4,129/
c_end_var
c
c  executable code for routine CCM_TCL_INIT:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        WRITE(CRMESS,*)'Tcl definitions for the CCM package'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
c
c  The below call LINKS the fortran variable to the tcl variable, to 
c  interactive change the value of `my_variable' either:
c     A) type  set my_variable 10  at the prompt or in your INITializing script
c     B) setup the communication shell and : SendMsg "set my_variable 10"
c
      CALL TCL_LINKVAR('CCM_Dbg_hist',CCM_Dbg_hist,itcl_int)
      CALL TCL_LINKVAR('CCM_Sim_bank',CCM_Sim_bank,itcl_int)
      CALL TCL_LINKVAR('CCM_BOSb_out',CCM_BOSb_out,itcl_int)
C     ---- =========== name in list , value , 1=int,2=double,4=string,129=READ
c
      RETURN
      END
c
c------------------------------------------------------------------------------




