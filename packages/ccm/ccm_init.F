      SUBROUTINE CCM_INIT
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_init.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_INIT (close to CC_INIT ?)
c
c  Purpose:  Book histograms for CCM package
c  --------  Create //PAWC/CCM directory in PAW
c
c  Input Parameters: NONE
c  ----------------
c
c  Output Parameters: NONE
c  -----------------
c
c  Other routines:
c  ---------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov      Created:  Fri May 9 16:27:07 EDT 1997
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
      PARAMETER ( CFILE = '$RCSfile: ccm_init.F,v $')
      PARAMETER ( CREVIS = '$Revision: 1.1.1.1 $')
      PARAMETER ( CSTATE = '$State: Exp $')
      PARAMETER ( CDATE = '$Date: 1997/08/16 23:05:05 $')
      PARAMETER ( CAUTHO = '$Author: kossov $')
      DATA CRCSID
     + /'$Id: ccm_init.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c  Module information:
      CHARACTER*132  CRNAME, CRAUTH
      CHARACTER*132  CRMESS
      PARAMETER (CRNAME='ccm_init')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE
c_end_var
c
c  executable code for routine CCM_INIT:
c  -------------------------------------
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        WRITE(CRMESS,*)'First call'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
c
c Do the HMDIR stuff twice to declare the subdirectory in memory and disk
c
      CALL HMDIR('CCM','S')
      CALL HCDIR('//PAWC',' ')
      CALL HMDIR('CCM','S')
      CALL HCDIR('//PAWC/CCM','S')
C --- One can make further directories in future if XXM packages are shared
C
c - examples only
      IF ( CCM_Dbg_hist .GT. 0) THEN
        CALL HBOOK2(201,'CCM TDC sector/PMT',36,.5,36.5,6,.5,6.5,0.)
        CALL HBOOK2(202,'CCM ADC sector/PMT',36,.5,36.5,6,.5,6.5,0.)
      ENDIF
c
c  always changed back to top directory
c
      CALL HLDIR('//PAWC/CCM','T')
      CALL HCDIR('//PAWC',' ')
c
      RETURN
      END
c
c------------------------------------------------------------------------------
