C **********************************************************************


      SUBROUTINE MONTECARLO

C+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
C                                                           
C FUNCTIONAL DESCRIPTION:                                         
C                                                            
C Selects a proper energy  of gamma to make an hadron interaction,
C if electromagnetic event is ordered, do nothing.
C               
C MODIFICATION DATE:
C 
C     12.05.95       by Igor Pshenichnov
C
C  ********** BY MARCO MIRAZITA
C     23.04.99
C --> Aggiunto il caso (IBEAM=3) di uno spettro di energia dei fotoni
C     uniforme tra ETAG-FWHM e ETAG+FWHM. Per il caso dello spettro di 
C     bremstrahhlung con IBEAM=2, l'energia e' estratta tra ETAG-FWHM
C     e ETAG anziche' tra 0.151 GeV e ETAG.
C
C                                           
C COMMON BLOCKS:                                               
C                                                             
C     /FLAG_GEN/
C     /FLAG_COMP/
C     /MONTECARL/                                            
C-----------------------------------------------------------------------
      INTEGER IBEAM,IELET,NCHAIN,ICHAIN(40),ICIBLE,IPOL,ILAM
      REAL ETAG,FWHM
      COMMON/FLAG_COMP/IELET,IBEAM,ICIBLE,ETAG,FWHM,NCHAIN,ICHAIN,IPOL,
     &   ILAM
      REAL EGAM,P(4,11),VERTX(3)
      INTEGER I(11),NPART
      COMMON/MONTECARL/ EGAM,I,NPART,P,VERTX
      INTEGER ITARG,IIDH
      CHARACTER*12 TARGET,TARGFERMI
      REAL SP(60)
      COMMON/CBC/SP
      COMMON /TARGET/ ITARG,IIDH,TARGET,TARGFERMI


      real vran(1)

c      print *,'montecarlo'

      IF (IBEAM.EQ.0) THEN
C ***    Select the energy of tagged gamma quanta in accordance with
C ***    average energy and width
         call ranmar(vran,1)
         EGAM = (ETAG + .425*FWHM*vran(1))
      ELSEIF (IBEAM.EQ.1) THEN
C ***    Select the energy of gamma quanta in accordance with CBC 
C ***    spectrum.
         EGAM = HRNDM1(610) ! From cambridge bubble chamber experiment    
      ELSEIF (IBEAM.EQ.2) THEN
C ***    Select the energy of gamma quanta in accordance with bremsstrahlung
C ***    spectra. In this case ETAG is the maximum energy and (ETAG-FWHM) is
C ***    the minimum energy of such a spectrum.
                         ! PURE BREMSSTRAHLUNG  ....
         Emin=ETAG-FWHM
         Emax=ETAG+FWHM
         call ranmar(vran,1)
         EGAM = Emin*(Emax/Emin)**vran(1)

      elseif (ibeam.eq.3) then
C ***   Select the energy of gamma quanta in accordance with uniform spectrum
C ***   between ETAG-FWHM and ETAG+FWHM
         call ranmar(vran,1)
         egam=etag+fwhm*(2.*vran(1)-1.)

      ENDIF

      IF (IELET.EQ.0) THEN
          CALL EV_NUC
          CALL CHECK_CL
      ELSE
        NPART  = 1
        P(1,1) = 0.
        P(2,1) = 0.
        P(3,1) = EGAM
        I(1)   = 1
      ENDIF

      RETURN
      END

C ****************************************************************

	SUBROUTINE CHECK_CL
C
C
C FUNCTIONAL DESCRIPTION:
C 
C     Check energy-momentum conservation for an event presented
C     in P array. Nucleon(s) momentum (momenta) presented in PN array.
C     If the difference is out of tolerance, NERR=NERR+1.
C 
C CREATION DATE: 
C 
C     22.05.95       by Igor Pshenichnov
C 
C COMMON BLOCKS:
C  
C     /FLAG_GEN/
C     /MONTECARL/
C     /LOGEG/
C    
C *** E' solo per lo stato iniziale, compreso il moto di Fermi ?
C
      INTEGER NERR,LOOPV,NCASEG,LOOPC,NPROC
      COMMON /FLAG_GEN/ NERR,LOOPV,NCASEG,LOOPC,NPROC
      REAL EGAM,P(4,11),VERTX(3)
      INTEGER I(11),NPART
      COMMON/MONTECARL/ EGAM,I,NPART,P,VERTX
      REAL PN(5,3),DELTA(4)
      COMMON /MOM_NUCLEON/PN
      LOGICAL EG,CMSF
      COMMON/LOGEG/EG,CMSF

