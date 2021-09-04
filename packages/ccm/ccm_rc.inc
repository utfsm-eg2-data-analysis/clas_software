c      include file CCM_RC
c
c_begin_doc
c  RCS ID string
c  $Id: ccm_rc.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $
c
c  Documentation for include file CCM_RC as CC_RC (A.V.)
c
c  Purpose:
c  --------
c
c  Used in routines:
c  ----------------
c
c  Notes:
c  ------
c
c  Author:   Mikhail Kossov    Created:  Mon May 12 11:23:44 EDT 1997
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
c  variables for include file CCM_RC:
c  ----------------------------------
c  RCS information: 
      CHARACTER*(132)  CICCM_RC
      DATA CICCM_RC/
     1'$Id: ccm_rc.inc,v 1.1.1.1 1997/08/16 23:05:05 kossov Exp $'/
c----6----------------------------------------------------------------72
c  
c  Variables contained in CCM_RC common block
c  --------------------------------------------
c
      INTEGER maxcrec
      PARAMETER( maxcrec = 20)
      INTEGER nrclust,    ! Number of separated hits in CC
c         For every cluster in the sector
c         ===============================
     *        nrsegm,     ! 10 * Mean segment #
     *      nrsegm_p,     ! 10 * Max segment # in the cluster
     *      nrsegm_m,     ! 10 * Min segment # in the cluster
     *         nrphe,     ! Sum of photoelectrons obtained
     *        nrtime,     ! TOF from the target in channels (50 ps/chan)
     *        nrthet,     ! Estimated angle Theta in degrees
     *       nrdthet,     ! Estimated error of angle Theta in degrees
     *         nrphy,     ! -1 if Phy < 0 ; 1 if Phy > 0 ; 0 if Phy ~ 0 
     *         nriec,     ! Estimated i-coordinate in EC 
     *        nrdiec,     ! Estimated error of i-coordinate in EC 
     *         nrxec,     ! Estimated x-coordinate in EC 
     *        nrdxec,     ! Estimated error of x-coordinate in EC 
     *        nrstat      ! Status word (yet unclear) 
c
      INTEGER   isgmdiff
      PARAMETER (isgmdiff=40)    !   Parameter of the cluster-size
c_end_var
c
       COMMON /CCM_RC/ nrclust,  nrsegm(maxcrec),
     *       nrsegm_p(maxcrec), nrsegm_m(maxcrec),   nrphe(maxcrec),
     *         nrtime(maxcrec),   nrthet(maxcrec), nrdthet(maxcrec),
     *          nrphy(maxcrec),    nriec(maxcrec),  nrdiec(maxcrec),
     *          nrxec(maxcrec),   nrdxec(maxcrec),  nrstat(maxcrec)     
      SAVE /CCM_RC/
c----6----------------------------------------------------------------72




