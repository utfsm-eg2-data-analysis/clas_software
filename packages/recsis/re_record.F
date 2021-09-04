      SUBROUTINE RE_RECORD(NRECIN)
      IMPLICIT NONE
#include "run_control.inc"
#include "clasmdl.inc"
#include "bnkfmt.inc"
#include "bcs.inc"         
#include "wcs.inc"         
#include "bcsparm.inc"     
      INTEGER NRECIN
      INTEGER LENOCC

      SAVE

      call recpu(evtclas)

      CALL RECNTRL

      IF (ENDRUN)  CALL RENDRN
      IF (BEGJOB)  THEN
         CALL REBGJB
         CALL FPACK_MESS
         BEGJOB = .FALSE.
      ENDIF
      IF (BEGRUN)  THEN
         CALL FPACK_MESS
         CALL REBGRN
         CALL FPACK_MESS
         LEOF = .FALSE.
      ENDIF
      IF (REVENT)  CALL RECEVT
      IF (LSCALER) CALL REC_SCALER
      IF (LEPICS)  CALL REC_EPICS
      IF (OTHDAT)  CALL REOTHA
      
c     
c     clean up at the end of the event.
c     
         CALL BDROP(IW,'E')
         CALL BDROP(IW,'R')
         CALL BGARB(IW)
cfk      END IF
      RETURN
      END
c-------------------------------------