c      print *,'CHECK_CL'

      TOL=1.E-04 ! 0.1 MeV accuracy
 
      IF(NPART.EQ.1) RETURN     ! If there is no hadron interaction,
                            ! nothing to check there.

      IF (CMSF) THEN
         DELTA(1)=0.
         DELTA(2)=0.
         DELTA(3)=0.
         RMN = PN(4,1)
         DELTA(4)= -SQRT(RMN*RMN + 2.*RMN*EGAM)
      ELSE
         DELTA(1)=PN(1,2)+PN(1,3)
         DELTA(2)=PN(2,2)+PN(2,3)
         DELTA(3)=-EGAM-PN(3,1)
         DELTA(4)=-EGAM-PN(4,1)
      ENDIF

      DO J=1,NPART
         PSQR=0.0
         DO IL=1,3
            DELTA(IL)=DELTA(IL)+P(IL,J)
            PSQR=PSQR+P(IL,J)**2 
         ENDDO
         DELTA(4)=DELTA(4)+SQRT(PSQR+P(4,J)**2)
      ENDDO

      IF (ABS(DELTA(1)).GT.TOL.OR.ABS(DELTA(2)).GT.TOL.OR.
     &     ABS(DELTA(3)).GT.TOL.OR.ABS(DELTA(4)).GT.TOL) THEN
         NERR = NERR+1
      ENDIF


      RETURN
      END

C***********************************************************************




C***********************************************************************

      SUBROUTINE GEN_EVT(W_S,LEV,JCH)

C+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
C                                                            
C FUNCTIONAL DESCRIPTION:                                            
C                                                            
C    This subroutine extracts c.m. direction of final state particles,
C    accounting of differential cross sections.
C                                                             
C MODIFICATION DATE:
C 
C     12.05.95       by Igor Pshenichnov
C
C                                           
C 
C COMMON BLOCKS:                                               
C                                                                 
C     /SIGMA/
C     /FLAG_COMP/
C     /MASSES/
C     /GENIN/
C     /GENOUT/
C                                                              
C-----------------------------------------------------------------------

      IMPLICIT NONE
      REAL XSECT(40,50,0:18)
      COMMON /SIGMA/ XSECT,I
      REAL P,SIGM,T,CX,CZ,OX,OZ,PGC,PGR,APH
      INTEGER IBEAM,IELET,NCHAIN,ICHAIN(40),ICIBLE,IPOL,ILAM
      REAL ETAG,FWHM
      COMMON/FLAG_COMP/IELET,IBEAM,ICIBLE,ETAG,FWHM,NCHAIN,ICHAIN,IPOL,
     &     ILAM
      REAL RNDM,ARGUMENT
      DOUBLE PRECISION PI,TWOPI,PIBY2,DEGRAD,RADDEG
*
      PARAMETER (PI=3.14159265358979324D0)
      PARAMETER (TWOPI=6.28318530717958648D0)
      PARAMETER (PIBY2=1.57079632679489662D0)
      PARAMETER (DEGRAD=0.0174532925199432958D0)
      PARAMETER (RADDEG=57.2957795130823209D0)
*
      COMMON/IMPUL/P4_CDM(3),P3_CDM(3),PHII
      COMMON/POL/P,SIGM,T,CX,CZ,OX,OZ,PGC,PGR,APH
      REAL RMB1,RMB2,RMME,DELTAMASS,DIBMASS,DEUMASS,RHOMASS
      COMMON/MASSES/RMB1,RMB2,RMME,DELTAMASS,DIBMASS,DEUMASS,RHOMASS
      INTEGER NP,KGENEV
      REAL ECM,AMASS,PCM,WT
      COMMON/GENIN/NP,ECM,AMASS(18),KGENEV
      COMMON/GENOUT/PCM(5,18),WT

      REAL SIGRIF(0:18),SIGMODEL(0:18),PROB(0:18),
     &     W_I,W_F,DW,W,W_S,
     &     DTHETA,SIGRIFTOT,WR(2),TET(0:18),SR(2),PHII,THETA_M,PHI_M,
     &     TETA,ETOT_M,P_M,U1,U2,U3,YRNDM,P4_CDM,P3_CDM,RNDB(2)
      INTEGER J,LEV,I,JCH,K
      REAL ALI
      real cosdd

      integer jm,jk
      real vran(1)

