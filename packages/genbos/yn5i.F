
      SUBROUTINE ORFT0(NP,U,IPATN)
C--------------ORFRIT T0=0
      COMMON / MEMORY/PM(9,100),IM(9,100)
     */CHISLA/NPIM,NPIP,NPI0
     */PARM1/ A,CRMH,BB
     */PARMS/ SIGMA,ALPHA,TT
     */POM/ IPATI,PARTI
      DIMENSION W(30)

      real vran(1)

      DATA I1/0/
      DO 30 K=1,30
   30 W(K)=0.0
      CRMH=5.01
      IF(PARTI.GT.0.3) GO TO 100
      A=0.18
      BB=0.2
      ALPHA=1.55
  100 IF(PARTI.GT.1.5) GO TO 101
      GO TO 102
  101 A=0.4
      BB=0.27
      ALPHA=1.55
  102 CONTINUE
      NP=0
      S=U*U
      AM=0.94
      ANV=CRMH*(S/(4.*AM*AM))**BB
      I1=I1+1
      IF(I1.LT.10)PRINT 123, S,ANV,PARTI,IPATI,A,BB,ALPHA
 123  FORMAT(5X,'ORFPAR S ANV PARTI IPATI A BB ALPHA',3E13.6,I5,3E13.6)
      SIGKV=A*ANV
      SIGMA=SQRT(SIGKV)
      SIGMA=0.9
      CALL NORMCO(RA,RB,ANV,ANV,SIGMA,SIGMA,0.0)
      NP=RA
      IF(I1.LT.10) PRINT 124,NP
 124  FORMAT(5X,'ORFPAR NP',I10)
      RZ=RA-NP
      IF(RZ.GE.0.5) NP=NP+1
      APN1=FLOAT(NP)/2.
      PN1=INT(APN1)
      IFIP=IPATN+IPATI
      IF(APN1-PN1-0.001)1,1,2
    1 LMAX=NP/2
      GO TO 3
    2 LMAX=(NP-1)/2
      IF(IFIP.NE.0)LMAX=(NP+1)/2
    3 CONTINUE
      IF(IFIP.GT.0)LMAX=LMAX-1
      IF(IFIP) 12,13,12
C  FOR ANTI P -P AND ANTI N - N
   13 KMAX=LMAX+1
      B=1
      KPP=0
      DO 14 KL=1,KMAX
      J=2*(KL-1)
   14 W(KL)=PNL(ALPHA,NP,J,B)
      DO 15 M=2,30
   15 W(M)=W(M-1)+W(M)
      call ranmar(vran,1)
      BM=vran(1)*W(30)
      DO 17 M=1,30
      IF(BM-W(M))16,16,17
   16 L=M-1
      GO TO 8
   17 CONTINUE
C  FOR ANTI P - N AND ANTI N - P
   12 B=-1
      KPP=1
      IF(LMAX.LE.0)L=0
      IF(LMAX.LE.0)GO TO 8
      DO 4 L=1,LMAX
      J=2*L-KPP
    4 W(L)=PNL(ALPHA,NP,J,B)
      DO 5 K=2,30
    5 W(K)=W(K-1)+W(K)
      call ranmar(vran,1)
      BM=vran(1)*W(30)
      DO 7 K=1,30
      IF(BM-W(K))6,6,7
    6 L=K
      GO TO 8
    7 CONTINUE
    8 IF (IFIP.GT.0) KPP=-1
      NPIM= L
      NPIP=L-KPP
      NPI0=NP-L-NPIP
CCCC   ONLY FOR ANTI P-P OR ANTI N-P
C     IF(IPATN.EQ.1) CALL CHIS
      IF(I1.LT.10) PRINT 125,NPIM,NPIP,NPI0
  125 FORMAT(10X,'NPIM,NPIP,NPI0',3I10)
      NPIM1=0
      NPIP1=0
      NPI01=0
      MV=0
      MV1=MV+1
      MV2=MV+NP
      DO 20 K=MV1,MV2
      IF(NPIM-NPIM1) 21,21,22
   21 VPIM=0.
      GO TO 23
   22 VPIM=1.0
   23 IF(NPIP-NPIP1) 24,24,25
   24 VPIP=0.
      GO TO 26
   25 VPIP=1.
   26 IF(NPI0-NPI01) 27,27,28
   27 VPI0=0.
      GO TO 29
   28 VPI0=1.
   29 VPI=VPIM+VPIP+VPI0
      B1=VPIM/VPI
      B2=(VPIM+VPIP)/VPI
      call ranmar(vran,1)
      B=vran(1)
      IF(B-B1) 40,40,31
   40 IM(1,K)=-1
      NPIM1=NPIM1+1
      GO TO 20
   31 IF(B-B2) 32,32,33
   32 IM(1,K)=1
      NPIP1=NPIP1+1
      GO TO 20
   33 IM(1,K)=0
      NPI01=NPI01+1
   20 CONTINUE
      RETURN
      END


      SUBROUTINE ORFRIT(NP,U,IPATN,MV)
      COMMON / MEMORY/PM(9,100),IM(9,100)
C---------ORFRIT OUNLY TO FOR T0>0   MV IN PARAMS AND MV>0
      COMMON /CHISLA/NPIM,NPIP,NPI0
      COMMON /POM/ IPATI,PARTI
      DIMENSION W(30)

      real vran(1)

      DATA I1/0/
      DO 30 K=1,30
   30 W(K)=0.0
      CRMH=5.01
      IF(PARTI.GT.1.5) GO TO 100
      A=0.18
      BB=0.2
      ALPHA=1.55
      GO TO 102
 100  IF(PARTI.GT.1.5 )GO TO 101
      A=0.25
      BB=0.2
      ALPHA=1.89
      GO TO 102
 101  A=0.4
      BB=0.27
      ALPHA=1.89
 102  CONTINUE
      NP=0
      S=U*U
      AM=0.94
      ANV=CRMH*(S/(4.*AM*AM))**BB
      I1=I1+1
      IF(I1.LT.10)PRINT 123, S,ANV,PARTI,IPATI,A,BB,ALPHA
 123  FORMAT(5X,'ORFPAR S ANV PARTI IPATI A BB ALPHA',3E13.6,I5,3E13.6)
      SIGKV=A*ANV
      SIGMA=SQRT(SIGKV)
      CALL NORMCO(RA,RB,ANV,ANV,SIGMA,SIGMA,0.0)
      NP=RA
      IF(I1.LT.10) PRINT 124,NP
 124  FORMAT(5X,'ORFPAR NP',I10)
      RZ=RA-NP
      IF(RZ.GE.0.5) NP=NP+1
      APN1=FLOAT(NP)/2.
      PN1=INT(APN1)
      IFIP=IPATN+IPATI
      IF(APN1-PN1-0.001)1,1,2
    1 LMAX=NP/2
      GO TO 3
    2 LMAX=(NP-1)/2
      IF(IFIP.NE.0)LMAX=(NP+1)/2
    3 CONTINUE
      IF(IFIP) 12,13,12
C  FOR ANTI P -P AND ANTI N - N
   13 KMAX=LMAX+1
      B=1
      KPP=0
      DO 14 KL=1,KMAX
      J=2*(KL-1)
   14 W(KL)=PNL(ALPHA,NP,J,B)
      DO 15 M=2,30
   15 W(M)=W(M-1)+W(M)
      call ranmar(vran,1)
      BM=vran(1)*W(30)
      DO 17 M=1,30
      IF(BM-W(M))16,16,17
   16 L=M-1
      GO TO 8
   17 CONTINUE
C  FOR ANTI P - N AND ANTI N - P
   12 B=-1
      KPP=1
      IF(LMAX.LE.0)L=0
      IF(LMAX.LE.0)GO TO 8
      DO 4 L=1,LMAX
      J=2*L-KPP
    4 W(L)=PNL(ALPHA,NP,J,B)
      DO 5 K=2,30
    5 W(K)=W(K-1)+W(K)
      call ranmar(vran,1)
      BM=vran(1)*W(30)
      DO 7 K=1,30
      IF(BM-W(K))6,6,7
    6 L=K
      GO TO 8
    7 CONTINUE
    8 IF (IFIP.GT.0) GO TO 41
      NPIM= L
      NPIP=L-KPP
      NPI0=NP-L-NPIP
      GO TO 42
   41 NPIP=L
      NPIM=L-1
      NPI0=NP-NPIM-NPIP
   42 CONTINUE
CCCC   ONLY FOR ANTI P-P OR ANTI N-P
      IF(I1.LT.10) PRINT 125,NP,NPIM,NPIP,NPI0
  125 FORMAT(10X,'NP,NPIM,NPIP,NPI0',4I10)
      NPIM1=0
      NPIP1=0
      NPI01=0
      MV1=MV+1
      MV2=MV+NP
      DO 20 K=MV1,MV2
      IF(NPIM-NPIM1) 21,21,22
   21 VPIM=0.
      GO TO 23
   22 VPIM=1.0
   23 IF(NPIP-NPIP1) 24,24,25
   24 VPIP=0.
      GO TO 26
   25 VPIP=1.
   26 IF(NPI0-NPI01) 27,27,28
   27 VPI0=0.
      GO TO 29
   28 VPI0=1.
   29 VPI=VPIM+VPIP+VPI0
      B1=VPIM/VPI
      B2=(VPIM+VPIP)/VPI
      call ranmar(vran,1)
      B=vran(1)
      IF(B-B1) 40,40,31
   40 IM(1,K)=-1
      NPIM1=NPIM1+1
      GO TO 20
   31 IF(B-B2) 32,32,33
   32 IM(1,K)=1
      NPIP1=NPIP1+1
      GO TO 20
   33 IM(1,K)=0
      NPI01=NPI01+1
   20 CONTINUE
      IF(NP.GT.2) RETURN
      IM(1,MV+3)=IM(1,MV+2)
      RETURN
      END


      SUBROUTINE VMOM(AM0)
      DIMENSION SPINP(3),ALPIP(3)
      COMMON /AMPNS/  AMPN(3)
     */ORBMOM/ PIL(10)
     */SPINN/ SPIN
     */BLNUCL/ ANUCL,ZNUCL,EPS,VPI,N,RSM,RB,RHP,RH N,AF,TFP,TFN
      DIMENSION RSM(10),RB(10),RHP(10),RHN(10),AF(10),TFP(10),TFN(10)
      DIMENSION AM0(3)

      real vran(1)

      call ranmar(vran,1)
      B=vran(1)*PIL(10)
      DO 10 I=1,10
      IF(B-PIL(I))11,10,10
   11 ALPI=FLOAT(I-1)
      GO TO 12
   10 CONTINUE
      ALPI=I-1
 12   call ranmar(vran,1)
      TEMP1=1.-2.*vran(1)
      call ranmar(vran,1)
      TEMP2=6.283185*vran(1)
      TEMP3=SQRT(1.-TEMP1**2)
      SPINP(1)=SPIN*TEMP3*COS(TEMP2)
      SPINP(2)=SPIN*TEMP3*SIN(TEMP2)
      SPINP(3)=SPIN*TEMP1
      call ranmar(vran,1)
      TEMP1=1.-2*vran(1)
      call ranmar(vran,1)
      TEMP2=6.283185*vran(1)
      TEMP3=SQRT(1.-TEMP1**2)
      ALPIP(1)=ALPI*TEMP3*COS(TEMP2)
      ALPIP(2)=ALPI*TEMP3*SIN(TEMP2)
      ALPIP(3)=ALPI*TEMP1
      DO 13 K=1,3
      AM0(K)=(SPINP(K)+ALPIP(K))/(5.07*RSM(N))
   13 AMPN(K)=AM0(K) *5.07*RSM(N)
      RETURN
      END


      FUNCTION GEOM (RBIG,PARTIN,IPATIN)
      COMMON/CTINJB/CTINJB
