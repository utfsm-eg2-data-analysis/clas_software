      SUBROUTINE CCM_HRBF
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_hrbf.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for subroutine CCM_HRBF
c
c  Purpose: Filling CC_HRB common block from CCH  - bank
c  --------
c
c  Input Parameters:  (Name - Type - Meaning)
c  ----------------
c
c  Output Parameters:  (Name - Type - Meaning)
c  -----------------
c
c  Other routines:
c  ---------------
c
c  Notes:
c  ------
c
c  Author:  Mikhail Kossov    Created:  Mon May  12 13:23:13 EDT 1997
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
c BOS common block  uncomment the next line for BOS include file
#include "bcs.inc"
#include "ccm_hrb.inc"
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
      PARAMETER (CFILE = '$RCSfile: ccm_hrbf.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.1.1.1 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 1997/08/16 23:05:05 $')
      PARAMETER (CAUTHO = '$Author: kossov $')
      DATA CRCSID/   
     1'$Id: ccm_hrbf.F,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='ccm_hrbf')
      PARAMETER (CRAUTH='Mikhail Kossov')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE,IFIRST,NCOL,NROW
      INTEGER ind, kword, i, k, name_i
      integer NAMIND
c_end_var
      data IFIRST /0/
c
c
 900  FORMAT(A10,I10)
c
c  executable code for routine CCM_HRBF:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='First call'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
c
c-----------------------------------------------------------------------
c
      IF (IFIRST.EQ.0) THEN
        name_i = NAMIND('CCH1')
        IF (name_i.EQ.0) THEN
          CRMESS='No CCH1 BOS bank registered'
          CALL RECMES(CRNAME,'I',CRMESS)
          RETURN
        ENDIF
        IFIRST = 1
      ENDIF
      ind = iw(name_i) ! the first pointer to the bank
c
      jhtrk = 0  ! track counter
c
    1 CONTINUE   ! Cycle on "hits" in CCH1
c
      IF (ind.NE.0) THEN
c
        kword = iw(ind)     ! a total number of words
        NCOL  = iw(ind - 5) ! a#of columns
        NROW  = iw(ind - 4) ! a#of rows (tracks)
c
        DO i = 1,NROW
c
          k = ind + NCOL*(i-1)
c
          IF (i .GT. mhtrk) GOTO 20  ! too many tracks ????? M.K.
c
          jhtrk = jhtrk + 1 
          itrk_num(jhtrk) = iw(k + 1) ! track #
          idh_prt (jhtrk) = iw(k + 2) ! particle ID
          ihitrk  (jhtrk) = iw(k + 3) ! ????
          itrsect (jhtrk) = iw(k + 4) ! sector # for entry
          itrsegm (jhtrk) = iw(k + 5) ! segment # for entry
          ph_tot  (jhtrk) = rw(k + 6) ! a#of photons
          CALL UCOPY(rw(k + 7),xenter(1,jhtrk),3) ! enter coordinates
          CALL UCOPY(rw(k +10),xexit (1,jhtrk),3) ! exit coordinates
c
        ENDDO
c
      ELSE
        IFIRST = 0
        go to 30
c
      ENDIF
      ind = iw(ind-1)
      GOTO 1
c
   20 CONTINUE
c     ========> too many simulated tracks in CC
c
      WRITE(CRMESS,25) NROW,mhtrk,NCOL
   25 FORMAT('DCM/CC: Too many tracks in CC',I3,'>',I3,', NCOL=',I3)
      CALL RECMES(CRNAME,'I',CRMESS)
c
   30 CONTINUE
c     ========> CCH2 bank
c
      IF (IFIRST.eq.0) THEN
        name_i = NAMIND('CCH2')
        IF (name_i.eq.0) then
          CRMESS='DCM/CC: No CCH2 BOS bank registered'
          CALL RECMES(CRNAME,'I',CRMESS)
          RETURN
        ENDIF
        IFIRST = 1
      ENDIF
      ind = iw(name_i)
      icchit = 0 ! hit counter
c
    2 CONTINUE   ! Cycle on "hits" in CCH2
c
      IF (ind.NE.0) THEN
c
        kword = iw(ind)     ! a total #of words
        NCOL  = iw(ind - 5) ! a#of columns
        NROW  = iw(ind - 4) ! a#of rows (hits)
c
        DO i = 1,NROW
c
          k = ind + NCOL*(i-1)
c
          IF (i .GT. mcchit) GOTO 40  ! too many hits in CC
c
          icchit = icchit + 1         ! increment a hit counter
          itrnum (icchit) = iw(k + 1) ! track #
          iccsect(icchit) = iw(k + 2) ! sector #
          iccsegm(icchit) = iw(k + 3) ! segment #
          icctdc (icchit) = iw(k + 4) ! TDC value
c
        ENDDO
c
      ELSE
        IFIRST = 0
        GOTO 100
c
      ENDIF
      ind = iw(ind-1)
      GOTO 2
c
c ==========================================================
c
   40 CONTINUE
c     ========> too many hits in CC
c
      WRITE(CRMESS,50) NROW,mcchit,NCOL
   50 FORMAT('DCM/CC: Too many hits in CC',I3,'>',I3,', NCOL=',I3)
      CALL RECMES(CRNAME,'I',CRMESS)
c
  100 CONTINUE
c     ========> some other actions
c
      RETURN
      END