c      print *,' '
c      print *,'  GEN_EVT'

      DTHETA = 10.
      SIGRIF(0) = 0.
      SIGMODEL(0) = 0.
      PROB(0) = 0.
      DO J=0,18
         TET(J) = J*DTHETA
      END DO
      IF (LEV.GT.1) GO TO 10
      W_I = 1.
      W_F = 3.5
      DW = 0.050
      W = W_S
      SIGRIFTOT = 0.


C ***********************************************
C *** Select CM angle
C ***********************************************

      DO I=1,50
         IF (W.GE.(W_I+DW*I).AND.W.LT.(W_I+DW*(I+1))) GOTO 1
      END DO
 1    CONTINUE

c      write (15,*)'W=',w
c      write (15,*) 'bin in W estratto',i
C ***************************************
C *** Correzione: I non puo' superare 50
      if (I.gt.50) I=50
c      write (15,*) 'bin in W corretto',i
C ***************************************

c      print *,'ilam=',ilam
      IF (ILAM.EQ.0) THEN
         WR(1) = W_I+DW*I
         WR(2) = W_I+DW*(I+1)
c         write (15,*) '*** WR=',wr(1),wr(2)
         SR(1) = XSECT(JCH,I,0)

C ***************************************
C *** Correzione: I non puo' superare 50
         if (I.lt.50) then
            SR(2) = XSECT(JCH,I+1,0)
         else
            SR(2) = XSECT(JCH,50,0)
         endif
C ***************************************

c         write (15,*) 'J=0 - sigma(teta)=',sr(1),sr(2)
         SIGMODEL(0) = ALI(W,WR,SR,2) 

         DO J=1,18
            SR(1) = XSECT(JCH,I,J)

C ***************************************
C *** Correzione: I non puo' superare 50
            if (I.lt.50) then
               SR(2) = XSECT(JCH,I+1,J)
            else
               SR(2) = XSECT(JCH,50,J)
            endif
C ***************************************

c            write (15,*) 'J=',j,' - sigma(teta)=',sr(1),sr(2)
            SIGMODEL(J) = ALI(W,WR,SR,2) 
            SIGRIF(J) = ((SIGMODEL(J)+SIGMODEL(J-1))/2.)
     &           *(COSDD(TET(J-1))-COSDD(TET(J)))
            SIGRIFTOT = SIGRIFTOT + SIGRIF(J)
         END DO

c         write (15,*) 'sigma mod.=',sigmodel
c         write (15,*) 'sigma rif.=',sigrif
c         write (15,*) 'SIGRIFTOT=',SIGRIFTOT

         PROB(0) = 0.
         DO J=1,18
            SIGRIF(J) = SIGRIF(J)/SIGRIFTOT
            PROB(J) = PROB(J-1)+SIGRIF(J)
         END DO

c         write (15,*) 'prob=',prob

c         TETA=ALI(RNDM(-1),PROB,TET,19)
         call ranmar(vran,1)
         TETA=ALI(vran(1),PROB,TET,19)

c         write (15,*) 'teta=',teta

      ELSE
         CALL SECPOL
         CALL HRNDM2(105,TETA,PHII)
         CALL HRESET(105,' ')
      ENDIF


      THETA_M = TETA*DEGRAD
c      print *,'gen_evt:teta(cm)=',teta

C *** Estrazione uniforme di fi
c      PHII = TWOPI*RNDM(-1)
      call ranmar(vran,1)
      PHII = TWOPI*vran(1)
      PHI_M = PHII + APH
c      print *,'gen_evt:fi(cm)=',phi_m*180./pi