C     BLOK OF CALCULATION OF GEOMETRICAL PATH OF PARTICLE.
      DIMENSION RBIG(10),PARTIN(9),IPATIN(9)
      RIN = SQRT(PARTIN(1)**2+PARTIN(2)**2+PARTIN(3)**2)
      IF((RIN-RBIG(IPATIN(5))).GT.5.0E-06) THEN
         PRINT 111,IPATIN(5),RBIG(IPATIN(5)),RIN
 111     FORMAT(1X,'GEOM REPORTS: ZONE=',I3,' RBIG=',F15.9,' .LT.',
     *         ' RIN=',F15.9)
         PRINT 200,RBIG,PARTIN,IPATIN
         STOP
      ENDIF
      CTINJB=(PARTIN(1)*PARTIN(4)*PARTIN(7)+PARTIN(2)*PARTIN(4)*
     1PARTIN(6)+PARTIN(3)*PARTIN(5))/RIN
      IF (CTINJB) 10,11,11
   10 G=-1.
      KG=IPATIN(5)-1
      IF (KG) 13,13,14
   13 RL = 0.
      GO TO 12
   14 RL = RBIG(KG)
      GO TO 12

   11 G=1.
      KG=IPATIN(5)
      RL=RBIG(KG)
      GO TO 12
   12 ARGUMENT=1.-CTINJB**2 
      IF (ARGUMENT.GE.0.0) THEN
          STINJB = SQRT(ARGUMENT)
      ELSE
          STINJB = 0.0
!         PRINT 100, CTINJB,ARGUMENT
 100  FORMAT(2X,'GEOM: CTINJB=',E14.7,'    ARGUMENT=',E14.7)
!         PRINT 200,RBIG,PARTIN,IPATIN
 200  FORMAT(1X,' RBIG=',10E10.3/'  PARTIN=',9E10.3/'  IPATIN=',9I3)
!         PRINT 300,G,KG,RL,STINJB
 300  FORMAT(1X,' G=',E14.7,' KG=',I3,' RL=',E14.7,' STINJGB=',E14.7)
!         PRINT 400,RIN,RL**2-(RIN*STINJB)**2
 400  FORMAT(1X,' RIN=',E14.7,' DELTAG=',E14.7)
      ENDIF
      DELTAG = RL**2-(RIN*STINJB)**2
!   SIC !
      IF (DELTAG) 16,15,15
   16 IF(ABS(DELTAG)-1.E-6)17,11,11
   17 DELTAG=0.
   15 GEOM = G*SQRT(DELTAG)-RIN*CTINJB
       IF ((IPATIN(5).EQ.1).AND.(RIN.LE.0.001))THEN
             ! TREAT THE CASE OF THE CENTER OF THE NICLEUS SEPARATELY
              GEOM = RBIG(1)
       ENDIF   
       RETURN
         END

       
        FUNCTION QB(X,T,B,N)
        DIMENSION B(40),T(40)
        LP=1
  18    IF(X-T(LP)) 10,11,12
  10    IF(LP-1) 13,13,14
  13    QB=B(1)
        RETURN
  14    IF(LP-(N-1))17,16,16
  16    PH1=B(N-2)
        PS1=T(N-2)
        PH2=B(N-1)
        PS2=T(N-1)
        PH3=B(N)
        PS3=T(N)
        GO TO 15
  11    QB=B(LP)
        RETURN
  12    LP=LP+1
        IF(LP-N)18,19,19
  19    QB=B(N)
        RETURN
  17    PH1=B(LP-1)
        PS1=T(LP-1)
        PH2=B(LP)
        PS2=T(LP)
        PH3=B(LP+1)
        PS3=T(LP+1)
        GO TO 15
  15    DEL=(PS2-PS3)*PS1**2+(PS3-PS1)*PS2**2+(PS1-PS2)*PS3**2
        DELA=PH1*(PS2-PS3)+PH2*(PS3-PS1)+PH3*(PS1-PS2)
        DELD=(PH2-PH3)*PS1**2+(PH3-PH1)*PS2**2+(PH1-PH2)*PS3**2
        DELC=(PS2*PH3-PS3*PH2)*PS1**2+(PS3*PH1-PS1*PH3)*PS2**2
     *  +(PS1*PH2-PS2*PH1)*PS3**2
        A=DELA/DEL
        D=DELD/DEL
        C=DELC/DEL
        QB=A*X**2+D*X+C
        RETURN
        END


      FUNCTION QINTS (X,LQ)
      DIMENSION SIGMA(30,46),ARGUS(30,8)
C      SUBPROGRAM OF INTERPOLATION OF CROSS SECTIONS .
      COMMON /TABLCS/SIGMA,ARGUS
      IF (LQ-4) 19,19,20
   19 I=1
      GO TO 31
   20 IF (LQ-10) 21,21,22
   21 I=2
      GO TO 31
   22 IF (LQ-19) 23,23,24
   23 I=3
      GO TO 31
   24 IF (LQ-21) 25,25,26
   25 I=4
      GO TO 31
   26 IF (LQ-22) 27,27,28
   27 I=5
      GO TO 31
  28  IF(LQ-27)29,29,32
   29 I=6
      GO TO 31
  32  IF(LQ-28)30,30,33
  30  I=4
      GO TO 31
  33  IF(LQ-40)34,34,35
  34  I=7
      GO TO 31
  35  I=8
      GO TO 31
   31 CONTINUE
      LPHA = 1
   18 IF (X-ARGUS(LPHA,I)) 10,11,12
   10 IF (LPHA - 1) 13,13,14
   13 QINTS = 0.
      RETURN
   14 IF (LPHA - 29) 17,16,16
   16 PHI1=SIGMA(28,LQ)
      PSI1=ARGUS(28,I)
      PHI2=SIGMA(29,LQ)
      PSI2=ARGUS(29,I)
      PHI3=SIGMA(30,LQ)
      PSI3=ARGUS(30,I)
      GO TO 15
   17 PHI1=SIGMA(LPHA-1,LQ)
      PSI1=ARGUS(LPHA-1,I)
      PHI2=SIGMA(LPHA,LQ)
      PSI2=ARGUS(LPHA,I)
      PHI3=SIGMA(LPHA+1,LQ)
      PSI3=ARGUS(LPHA+1,I)
      GO TO 15
   11 QINTS = SIGMA (LPHA,LQ)
      RETURN
   12 IF(LPHA .EQ.30) GO TO 11
      LPHA = LPHA + 1
      GO TO 18
   15 DELTA=(PSI2-PSI3)*PSI1**2+(PSI3-PSI1)*PSI2**2+(PSI1-PSI2)*PSI3**2
      DELTAA=PHI1*(PSI2-PSI3)+PHI2*(PSI3-PSI1)+PHI3*(PSI1-PSI2)
      DELTAB=(PHI2-PHI3)*PSI1**2+(PHI3-PHI1)*PSI2**2+(PHI1-PHI2)*PSI3**2
     0DELTAC=(PSI2*PHI3-PSI3*PHI2)*PSI1**2+(PSI3*PHI1-PSI1*PHI3)*PSI2**2
     1+(PSI1*PHI2-PSI2*PHI1)*PSI3**2
      A = DELTAA / DELTA
      B = DELTAB / DELTA
      C = DELTAC / DELTA
      QINTS = A*X**2 + B*X + C
      RETURN
      END


      SUBROUTINE PARTN (PARTIN,IPATIN,PARTNE,IPATNE)
C
C     BLOCK OF PARTNER SELECTION.
C     TREATS TWO POSSIBILITIES TO PRODUCE FERMI MOTION:
C     1) LOCAL=.TRUE.  LOCAL DENSITY APPROXIMATION
C     2) LOCAL=.FALSE. DISTRIBUTION USED BY SHOR ET AL.
C
      DIMENSION TFP(10),TFN(10),PARTIN(9),IPATIN(9),PARTNE(9),IPATNE(5),
     1V(3),RHOP(10),RHON(10),RSM(10),RBIG(10),AF(10)
      COMMON/BLNUCL/ANUCL,ZNUCL,EPS,VPI,N,RSM,RBIG,RHOP,RHON,AF,TFP,TFN
      LOGICAL LOCAL
      COMMON/FERMI_SW/LOCAL
      COMMON /FER_ARRAY/F_PROT(100),F_NEUT(100),F_PP(100)

      real vran(1)

      NAVNI = 0
      IF (NAVNI-1) 10,11,10
   10 J1 = IPATIN(5)
      GO TO 12
   11 J1 = 1
      GO TO 12
   12 J2 = IPATIN(5)

      BPARTN = (ANUCL-ZNUCL)/ANUCL
      call ranmar(vran,1)
      IF (vran(1).GE.BPARTN) THEN 
C--------------------------------
!  FOR PROTONS
         IPATNE(1) = 1
      IF(LOCAL) THEN      
         TNJR=-100.
        DO WHILE (TNJR.LE.0.)
           call ranmar(vran,1)
         TNJ1 = TFP(J1)*vran(1)**(2./3.)
         TNJR = TNJ1+TFP(J1)-TFP(J2)
        ENDDO
      ELSE
         call ranmar(vran,1)
        P = ALI(vran(1),F_PROT,F_PP,100)
        TNJR = SQRT(P**2+0.940**2)-0.940
      ENDIF
      CALL HFILL(2999,TNJR,0.,1.)
      ELSE
C--------------------------------
!  FOR NEUTRONS
         IPATNE(1) = 0
      IF(LOCAL) THEN      
         TNJR=-100.
        DO WHILE (TNJR.LE.0.)
           call ranmar(vran,1)
         TNJ1 = TFN(J1)*vran(1)**(2./3.)
         TNJR = TNJ1+TFN(J1)-TFN(J2)
        ENDDO
      ELSE
         call ranmar(vran,1)
        P = ALI(vran(1),F_NEUT,F_PP,100)
        TNJR = SQRT(P**2+0.940**2)-0.940
      ENDIF
      CALL HFILL(3000,TNJR,0.,1.)
      ENDIF
C--------------------------------
      call ranmar(vran,1)
      PARTNE(5) = 1.-2.*vran(1)
      call ranmar(vran,1)
      PHIN = 6.283185*vran(1)
      PARTNE(4) = SQRT(1.-PARTNE(5)**2)
      PARTNE(7) = COS(PHIN)
      PARTNE(6)=SIN(PHIN)
      PARTNE(1)=PARTIN(1)
      PARTNE(2)=PARTIN(2)
      PARTNE(3)=PARTIN(3)
      PARTNE(9) = 0.940
      PARTNE(8) = TNJR
      IPATNE(5) = IPATIN(5)
      IPATNE(2)=0
      IPATNE(3)=0
      IPATNE(4)=1

      RETURN
      END



        FUNCTION COSA(T)
        COMMON/B/B1(30),B2(30),CTM(30)
        COMMON/TL/TL(30),NL

        real vran(1)

        OTN(X)=0.0105+0.0165*X
        IF(T-0.084) 1,1,2
  1     B=QB(T,TL,B1,NL)
        call ranmar(vran,1)
        SI=vran(1)
        COSA=1.+ALOG(SI*(1.-EXP(-2.*B))+EXP(-2.*B))/B
        RETURN
  2     X=SQRT((T+0.94)**2-0.94)
        call ranmar(vran,1)
        IF(vran(1)-OTN(X))3,3,7
C               BACK
  3     IF(T-0.226) 4,4,5
  4     CT=QB(T,TL,CTM,NL)
        call ranmar(vran,1)
        COSA=vran(1)*(CT+1.)-1.
        RETURN
  5     B=QB(T,TL,B2,NL)
        CT=QB(T,TL,CTM,NL)
        call ranmar(vran,1)
        SI=vran(1)
        COSA=ALOG(SI*EXP(B*CT)+(1.-SI)*EXP(-B))/B
        RETURN
