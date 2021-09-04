      SUBROUTINE BRWG(CEN, FWID, XMIN, XMAX, RANP,MASS)
*
C   Generate exact Breit Wigner distribution with Mean=CEN, FWHM=FWID
C   between the limits XMIN, XMAX. RANP - random number...
C
      IMPLICIT NONE
      REAL CEN, FWID, XMIN, XMAX
      REAL RANP,MASS
C     Local variables
      REAL YMIN, YMAX
C
      IF(FWID .EQ. 0) THEN
        MASS = XMIN
      ELSE
        YMIN = ATAN(2.*(XMIN-CEN)/FWID)
        YMAX = ATAN(2.*(XMAX-CEN)/FWID)
        MASS = CEN + FWID/2. * TAN(RANP*(YMAX-YMIN)+YMIN)
      ENDIF
C     Only exit point
      RETURN
      END