C *********************************************
C *** Final state kinematics
C *********************************************
c      print *,'gen_ev:M(mes)=',rmme
c      print *,'gen_ev:M(bar)=',rmb2

      ETOT_M = (W_S**2+RMME**2-RMB2**2)/(2*W_S)
      ARGUMENT = ETOT_M**2-RMME**2
      IF (ARGUMENT.GT.0.0) THEN
         P_M=SQRT(ARGUMENT)
      ELSE
         P_M=0.0
      ENDIF
c      print *,'gen_ev: P(cm)=',p_m


      U1=SIN(THETA_M)*COS(PHI_M)
      U2=SIN(THETA_M)*SIN(PHI_M)
      U3=COS(THETA_M)
c      print *,'gen_ev:cx=',u1
c      print *,'gen_ev:cy=',u2
c      print *,'gen_ev:cz=',u3

C *** Mesone prodotto
      PCM(1,1)=P_M*U1
      PCM(2,1)=P_M*U2
      PCM(3,1)=P_M*U3
      PCM(4,1)=ETOT_M
      PCM(5,1)=P_M
c      write (*,15) (pcm(k,1),k=1,5)
 15   format (1x,'Mes.',5(1x,f8.5))

C *** Barione diffuso
      PCM(1,2)=-PCM(1,1)
      PCM(2,2)=-PCM(2,1)
      PCM(3,2)=-PCM(3,1)
      PCM(4,2)=W_S-ETOT_M
      PCM(5,2)=P_M
c      write (*,16) (pcm(k,2),k=1,5)
 16   format (1x,'Bar.',5(1x,f8.5))

C ***
      P4_CDM(1) = PCM(1,1)
      P4_CDM(2) = PCM(2,1)
      P4_CDM(3) = PCM(3,1)
      P3_CDM(1) = PCM(1,2)
      P3_CDM(2) = PCM(2,2)
      P3_CDM(3) = PCM(3,2)

c      do jk=1,2
c         print *,'**Gen_evt: PCM=',(pcm(jm,jk),jm=1,5)
c      enddo

10      RETURN
      END                                               !*** END GEN_EVT

C***********************************************************************

CDECK  ID>, SECPOL. 
C******************************************************************
      SUBROUTINE SECPOL
C ***     creation of a 2-dim-histo sigma(theta,phi) for lambda polar.
      INTEGER IBEAM,IELET,NCHAIN,ICHAIN(40),ICIBLE,IPOL,ILAM
      REAL ETAG,FWHM
      COMMON/FLAG_COMP/IELET,IBEAM,ICIBLE,ETAG,FWHM,NCHAIN,ICHAIN,IPOL,
     &   ILAM
      REAL EGAM, P(4,11),VERTX(3)
      INTEGER I(11),NPART
      COMMON/MONTECARL/ EGAM,I,NPART,P,VERTX
      COMMON/POL/PP,SIGM,T,CX,CZ,OX,OZ,PGC,PGR,APH
      COMMON /SIGMA/ XSECT(40,50,0:18),IE
      DATA EMAX/1.505/

      print *,'SECPOL'

      IF (IPOL.GT.0.AND.IPOL.LE.4) THEN
!        PGR = HX(200,EGAM/EMAX)
      ELSE IF (IPOL.EQ.6) THEN
!        PGC = -HX(200,EGAM/EMAX)
      ELSE
!        PGC = HX(200,EGAM/EMAX)
      ENDIF

      CNPHI = -3.1415/60.
      DO  J = 1,60
         CNR   = -5.
         CNPHI = CNPHI + 6.2831/60.
         DO IF = 1,18
            CNR = CNR + 10.
            CFF = XSECT(29,IE,IF)*(1.-SIGM*PGR*COS(2.*CNPHI))
            CALL HF2(105,CNR,CNPHI,CFF)
         ENDDO
      ENDDO

      RETURN
      END



C***********************************************************************

      REAL FUNCTION RMASS(P)

C+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
C                                                            
C FUNCTIONAL DESCRIPTION:                                         
C                                                            
C    Put a mass of particle as it was adopted by INC code, including
C    some resonances
C                                                            
C MODIFICATION DATE 
C
C     20.05.95       by Igor Pshenichnov
C                                                           
C                                                            
C FUNCTION VALUE:                                               
C                                                            
C    RMASS   (GeV)                                                  
C                                                            
C code was modified to generate BW mass distribution for Delta particles
C Avto Tkabladze, 11/10/05
C
C-----------------------------------------------------------------------

      IMPLICIT NONE
      CHARACTER*12 P
      REAL Q,AMAS,AMREZ   
      REAL VRAN(1)                       !  added by Avto Tkabladze
      REAL DMASS,FWID,MMIN,MMAX,MASS    !  added by Avto Tkabladze

      CALL NORRAN(Q)