C               FORWARD
  7     B=QB(T,TL,B1,NL)
        CT=QB(T,TL,CTM,NL)
        call ranmar(vran,1)
        SI=vran(1)
        COSA=ALOG(SI*EXP(B)+(1.-SI)*EXP(B*CT))/B
        RETURN
        END


        FUNCTION COSE(T)
        COMMON/TE/TE(13),NE
        COMMON/BE/BE(13)

        real vran(1)

        B=QB(T,TE,BE,NE)
        call ranmar(vran,1)
        SI=vran(1)
        COSE=1.+ALOG(SI*(1.-EXP(-2.*B))+EXP(-2.*B))/B
        RETURN
        END


        SUBROUTINE TC8
        COMMON/B/B1(30),B2(30),CTM(30)
        COMMON/TL/TL(30),NL
        COMMON/TE/TE(13),NE
        COMMON/BE/BE(13)
        DATA TL/
     *  0.020, 0.040, 0.050, 0.063, 0.083, 0.110, 0.137, 0.175, 0.226,
     *  0.288, 0.334, 0.425, 0.499, 0.538, 0.608, 0.664, 0.713, 0.771,
     *  0.830, 0.916, 1.011, 1.100, 1.144, 1.189, 1.279, 1.379, 1.572,
     *  2.203, 4.840, 7.115/
        DATA B1/
     *  1.13,  1.52,  1.67,  1.94,  2.45,  2.70,  3.00,  3.54,  4.14,
     *  4.46,  4.71,  5.99,  7.04,  7.58,  8.57,  9.37, 10.06, 10.87,
     * 11.12, 12.27, 13.55, 14.73, 15.32, 15.09, 15.33, 17.50, 18.84,
     * 29.66, 53.06, 84.34/
        DATA B2/
     *  0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.,    0.180,
     *  0.210, 0.230, 0.300, 0.350, 0.380, 0.429, 0.468, 0.503, 0.544,
     *  0.560, 0.610, 0.677, 0.736, 0.770, 0.800, 0.851, 0.875, 1.050,
     *  3.707, 5.970, 7.028/
        DATA CTM/
     * -1.,   -1.,   -1.,   -0.90, -0.80, -0.68, -0.53, -0.37, -0.19,
     * -0.02,  0.11,  0.21,  0.27,  0.30,  0.34,  0.40,  0.44,  0.48,
     *  0.50,  0.54,  0.57,  0.60,  0.61,  0.63,  0.65,  0.67,  0.72,
     *  0.75,  0.906, 0.913/
        DATA TE/
     *  0.0437, 0.116, 0.143, 0.167, 0.192, 0.214, 0.231, 0.249,
     *  2.68,  4.15,  5.13,  6.12,  8.11/
        DATA BE/
     *  0.838,  1.284, 1.695, 1.575, 1.989, 2.172, 2.388, 1.908,
     *  16.75,  18.92,  22.87,  23.88,  30.97/
        DATA NL/30/
        DATA NE/13/
        RETURN
        END


      FUNCTION PNL(ALPHA,NP,J,B)
      ZN=(1.+ALPHA)**NP+(1.-ALPHA)**NP*B
      CH=2.*ALPHA**J*BINOM(NP,J)
      PNL=CH/ZN
      RETURN
      END


      FUNCTION FACTOR(M)
      F=1.0
      IF(M-2)1,2,2
    1 FACTOR=F
      RETURN
    2 DO 3 K=1,M
    3 F=FLOAT(K)*F
      FACTOR=F
      RETURN
      END


      FUNCTION BINOM(N,J)
      BINOM=FACTOR(N)/(FACTOR(J)*FACTOR(N-J))
      RETURN
      END


      SUBROUTINE NORMCO(A,B,UA,UB,SIGMAA,SIGMAB,RO)

      real vran(1)

      call ranmar(vran,1)
      Y=vran(1)
      call ranmar(vran,1)
      Z=vran(1)
      X=6.2831853*Z
      AA=SQRT(-2.*ALOG(Y))
      A=UA+SIGMAA*AA*(SQRT(1.-RO**2)*COS(X)+RO*SIN(X))
      B=UB+SIGMAB*AA*SIN(X)
      RETURN
      END


      SUBROUTINE CHINEL (IPATIN,L,MS,MQ,KSI,NP,MV,TIN1,ME,IPATNE)
C     DETERMINING OF SECONDARY PARTICLES CHARGES IN INELASTIC
C     SCATTERING.
      DIMENSION IPATIN(9),IPATNE(5),PMEMO(9,100),IMEMO(9,100)
      COMMON/MEMORY/PMEMO,IMEMO

      real vran(1)

      ITQ=IPATIN(4)
      IF (NP-3) 21,1,21
   1  IF(MQ) 10,2,10
   2  IF(IPATIN(1)-IPATNE(1)) 3,5,3
   3  BPI0=0.33333
      BPIEX=0.66667
      call ranmar(vran,1)
      TEMP1=vran(1)
      IF(TEMP1-BPI0) 19,4,4
   4  IF(TEMP1-BPIEX) 20,9,9
C
   5  BPI0=0.2500
      BPIEX=0.5000
      BPIEX2=0.7500
      call ranmar(vran,1)
      TEMP1=vran(1)
      IF(TEMP1-BPI0) 19,6,6
   6  IF(TEMP1-BPIEX)20,7,7
   7  IF(TEMP1-BPIEX2)9,8,8
C
   8  IMEMO(1,MV+3)=-IPATIN(1)-1
      IMEMO(1,MV+2)=0.
      IMEMO(1,MV+1)=-IMEMO(1,MV+3)
      RETURN
   9  IMEMO(1,MV+1)=IPATNE(1)
      IMEMO(1,MV+3)=-1-IPATIN(1)
      IMEMO(1,MV+2)=ME-IMEMO(1,MV+1)-IMEMO(1,MV+3)
      RETURN
  10  SPI0=SIGMAT(L,MS,MQ,ME,KSI,4,TIN1,ITQ)
      STH=SIGMAT(L,MS,MQ,ME,KSI,7,TIN1,ITQ)
      BPI0 = SPI0/STH
      BPIEX=(SPI0+SIGMAT(L,MS,MQ,ME,KSI,5,TIN1,ITQ))/STH
      call ranmar(vran,1)
      TEMP1 = vran(1)
      IF (TEMP1-BPI0) 19,11,11
   11 IF (TEMP1-BPIEX) 20,12,12
   12 IMEMO(1,MV+1)=IPATNE(1)-(IPATIN(4)-1)*IPATIN(1)
      IMEMO(1,MV+3)=(IPATIN(4)-1)*IPATIN(1)**2-IPATIN(4)*IPATIN(1)+1
      GO TO 18
   18 IMEMO(1,MV+2)=ME-IMEMO(1,MV+1)-IMEMO(1,MV+3)
      RETURN
   19 IMEMO(1,MV+1) = IPATNE(1)
      IMEMO(1,MV+2) = 0
      IMEMO(1,MV+3) = IPATIN(1)
      RETURN
   20 IMEMO(1,MV+1) = 1-IPATNE(1)
      IMEMO(1,MV+3) = IPATIN(1)
      IMEMO(1,MV+2)=ME-IMEMO(1,MV+1)-IMEMO(1,MV+3)
      RETURN
 21   call ranmar(vran,1)
      IF (vran(1)-0.5) 22,22,23
   22 IMEMO(1,MV+1) = 1
      GO TO 24
   23 IMEMO(1,MV+1) = 0
      GO TO 24
   24 IF(MQ-1) 42,28,25
 42   call ranmar(vran,1)
      IF (vran(1)-0.5) 41,41,27
   41 IMEMO(1,MV+3) =-1
      GO TO 28
 25   call ranmar(vran,1)
      IF (vran(1)-0.5) 26,26,27
   26 IMEMO(1,MV+3) = 1
      GO TO 28
   27 IMEMO(1,MV+3)=0
      GO TO 28
   28 LAMBDA = 2
   29 IF (MQ-1) 30,31,30
   30 IF (LAMBDA-3) 31,36,31
 31   call ranmar(vran,1)
      TEMP2 = vran(1)
      MTEMP=MV+LAMBDA
      IF (TEMP2-1./3.) 33,32,32
   32 IF (TEMP2-2./3.) 34,35,35
   33 IMEMO(1,MTEMP) = 1
      GO TO 36
   34 IMEMO(1,MTEMP) = 0
      GO TO 36
   35 IMEMO(1,MTEMP) = -1
      GO TO 36
   36 IF (LAMBDA-NP) 37,38,38
   37 LAMBDA = LAMBDA+1
      GO TO 29
   38 MIGQ=0
      DO 39 I=1,NP
      ITEMP = MV+I
      MIGQ=MIGQ+IMEMO(1,ITEMP)
   39 CONTINUE
      IF(ME-MIGQ) 21,40,21
   40 RETURN
         END


      SUBROUTINE ABEL(PARTIN,V,U,PIST,PNST,CTI,FII,CMI,CMN)
C     BLOCK OF CALCULATION OF MOMENTA OF SECONDARY PARTICLES
C     IN CENTRE OF MASS SISTEM FOR ABSORPTION AND ELASTIC SCATTERING.
      DIMENSION V(3),PI(3),PIST(3),PNST(3),PARTIN(9),PINS(3)
      EI=(U**2+CMI**2-CMN**2)/(2.*U)
      GG=EI**2-CMI**2
      IF(GG.LE.0.) THEN
        PIM=0.0000001
      ELSE
        PIM=SQRT(GG)
      ENDIF
      V2 = V(1)**2+V(2)**2+V(3)**2
      TEMP3 = SQRT(PARTIN(8)*(PARTIN(8)+2.*PARTIN(9)))
      SPV=TEMP3*PARTIN(4)*PARTIN(7)*V(1)+TEMP3*PARTIN(5)*V(3)+
     1TEMP3*PARTIN(4)*PARTIN(6)*V(2)
      TEMP1 = SPV*(1./SQRT(1.-V2)-1.)/V2
      TEMP2 = (PARTIN(8)+PARTIN(9))/SQRT(1.-V2)
      PINS(1)=TEMP3*PARTIN(4)*PARTIN(7)+V(1)*TEMP1-V(1)*TEMP2
      PINS(2)=TEMP3*PARTIN(4)*PARTIN(6)+V(2)*TEMP1-V(2)*TEMP2
      PINS(3)=TEMP3*PARTIN(5)+V(3)*TEMP1-V(3)*TEMP2
      STI=SQRT(1.-CTI**2)
      CFI=COS(FII)
      SFI=SIN(FII)
      PI(1)=PIM*STI*CFI
      PI(2)=PIM*STI*SFI
      PI(3)=PIM*CTI
      CALL ROTOR (PINS,V,PI,PIST)
      PNST(1) = -PIST(1)
      PNST(2) = -PIST(2)
      PNST(3) = -PIST(3)
      RETURN
         END

      
      SUBROUTINE CABC
