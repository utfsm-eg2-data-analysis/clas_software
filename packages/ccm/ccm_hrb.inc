c      include file CCM_HRB
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_hrb.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file CCM_HRB
c
c  Purpose:  Stored information fron CCH banks
c  --------
c
c  Used in routines:
c  ----------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov    Created:  Mon May 12 13:15:54 EDT 1997
c  -------
c
c  Major revisions:
c  ----------------
c
c_end_doc
c
c_begin_var
c  variables for include file CC_HRB:
c  -----------------------------------
c  RCS information: 
      CHARACTER*(132)  CICC_HRB
      DATA CICC_HRB/
     1'$Id: ccm_hrb.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c----6----------------------------------------------------------------72
c  
c  Variables contained in CCM_HRB common block
c  --------------------------------------------
c
      integer mhtrk,   ! Max number of tracks
     &        jhtrk,   ! Number of tracks in the event
     &     itrk_num,   ! # track in the event (1000*istak + itrack ) 
     &      idh_prt,   ! Particle ID
     &      ihitrk,    ! Number of photoelectrons produced by track
     &      itrsect,   ! Sector #
     &      itrsegm    ! Segment #
c
      real xenter,     ! Track entering point coordinates in Sector system
     &      xexit,     ! Track exit point coordinates in Sector system
     &     ph_tot      ! Particle momentum

      parameter ( mhtrk  = 50)       !  Number of tracks

      integer  mcchit, ! Max number of hits
     &       mbos_cch  ! Max size of the buffer for BOS - output 
      parameter ( mcchit = 400)      !  Number of hits
      parameter (mbos_cch = 5000 )   !  Max number of words in hits
c ======================================================================
c
      integer icchit,  ! Number of hits in event
     &        itrnum,  ! Number if track for this hit
     &       iccsect,  ! Sector #
     &       iccsegm,  ! Segment #
     &        icctdc   ! ITDC
c
      integer jhit_cc
      real  xhit_cc(mbos_cch)
      equivalence(xhit_cc,jhit_cc)
c
      common /CCHIT1/ jhtrk, itrk_num(mhtrk), idh_prt(mhtrk),
     &                ihitrk(mhtrk), itrsect(mhtrk), itrsegm(mhtrk),
     &                ph_tot(mhtrk), xenter(3,mhtrk), xexit(3,mhtrk)
      common /CCHIT2/ icchit, itrnum(mcchit), iccsect(mcchit),
     &                iccsegm(mcchit), icctdc(mcchit)
c
      common /CCJHIT/jhit_cc(mbos_cch)
c