C additions for Delta BW distribution
      CALL RANMAR(vran,1)
      DMASS = 1.235                     ! Delta PDG mass
      FWID  = 0.115                     ! Delta width
      MMIN  = 1.08                      ! minimum mass for Delta
      MMAX  = 1.45                      ! Maximum mass for Delta

      CALL BRWG(DMASS, FWID, MMIN, MMAX, VRAN(1),MASS)
C
      RMASS = -1.
      IF(P.EQ.'gamma')  THEN      
                     RMASS = 0.0
      ELSEIF(P.EQ.'neutrino')  THEN   
                     RMASS = 0.0
      ELSEIF(P.EQ.'nulla')  THEN      
                     RMASS = 0.0
      ELSEIF(P.EQ.'electron')  THEN   
                     RMASS = 0.511E-03
      ELSEIF(P.EQ.'positron')  THEN   
                     RMASS = 0.511E-03
      ELSEIF(P.EQ.'mu+')  THEN        
                     RMASS = 0.10566
      ELSEIF(P.EQ.'mu-')  THEN        
                     RMASS = 0.10566
      ELSEIF(P.EQ.'proton')  THEN     
                     RMASS = AMAS(37)
      ELSEIF(P.EQ.'neutron')  THEN      
                     RMASS = AMAS(38)
      ELSEIF(P.EQ.'lambda')  THEN     
                     RMASS = 1.116
      ELSEIF(P.EQ.'sigma+')  THEN     
                     RMASS = 1.189
      ELSEIF(P.EQ.'sigma0')  THEN     
                     RMASS = 1.192
      ELSEIF(P.EQ.'sigma-')  THEN     
                     RMASS = 1.197
      ELSEIF(P.EQ.'csi0')  THEN       
                     RMASS = 1.3149
      ELSEIF(P.EQ.'csi-')  THEN       
                     RMASS = 1.3213
      ELSEIF(P.EQ.'dibaryon')  THEN   
                     RMASS =
     +  2.23 + Q*0.0165/2.355
C      ELSEIF(P.EQ.'delta++')  THEN    
C                     RMASS =
C     +      AMAX1(1.08,(1.235 + Q*0.115/2.355))
C      ELSEIF(P.EQ.'delta+')  THEN     
C                     RMASS =
C     +      AMAX1(1.08,(1.235 + Q*0.115/2.355))
C      ELSEIF(P.EQ.'delta0')  THEN     
C                     RMASS =
C     +      AMAX1(1.08,(1.235 + Q*0.115/2.355))
C      ELSEIF(P.EQ.'delta-')  THEN     
C                     RMASS =
C     +      AMAX1(1.08,(1.235 + Q*0.115/2.355))
C
      ELSEIF(P.EQ.'delta++')  THEN    
                     RMASS = MASS
      ELSEIF(P.EQ.'delta+')  THEN     
                     RMASS = MASS
      ELSEIF(P.EQ.'delta0')  THEN     
                     RMASS = MASS
      ELSEIF(P.EQ.'delta-')  THEN     
                     RMASS = MASS