C
C     SUBROUTINE WICH PUT THE COEFFICIENTS
C     IN THE MAIN PROGRAM
C
      COMMON /COEFA/ ANKJ  /COEFBC/ BNKJ,CKJ
      DIMENSION ANKJ(4,4,29),BNKJ(4,4,8),CKJ(3,8)
      RETURN
      END


      SUBROUTINE TC5
      COMMON/COEFA/A1(72),A2(72),A3(72),A4(72),A5(72),A6(72),A7(32)
      COMMON/COEFBC/B1(64),B2(64),C(24)
      DATA A1/
     * 2.7404E 00 , -9.6998E 00 ,  1.0400E 01 ,  2.3882E 00 ,
     *-7.5137E 00 ,  4.4096E 01 , -7.4379E 01 ,  4.6038E 01 ,
     * 7.5479E 00 , -3.9274E 01 ,  6.4835E 01 , -4.1609E 01 ,
     *-1.8369E 00 ,  8.6911E 00 , -1.3060E 01 ,  7.1880E 00 ,
     *-3.0853E 01 ,  1.0624E 02 , -1.2939E 02 ,  5.4339E 01 ,
     * 1.9465E 01 , -6.8102E 01 ,  9.6358E 01 , -5.6827E 01 ,
     *-3.4831E 00 ,  1.2341E 01 , -1.8592E 01 ,  1.2024E 01 ,
     * 1.8941E-01 , -6.7880E-01 ,  1.0665E 00 , -7.2910E-01 ,
     * 1.0258E-01 , -1.0542E 00 ,  1.1389E 01 , -1.6638E 01 ,
     *-4.9607E-01 ,  1.1800E 01 , -9.0857E 01 ,  1.6476E 02 ,
     * 1.5437E 00 , -3.3769E 01 ,  2.5192E 02 , -4.5071E 02 ,
     *-1.2021E 00 ,  2.5336E 01 , -1.8658E 02 ,  3.3254E 02 ,
     * 1.5789E-01 ,  2.9671E 00 , -5.5251E 00 ,  6.8925E 00 ,
     *-7.0218E 00 , -2.0534E 02 ,  5.6951E 02 , -8.9858E 02 ,
     * 1.3496E 02 ,  4.8722E 03 , -1.4674E 04 ,  2.3924E 04 ,
     *-8.2116E 02 , -3.2586E 04 ,  1.0098E 05 , -1.6553E 05 ,
     * 3.1531E-01 , -7.4981E 00 ,  4.3295E 01 , -7.6360E 01 ,
     *-6.5373E 00 ,  1.9307E 02 , -1.0181E 03 ,  1.7426E 03 /
      DATA A2/
     * 4.6864E 01 , -1.3030E 03 ,  6.7291E 03 , -1.1075E 04 ,
     *-9.5192E 01 ,  2.6373E 03 , -1.2857E 04 ,  2.0294E 04 ,
     *-1.7953E 01 ,  1.0972E 02 , -2.3954E 02 ,  2.2826E 02 ,
     * 9.1968E 01 , -5.1963E 02 ,  1.1266E 03 , -1.0740E 03 ,
     *-1.3270E 02 ,  7.4112E 02 , -1.6000E 03 ,  1.5249E 03 ,
     * 5.8598E 01 , -3.1874E 02 ,  6.7751E 02 , -6.4011E 02 ,
     * 4.2169E-01 ,  1.4705E 02 , -6.5335E 02 ,  9.1507E 02 ,
     *-3.5198E 00 , -2.6019E 02 ,  1.2250E 03 , -1.7481E 03 ,
     * 3.6373E 00 ,  1.5592E 02 , -7.5201E 02 ,  1.0796E 03 ,
     *-7.8041E-01 , -3.0563E 01 ,  1.4795E 02 , -2.1250E 02 ,
     *-3.8288E-01 ,  3.7587E 00 , -6.5144E 00 ,  6.7740E 00 ,
     * 1.0381E 02 , -2.7282E 02 ,  4.7759E 02 , -5.1222E 02 ,
     *-1.7882E 03 ,  4.3052E 03 , -7.9314E 03 ,  9.3471E 03 ,
     * 7.1475E 03 , -3.3395E 03 , -4.1392E 03 , -4.4364E 03 ,
     * 2.4991E-01 ,  3.2028E 01 , -1.1882E 02 ,  1.5099E 02 ,
     *-2.6994E 00 , -4.6045E 02 ,  1.8959E 03 , -2.5190E 03 ,
     * 1.6268E 01 ,  2.1384E 03 , -9.1262E 03 ,  1.2431E 04 ,
     *-2.9654E 01,-3.1823E 03, 1.3944E 04,-1.9342E 04/
      DATA A3/
     * 3.9025E 00 , -9.1126E 01 ,  3.2373E 02 , -4.0048E 02 ,
     *-2.0619E 01 ,  4.9170E 02 , -1.7155E 03 ,  2.1143E 03 ,
     * 3.3004E 01 , -7.6684E 02 ,  2.7003E 03 , -3.3525E 03 ,
     *-1.6367E 01 ,  3.7394E 02 , -1.3202E 03 ,  1.6423E 03 ,
     * 1.9402E 01 , -2.2446E 02 ,  7.4733E 02 , -9.3570E 02 ,
     *-4.4180E 01 ,  4.7194E 02 , -1.4856E 03 ,  1.8055E 03 ,
     * 3.1567E 01 , -3.0176E 02 ,  9.0763E 02 , -1.0773E 03 ,
     *-6.8648E 00 ,  6.0476E 01 , -1.7520E 02 ,  2.0381E 02 ,
     * 4.0693E-01 , -4.1404E 00 ,  1.4044E 01 , -1.7265E 01 ,
     *-3.6799E 00 ,  5.9610E 01 , -1.6269E 02 ,  1.8873E 02 ,
     * 1.4556E 01 , -1.7550E 02 ,  4.5839E 02 , -5.3390E 02 ,
     *-1.2621E 01 ,  1.4964E 02 , -3.8118E 02 ,  4.5141E 02 ,
     *-4.7554E-01 ,  2.2641E 00 , -1.2528E 01 ,  2.4647E 01 ,
     * 5.1620E 00 , -9.9236E 00 ,  5.5623E 01 , -1.0462E 02 ,
     *-8.1117E 00 ,  1.9315E 01 , -8.4255E 01 ,  1.3908E 02 ,
     * 3.5187E 00 , -9.1783E 00 ,  3.4950E 01 , -5.1243E 01 ,
     * 4.8173E-01 ,  5.7726E 00 , -1.3745E 01 ,  2.7125E 01 ,
     *-4.4804E 00 , -3.8582E 01 ,  1.1159E 02 , -2.4305E 02/
      DATA A4/
     * 1.6306E 01 ,  1.1046E 02 , -3.3045E 02 ,  7.2270E 02 ,
     *-1.5968E 01 , -8.0140E 01 ,  2.4616E 02 , -6.0753E 02 ,
     *-5.1646E 00 , -6.0776E 00 ,  7.8989E 01 , -1.0705E 02 ,
     * 2.1871E 01 ,  5.6915E 01 , -4.0159E 02 ,  5.1215E 02 ,
     *-2.7993E 01 , -9.4670E 01 ,  5.6928E 02 , -6.9621E 02 ,
     * 1.1587E 01 ,  4.5998E 01 , -2.456 E 02 ,  2.8452E 02 ,
     *-5.3067E 01 ,  5.7612E 02 , -1.5438E 03 ,  1.6455E 05 ,
     * 1.4750E 02 , -1.6 38E 03 ,  4.5923E 03 , -4.9949E 03 ,
     *-1.3436E 02 ,  1.5780E 03 , -4.4463E 03 ,  4.9022E 03 ,
     * 4.0253E 01 , -4.8860E 02 ,  1.4001E 03 , -1.5606E 03 ,
     * 1.4988E-01 ,  2.8753E 00 , -5.3078E 00 ,  6.2233E 00 ,
     *-5.9558E 00 , -1.6203E 02 ,  4.3079E 02 , -6.2548E 02 ,
     * 1.2875E 02 ,  3.1402E 03 , -7.9189E 03 ,  1.0983E 04 ,
     *-8.5161E 02 , -1.8780E 04 ,  4.4607E 04 , -5.8790E 04 ,
     * 5.3689E-01 , -1.3216E 01 ,  8.1011E 01 , -1.4285E 02 ,
     *-1.0550E 01 ,  2.9629E 02 , -1.6957E 03 ,  2.8935E 03 ,
     * 6.9621E 01 , -1.9245E 03 ,  1.0620E 04 , -1.7468E 04 ,
     *-1.3865E 02 ,  3.9281E 03 , -2.0293E 04 ,  3.2058E 04/
      DATA A5/
     * 6.5288E-01 ,  3.8977E-01 ,  8.4078E-01 ,  1.8893E-01 ,
     *-4.3964E 00 ,  3.4309E 01 , -7.3692E 01 ,  8.4308E 01 ,
     * 1.4889E 01 , -1.4380E 02 ,  3.1227E 02 , -3.5014E 02 ,
     *-1.5658E 01, 1.7160E 02,-3.7212E 02, 4.1299E 02,
     * 8.5591E-02 ,  5.0390E 00 , -1.3782E 01 ,  1.4661E 01 ,
     * 5.4284E-02 , -9.2324E 00 ,  3.6397E 01 , -4.2962E 01 ,
     *-5.1111E-02 ,  4.6003E 00 , -2.0534E 01 ,  2.7731E 01 ,
     * 7.4514E-03 , -6.2529E-01 ,  2.9159E 00 , -4.1101E 00 ,
     * 7.1622E-02 ,  3.0960E 00 , -1.1125E 01 ,  1.8130E 01 ,
     * 9.2581E-02 , -3.2186E 00 ,  2.0273E 01 , -3.3245E 01 ,
     *-5.1531E-02 ,  8.9886E-01 , -7.5084E 00 ,  1.3188E 01 ,
     * 5.8258E-03 , -1.7288E-03 ,  7.0224E-01 , -1.4854E 00 ,
     * 8.2300E-02 ,  1.5854E-01 ,  3.7716E 00 , -4.0562E 00 ,
     * 1.0802E-02 , -3.3688E-01 ,  1.1727E 00 , -6.7476E-01 ,
     *-2.1798E-03 ,  5.2166E-02 , -2.5816E-01 ,  3.2048E-01 ,
     * 6.5764E-05 , -1.4711E-03 ,  7.8209E-03 , -1.0580E-02 ,
     * 1.1138E-01 ,  6.0396E-01 ,  3.0174E 00 , -4.4190E 00 ,
     *-1.7709E-02 ,  2.3015E-01 , -1.8187E 00 ,  3.4518E 00/
      DATA A6/
     * 2.0977E-03 , -2.5458E-02 ,  2.1626E-01 , -4.0692E-01 ,
     *-5.4799E-05 ,  5.9111E-04 , -5.5552E-03 ,  1.0647E-02 ,
     * 1.7288E-01 ,  7.1080E 00 , -1.7961E 01 ,  1.6403E 01 ,
     *-1.4504E-01 , -1.3032E 01 ,  4.1781E 01 , -4.0799E 01 ,
     * 4.5390E-02 ,  8.3515E 00 , -3.0260E 01 ,  3.2882E 01 ,
     *-4.7961E-03 , -1.4095E 00 ,  5.3505E 00 , -6.0946E 00 ,
     * 3.7596E-02 ,  1.4331E 00 , -3.1350E 00 ,  6.4864E 00 ,
     * 2.3827E-01 ,  1.8253E 00 ,  1.7648E 00 , -1.6735E 01 ,
     *-1.5410E-01 , -1.5201E 00 , -1.5692E 00 ,  1.7185E 01 ,
     * 2.5037E-02 ,  3.0588E-01 ,  3.2520E-01 , -3.5277E 00 ,
     * 1.2489E-01 ,  1.3573E 00 ,  8.2338E-01 , -1.4595E 00 ,
     *-5.1577E-02 , -3.5778E-01 , -1.1690E 00 ,  1.8078E 00 ,
     * 7.4864E-03 ,  3.2888E-02 ,  2.3744E-01 , -3.9802E-01 ,
     *-2.9880E-04 , -7.5117E-04 , -1.1402E-02 ,  1.9505E-02 ,
     * 1.8470E-01 ,  1.9269E 00 , -3.2979E 00 ,  3.6843E 00 ,
     *-7.3932E-02 ,  2.7213E-01 ,  1.0600E 00 , -2.3354E 00 ,
     * 1.8907E-02 , -5.6473E-02 , -1.6487E-01 ,  3.8426E-01 ,
     *-9.2984E-04 ,  2.5506E-03 ,  7.3052E-03 , -1.7220E-02/
      DATA A7/
     *-1.0306E 00 ,  3.2849E 01 , -7.5052E 01 ,  6.0255E 01 ,
     * 7.9586E 00 , -1.2572E 02 ,  2.5604E 02 , -1.6547E 02 ,
     *-1.4797E 01 ,  1.6590E 02 , -2.7991E 02 ,  1.1333E 02 ,
     * 8.2309E 00 , -6.7871E 01 ,  8.5762E 01 ,  5.9727E 00 ,
     *-2.3722E 02 ,  9.6890E 02 , -1.6219E 03 ,  1.3637E 03 ,
     * 6.5800E 02 , -2.6941E 03 ,  4.5480E 03 , -3.8460E 03 ,
     *-6.0653E 02 ,  2.4983E 03 , -4.2498E 03 ,  3.6136E 03 ,
     * 1.8604E 02,-7.6933E 02, 1.3166E 03,-1.1242E 03/
      DATA B1/
     * 5.0278E-01 ,  3.1442E 00 , -7.8172E 00 ,  8.1667E 00 ,
     * 9.3482E-01 , -1.0590E 01 ,  2.9227E 01 , -3.4550E 01 ,
     *-9.6685E-02 ,  4.7335E 00 , -1.4298E 01 ,  1.7685E 01 ,
     *-2.5041E-02 , -6.2478E-01 ,  2.0282E 00 , -2.5895E 00 ,
     * 1.1965E 00 , -8.2889E-01 ,  1.0426E 00 , -1.9090E 00 ,
     * 2.8703E-01 , -4.9065E 00 ,  1.6264E 01 , -1.9904E 01 ,
     *-2.4492E-01 ,  2.9191E 00 , -9.5776E 00 ,  1.1938E 01 ,
     * 3.7297E-02 , -4.2200E-01 ,  1.3883E 00 , -1.7476E 00 ,
     * 1.3508E 00 , -4.3139E 00 ,  1.2291E 01 , -1.5288E 01 ,
     *-2.0086E-01 ,  1.3641E 00 , -3.4030E 00 ,  3.8559E 00 ,
     * 1.2583E-02 , -8.3492E-02 ,  1.8600E-01 , -2.0043E-01 ,
     *-2.3628E-04 ,  1.3514E-03 , -2.4324E-03 ,  2.1906E-03 ,
     * 1.2419E 00 , -4.3633E 00 ,  1.3743E 01 , -1.8592E 01 ,
     *-2.4404E-01 ,  1.3158E 00 , -3.5691E 00 ,  4.3867E 00 ,
     * 1.5693E-02 , -8.2579E-02 ,  2.1427E-01 , -2.5846E-01 ,
     *-2.9386E-04 ,  1.4060E-03 , -3.3835E-03 ,  3.8664E-03/
      DATA B2/
     * 6.3054E-01 , -3.7333E 00 ,  1.3464E 01 , -1.8594E 01 ,
     * 2.1801E 00 ,  1.5163E 00 , -1.6380E 01 ,  2.7944E 01 ,
     *-1.2886E 00 , -2.4570E 00 ,  1.5129E 01 , -2.3295E 01 ,
     * 2.0915E-01 ,  5.2279E-01 , -2.8687E 00 ,  4.2688E 00 ,
     * 9.3363E-01 , -1.8181E 00 ,  5.5157E 00 , -8.5216E 00 ,
     * 1.7811E 00 , -8.2927E 00 ,  2.0607E 01 , -2.0827E 01 ,
     *-1.5264E 00 ,  6.8433E 00 , -1.6067E 01 ,  1.6845E 01 ,
     * 2.7128E-01 , -1.1944E 00 ,  2.7495E 00 , -2.9045E 00 ,
     * 1.9439E 00 , -4.6268E 00 ,  9.7879E 00 , -9.6074E 00 ,
     *-3.4640E-01 ,  1.1093E 00 , -1.9313E 00 ,  1.7064E 00 ,
     * 2.7054E-02 , -1.1638E-01 ,  2.6969E-01 , -3.1853E-01 ,
     *-6.6092E-04 ,  5.0728E-03 , -1.4995E-02 ,  1.9605E-02 ,
     * 1.8693E 00 , -5.5678E 00 ,  1.4795E 01 , -1.6903E 01 ,
     *-4.9965E-01 ,  1.7874E 00 , -4.1330E 00 ,  3.8393E 00 ,
     * 4.6194E-02 , -1.8536E-01 ,  4.5315E-01 , -4.6273E-01 ,
     *-1.3341E-03, 5.7710E-03,-1.4554E-02, 1.5554E-02/
      DATA C/
     * 1.4509E-01 ,  4.6520E-01 , -3.3005E-02 ,  1.5376E-01 ,
     * 2.7436E-01 , -1.4604E-02 ,  6.2959E-01 ,  1.7866E-01 ,
     *-2.6216E-03 ,  8.3810E-01 ,  8.6137E-03 ,  3.2946E-03 ,
     * 9.2852E-02 ,  5.3886E-01 , -5.4493E-02 ,  1.3032E-01 ,
     * 4.0709E-01 , -2.8782E-02 ,  1.4909E-01 ,  3.8502E-01 ,
     *-1.2775E-02, 1.8024E-01, 3.3022E-01,-9.4491E-03/
         RETURN
         END


      SUBROUTINE CHABS_NEW (L,INE,NE1,NE2,A,Z,TIN1)
!      
!     DETERMINATION OF THE CHARGES OF OUTGOING PARTICLES
!     IN PION AND GAMMA ABSORPTION.
!     SUBROUTINE INCLUDES ISOTOPIC EFFECTS AS A FUNCTION OF PION
!     ENERGY IN NN RESTING SYSTEM.
!
        COMMON /ISOTOPIC/ ISOTOPIC,O_PP,O_PN,O_NN

      real vran(1)

      N=A-Z
      call ranmar(vran,1)
      RN = vran(1)
      IF (L) 11,10,11
   10 NP = 0
      RIT=RITCHIE(TIN1) 
      GO TO 12
   11 NP = 1
      GO TO 12
   12 IF (INE) 13,14,15
   13 IF (NP) 22,17,22
   14 IF (NP) 20,18,20
   15 IF (NP) 21,16,21
   16 TEMP1 = (2*Z*RIT)/(2*Z*RIT+N-1)
      IF (RN-TEMP1) 21,21,20
   17 TEMP2 = (Z-1)/(2*N*RIT+Z-1)
      IF (RN-TEMP2) 20,20,22
   18 TEMP3 = (2*Z*N*RIT)/(2*Z*N*RIT+Z*(Z-1)+N*(N-1))
      IF (RN-TEMP3) 20,20,19
   19 TEMP4 = (2*Z*N*RIT+Z*(Z-1))/(2*Z*N*RIT+Z*(Z-1)+N*(N-1))
      IF (RN-TEMP4) 21,21,22
   20 NE1 = 0
      NE2 = 1
      O_PN=O_PN+1.
      RETURN
   21 NE1 = 1
      NE2 = 1
      O_PP=O_PP+1.
      RETURN
   22 NE1 = 0
      NE2 = 0
      O_NN=O_NN+1.
      RETURN
         END
      

      REAL*4 FUNCTION RITCHIE(T_GEV)
        COMMON /ISOTOPIC/ ISOTOPIC,O_PP,O_PN,O_NN
        T=T_GEV*1000
      IF (ISOTOPIC.GT.0) THEN
!
!     RITCHIE B.G. PR C28(1983)926
!          T - KINETIC ENERGY (IN MEV), T.LE.330 MEV
!
            IF (T.LE.1.) THEN
                RITCHIE=4.
            ELSE IF (T.LE.330.) THEN
                E=SQRT((139.57+1876.)**2+2.*T*1876)
                RITCHIE=-1.2+3.5/SQRT(T)+74000./((E-2136.)**2+5600.)
            ELSE
                RITCHIE=1.5
            ENDIF
      ELSE
           RITCHIE=1.0
      ENDIF
      RETURN
      END


      SUBROUTINE CINEMA(PSTAR,V,P,CT,ST,CFI,SFI,T,CM)
C
C     KINEMATIC BLOCK. BACKWARD LORENTS TRANSFORMATION:
C
C     PSTAR ---> -V ---> P
C
C     N.B.: SPECIAL CASE V=0 SHOULD BE TREATED SEPARATELY !
C
      DIMENSION PSTAR(3),V(3),P(3)
      SPV = PSTAR(1)*V(1)+PSTAR(2)*V(2)+PSTAR(3)*V(3)
      V2 = V(1)**2+V(2)**2+V(3)**2
      TEMP1 = SQRT(1.-V2)
      TEMP2 = SPV*(1./TEMP1-1.)/V2
      PMSTAR = SQRT(PSTAR(1)**2+PSTAR(2)**2+PSTAR(3)**2)
      TSTAR=SQRT(PMSTAR**2+CM**2)-CM
      P(1) = PSTAR(1)+V(1)*TEMP2+V(1)*(TSTAR+CM)/TEMP1
      P(2) = PSTAR(2)+V(2)*TEMP2+V(2)*(TSTAR+CM)/TEMP1
      P(3) = PSTAR(3)+V(3)*TEMP2+V(3)*(TSTAR+CM)/TEMP1
      PM = SQRT(P(1)**2+P(2)**2+P(3)**2)
      IF (PM.GT.1.E-30) THEN
          CT = P(3)/PM
          TEMP4 = 1.-CT**2
          IF(TEMP4.GT.0.0) THEN
              ST = SQRT(TEMP4)
              TEMP3 = PM*ST  
              CFI=P(1)/TEMP3
              SFI=P(2)/TEMP3
          ELSE  ! FORWARD DIRECTION
              CT=1.
              CFI=1.
              SFI=0.
              ST=0.
          ENDIF
      ELSE    ! BECAUSE PM TOO LOW
          CT=1.
          CFI=1.
          SFI=0.
          ST=0.
      ENDIF
      T = SQRT(PM**2+CM**2)-CM
      RETURN
         END


      SUBROUTINE CMS(P,V,PSTART,T,CM)
      DIMENSION P(3),V(3),PSTART(3)
      V2=V(1)**2+V(2)**2+V(3)**2
      TEMP1=SQRT(1.-V2)
      SPV=P(1)*V(1)+P(2)*V(2)+P(3)*V(3)
      TEMP2=SPV/V2*(1./TEMP1-1.)
      SV=(T+CM)/TEMP1
      PSTART(1)=P(1)+V(1)*TEMP2+V(1)*SV
      PSTART(2)=P(2)+V(2)*TEMP2+V(2)*SV
      PSTART(3)=P(3)+V(3)*TEMP2+V(3)*SV
      RETURN
      END


      FUNCTION COSEL (L,MQ,KSI,T,CM)
C     BLOCK OF COSINUS CALCULATION FOR ELASTIC SCATTERING.

      real vran(1)

      IF (L) 10,13,10
   10 IF (T-0.45) 11,11,12
   11 COSEL = COSTA(12,T)
      RETURN
   12 COSEL = COSTA(13,T)
      RETURN
   13 IF (MQ-2) 24,14,14
   14 IF (KSI-2) 17,15,15
   15 IF (T-0.97) 16,16,19
   16 COSEL = COSTA(3,T)
      RETURN
   17 IF (T-0.46) 18,18,19
 18   call ranmar(vran,1)
      COSEL = 1.-2.*vran(1)
      RETURN
   19 IF (T-2.8) 20,20,21
   20 COSEL = (1.+COSTA(1,T))/2.
      RETURN
   21 IF (T-10.) 22,22,23
   22 COSEL = (3.-COSTA(2,T))/4.
      RETURN
   23 TMAX = SQRT(T*(T+2.*CM))
      call ranmar(vran,1)
      COSEL=1.+(2.*ALOG(1.+vran(1)*(EXP(-8.7*TMAX)-1.)))/(8.7*TMAX)
      RETURN
   24 IF (KSI-2) 25,34,43
   25 IF (T-0.08) 26,26,27
   26 COSEL = COSTA(4,T)
      RETURN
   27 IF (T-0.3) 28,28,29
   28 COSEL = COSTA(5,T)
      RETURN
   29 IF (T-1.) 30,30,31
   30 COSEL = COSTA(6,T)
      RETURN
   31 IF (T-2.4) 32,32,33
   32 COSEL = COSTA(7,T)
      RETURN
   33 TMAX = SQRT(T*(T+2.*CM))
      call ranmar(vran,1)
      COSEL=1.+(2.*ALOG(1.+vran(1)*(EXP(-7.5*TMAX)-1.)))/(7.5*TMAX)
      RETURN
   34 IF (T-0.08) 35,35,36
   35 COSEL = COSTA(8,T)
      RETURN
   36 IF (T-0.3) 37,37,38
   37 COSEL = COSTA(9,T)
      RETURN
   38 IF (T-1.0) 39,39,40
   39 COSEL = COSTA(10,T)
      RETURN
   40 IF (T-2.4) 41,41,42
   41 COSEL = COSTA(11,T)
      RETURN
   42 TMAX = SQRT(T*(T+2.*CM))
      call ranmar(vran,1)
      COSEL=1.+(2.*ALOG(1.+vran(1)*(EXP(-7.5*TMAX)-1.)))/(7.5*TMAX)
      RETURN
 43   call ranmar(vran,1)
      IF (vran(1)-0.5) 25,25,34
         END


      FUNCTION COSEX (L,T,CM)