C
      ELSEIF(P.EQ.'sigma+3/2')  THEN  
                     RMASS = 1.382
      ELSEIF(P.EQ.'sigma03/2')  THEN  
                     RMASS = 1.387
      ELSEIF(P.EQ.'sigma-3/2')  THEN  
                     RMASS = 1.382
      ELSEIF(P.EQ.'csi03/2')  THEN    
                     RMASS = 1.532
      ELSEIF(P.EQ.'csi-3/2')  THEN    
                     RMASS = 1.535
      ELSEIF(P.EQ.'omega-')  THEN     
                     RMASS = 1.67245
      ELSEIF(P.EQ.'omega')  THEN      
                     RMASS = AMREZ(17)
      ELSEIF(P.EQ.'pi+')  THEN        
                     RMASS = AMAS(1)
      ELSEIF(P.EQ.'pi0')  THEN        
                     RMASS = AMAS(7)
      ELSEIF(P.EQ.'pi-')  THEN        
                     RMASS = AMAS(2)
      ELSEIF(P.EQ.'kappa+')  THEN     
                     RMASS = 0.49367
      ELSEIF(P.EQ.'kappa0')  THEN     
                     RMASS = 0.49772
      ELSEIF(P.EQ.'kappa-')  THEN     
                     RMASS = 0.49367
      ELSEIF(P.EQ.'kappas')  THEN     
                     RMASS = 0.49772
      ELSEIF(P.EQ.'kappal')  THEN     
                     RMASS = 0.49772
      ELSEIF(P.EQ.'akappa0')  THEN    
                     RMASS = 0.49772
      ELSEIF(P.EQ.'eta')  THEN        
                     RMASS = AMAS(8)
      ELSEIF(P.EQ.'etap')  THEN       
                     RMASS = 0.95747
      ELSEIF(P.EQ.'rho+')  THEN       
                     RMASS = AMREZ(10)
      ELSEIF(P.EQ.'rho0')  THEN       
                     RMASS = AMREZ(16)
      ELSEIF(P.EQ.'rho-')  THEN       
                     RMASS = AMREZ(11)
      ELSEIF(P.EQ.'phi')  THEN        
                     RMASS = 1.020
      ELSEIF(P.EQ.'deuteron')  THEN   
                     RMASS = 1.8755
      ELSEIF(P.EQ.'deutheavy')  THEN  
                     RMASS = 1.878
      ELSEIF(P.EQ.'H3')  THEN         
                     RMASS = 2.80875
      ELSEIF(P.EQ.'He3')  THEN        
                     RMASS = 2.80822
      ELSEIF(P.EQ.'He4')  THEN        
                     RMASS = 3.72715
      ENDIF

      RETURN
      END                                                 !*** END RMASS



C***********************************************************************

      INTEGER FUNCTION CODE(P)