C     BLOCCK OF COSINUS CALCULATION FOR CHARGE EXCHANGE SCATTERING.

      real vran(1)

      IF (L) 10,11,10
   10 IF (T-0.51) 23,23,12
   23 COSEX = COSTA(14,T)
      RETURN
   12 IF (T-1.) 13,13,14
   13 COSEX = COSTA(15,T)
      RETURN
   14 COSEX = COSTA(16,T)
      RETURN
   11 IF (T-0.08) 15,15,16
   15 COSEX = COSTA(17,T)
      RETURN
   16 IF (T-0.3) 17,17,18
   17 COSEX = COSTA(18,T)
      RETURN
   18 IF (T-1.0) 19,19,20
   19 COSEX = COSTA(10,T)
      RETURN
   20 IF (T-2.4) 21,21,22
   21 COSEX = COSTA(11,T)
      RETURN
   22 TMAX = SQRT(T*(T+2.*CM))
      call ranmar(vran,1)
      COSEX=1.+(2.*ALOG(1.+vran(1)*(EXP(-7.5*TMAX)-1.)))/
     1(7.5*TMAX)
      RETURN
         END


      FUNCTION COSTA (J,T)
C     BLOCK OF COSINUS CALCULATION.
      COMMON/COEFA/ANKJ
      DIMENSION ANKJ(4,4,29),ANK(4,4)

      real vran(1)

      DO 10 K=1,4
      DO 10 N=1,4
      ANK(N,K) = ANKJ(N,K,J)
   10 CONTINUE
      S1=0.
      call ranmar(vran,1)
      R1=vran(1)
      S2=0.
      IF((T.GT.0.0).AND.(R1.GT.0.0)) THEN
          DO 11 N=1,4
          DO 11 K=1,4
            S1 = S1+ANK(N,K)*(T**(K-1))*(R1**(N-1))
   11     CONTINUE
      ELSE
            S1 = ANK(1,1)+ANK(2,1)*R1+ANK(3,1)*R1**2+ANK(4,1)*R1**3
      ENDIF
      IF(T.GT.0.0) THEN 
         DO 12 N=1,4
         DO 12 K=1,4
           S2 = S2+ANK(N,K)*T**(K-1)
   12    CONTINUE
      ELSE
           S2 = ANK(1,1)+ANK(2,1)+ANK(3,1)+ANK(4,1)
      ENDIF
      CTA = 2.*SQRT(R1)*(S1+(1.-S2)*R1**4)-1.
      TEMP1 = ABS(CTA)
      IF (TEMP1-1.) 13,13,14
   13 COSTA=CTA
      RETURN
   14 COSTA=SIGN(1.,CTA)
      RETURN
         END


      SUBROUTINE DIRECT (V,U,TIN1,MQ,MV,NP,PARTIN,KP,ITH)
C     DETERMINING OF DIRECTION OF SECONDARY PARTICLES MOTION.
      DIMENSION PMEMO(9,100),IMEMO(9,100),V(3),PAKV(3),PARTIN(9),
     1PLST(3),PL(3),PAKST(3),PIN(3)
      COMMON/MEMORY/PMEMO,IMEMO

      real vran(1)

      ND = 0
      KP = 0
      IF (MQ-1) 10,12,10
 10   call ranmar(vran,1)
      IF(vran(1)-0.5) 15,11,11
 11   call ranmar(vran,1)
      IF(vran(1)-0.5)14,16,16
 12   call ranmar(vran,1)
      IF(vran(1)-0.5) 14,13,13
 13   call ranmar(vran,1)
      IF(vran(1)-0.5) 15,16,16
   14 M1 = 2
      M2 = 3
      GO TO 17
   15 M1 = 1
      M2 = 3
      GO TO 17
   16 M1 = 1
      M2 = 2
      GO TO 17
   17 LAMBDA=1
      PAKV(1)=0
      PAKV(2)=0
      PAKV(3)=0
      M1TEMP=MV+M1
      M2TEMP=MV+M2
   18 LTEMP=MV+LAMBDA
      IF (LAMBDA-M1) 19,21,19
   19 IF (LAMBDA-M2) 20,21,20
   20 JA = JTYPA(ITH,MQ,LAMBDA)
      CTL = COSTA(JA,TIN1)
      call ranmar(vran,1)
      FL = 6.283185*vran(1)
      STL = SQRT(1.-CTL**2)
      TEMP1=COS(FL)
      TEMP2=SIN(FL)
      TEMP3=PMEMO(4,LTEMP)
      PMEMO(1,LTEMP) = TEMP3*STL*TEMP1
      PMEMO(2,LTEMP) = TEMP3*STL*TEMP2
      PMEMO(3,LTEMP) = TEMP3*CTL
      PAKV(1) = PAKV(1)+PMEMO(1,LTEMP)
      PAKV(2) = PAKV(2)+PMEMO(2,LTEMP)
      PAKV(3) = PAKV(3)+PMEMO(3,LTEMP)
   21 IF (LAMBDA-NP) 22,23,23
   22 LAMBDA=LAMBDA+1
      GO TO 18
   23 PAKVM=SQRT(PAKV(1)**2+PAKV(2)**2+PAKV(3)**2)
      IF (NP-3) 25,24,25
   24 V2 = V(1)**2+V(2)**2+V(3)**2
      TEMP4 = SQRT(PARTIN(8)*(PARTIN(8)+2.*PARTIN(9)))
      SPV = TEMP4*PARTIN(4)*PARTIN(7)*V(1)+TEMP4*PARTIN(5)*V(3)+
     1TEMP4*PARTIN(4)*PARTIN(6)*V(2)
      TEMP5 = SPV*(1./SQRT(1.-V2)-1.)/V2
      TEMP6 = (PARTIN(8)+PARTIN(9))/SQRT(1.-V2)
      PIN(1) = TEMP4*PARTIN(4)*PARTIN(7)+V(1)*TEMP5-V(1)*TEMP6
      PIN(2) = TEMP4*PARTIN(4)*PARTIN(6)+V(2)*TEMP5-V(2)*TEMP6
      PIN(3) = TEMP4*PARTIN(5)+V(3)*TEMP5-V(3)*TEMP6
      LAMBDA=1
      GO TO 27
   25 IF (PMEMO(4,M1TEMP)-PAKVM-PMEMO(4,M2TEMP)) 26,32,32
   26 IF(PMEMO(4,M1TEMP)-ABS(PAKVM-PMEMO(4,M2TEMP)))32,32,24
   27 LTEMP = MV+LAMBDA
      IF (LAMBDA-M1) 29,34,29
   28 LAMBDA=LAMBDA+1
      GOTO 27
   29 IF (LAMBDA-M2) 30,34,30
   30 PL(1)=PMEMO(1,LTEMP)
      PL(2)=PMEMO(2,LTEMP)
      PL(3) = PMEMO(3,LTEMP)
      CALL ROTOR (PIN,V,PL,PLST)
      PMEMO(1,LTEMP)=PLST(1)
      PMEMO(2,LTEMP)=PLST(2)
      PMEMO(3,LTEMP) = PLST(3)
   34 IF(LAMBDA-NP) 28,31,31
   31 CALL ROTOR (PIN,V,PAKV,PAKST)
      CTM1 = (PMEMO(4,M2TEMP)**2-PMEMO(4,M1TEMP)**2-PAKVM**2)/
     1(2.*PAKVM*PMEMO(4,M1TEMP))
      CTM2 = (PMEMO(4,M1TEMP)**2-PMEMO(4,M2TEMP)**2-PAKVM**2)/
     1(2.*PAKVM*PMEMO(4,M2TEMP))
      call ranmar(vran,1)
      FM1=6.283185*vran(1)
      FM2=3.141592+FM1
      CFM1=COS(FM1)
        ARG1=1.-CTM1**2
      IF (ARG1.GE.0.0) THEN
         STM1=SQRT(ARG1)
      ELSE
         STM1=0.0
      ENDIF
        ARG2=1.-CTM2**2
      IF (ARG2.GE.0.0) THEN
         STM2=SQRT(ARG2)
      ELSE
         STM2=0.0
      ENDIF
      SFM1=SIN(FM1)
      CFM2=COS(FM2)
      SFM2=SIN(FM2)
      PL(1) = PMEMO(4,M1TEMP)*STM1*CFM1
      PL(2) = PMEMO(4,M1TEMP)*STM1*SFM1
      PL(3) = PMEMO(4,M1TEMP)*CTM1
      CALL ROTOR (PAKST,V,PL,PLST)
      PMEMO(1,M1TEMP)=PLST(1)
      PMEMO(2,M1TEMP)=PLST(2)
      PMEMO(3,M1TEMP) = PLST(3)
      PL(1) = PMEMO(4,M2TEMP)*STM2*CFM2
      PL(2) = PMEMO(4,M2TEMP)*STM2*SFM2
      PL(3) = PMEMO(4,M2TEMP)*CTM2
      CALL ROTOR (PAKST,V,PL,PLST)
      PMEMO(1,M2TEMP)=PLST(1)
      PMEMO(2,M2TEMP)=PLST(2)
      PMEMO(3,M2TEMP) = PLST(3)
      RETURN
   32 ND=ND+1
      IF (ND-100) 17,33,33
   33 KP = 2
      RETURN
         END


      FUNCTION FINT (FNAME,FLIM1,FLIM2,BS,RS)
!
!  GAUSS QUADRATURE METHOD FOR FUNCTION FNAME IN
!  THE REGION [FLIM1,FLIM2]
!    
      COMMON/COHELP/W(8),FIKS(8)
      TEMP = 0.
      DO 30 IT=1,8
      FY = ((FLIM1-FLIM2)*FIKS(IT)+FLIM1+FLIM2)/2.
      TEMP = TEMP+W(IT)*FNAME(FY,BS,RS)
   30 CONTINUE
      FINT = TEMP*(FLIM1-FLIM2)/2.
      RETURN
         END


      FUNCTION FINT1 (FNAME,FLIM1,FLIM2,BS,RS)
!
!  GAUSS QUADRATURE METHOD FOR FUNCTION FNAME IN
!  THE REGION [FLIM1,FLIM2]
!    
      COMMON/COHELP/W(8),FIKS(8)
      TEMP = 0.
      DO 30 IT=1,8
      FY = ((FLIM1-FLIM2)*FIKS(IT)+FLIM1+FLIM2)/2.
      TEMP = TEMP+W(IT)*FNAME(FY,BS,RS)
   30 CONTINUE
      FINT1 = TEMP*(FLIM1-FLIM2)/2.
      RETURN
         END


      FUNCTION S1 (SX,BS,RS)
      S1 = SX/(1.+EXP((SX-RS)/BS))
      RETURN
         END


      FUNCTION S2 (SX,BS,RS)
      S2 = (SX**2)/(1.+EXP((SX-RS)/BS))
      RETURN
         END


      FUNCTION FIS (SXFI,BS,RS)
      EXTERNAL S1,S2
      COMMON/BLNUCL/ANUCL,ZNUCL,EPS,VPI,N,RSM(10),RBIG(10),RHOP(10),
     *RHON(10),AF(10),TFP(10),TFN(10)
      FIS=(FINT1(S2,SXFI,0.0,BS,RS)/SXFI+FINT1(S1,RSM(N),0.0,BS,RS)-
     1FINT1(S1,SXFI,0.0,BS,RS))*SXFI**2
      RETURN
         END


      FUNCTION SPECTR (T1,T2,IBEAM)
C
C     BREMSSTRAHLUNG (OR OTHER TYPE) GAMMA ENERGY SPECTRUM
C     TO BE SELECTED                
C
      real vran(1)

      IF (IBEAM.EQ.0) THEN
C ***    Select the energy of tagged gamma quanta in accordance with
C ***    average energy and width
         CALL NORRAN(RND)
         ETAG=(T1+T2)/2.
         FWHM=T2-T1
         ENERGY = (ETAG + .425*FWHM*RND)
      ELSEIF(IBEAM.EQ.1) THEN
C ***    Select the energy of gamma quanta in accordance with CBC
C ***    spectrum, tabulated in the PROFILES subroutine.
         ENERGY = HRNDM1(610) ! From cambridge bubble chamber experiment
      ELSEIF (IBEAM.EQ.2) THEN
C ***    Select the energy of gamma quanta in accordance with bremsstrahlung
C ***    spectra. In this case ETAG is the maximum energy of such a spectrum.
                         ! PURE BREMSSTRAHLUNG  ....
         call ranmar(vran,1)
         TEMP1 = vran(1)
         ENERGY = T1*(T2/T1)**TEMP1
      ELSEIF (IBEAM.EQ.3) THEN
C ***    Select the energy of gamma quanta in accordance with rectangular
C ***    distribution in this case T1 and T2 are boundaries of the spectrum.
         call ranmar(vran,1)
         ENERGY = T1+(T2-T1)*vran(1)
      ELSE
         STOP ' UNKNOW BEAM TYPE: PROGRAM STOPPED IN FUNCTION SPECTR'
      ENDIF
         CALL HFILL(1000,ENERGY,0.,1.)
         SPECTR=ENERGY
 
      RETURN
         END


      SUBROUTINE ISOBAR (U,V,TIN1,PARTIN,IPATNE,MV,NP)
C     DETERMINING OF SECONDARY PARTICLES CHARACTERISTICS FOR GAMMA-N
C     INTERACTION WITH (3/2,3/2) ISOBAR PRODUCTION.
      DIMENSION VT(3),PPIM(3),PPT(3),PPIT(3),PPI(3),PP(3),PIN(3),
     1PINST(3),PPIMST(3),PPIST(3),PPST(3),PMEMO(9,100),IMEMO(9,100),
     2PARTIN(9),IPATNE(5),V(3)
      COMMON/MEMORY/PMEMO,IMEMO

      real vran(1)

      A1 = (U**2+0.0196-1.08**2)/(2.*U)
      A2 = SQRT(A1**2-.0196)
      A3 = U-A1
      F1 = A1*A2*A3/U
      ALPHA = 200.*F1
 10   call ranmar(vran,1)
      BMS = vran(1)*(U-1.22)+1.08
      EPIM = (U**2+0.0196-BMS**2)/(2.*U)
      EDN = U-EPIM
      PIM = SQRT(EPIM**2-0.0196)
      F = (PIM*EPIM*EDN)/U
      TS = (BMS**2-1.08**2)/1.88
      P = F*QINTS(TS,9)/ALPHA
      call ranmar(vran,1)
      IF (vran(1)-P) 11,10,10
   11 TPI = EPIM-0.14
      IF (TIN1-1.) 12,13,13
   12 CTPI = COSTA(28,TIN1)
      GO TO 14
   13 CTPI = COSTA(29,TIN1)
      GO TO 14
 14   call ranmar(vran,1)
      FIPI = 6.283185*vran(1)
      EPIT = (BMS**2+0.0196-0.94**2)/(2.*BMS)
      ENT = BMS-EPIT
      TEMP1 = SQRT(1.-CTPI**2)
      PPIM(1) = PIM*TEMP1*COS(FIPI)
      PPIM(2) = PIM*TEMP1*SIN(FIPI)
      PPIM(3) = PIM*CTPI
      TEMP2 = TPI+0.14-U
      VT(1) = PPIM(1)/TEMP2
      VT(2) = PPIM(2)/TEMP2
      VT(3) = PPIM(3)/TEMP2
      call ranmar(vran,1)
      CTILPI=1.-2.*vran(1)
      call ranmar(vran,1)
      FTILPI=6.283185*vran(1)
      TEMP1 = SQRT(1.-CTILPI**2)
      PMT = SQRT(EPIT**2-0.0196)
      PPIT(1) = PMT*TEMP1*COS(FTILPI)
      PPIT(2) = PMT*TEMP1*SIN(FTILPI)
      PPIT(3) = PMT*CTILPI
      TPI = EPIT-0.14
      VT(1)=-VT(1)
      VT(2)=-VT(2)
      VT(3)=-VT(3)
      CALL CMS (PPIT,VT,PPI,TPI,0.14)
      PPT(1) = -PPIT(1)
      PPT(2) = -PPIT(2)
      PPT(3) = -PPIT(3)
      TN = ENT-0.94
      CALL CMS (PPT,VT,PP,TN,0.94)
      TEMP2 = SQRT(PARTIN(8)*(PARTIN(8)+2.*PARTIN(9)))
      PIN(1)=TEMP2*PARTIN(4)*PARTIN(7)
      PIN(2)=TEMP2*PARTIN(4)*PARTIN(6)
      PIN(3) = TEMP2*PARTIN(5)
      CALL CMS(PIN,V,PINST,PARTIN(8),PARTIN(9))
      CALL ROTOR(PINST,V,PPIM,PPIMST)
      PMEMO(1,MV+1) = PPIMST(1)
      PMEMO(2,MV+1) = PPIMST(2)
      PMEMO(3,MV+1) = PPIMST(3)
      PMEMO(9,MV+1) = 0.14
      CALL ROTOR(PINST,V,PPI,PPIST)
      PMEMO(1,MV+2) = PPIST(1)
      PMEMO(2,MV+2) = PPIST(2)
      PMEMO(3,MV+2) = PPIST(3)
      PMEMO(9,MV+2) = 0.14
      CALL ROTOR(PINST,V,PP,PPST)
      PMEMO(1,MV+3) = PPST(1)
      PMEMO(2,MV+3) = PPST(2)
      PMEMO(3,MV+3) = PPST(3)
      PMEMO(9,MV+3) = 0.94
      IF (IPATNE(1)) 15,15,16
   16 IMEMO(1,MV+1) = -1
      IMEMO(2,MV+1) = 0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 0
      IMEMO(1,MV+2) = 1
      IMEMO(2,MV+2) = 0
      IMEMO(3,MV+2) = 0
      IMEMO(4,MV+2) = 0
      IMEMO(1,MV+3) = 1
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = 0
      IMEMO(4,MV+3) = 1
      NP = 3
      RETURN
   15 IMEMO(1,MV+1) = 1
      IMEMO(2,MV+1) = 0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 0
      IMEMO(1,MV+2) = -1
      IMEMO(2,MV+2) = 0
      IMEMO(3,MV+2) = 0
      IMEMO(4,MV+2) = 0
      IMEMO(1,MV+3) = 0
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = 0
      IMEMO(4,MV+3) = 1
      NP = 3
      RETURN
         END


      FUNCTION JTYPA (ITH,MQ,LAMB)
C     DETERMINING OF TYPE OF COEFFICIENTS A(N,K).
      IF (ITH) 10,18,10
   10 IF (MQ-1) 14,11,14
   11 IF (LAMB-1) 13,13,12
   12 JTYPA = 25
      RETURN
   13 JTYPA = 24
      RETURN
   14 IF (LAMB-1) 16,16,15
   15 IF (LAMB-3) 17,16,17
   16 JTYPA = 20
      RETURN
   17 JTYPA = 21
      RETURN
   18 IF (MQ-1) 22,19,22
   19 IF (LAMB-1) 20,20,21
   20 JTYPA = 26
      RETURN
   21 JTYPA = 27
      RETURN
   22 IF (LAMB-1) 24,24,23
   23 IF (LAMB-3) 25,24,25
   24 JTYPA = 22
      RETURN
   25 JTYPA = 23
      RETURN
         END


      FUNCTION JTYPB (ITH,MQ,LAMB)
      IMPLICIT REAL*8(A-H,O-Z)
C     DETERMINING OF TYPE OF COEFFICIENTS B(N,K).
      IF (ITH) 10,18,10
   10 IF (MQ-1) 14,11,14
   11 IF (LAMB-1) 13,13,12
   12 JTYPB = 6
      RETURN
   13 JTYPB = 5
      RETURN
   14 IF (LAMB-1) 16,16,15
   15 IF (LAMB-3) 17,16,17
   16 JTYPB=1
      RETURN
   17 JTYPB = 2
      RETURN
   18 IF (MQ-1) 22,19,22
   19 IF (LAMB-1) 20,20,21
   20 JTYPB = 7
      RETURN
   21 JTYPB = 8
      RETURN
   22 IF (LAMB-1) 24,24,23
   23 IF (LAMB-3) 25,24,25
   24 JTYPB = 3
      RETURN
   25 JTYPB = 4
      RETURN
         END


      FUNCTION PMOM (J,T)
C     BLOCK OF CALCULATION OF SECONDARY PARTICLES MOMENTUM.
      COMMON/COEFBC/BNKJ,CKJ
      DIMENSION BNKJ(4,4,8),CKJ(3,8),BNK(4,4)

      real vran(1)

      DO 10 K=1,4
      DO 10 N=1,4
      BNK(N,K) = BNKJ(N,K,J)
   10 CONTINUE
      S1 = 0.
      call ranmar(vran,1)
      R1 = vran(1)
      S2 = 0.
      S3 = 0.
      IF((T.GT.0.0).AND.(R1.GT.0.0)) THEN
         DO 11 N=1,4
         DO 11 K=1,4
       S1 = S1+BNK(N,K)*(T**(K-1))*(R1**(N-1))
   11    CONTINUE
      ELSE
       S1 = BNK(1,1)+BNK(2,1)*R1+BNK(3,1)*R1**2+BNK(4,1)*R1**3
      ENDIF
      IF(T.GT.0.0) THEN
         DO 12 N=1,4
         DO 12 K=1,4
           S2 = S2+BNK(N,K)*T**(K-1)
   12    CONTINUE
        DO 13 K=1,3
          S3 = S3+CKJ(K,J)*T**(K-1)
   13   CONTINUE
      ELSE
           S2 = BNK(1,1)+BNK(2,1)+BNK(3,1)+BNK(4,1)
           S3 = CKJ(1,J)
      ENDIF
      PMOM = S3*SQRT(R1)*(S1+(1.-S2)*R1**4)
      RETURN
         END



      SUBROUTINE ROTOR(AR,BR,PSTAR,PR)
C
C    Make a rotation from the system with Z-axis along AR vector
C    to the system with Z-axis along BR vector.
C    PSTAR is an input vector, PR (output) is the same vector in 
C    the second system.
C
      DIMENSION AR(3),BR(3),PSTAR(3),PR(3),AN(3)
      SP = 0.
      DO 31 IR=1,3
      SP = SP+AR(IR)*BR(IR)
   31 CONTINUE
      AMOD = SQRT(AR(1)**2+AR(2)**2+AR(3)**2)
      ALPHA1 = SP/AMOD
      BMOD2 = BR(1)**2+BR(2)**2+BR(3)**2
      ARGUMENT=BMOD2-ALPHA1**2
      IF(ARGUMENT.GT.0.0) THEN
        ALPHA2 = SQRT(ARGUMENT)
      ELSE
        ALPHA2 = 0.0
      ENDIF
      IF (ALPHA2.LE.1.E-4) GO TO 32
      AN(1) = AR(2)*BR(3)-AR(3)*BR(2)
      AN(2) = AR(3)*BR(1)-AR(1)*BR(3)
      AN(3) = AR(1)*BR(2)-AR(2)*BR(1)
      PR(1)=PSTAR(1)*BR(1)/ALPHA2+(PSTAR(3)-ALPHA1*PSTAR(1)/ALPHA2)
     1*AR(1)/AMOD+(PSTAR(2)*AN(1))/(ALPHA2*AMOD)
      PR(2)=PSTAR(1)*BR(2)/ALPHA2+(PSTAR(3)-ALPHA1*PSTAR(1)/ALPHA2)
     1*AR(2)/AMOD+(PSTAR(2)*AN(2))/(ALPHA2*AMOD)
      PR(3)=PSTAR(1)*BR(3)/ALPHA2+(PSTAR(3)-ALPHA1*PSTAR(1)/ALPHA2)
     1*AR(3)/AMOD+(PSTAR(2)*AN(3))/(ALPHA2*AMOD)
      RETURN
 32   PR(1)=PSTAR(1)   
      PR(2)=PSTAR(2)   
      PR(3)=PSTAR(3)   
      RETURN
      END



      SUBROUTINE STAT (U,V,PARTIN,IPATNE,MV,NP)