C+++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
C                                                     
C FUNCTIONAL DESCRIPTION:                                         
C                                                           
C    Particle numbering according to old table (used by INC) or to GEANT 
C
C MODIFICATION DATE 
C
C     21.05.95       by Igor Pshenichnov
C                                                           
C FUNCTION VALUE:                                           
C                                                           
C    CODE                                                    
C
C COMMON BLOCK:
C 
C    LOGEG   -  select a proper mood for numbering
C                                                         
C----------------------------------------------------------------------- 

      IMPLICIT NONE
      CHARACTER*12 P
      LOGICAL EG,CMSF
      COMMON/LOGEG/EG,CMSF


      CODE = 0.
                   IF(EG) THEN
      IF(P.EQ.'gamma') THEN
           CODE = 1
      ELSEIF(P.EQ.'neutrino') THEN
           CODE = 4
      ELSEIF(P.EQ.'nulla') THEN      
           CODE = 0
      ELSEIF(P.EQ.'electron') THEN   
           CODE = 3
      ELSEIF(P.EQ.'positron') THEN   
           CODE = 2
      ELSEIF(P.EQ.'mu+') THEN        
           CODE = 5
      ELSEIF(P.EQ.'mu-') THEN        
           CODE = 6
      ELSEIF(P.EQ.'proton') THEN     
           CODE = 14
      ELSEIF(P.EQ.'neutron') THEN    
           CODE = 13
      ELSEIF(P.EQ.'lambda') THEN     
           CODE = 18
      ELSEIF(P.EQ.'sigma+') THEN     
           CODE = 19
      ELSEIF(P.EQ.'sigma0') THEN     
           CODE = 20
      ELSEIF(P.EQ.'sigma-') THEN     
           CODE = 21
      ELSEIF(P.EQ.'csi0') THEN       
           CODE = 22
      ELSEIF(P.EQ.'csi-') THEN       
           CODE = 23
      ELSEIF(P.EQ.'dibaryon') THEN   
           CODE = 109
      ELSEIF(P.EQ.'delta') THEN      
           CODE = 101
      ELSEIF(P.EQ.'delta++') THEN    
           CODE = 101
      ELSEIF(P.EQ.'delta+') THEN     
           CODE = 102
      ELSEIF(P.EQ.'delta0') THEN     
           CODE = 103
      ELSEIF(P.EQ.'delta-') THEN     
           CODE = 104
      ELSEIF(P.EQ.'sigma+3/2') THEN  
           CODE = 110
      ELSEIF(P.EQ.'sigma03/2') THEN  
           CODE = 111
      ELSEIF(P.EQ.'sigma-3/2') THEN  
           CODE = 112
      ELSEIF(P.EQ.'csi03/2') THEN    
           CODE = 114
      ELSEIF(P.EQ.'csi-3/2') THEN    
           CODE = 115
      ELSEIF(P.EQ.'omega-') THEN     !Baryon
           CODE = 24
      ELSEIF(P.EQ.'omega') THEN      !Meson GSIM
           CODE = 60
      ELSEIF(P.EQ.'pi+') THEN        
           CODE = 8
      ELSEIF(P.EQ.'pi0') THEN        
           CODE = 7
      ELSEIF(P.EQ.'pi-') THEN        
           CODE = 9
      ELSEIF(P.EQ.'kappa+') THEN     
           CODE = 11
      ELSEIF(P.EQ.'kappa0') THEN     
           CODE = 211
      ELSEIF(P.EQ.'kappa-') THEN     
           CODE = 12
      ELSEIF(P.EQ.'kappas') THEN     
           CODE = 16
      ELSEIF(P.EQ.'kappal') THEN     
           CODE = 10
      ELSEIF(P.EQ.'akappa0') THEN    
           CODE = 210
      ELSEIF(P.EQ.'eta') THEN        
           CODE = 17
      ELSEIF(P.EQ.'etap') THEN       ! GSIM
           CODE = 61
      ELSEIF(P.EQ.'rho+') THEN       ! GSIM
           CODE = 58
      ELSEIF(P.EQ.'rho0') THEN       ! GSIM
           CODE = 57
      ELSEIF(P.EQ.'rho-') THEN       ! GSIM
           CODE = 59
      ELSEIF(P.EQ.'phi') THEN        
           CODE = 117
      ELSEIF(P.EQ.'deuteron') THEN   
           CODE = 45
      ELSEIF(P.EQ.'deutheavy') THEN  
           CODE = 245
      ELSEIF(P.EQ.'H3') THEN         
           CODE = 46
      ELSEIF(P.EQ.'He3') THEN        
           CODE = 49
      ELSEIF(P.EQ.'He4') THEN        
           CODE = 47
      ENDIF
                   ELSE
      IF(P.EQ.'gamma') THEN      
           CODE = 55
      ELSEIF(P.EQ.'proton') THEN     
           CODE = 37
      ELSEIF(P.EQ.'neutron') THEN    
           CODE = 38
      ELSEIF(P.EQ.'omega') THEN      
           CODE = 17
      ELSEIF(P.EQ.'pi+') THEN        
           CODE = 1
      ELSEIF(P.EQ.'pi0') THEN        
           CODE = 7
      ELSEIF(P.EQ.'pi-') THEN        
           CODE = 2
      ELSEIF(P.EQ.'eta') THEN        
           CODE = 8
      ELSEIF(P.EQ.'rho+') THEN       
           CODE = 10
      ELSEIF(P.EQ.'rho0') THEN       
           CODE = 16
      ELSEIF(P.EQ.'rho-') THEN       
           CODE = 11
      ELSEIF(P.EQ.'kappa+') THEN     
           CODE = 3
      ELSEIF(P.EQ.'kappa0') THEN     
           CODE = 5
      ELSEIF(P.EQ.'kappa-') THEN     
           CODE = 4
      ELSEIF(P.EQ.'akappa0') THEN    
           CODE = 6
      ELSEIF(P.EQ.'phi') THEN        
           CODE = 18
      ENDIF
                   ENDIF
      RETURN
      END                                                  !*** END CODE
C *********************************************

C *********************************************
C *** Trigonometric functions for angle in degrees
C *********************************************

      real function acosdd(x)
      real x,ac
      pi=acos(-1.)

      ac=acos(x)
      acosdd=ac*180./pi

      return
      end

C *********************************************      
      real function cosdd(x)
      real x,y
      pi=acos(-1.)
      y=x*pi/180.
      cosdd = cos(y)
      return
      end