C     DETERMINING OF SECONDARY PARTICLES CHARACTERISTICS FOR
C     GAMMA-N INTERACTION WITH STATISTICAL MODEL.
      DIMENSION V(3),PV1(3),PV2(3),PV3(3),PS1(3),PS2(3),PS3(3),PIN(3),
     1PINST(3),PMEMO(9,100),IMEMO(9,100),PARTIN(9),IPATNE(5)
      COMMON/MEMORY/PMEMO,IMEMO

      real vran(1)

      EPIM = (U**2+0.0196-1.08**2)/(2.*U)
      TPIM = EPIM-0.14
 10   call ranmar(vran,1)
      T1 = vran(1)*TPIM
      call ranmar(vran,1)
      T2 = vran(1)*TPIM
      E1 = T1+0.14
      E2 = T2+0.14
      call ranmar(vran,1)
      IF(vran(1)-27.*E1*E2*(U-E1-E2)/(U**3))11,10,10
   11 E3 = U-E1-E2
      T3 = E3-0.94
      IF (T3) 10,10,23
   23 P1 = SQRT(T1*(T1+0.28))
      P2 = SQRT(T2*(T2+0.28))
      P3 = SQRT(T3*(T3+1.88))
      TEMP1 = (P1+P2-P3)*(P1-P2+P3)*(P2+P3-P1)
      IF (TEMP1) 10,10,12
 12   call ranmar(vran,1)
      CT3 = 1.-2.*vran(1)
      call ranmar(vran,1)
      FI3 = 6.283185*vran(1)
      TEMP2 = SQRT(1.-CT3**2)
      PV3(1) = P3*TEMP2*COS(FI3)
      PV3(2) = P3*TEMP2*SIN(FI3)
      PV3(3) = P3*CT3
      TEMP3=SQRT(PARTIN(8)*(PARTIN(8)+2.*PARTIN(9)))
      PIN(1)=TEMP3*PARTIN(4)*PARTIN(7)
      PIN(2)=TEMP3*PARTIN(4)*PARTIN(6)
      PIN(3) = TEMP3*PARTIN(5)
      CALL CMS(PIN,V,PINST,PARTIN(8),PARTIN(9))
      CALL ROTOR (PINST,V,PV3,PS3)
      CT1 = (P2**2-P1**2-P3**2)/(2.*P3*P1)
      CT2 = (P1**2-P2**2-P3**2)/(2.*P3*P2)
      call ranmar(vran,1)
      FI1 = 6.283185*vran(1)
      FI2 = 3.141592+FI1
      ST1 = SQRT(1.-CT1**2)
      ST2 = SQRT(1.-CT2**2)
      PV1(1) = P1*ST1*COS(FI1)
      PV1(2) = P1*ST1*SIN(FI1)
      PV1(3) = P1*CT1
      CALL ROTOR (PS3,V,PV1,PS1)
      PV2(1) = P2*ST2*COS(FI2)
      PV2(2) = P2*ST2*SIN(FI2)
      PV2(3) = P2*CT2
      CALL ROTOR (PS3,V,PV2,PS2)
      PMEMO(1,MV+1) = PS1(1)
      PMEMO(2,MV+1) = PS1(2)
      PMEMO(3,MV+1) = PS1(3)
      PMEMO(9,MV+1) = 0.14
      PMEMO(1,MV+2) = PS2(1)
      PMEMO(2,MV+2) = PS2(2)
      PMEMO(3,MV+2) = PS2(3)
      PMEMO(9,MV+2) = 0.14
      PMEMO(1,MV+3) = PS3(1)
      PMEMO(2,MV+3) = PS3(2)
      PMEMO(3,MV+3) = PS3(3)
      PMEMO(9,MV+3) = 0.94
      IF (IPATNE(1)) 24,24,17
 24   call ranmar(vran,1)
      TEMP4 = vran(1)
      IF (TEMP4-1./3.) 14,14,13
   13 IF (TEMP4-2./3.) 15,15,16
   14 IMEMO(1,MV+1) = 0
      IMEMO(2,MV+1) = 0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 0
      IMEMO(1,MV+2) = 0
      IMEMO(2,MV+2) = 0
      IMEMO(3,MV+2) = 0
      IMEMO(4,MV+2) = 0
      IMEMO(1,MV+3) = 0
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = 0
      IMEMO(4,MV+3) = 1
      GO TO 22
   15 IMEMO(1,MV+1) = 0
      IMEMO(2,MV+1) = 0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 0
      IMEMO(1,MV+2) = -1
      IMEMO(2,MV+2) = 0
      IMEMO(3,MV+2) = 0
      IMEMO(4,MV+2) = 0
      IMEMO(1,MV+3) = 1
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = 0
      IMEMO(4,MV+3) = 1
      GO TO 22
   16 IMEMO(1,MV+1) = -1
      IMEMO(2,MV+1) = 0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 0
      IMEMO(1,MV+2) = 1
      IMEMO(2,MV+2) = 0
      IMEMO(3,MV+2) = 0
      IMEMO(4,MV+2) = 0
      IMEMO(1,MV+3) = 0
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = 0
      IMEMO(4,MV+3) = 1
      GO TO 22
 17   call ranmar(vran,1)
      TEMP4 = vran(1)
      IF (TEMP4-1./3.) 19,19,18
   18 IF (TEMP4-2./3.) 20,20,21
   19 IMEMO(1,MV+1) = 0
      IMEMO(2,MV+1) = 0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 0
      IMEMO(1,MV+2) = 0
      IMEMO(2,MV+2) = 0
      IMEMO(3,MV+2) = 0
      IMEMO(4,MV+2) = 0
      IMEMO(1,MV+3) = 1
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = 0
      IMEMO(4,MV+3) = 1
      GO TO 22
   20 IMEMO(1,MV+1) = 0
      IMEMO(2,MV+1) = 0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 0
      IMEMO(1,MV+2) = 1
      IMEMO(2,MV+2) = 0
      IMEMO(3,MV+2) = 0
      IMEMO(4,MV+2) = 0
      IMEMO(1,MV+3) = 0
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = 0
      IMEMO(4,MV+3) = 1
      GO TO 22
   21 IMEMO(1,MV+1) = 1
      IMEMO(2,MV+1) = 0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 0
      IMEMO(1,MV+2) = -1
      IMEMO(2,MV+2) = 0
      IMEMO(3,MV+2) = 0
      IMEMO(4,MV+2) = 0
      IMEMO(1,MV+3) = 1
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = 0
      IMEMO(4,MV+3) = 1
      GO TO 22
   22 NP = 3
      RETURN
         END


      SUBROUTINE TINVU (TIN,CMIN,TN,CMN,SINTIN,COSTIN,SINFIN,COSFIN,
     1SINTN,COSTN,SINFN,COSFN,V,U,TIN1)
C     BLOCK OF CALCULATION T,V,U.
      DIMENSION V(3)
      PIN = SQRT(TIN*(TIN+2.*CMIN))
      PINX = PIN*SINTIN*COSFIN
      PINY = PIN*SINTIN*SINFIN
      PINZ = PIN*COSTIN
      PN = SQRT(TN*(TN+2.*CMN))
      PNX = PN*SINTN*COSFN
      PNY = PN*SINTN*SINFN
      PNZ = PN*COSTN
      EIN = TIN+CMIN
      EN = TN+CMN
      V(1) = (PINX+PNX)/(EIN+EN)
      V(2) = (PINY+PNY)/(EIN+EN)
      V(3) = (PINZ+PNZ)/(EIN+EN)
      V2 = V(1)**2+V(2)**2+V(3)**2
      U = (SQRT(1.-V2))*(EIN+EN)
      TIN1 = (U**2-(CMIN+CMN)**2)/(2.*CMN)
      RETURN
         END


      SUBROUTINE VMNSP (PARTIN,IPATIN,U,MV,NP,ITH,MQ,TIN1,LP)
C
C     BLOCK OF CALCULATION OF SECONDARY PARTICLES NUMBER AND
C     DETERMINING ABSOLUTE VALUES OF MOMENTUMS IN INELASTIC INTERACTION.
C
      DIMENSION PMEMO(9,100),IMEMO(9,100),PARTIN(9),IPATIN(9)
      COMMON/MEMORY/PMEMO,IMEMO
      KH = 0
      LP = 0
   10 U1 = U
      LAMBDA = 1
   11 LTEMP = MV+LAMBDA
      IF (LTEMP-100) 37,37,38
   38 NP = 0
      PRINT 39
   39 FORMAT (45X,29H MEMORY IS EXCEEDED IN CASCAD)
      RETURN
   37 CONTINUE
      IF (LAMBDA-1) 12,12,13
   12 PMEMO(9,MV+1)=0.94
      IMEMO(2,MV+1)=0
      IMEMO(3,MV+1)=0
      IMEMO(4,MV+1) = 1
      GO TO 16
   13 IF (LAMBDA-3) 15,14,15
   14 PMEMO(9,MV+3) = PARTIN(9)
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = IPATIN(3)
      IMEMO(4,MV+3) = IPATIN(4)
      GO TO 16
   15 PMEMO(9,LTEMP) = 0.14
      IMEMO(2,LTEMP) = 0
      IMEMO(3,LTEMP) = 0
      IMEMO(4,LTEMP) = 0
      GO TO 16
   16 JB = JTYPB(ITH,MQ,LAMBDA)
      PMEMO(4,LTEMP) = PMOM(JB,TIN1)
      EL = SQRT(PMEMO(4,LTEMP)**2+PMEMO(9,LTEMP)**2)
      DELTU = U1-EL
      IF (LAMBDA-2) 23,17,23
   17 IF (DELTU-PARTIN(9)) 35,35,18
   18 IF (ITH) 19,22,19
   19 PMEMO(4,MV+3) = SQRT(DELTU**2-PARTIN(9)**2)
      PMEMO(9,MV+3) = PARTIN(9)
      IMEMO(2,MV+3) = 0
      IMEMO(3,MV+3) = IPATIN(3)
      IMEMO(4,MV+3) = IPATIN(4)
      IF (PMEMO(4,MV+1)-PMEMO(4,MV+2)-PMEMO(4,MV+3)) 20,20,35
   20 IF (PMEMO(4,MV+1)-ABS(PMEMO(4,MV+2)-PMEMO(4,MV+3))) 35,35,21
   21 NP = 3
      RETURN
   22 U1 = DELTU
      LAMBDA = LAMBDA+1
      GO TO 11
   23 IF (DELTU-0.14) 24,24,22
   24 IF (LAMBDA-1) 35,35,25
   25 IF (LAMBDA-3) 26,35,26
   26 EL = DELTU+EL
      PMEMO(4,LTEMP) = SQRT(EL**2-PMEMO(9,LTEMP)**2)
      NP = LAMBDA
      I = 1
   28 ITEMP = MV+I
      C = PMEMO(4,ITEMP)
   29 IF (NP-I) 34,34,30
   30 IF (C-PMEMO(4,ITEMP+1)) 32,31,31
   31 I = I+1
      GO TO 29
   32 I = I+1
      GO TO 28
   34 PMAX = C
      SIGMA = 0.
      DO 33 I=1,NP
      ITEMP = MV+I
      SIGMA = SIGMA+PMEMO(4,ITEMP)
   33 CONTINUE
      IF (2.*PMAX-SIGMA) 27,35,35
   27 RETURN
   35 KH = KH+1
      IF (KH-100) 10,36,36
   36 LP = 2
      RETURN
      END
