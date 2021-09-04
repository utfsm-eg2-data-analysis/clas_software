
      SUBROUTINE BILD
      COMMON/BLNUCL/ANUCL,ZNUCL,EPS,VPI,N,RSM(10),RBIG(10),RHOP(10),
     *RHON(10),AF(10),TFP(10),TFN(10) 
      COMMON/BLOKC/SPTU(10,250) 
      COMMON/AMPNUCL/AMNUCL(3),PNUCL(3)
      COMMON/KS/KSTART,UP,AP,ZP
      COMMON/TOCHKA/RAN
     */COMCHA/ICHAM(18),ICHAB(18)
C    */COMSTR/ISTR(36)
      COMMON/U1/SUCH,SUPIM,SUPIP,SUPI0
      COMMON/U2/SUOMG,SUETA,SUROM,SURO0,SUROP
      COMMON/U3/SUS,SUG,SUB,SUH,SUSPR
      COMMON/U4/SUPR,SUN,SUFR,SULI,SUD,SUT,SUHE3,SUHE4
      COMMON/U5/SUCHDE,SUPIPDE,SUPIMDE,SUPI0DE
      COMMON/FAST/FASTP,FASTN,AMINUS1,ZMINUS1
      COMMON/ENERGY/ENUCL,EPION,ESTAR,ESTERNX(26),ESTERNY(26)
      COMMON/RESIDUAL/REN(86),REX(86),RMO(86),DELT(86),
     *                DELA(86),DELZ(86),ANG(86),ANM(86)
C
      COMMON/APP2/ APP2_P1(21), APP2_E1(21),APP2_Z1(21,21),
     #            APP2_PM2(21),APP2_PP2(21),APP2_Z2(21,21),
     #            APP2_X(66), APP2_Y(66)
      COMMON/APN2/ APN2_P1(21), APN2_E1(21),APN2_Z1(21,21),
     #            APN2_PM2(21),APN2_PP2(21),APN2_Z2(21,21),
     #            APN2_X(66), APN2_Y(66)
      COMMON/ANN2/ ANN2_P1(21), ANN2_E1(21),ANN2_Z1(21,21),
     #            ANN2_PM2(21),ANN2_PP2(21),ANN2_Z2(21,21),
     #            ANN2_X(66), ANN2_Y(66)
C
      COMMON/PI11/PXPR(66),PYPR(66),PXNE(66),PYNE(66)
      COMMON/PI12/PXPIP(66),PYPIP(66),PXPIM(66),PYPIM(66)
      COMMON/PI13/PXPI0(66),PYPI0(66),PXETA(66),PYETA(66)
      COMMON/PI14/PXOME(66),PYOME(66),PXRO0(66),PYRO0(66)
      COMMON/PI15/PXPIC(66),PYPIC(66)                    
           COMMON/BERLIN/EPX(86),EPY(86),ENX(86),ENY(86),
     #              ECHX(86),ECHY(86),PRONONS,PROLOWNS,
     #EPX20(26), EPY20(26), ENX20(26), ENY20(26), 
     #EPX30(26), EPY30(26), ENX30(26), ENY30(26), 
     #EPX45(26), EPY45(26), ENX45(26), ENY45(26), 
     #EPX60(26), EPY60(26), ENX60(26), ENY60(26), 
     #EPX90(26), EPY90(26), ENX90(26), ENY90(26), 
     #EPX120(26),EPY120(26),ENX120(26),ENY120(26), 
     #EPX160(26),EPY160(26),ENX160(26),ENY160(26),
     #RY20(26),RY30(26),RY45(26),RY60(26),
     #RY90(26),RY120(26),RY160(26),
     #RY(86)
      COMMON/FRAGMENTS/EXD(26),EYD(26),EXT(26),EYT(26),
     #                 EXHE3(26),EYHE3(26),EXHE4(26),EYHE4(26)
      COMMON/HIS1/HXPR(36),HYPR(36),HXNE(36),HYNE(36)
      COMMON/HIS2/HXPIP(36),HYPIP(36),HXPIM(36),HYPIM(36)
      COMMON/HIS3/HXPI0(36),HYPI0(36),HXETA(36),HYETA(36)
      COMMON/HIS4/HXOME(36),HYOME(36),HXRO0(36),HYRO0(36)
      COMMON/COR1/CX11(26),CY11(26),CX12(26),CY12(26)
      COMMON/COR2/CX21(16),CY21(16),CX22(16),CY22(16)

      COMMON/CEBAF/FERMI(66),RADIUS(66),Z_COORD(66),
     #             PART(26),CH_COUNT(26),T_COUNT(26)

      COMMON/MUCAT/SMOMEN(66),DNDPPL(66),DNDPMN(66),
     #             ANGLE(26),DNDTETAPL(26),DNDTETAMN(26),
     #             DEGREES(36),DNDEGPL(36),DNDEGMN(36),
     #             STRIP
C
      COMMON/COR/ CORM(15,30),NORM(15,30)
      COMMON/POGL4/PO(16)
      COMMON/SIG0/SIGOM
      COMMON/BOOK/NICAS,INTEL
      COMMON /GAM_CAS/GAM_CAS
      LOGICAL GAM_CAS
      DIMENSION PPOGLX(10),PPOGLY(10),
     *PPOGLZ(10),PPOGL(10),TPOGL(10),IP(10)
      DIMENSION V(3),PAKV(3),PL(3),PXR(3),PYR(3),PZR(3),IKR(3)
      REAL*8 MAR,PXR,PYR,PZR
      CHARACTER*80 CHTITL
      real cosdd,acosdd
C
        PPR=1.2 
        PPI=1.2 
        NPOGL=0
C
        TPI=0.055
        TPR1=0.026
        TPR2=0.400 
C
    	UCH=0.
           ETOT_C=0.
           PMX=0.
           PMY=0.
           PMZ=0.
           PPX=0.
           PPY=0.
           PPZ=0.
	UPIM=0.
	UPIP=0.
	UPI0=0.
C
        UOMG=0.
	UETA=0.
	UROM=0.
	URO0=0.
	UROP=0.
C
    	US=0.
	UG=0.
	UB=0.
	UH=0.	
        USPR=0.
C
        UPR=0.
	UN=0.
	   UFR=0.
           UD=0.
           UT=0.
           UHE3=0.
           UHE4=0.
           ULI=0.
C
	UCHDE=0.
	UPIPDE=0.
	UPIMDE=0.
        UPI0DE=0.
C
        NS=0
        NG=0
        NB=0
C
        P=SQRT(PNUCL(1)*PNUCL(1)+PNUCL(2)*PNUCL(2)+PNUCL(3)*PNUCL(3))
        AMN=SQRT(AMNUCL(1)*AMNUCL(1)+AMNUCL(2)*AMNUCL(2)+
     *  AMNUCL(3)*AMNUCL(3))
        DA=ANUCL-AP+0.1
      IF((IFIX(AP).EQ.IFIX(ANUCL-1.)).AND.(IFIX(ZP).EQ.IFIX(ZNUCL)))THEN
        AMINUS1=AMINUS1+1.
      ENDIF
      IF((IFIX(AP).EQ.IFIX(ANUCL-1.))
     *                 .AND.(IFIX(ZP).EQ.IFIX(ZNUCL-1.)))THEN
        ZMINUS1=ZMINUS1+1.
      ENDIF
  
C***************************************************
        KS=KSTART-1
	DO 10 K=1,KS
        T=SPTU(7,K)
        AM=SPTU(9,K)
        Q=SPTU(8,K)
	CT=SPTU(4,K)
        ST=SQRT(1.-CT*CT)
	SFI=SPTU(5,K)
	CFI=SPTU(6,K)
        NUM=IFIX(SPTU(10,K))
C
        P=SQRT(T*(T+2.*AM))
C  
        IF(NUM.EQ.55) GO TO 10
C  
        IF(NUM.EQ.0) GO TO 30
C
        IF(NUM.GT.2) 	GO TO 2

C   PI+ AND PI-    

        IF(NUM.EQ.1) THEN
        CALL HGIVE(720,CHTITL,NX,XMI,XMA,NY,YMI,YMA,NWT,LOC)
        TETA_STEP=(XMA-XMI)/NX
        P_STEP=(YMA-YMI)/NY
        TETA=ACOSDD(CT)
        POS=AINT(TETA/TETA_STEP)*TETA_STEP
        IF(GAM_CAS)THEN        
        DENOM=P_STEP*2.*3.1415926*
     #          (COSDD(POS)-COSDD(POS+TETA_STEP))/SIGOM
        ELSE
        DENOM=P_STEP*2.*3.1415926*
     #  (COSDD(POS)-COSDD(POS+TETA_STEP))/(SIGOM*NICAS/INTEL)
        ENDIF
        CALL HFILL(720,TETA,P,1./FLOAT(NICAS)/DENOM)
        ELSEIF(NUM.EQ.2) THEN
        CALL HGIVE(730,CHTITL,NX,XMI,XMA,NY,YMI,YMA,NWT,LOC)
        TETA_STEP=(XMA-XMI)/NX
        P_STEP=(YMA-YMI)/NY
        TETA=ACOSDD(CT)
        POS=AINT(TETA/TETA_STEP)*TETA_STEP
        IF(GAM_CAS)THEN        
        DENOM=P_STEP*2.*3.1415926*
     #          (COSDD(POS)-COSDD(POS+TETA_STEP))/SIGOM
        ELSE
        DENOM=P_STEP*2.*3.1415926*
     #  (COSDD(POS)-COSDD(POS+TETA_STEP))/(SIGOM*NICAS/INTEL)
        ENDIF
        CALL HFILL(730,TETA,P,1./FLOAT(NICAS)/DENOM)
        ENDIF

        UCH=UCH+1.
        EPION=EPION+T+AM
        CALL HIST_2D(P,PXPIC,PYPIC,66,1.0)
        CALL HIST_2D(T*1000.0,ECHX,ECHY,86,1.0)
         ETOT_C=ETOT_C+T+AM
         PMX=PMX+P*ST*CFI
         PMY=PMY+P*ST*SFI
         PMZ=PMZ+P*CT
        IF (Q.GT.0.) GO TO 11
        UPIM= UPIM+1. 
        CALL HIST_2D(P,PXPIM,PYPIM,66,1.0)
        IF(P.GT.0.070) THEN   ! BUBBLE CHAMBER RESTRICTIONS   
           CALL HIST_2D(P,SMOMEN,DNDPMN,66,1.0)
           CALL HIST_2D(CT,ANGLE,DNDTETAMN,26,1.0)
           CALL HIST_2D(ACOSDD(CT),DEGREES,DNDEGMN,36,1.0)
        ENDIF
        IF(P.LT.PPI) GO TO 13
        NPOGL=NPOGL+1
        PPOGLX(NPOGL)=P*ST*CFI
        PPOGLY(NPOGL)=P*ST*SFI
        PPOGLZ(NPOGL)=P*CT
        PPOGL(NPOGL)=P
        IP(NPOGL)=2
        TPOGL(NPOGL)=T
C
        GO TO 13
   11   UPIP=UPIP+1. 
        CALL HIST_2D(P,PXPIP,PYPIP,66,1.0)
        IF(P.GT.0.070) THEN   ! BUBBLE CHAMBER RESTRICTIONS   
           CALL HIST_2D(P,SMOMEN,DNDPPL,66,1.0)
           CALL HIST_2D(CT,ANGLE,DNDTETAPL,26,1.0)
           CALL HIST_2D(ACOSDD(CT),DEGREES,DNDEGPL,36,1.0)
        ENDIF
        GO TO 13
  13    IF(T-TPI) 16,16,17
  16    UG=UG+1.
        UH=UH+1.
        NG=NG+1
        GO TO 10

  17    US=US+1.
        NS=NS+1
        GO TO 10
  2   IF(NUM.GT.6) 	GO TO 3
C   KAONS            NUM=3-6
  21   PRINT *,'KAONS'
        GO TO 10
  3   IF(NUM.GT.7) 	GO TO 4
C   PI0              NUM=7
        EPION=EPION+T+AM
        UPI0=UPI0+1. 
        CALL HIST_2D(P,PXPI0,PYPI0,66,1.0)
        GO TO 10
  4   IF(NUM.GT.8) 	GO TO 5
C   ETA              NUM=8
        UETA=UETA+1.
        CALL HIST_2D(P,PXETA,PYETA,66,1.0)
        GO TO 91
  5   IF(NUM.EQ.9) 	GO TO 92
        IF(NUM.GT.11)	GO TO 6
C   RO+ AND RO-      NUM=10-11 
        IF(Q) 51,92,52
   51   UROM=UROM+1.
        GO TO 91
   52   UROP=UROP+1.
        GO TO 91 
  6   IF(NUM.GT.15)	GO TO 7
C   KAONS*           NUM=12-15
        GO TO 91
  7   IF(NUM.GT.16)	GO TO 8
C   RO0              NUM=16
        URO0=URO0+1.
        CALL HIST_2D(P,PXRO0,PYRO0,66,1.0)
        GO TO 91
  8   IF(NUM.GT.17)	GO TO 9
C   OMEGA            NUM=17  
        UOMG=UOMG+1.  
        CALL HIST_2D(P,PXOME,PYOME,66,1.0)
        GO TO 91
  9   IF(NUM.EQ.18.OR.NUM.GT.38)	GO TO 92
C   NUCLEON 
        IF(NUM.EQ.38)GO TO 81  
C   PROTON           NUM=37          
  19    CALL HGIVE(710,CHTITL,NX,XMI,XMA,NY,YMI,YMA,NWT,LOC)
        TETA_STEP=(XMA-XMI)/NX
        P_STEP=(YMA-YMI)/NY
        TETA=ACOSDD(CT)
        POS=AINT(TETA/TETA_STEP)*TETA_STEP
        IF(GAM_CAS)THEN        
        DENOM=P_STEP*2.*3.1415926*
     #          (COSDD(POS)-COSDD(POS+TETA_STEP))/SIGOM
        ELSE
        DENOM=P_STEP*2.*3.1415926*
     #  (COSDD(POS)-COSDD(POS+TETA_STEP))/(SIGOM*NICAS/INTEL)
        ENDIF
        CALL HFILL(710,TETA,P,1./FLOAT(NICAS)/DENOM)
          CALL HIST_2D(P*1000.0,PXPR,PYPR,66,1.0)
          CALL HIST_2D(T*1000.0,EPX,EPY,86,1.0)
          ENUCL=ENUCL+T
        IF (P.GT.0.240) THEN
           FASTP=FASTP+1.
        ENDIF
        IF((P.GT.3.).AND.(CT.GT.COSDD(4.))) THEN
           STRIP=STRIP+1
        ENDIF

        IF((CT.LE.COSDD(15.)).AND.(CT.GT.COSDD(25.))) THEN
            CALL HIST_2D(T*1000.0,EPX20,EPY20,26,1.0)

        ELSE IF((CT.LE.COSDD(25.)).AND.(CT.GT.COSDD(35.))) THEN
            CALL HIST_2D(T*1000.0,EPX30,EPY30,26,1.0)

        ELSE IF((CT.LE.COSDD(40.)).AND.(CT.GT.COSDD(50.))) THEN
            CALL HIST_2D(T*1000.0,EPX45,EPY45,26,1.0)

        ELSE IF((CT.LE.COSDD(50.)).AND.(CT.GT.COSDD(70.))) THEN
            CALL HIST_2D(T*1000.0,EPX60,EPY60,26,1.0)

        ELSE IF((CT.LE.COSDD(80.)).AND.(CT.GT.COSDD(100.))) THEN
            CALL HIST_2D(T*1000.0,EPX90,EPY90,26,1.0)

        ELSE IF((CT.LE.COSDD(100.)).AND.(CT.GT.COSDD(140.))) THEN
            CALL HIST_2D(T*1000.0,EPX120,EPY120,26,1.0)

        ELSE IF((CT.LE.COSDD(140.)).AND.(CT.GT.COSDD(180.))) THEN
            CALL HIST_2D(T*1000.0,EPX160,EPY160,26,1.0)
        ENDIF

          IF((T.GE.0.0).AND.(P.LE.3.0)) THEN
               PRONONS=PRONONS+1.0
          ENDIF
          IF((T.GE.0.40).AND.(P.LE.3.0)) THEN
               PROLOWNS=PROLOWNS+1.0
          ENDIF

        UPR=UPR+1.
        UCH=UCH+1.
              ETOT_C=ETOT_C+T+AM
              PPX=P*ST*CFI
              PPY=P*ST*SFI
              PPZ=P*CT
C        IF(P.LE.0.) PRINT *,'NUM,AM,P,Q',NUM,AM,P,Q
C
        IF(P.LT.PPR) GO TO 20
        NPOGL=NPOGL+1
C        PRINT *,'POGL PR NPOGL,P',NPOGL,P
        PPOGLX(NPOGL)=P*ST*CFI
        PPOGLY(NPOGL)=P*ST*SFI
        PPOGLZ(NPOGL)=P*CT
        PPOGL(NPOGL)=P
        IP(NPOGL)=37
        TPOGL(NPOGL)=T
C
  20    IF(T-TPR1) 24,24,25
  24    UH=UH+1.
        NB=NB+1
        GO TO 10
  25    IF(T-TPR2) 26,26,27 
  26    UG=UG+1.
        UH=UH+1.
        NG=NG+1
        GO TO 10
  27    US=US+1.
        USPR=USPR+1.
        NS=NS+1
        GO TO 10
C   NEUTRON          NUM=38
  81    CALL HIST_2D(P*1000.0,PXNE,PYNE,66,1.0)
        CALL HIST_2D(T*1000.0,ENX,ENY,86,1.0)
          ENUCL=ENUCL+T
        IF (P.GT.0.240) THEN
           FASTN=FASTN+1.
        ENDIF
        IF((P.GT.3.).AND.(CT.GT.COSDD(4.))) THEN
           STRIP=STRIP+1
        ENDIF

        IF((CT.LE.COSDD(15.)).AND.(CT.GT.COSDD(25.))) THEN
            CALL HIST_2D(T*1000.0,ENX20,ENY20,26,1.0)

        ELSE IF((CT.LE.COSDD(25.)).AND.(CT.GT.COSDD(35.))) THEN
            CALL HIST_2D(T*1000.0,ENX30,ENY30,26,1.0)

        ELSE IF((CT.LE.COSDD(40.)).AND.(CT.GT.COSDD(50.))) THEN
            CALL HIST_2D(T*1000.0,ENX45,ENY45,26,1.0)

        ELSE IF((CT.LE.COSDD(50.)).AND.(CT.GT.COSDD(70.))) THEN
            CALL HIST_2D(T*1000.0,ENX60,ENY60,26,1.0)

        ELSE IF((CT.LE.COSDD(80.)).AND.(CT.GT.COSDD(100.))) THEN
            CALL HIST_2D(T*1000.0,ENX90,ENY90,26,1.0)

        ELSE IF((CT.LE.COSDD(100.)).AND.(CT.GT.COSDD(140.))) THEN
            CALL HIST_2D(T*1000.0,ENX120,ENY120,26,1.0)

        ELSE IF((CT.LE.COSDD(140.)).AND.(CT.GT.COSDD(180.))) THEN
            CALL HIST_2D(T*1000.0,ENX160,ENY160,26,1.0)
        ENDIF


           UN=UN+1.         
          GO TO 10 
   92 CONTINUE 
!    PRINT *,'THIS IS UNCOUNTED PARTICLE WITH NUM,AM,Q ',NUM,AM,Q
        GO TO 10
C    DECAY OF UNSTABLE PARTICLES
   91 CONTINUE
      MAR=AM
      NUR=NUM
      E=T+AM
      PX=P*ST*CFI
      PY=P*ST*SFI
      PZ=P*CT
C      PRINT *,'  DECAY1  E,P,PX,PY,PZ',E,P,PX,PY,PZ 
      V(1)=PX/E
      V(2)=PY/E
      V(3)=PZ/E
      E=0.
      PX=0.
      PY=0.
      PZ=0.
      IF (NUR.EQ.8) GO TO 400
      IF (NUR.EQ.17) GO TO 401
      CALL DECAY(MAR,NUR,IKR,PXR,PYR,PZR,NP)
      GO TO 402
C 
  400 CALL DECETA(MAR,NUR,IKR,PXR,PYR,PZR,NP)
      GO TO 402
C 
  401 CALL DECOME(MAR,NUR,IKR,PXR,PYR,PZR,NP)
      GO TO 402
C
 402  DO 93 KD=1,NP
      JPR=IKR(KD)
      AM=AMREZ(JPR)
      PL(1)=PXR(KD)
      PL(2)=PYR(KD)
      PL(3)=PZR(KD)
      CALL CINEMA(PL,V,PAKV,CT,ST,CFI,SFI,T,AM)      
C
      PX=PX+PAKV(1)
      PY=PY+PAKV(2)
      PZ=PZ+PAKV(3)
      E=E+T+AM
      P=SQRT(T*(T+2.*AM))
C
      IF(JPR.EQ.55) GO TO 93
      Q=ICHAM(JPR)
        IF (Q.EQ.0.)GO TO 97

C   PI+ AND PI-
        CALL HIST_2D(P,PXPIC,PYPIC,66,1.0)
        CALL HIST_2D(T*1000.0,ECHX,ECHY,86,1.0)
        IF(T-TPI) 416,416,417
 416    UG=UG+1.
        UH=UH+1.
        NG=NG+1
        GO TO 94
C 
  417   US=US+1.
        NS=NS+1

   94 UCHDE=UCHDE+1.

        IF(Q.GT.0.)THEN
        CALL HGIVE(720,CHTITL,NX,XMI,XMA,NY,YMI,YMA,NWT,LOC)
        TETA_STEP=(XMA-XMI)/NX
        P_STEP=(YMA-YMI)/NY
        TETA=ACOSDD(CT)
        POS=AINT(TETA/TETA_STEP)*TETA_STEP
        IF(GAM_CAS)THEN        
        DENOM=P_STEP*2.*3.1415926*
     #          (COSDD(POS)-COSDD(POS+TETA_STEP))/SIGOM
        ELSE
        DENOM=P_STEP*2.*3.1415926*
     #  (COSDD(POS)-COSDD(POS+TETA_STEP))/(SIGOM*NICAS/INTEL)
        ENDIF
        CALL HFILL(720,TETA,P,1./FLOAT(NICAS)/DENOM)
        ELSEIF(Q.LT.0.)THEN
        CALL HGIVE(730,CHTITL,NX,XMI,XMA,NY,YMI,YMA,NWT,LOC)
        TETA_STEP=(XMA-XMI)/NX
        P_STEP=(YMA-YMI)/NY
        TETA=ACOSDD(CT)
        POS=AINT(TETA/TETA_STEP)*TETA_STEP
        IF(GAM_CAS)THEN        
        DENOM=P_STEP*2.*3.1415926*
     #          (COSDD(POS)-COSDD(POS+TETA_STEP))/SIGOM
        ELSE
        DENOM=P_STEP*2.*3.1415926*
     #  (COSDD(POS)-COSDD(POS+TETA_STEP))/(SIGOM*NICAS/INTEL)
        ENDIF
        CALL HFILL(730,TETA,P,1./FLOAT(NICAS)/DENOM)
        ENDIF

      IF(Q) 96,97,98
   96 UPIMDE=UPIMDE+1.
           CALL HIST_2D(P,PXPIM,PYPIM,66,1.0)
         IF(P.GT.0.070) THEN   ! BUBBLE CHAMBER RESTRICTIONS   
           CALL HIST_2D(P,SMOMEN,DNDPMN,66,1.0)
         IF(P.NE.0.0) THEN
           COSTETA=PZ/P
         ELSE
           COSTETA=1.0
         ENDIF
       CALL HIST_2D(COSTETA,ANGLE,DNDTETAMN,26,1.0)
       CALL HIST_2D(ACOSDD(CT),DEGREES,DNDEGMN,36,1.0)
        ENDIF
      GO TO 93
   97 UPI0DE=UPI0DE+1.
       EPION=EPION+T+AM
       CALL HIST_2D(P,PXPI0,PYPI0,66,1.0)
      GO TO 93
   98 UPIPDE=UPIPDE+1.
         CALL HIST_2D(P,PXPIP,PYPIP,66,1.0)
        IF(P.GT.0.070) THEN   ! BUBBLE CHAMBER RESTRICTIONS   
         CALL HIST_2D(P,SMOMEN,DNDPPL,66,1.0)
         IF(P.NE.0.0) THEN
           COSTETA=PZ/P
         ELSE
           COSTETA=1.0
         ENDIF
         CALL HIST_2D(COSTETA,ANGLE,DNDTETAPL,26,1.0)
         CALL HIST_2D(ACOSDD(CT),DEGREES,DNDEGPL,36,1.0)
        ENDIF
      GO TO 93
   93 CONTINUE
      P=SQRT(PX**2+PY**2+PZ**2)
C      PRINT *,'  DECAY2  E,P,PX,PY,PZ',E,P,PX,PY,PZ 
      GO TO 10
C
   30 CONTINUE
C
C   FRAGMENTS
	M=INT((AM+0.1)/0.94)
        IF (AM.GT.1.) GO TO 300
        IF (Q.EQ.0.) GO TO 81
        IF (Q.EQ.1.) GO TO 19
C
 300    IF ((M.EQ.2).AND.(Q.EQ.1))    THEN    ! DEUTRON   
           UD=UD+1.
           CALL HIST_2D(T*1000.0,EXD,EYD,26,1.0)

        ELSEIF((M.EQ.3).AND.(Q.EQ.1)) THEN    ! TRITON
           UT=UT+1.
           CALL HIST_2D(T*1000.0,EXT,EYT,26,1.0)

        ELSEIF((M.EQ.3).AND.(Q.EQ.2)) THEN    ! HELIUM-3
           UHE3=UHE3+1.
           CALL HIST_2D(T*1000.0,EXHE3,EYHE3,26,1.0)

        ELSEIF((M.EQ.4).AND.(Q.EQ.2)) THEN    ! HELIUM-4
           UHE4=UHE4+1.
           CALL HIST_2D(T*1000.0,EXHE4,EYHE4,26,1.0)
        ENDIF

        IF(M.EQ.8)ULI=ULI+1.
C        IF(M.EQ.8)PRINT *,'FRAGMENT AM, Q,P ',AM,Q,P
        IF (Q.GT.10.) GO TO 10
        IQ=INT(Q+0.001) 
        GO TO (301,302,303,304,305,306,307,308,309,310),IQ 
 301    IF (P.LE.0.0204) GO TO 10
        GO TO 32
 302    IF (P.LE.0.047) GO TO 10
        GO TO 32
 303    IF (P.LE.0.075) GO TO 10
        GO TO 32
 304    IF (P.LE.0.095) GO TO 10
        GO TO 32
 305    IF (P.LE.0.120) GO TO 10
        GO TO 32
 306    IF (P.LE.0.134) GO TO 10
        GO TO 32
 307    IF (P.LE.0.179) GO TO 10
        GO TO 32
 308    IF (P.LE.0.204) GO TO 10
        GO TO 32
 309    IF (P.LE.0.238) GO TO 10
        GO TO 32
 310    IF (P.LE.0.273) GO TO 10
        GO TO 32

  32	UCH=UCH+1.
        UB=UB+1.
        UH=UH+1.
        NB=NB+1
	UFR=UFR+1.
C
  10    CONTINUE
C
	SUCH=SUCH+UCH
	SUPIP=SUPIP+UPIP
	SUPIM=SUPIM+UPIM
        SUPI0=SUPI0+UPI0
        SUETA=SUETA+UETA
        SUROM=SUROM+UROM
        SURO0=SURO0+URO0
        SUROP=SUROP+UROP
        SUOMG=SUOMG+UOMG
C
	SUCHDE=SUCHDE+UCHDE
	SUPIPDE=SUPIPDE+UPIPDE
	SUPIMDE=SUPIMDE+UPIMDE
        SUPI0DE=SUPI0DE+UPI0DE
C
	SUS=SUS+US	
	SUB=SUB+UB	
	SUG=SUG+UG	
	SUH=SUH+UH	
        SUSPR=SUSPR+USPR
C
	SUPR=SUPR+UPR
	SUN=SUN+UN
	  SUFR=SUFR+UFR
          SUD=SUD+UD
          SUT=SUT+UT
          SUHE3=SUHE3+UHE3
          SUHE4=SUHE4+UHE4
          SULI=SULI+ULI
C
                 UPIPAL=UPIP+UPIPDE
                 UPIMAL=UPIM+UPIMDE
                 UPI0AL=UPI0+UPI0DE
C
        CALL HIST_2D(UPR,HXPR,HYPR,36,1.0)
        CALL HIST_2D(UN,HXNE,HYNE,36,1.0)
        CALL HIST_2D(UPIPAL,HXPIP,HYPIP,36,1.0)
        CALL HIST_2D(UPIMAL,HXPIM,HYPIM,36,1.0)
        CALL HIST_2D(UPI0AL,HXPI0,HYPI0,36,1.0)
        CALL HIST_2D(UETA,HXETA,HYETA,36,1.0)
        CALL HIST_2D(UOMG,HXOME,HYOME,36,1.0)
        CALL HIST_2D(URO0,HXRO0,HYRO0,36,1.0)
C
! 5A  2*PI+; 2*PI- AND OTHERS
      IF((UPIPAL.EQ.2.).AND.(UPIMAL.EQ.2.).AND.(UPR.EQ.1.)) THEN
         PTOT_C=SQRT((PMX+PPX)**2+(PMY+PPY)**2+(PMZ+PPZ)**2)
      CALL HIST_3D(PTOT_C,ETOT_C,APP2_P1,21,APP2_E1,21,APP2_Z1,1.0)
      ENDIF

! 16A PI+; 2*PI- AND OTHERS
      IF((UPIPAL.EQ.1.).AND.(UPIMAL.EQ.2.).AND.(UPR.EQ.1.)) THEN
         PTOT_C=SQRT((PMX+PPX)**2+(PMY+PPY)**2+(PMZ+PPZ)**2)
      CALL HIST_3D(PTOT_C,ETOT_C,APN2_P1,21,APN2_E1,21,APN2_Z1,1.0)
      ENDIF

! 24A PI+; 3*PI- AND OTHERS
      IF((UPIPAL.EQ.1.).AND.(UPIMAL.EQ.3.).AND.(UPR.EQ.1.)) THEN
         PTOT_C=SQRT((PMX+PPX)**2+(PMY+PPY)**2+(PMZ+PPZ)**2)
      CALL HIST_3D(PTOT_C,ETOT_C,ANN2_P1,21,ANN2_E1,21,ANN2_Z1,1.0)
      ENDIF


        IF(NPOGL.LE.1)GO TO 700
        I=1
        DO 70 J=I+1,NPOGL
C      PRINT *,' POGL  I,J',I,J 
        IF(IP(I).EQ.IP(J)) GO TO 70
        COS=(PPOGLX(I)*PPOGLX(J)+PPOGLY(I)*PPOGLY(J)+
     *PPOGLZ(I)*PPOGLZ(J))/(PPOGL(I)*PPOGL(J))
        IF(COS.GE.0.)GO TO 70
        ANGL=ACOS(COS)*180./3.14
C      PRINT *,' POGL  I,J,COS(I,J),ANGL',I,J,COS,ANGL, 
C     *'TI,TJ',TPOGL(I),TPOGL(J)  
        CALL HIST_2D(ANGL,CX21,CY21,16,1.0)
C	
      CALL HIST(ANGL,90.,180.,10.,PO,16,1.)
  70  CONTINUE     
        IPOGL=0
C
C
  700   M=INT(UPIP+UPIM+1.1)
        IF(M.GT.30)RETURN
        AM=UPIP+UPIM+1.
  	CORM(1,M)=CORM(1,M)+UPR
	NORM(1,M)=NORM(1,M)+1
        CALL HIST_2D(AM,CX11,CY11,26,1.0)
        M=INT(US+1.1)
	CORM(2,M)=CORM(2,M)+UH
	NORM(2,M)=NORM(2,M)+1
	CORM(3,M)=CORM(3,M)+UG
	NORM(3,M)=NORM(3,M)+1
C
	RETURN
	END

      SUBROUTINE PRK2(NCAS,INTEL)
      COMMON/BLNUCL/ANUCL,ZNUCL,EPS,VPI,N,RSM(10),RBIG(10),RHOP(10),
     *       RHON(10),AF(10),TFP(10),TFN(10)
     */ta/nup
      COMMON/BLOKC/SPTU(10,250) 
      COMMON/U1/SUCH,SUPIM,SUPIP,SUPI0
      COMMON/U2/SUOMG,SUETA,SUROM,SURO0,SUROP
      COMMON/U3/SUS,SUG,SUB,SUH,SUSPR
      COMMON/U4/SUPR,SUN,SUFR,SULI,SUD,SUT,SUHE3,SUHE4
      COMMON/U5/SUCHDE,SUPIPDE,SUPIMDE,SUPI0DE
      COMMON/COR/ CORM(15,30),NORM(15,30)

      COMMON/POGL4/PO(16)
      COMMON/FILENAME/FILENAME,DATNAME
      COMMON/FAST/FASTP,FASTN,AMINUS1,ZMINUS1
      COMMON/ISOTOPIC/ISOTOPIC,O_PP,O_PN,O_NN
      COMMON/ENERGY/ENUCL,EPION,ESTAR,ESTERNX(26),ESTERNY(26)
      COMMON/RESIDUAL/REN(86),REX(86),RMO(86),DELT(86),
     *                DELA(86),DELZ(86),ANG(86),ANM(86)
C
      COMMON/APP2/ APP2_P1(21), APP2_E1(21),APP2_Z1(21,21),
     #            APP2_PM2(21),APP2_PP2(21),APP2_Z2(21,21),
     #            APP2_X(66), APP2_Y(66)
      COMMON/APN2/ APN2_P1(21), APN2_E1(21),APN2_Z1(21,21),
     #            APN2_PM2(21),APN2_PP2(21),APN2_Z2(21,21),
     #            APN2_X(66), APN2_Y(66)
      COMMON/ANN2/ ANN2_P1(21), ANN2_E1(21),ANN2_Z1(21,21),
     #            ANN2_PM2(21),ANN2_PP2(21),ANN2_Z2(21,21),
     #            ANN2_X(66), ANN2_Y(66)
C
      COMMON/PI11/PXPR(66),PYPR(66),PXNE(66),PYNE(66)
      COMMON/PI12/PXPIP(66),PYPIP(66),PXPIM(66),PYPIM(66)
      COMMON/PI13/PXPI0(66),PYPI0(66),PXETA(66),PYETA(66)
      COMMON/PI14/PXOME(66),PYOME(66),PXRO0(66),PYRO0(66)
      COMMON/PI15/PXPIC(66),PYPIC(66)                    
           COMMON/BERLIN/EPX(86),EPY(86),ENX(86),ENY(86),
     #               ECHX(86),ECHY(86),PRONONS,PROLOWNS,
     #EPX20(26), EPY20(26), ENX20(26), ENY20(26), 
     #EPX30(26), EPY30(26), ENX30(26), ENY30(26), 
     #EPX45(26), EPY45(26), ENX45(26), ENY45(26), 
     #EPX60(26), EPY60(26), ENX60(26), ENY60(26), 
     #EPX90(26), EPY90(26), ENX90(26), ENY90(26), 
     #EPX120(26),EPY120(26),ENX120(26),ENY120(26), 
     #EPX160(26),EPY160(26),ENX160(26),ENY160(26),
     #RY20(26),RY30(26),RY45(26),RY60(26),
     #RY90(26),RY120(26),RY160(26),
     #RY(86)
      COMMON/FRAGMENTS/EXD(26),EYD(26),EXT(26),EYT(26),
     #                 EXHE3(26),EYHE3(26),EXHE4(26),EYHE4(26)
      COMMON/HIS1/HXPR(36),HYPR(36),HXNE(36),HYNE(36)
      COMMON/HIS2/HXPIP(36),HYPIP(36),HXPIM(36),HYPIM(36)
      COMMON/HIS3/HXPI0(36),HYPI0(36),HXETA(36),HYETA(36)
      COMMON/HIS4/HXOME(36),HYOME(36),HXRO0(36),HYRO0(36)
      COMMON/COR1/CX11(26),CY11(26),CX12(26),CY12(26)
      COMMON/COR2/CX21(16),CY21(16),CX22(16),CY22(16)
      
      COMMON/CEBAF/FERMI(66),RADIUS(66),Z_COORD(66),
     #             PART(26),CH_COUNT(26),T_COUNT(26)
C
      COMMON/MUCAT/SMOMEN(66),DNDPPL(66),DNDPMN(66),
     #             ANGLE(26),DNDTETAPL(26),DNDTETAMN(26),
     #             DEGREES(36),DNDEGPL(36),DNDEGMN(36),
     #             STRIP
C
      COMMON/W_MODE/COMPACT
      DIMENSION XA(2,66),YA(2,66),XB(2,36),YB(2,36),XC1(2,26),
     *YC1(2,26),XC2(2,16),YC2(2,16),DX(1),DY(1),T1Y(26),T2Y(16),
     *XD(2,86),YD(2,86),XF(2,26),YF(2,26),XG(2,46),YG(2,46)
      CHARACTER*45 DL
      CHARACTER*80 FILENAME
      CHARACTER*8  DATNAME,PARNAM
      LOGICAL NAN93, BERL, CEBAF, COMPACT, MUCAT
      INTEGER NERR,LOOPV,NCASEG,LOOPC,NPROC
      COMMON /FLAG_GEN/ NERR,LOOPV,NCASEG,LOOPC,NPROC
      DIMENSION C(3,30),AK(16)
      DATA AK/1.090,1.058,0.992,0.897,0.774,0.628,0.463,0.283,0.095,
     *1.,1.,1.,1.,1.,1.,1./
C
      NAN93=.FALSE.
           BERL=.FALSE.
             CEBAF=.FALSE.
               MUCAT=.FALSE.
C
      PRINT 1,NCAS,INTEL
1     FORMAT(/5X,'NUMBER OF INELASTIC INTERACTIONS=',I10,2X,'NUMBER 
     *OF ELASTIC INTERACTIONS=',I10/)
      PRINT 2,NUP,NERR
2     FORMAT(/40X,'NEGATIVE E* =',I10//,
     *        40X,'ERRORS DETECTED IN CHECK_CL =',I10//)
C
        PRINT *,'  DATNAME IS:',DATNAME,':'
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)
  
        IF(COMPACT) OPEN(20,FILE=FILENAME//'.XH1',STATUS='UNKNOWN')

	BR=FLOAT(NCAS)

      CALL PRINT_1D('CHARGED PART. TOTAL ',SUCH,  BR,'          ',1)
      CALL PRINT_1D('        PIONS,  PI+ ',SUPIP, BR,'          ',1)
      CALL PRINT_1D('                PI- ',SUPIM, BR,'          ',1)
      CALL PRINT_1D('                PI0 ',SUPI0, BR,'          ',1)
      CALL PRINT_1D('NUCLEONS,   PROTONS ',SUPR,  BR,'          ',1)
      CALL PRINT_1D('           NEUTRONS ',SUN,   BR,'          ',1)
      CALL PRINT_1D('  HEAVY MESONS, ETA ',SUETA, BR,'          ',1)
      CALL PRINT_1D('              OMEGA ',SUOMG, BR,'          ',1)
      CALL PRINT_1D('                RO+ ',SUROP, BR,'          ',1)
      CALL PRINT_1D('                RO- ',SUROM, BR,'          ',1)
      CALL PRINT_1D('                RO0 ',SURO0, BR,'          ',1)

      CALL PRINT_1D('ABSOR. WITH PP OUT  ',O_PP,  BR,' A CASCADE',1)
      CALL PRINT_1D('ABSOR. WITH PN OUT  ',O_PN,  BR,' A CASCADE',1)
      CALL PRINT_1D('ABSOR. WITH NN OUT  ',O_NN,  BR,' A CASCADE',1)

      IF(COMPACT) CLOSE(20)
C
	GULI=SULI/BR
C
	GUS=SUS/BR
	GUG=SUG/BR
	GUB=SUB/BR
	GUH=SUH/BR
	GUSPR=SUSPR/BR
C
	GUCHDE=SUCHDE/BR
	GUPIMDE=SUPIMDE/BR
	GUPIPDE=SUPIPDE/BR
        GUPI0DE=SUPI0DE/BR
C
                             IF(MUCAT) THEN
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'W'
        CALL PRINT_2D(PARNAM,
     #  'NUMBER OF PI-PLUS AND PI-MINUS DISTRIBUTION                 ',
     #  BR,XB,YB,36,
     #  HXPIP,HYPIP,36,
     #  'DISTRIBUTION OF PIP                          ',
     #  HXPIM,HYPIM,36,
     #  'DISTRIBUTION OF PIM                          ',1)
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'MO'
        CALL PRINT_2D(PARNAM,
     #  ' MOMENTUM OF PIP AND PIM           FOR DEUTERON IND. REACT. ',
     #          BR*0.05,XA,YA,66,
     #  SMOMEN,DNDPPL,66,
     #  'MOMENTUM DISTRIBUTION  OF PIP                ',
     #  SMOMEN,DNDPMN,66,
     #  'MOMENTUM DISTRIBUTION  OF PIM                ',1)
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'CO'
        CALL PRINT_2D(PARNAM,
     #  ' COS(TET) FOR PIP AND PIM          FOR DEUTERON IND. REACT. ',
     #             BR*0.1,XF,YF,26,
     #  ANGLE,DNDTETAPL,26,
     #  'COS(TETA) DISTRIBUTION FOR PIP               ',
     #  ANGLE,DNDTETAMN,26,
     #  'COS(TETA) DISTRIBUTION FOR PIM               ',1)
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'TT'
        CALL PRINT_2D(PARNAM,
     #  ' TETA     FOR PIP AND PIM          FOR DEUTERON IND. REACT. ',
     #             BR*10.,XB,YB,36,
     #  DEGREES,DNDEGPL,36,
     #  '    TETA  DISTRIBUTION FOR PIP               ',
     #  DEGREES,DNDEGPL,36,
     #  '    TETA  DISTRIBUTION FOR PIM               ',1)
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'SP'
        CALL PRINT_2D(PARNAM,    
     #  'INCLUSIVE SPECTRA FOR PROTONS AND NEUTRONS                  ',
     #        BR*100.0,XA,YA,66,
     #  PXPR,PYPR,66,
     #  'INCLUSIVE SPECTRUM OF PROTONS 1/D DN/DP,1/MEV',
     #  PXNE,PYNE,66,
     #  'INCLUSIVE SPECTRUM OF NEUTR.  1/D DN/DP,1/MEV',1)
                             ENDIF
C
                             IF(CEBAF) THEN

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'FM'
        CALL PRINT_2D(PARNAM,
     #  '       DISTRIBUTION OF INTERACTION POINT FOR GAMMA QUANTA   ',
     #  BR*0.5,XA,YA,66,
     #  FERMI,RADIUS,66,
     #  'RADIAL DISTRIBUTION, RIN (FERMI)             ',
     #  FERMI,Z_COORD,66,
     #  'Z-COORDINATE, RARTIN(3)*RSM(N)  (FERMI)      ',1)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'ML'
        CALL PRINT_2D(PARNAM,
     #  'DISTRIBUTION OF SECONDARY PARTICLES FOR GAMMA-PROTON INTERAC',
     #  T_COUNT(23)*0.5,XF,YF,26,
     #  PART,T_COUNT,26,
     #  'DISTRIBUTION OF TOTAL MULTIPLICITY OF PART.  ',
     #  PART,CH_COUNT,26,
     #  'CHARGED PARTICLE DISTRIBUTION                ',1)
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'RX'
        CALL PRINT_2D(PARNAM,
     #  'EXCITATION ENERGY OF RESIDUAL NUCLEI AND SPATIAL MOMENTA    ',
     #  BR*25.0,XD,YD,86,
     #  REN,REX,86,
     #  'EXCITATION ENERGY                            ',
     #  REN,RMO,86,
     #  'MOMENTA                                      ',1)
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'AZ'
        CALL PRINT_2D(PARNAM,
     #  'DELTA A AND DELTA Z                                         ',
     #  BR,XD,YD,86,
     #  DELT,DELA,86,
     #  'DELTA A                                      ',
     #  DELT,DELZ,86,
     #  'DELTA Z                                      ',1)
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'NG'
        CALL PRINT_2D(PARNAM,
     #  'ANGULAR MOMENTA OF RESIDUAL NUCLEI                          ',
     #  BR,XD,YD,86,
     #  ANG,ANM,86,
     #  'ANGULAR MOMENTA                              ',
     #  ANG,ANM,86,
     #  'ANGULAR MOMENTA                              ',1)
C

                             ENDIF
C
                                IF(BERL) THEN
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'_'
        CALL PRINT_2D(PARNAM,
     #  'INCLUSIVE SPEC. FOR NUCLEONS                                ',
     #  BR*5.0,XD,YD,86,
     #  EPX,EPY,86,
     #  'INCLUSIVE SPECTRUM OF PROTONS                ',
     #  ENX,ENY,86,
     #  'INCLUSIVE SPECTRUM OF NEUTRONS               ',1)
C
        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'DT'
        CALL PRINT_2D(PARNAM,
     #  'INCLUSIVE SPEC. FOR D AND T                                 ',
     #  BR*10.0,XF,YF,26,
     #  EXD,EYD,26,
     #  'INCLUSIVE SPECTRUM OF DEUTERONS              ',
     #  EXT,EYT,26,
     #  'INCLUSIVE SPECTRUM OF TRITONS                ',1)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'HE'
        CALL PRINT_2D(PARNAM,
     #  'INCLUSIVE SPEC. FOR HE3 AND HE4                             ',
     #  BR*10.0,XF,YF,26,
     #  EXHE3,EYHE3,26,
     #  'INCLUSIVE SPECTRUM OF HE-3                   ',
     #  EXHE4,EYHE4,26,
     #  'INCLUSIVE SPECTRUM OF HE-4                   ',1)

        DO IRAT=1,86
             RY(IRAT)=0.0  
             IF(EPY(IRAT).NE.0.0) THEN
                  RY(IRAT)=BR*5.0*ENY(IRAT)/EPY(IRAT)
             ENDIF
        ENDDO

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'_P'
        CALL PRINT_2D(PARNAM,
     #  'N/P RATIO ANY ANGLES AND INCLUSIVE SPECTRUM OF PI+/-        ',
     #  BR*5.0,XD,YD,86,
     #  EPX,RY,86,
     #  'N/P RATIO AT ANY ANGLES                      ',
     #  ECHX,ECHY,86,
     #  'INCLUSIVE SPECTRUM OF PI+/-                  ',0)


        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'_X'
        CALL PRINT_2D(PARNAM,
     #  'EXCITATION ENERGY AFTER CASCADE STAGE                       ',
     #  BR*20.0,XF,YF,26,
     #  ESTERNX,ESTERNY,26,
     #  'EXITATION ENERGY (MEV) AFTER CASCADE         ',
     #  ESTERNX,ESTERNY,26,
     #  'EXITATION ENERGY (MEV) AFTER CASCADE         ',0)


          DO IRAT=1,26

             RY20(IRAT)=0.0  
             IF(EPY20(IRAT).NE.0.0) THEN
                  RY20(IRAT)=ENY20(IRAT)/EPY20(IRAT)
             ENDIF

             RY30(IRAT)=0.0  
             IF(EPY30(IRAT).NE.0.0) THEN
                  RY30(IRAT)=ENY30(IRAT)/EPY30(IRAT)
             ENDIF

             RY45(IRAT)=0.0  
             IF(EPY45(IRAT).NE.0.0) THEN
                  RY45(IRAT)=ENY45(IRAT)/EPY45(IRAT)
             ENDIF

             RY60(IRAT)=0.0  
             IF(EPY60(IRAT).NE.0.0) THEN
                  RY60(IRAT)=ENY60(IRAT)/EPY60(IRAT)
             ENDIF

             RY90(IRAT)=0.0  
             IF(EPY90(IRAT).NE.0.0) THEN
                  RY90(IRAT)=ENY90(IRAT)/EPY90(IRAT)
             ENDIF

             RY120(IRAT)=0.0  
             IF(EPY120(IRAT).NE.0.0) THEN
                  RY120(IRAT)=ENY120(IRAT)/EPY120(IRAT)
             ENDIF

             RY160(IRAT)=0.0  
             IF(EPY160(IRAT).NE.0.0) THEN
                  RY160(IRAT)=ENY160(IRAT)/EPY160(IRAT)
             ENDIF

           ENDDO

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'1'
        CALL PRINT_2D(PARNAM,
     #  'NEUTRON/PROTON RATIO VERSUS NUCLEON ENERGY                  ',
     #  1.0,XF,YF,26,
     #  EPX20,RY20,26,
     #  'N/P RATIO AT 20 DEGREE                       ',
     #  ENX30,RY30,26,
     #  'N/P RATIO AT 30 DEGREE                       ',0)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'2'
        CALL PRINT_2D(PARNAM,
     #  'NEUTRON/PROTON RATIO VERSUS NUCLEON ENERGY                  ',
     #  1.0,XF,YF,26,
     #  EPX45,RY45,26,
     #  'N/P RATIO AT 45 DEGREE                       ',
     #  ENX60,RY60,26,
     #  'N/P RATIO AT 60 DEGREE                       ',0)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'3'
        CALL PRINT_2D(PARNAM,
     #  'NEUTRON/PROTON RATIO VERSUS NUCLEON ENERGY                  ',
     #  1.0,XF,YF,26,
     #  EPX90,RY90,26,
     #  'N/P RATIO AT 90 DEGREE                       ',
     #  ENX120,RY120,26,
     #  'N/P RATIO AT 120 DEGREE                      ',0)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'4'
        CALL PRINT_2D(PARNAM,
     #  'NEUTRON/PROTON RATIO VERSUS NUCLEON ENERGY                  ',
     #  1.0,XF,YF,26,
     #  EPX160,RY160,26,
     #  'N/P RATIO AT 160 DEGREE                      ',
     #  EPX160,EPY160,26,
     #  'PROTON SPECTRUM AT 160 DEGREE                ',0)


! SPECTRA 20-A  30-B  45-C  60-D  90-E  120-F  160-G


        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'A'
        CALL PRINT_2D(PARNAM,
     #  'N  & P SPECTRA       VERSUS NUCLEON ENERGY                  ',
     #  BR*20.0,XF,YF,26,
     #  EPX20,EPY20,26,
     #  'PROTONS   AT 20 DEGREE                       ',
     #  ENX20,ENY20,26,
     #  'NEUTRONS  AT 20 DEGREE                       ',1)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'B'
        CALL PRINT_2D(PARNAM,
     #  'N  & P SPECTRA       VERSUS NUCLEON ENERGY                  ',
     #  BR*20.0,XF,YF,26,
     #  EPX30,EPY30,26,
     #  'PROTONS   AT 30 DEGREE                       ',
     #  ENX30,ENY30,26,
     #  'NEUTRONS  AT 30 DEGREE                       ',1)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'C'
        CALL PRINT_2D(PARNAM,
     #  'N  & P SPECTRA       VERSUS NUCLEON ENERGY                  ',
     #  BR*20.0,XF,YF,26,
     #  EPX45,EPY45,26,
     #  'PROTONS   AT 45 DEGREE                       ',
     #  ENX45,ENY45,26,
     #  'NEUTRONS  AT 45 DEGREE                       ',1)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'D'
        CALL PRINT_2D(PARNAM,
     #  'N  & P SPECTRA       VERSUS NUCLEON ENERGY                  ',
     #  BR*20.0,XF,YF,26,
     #  EPX60,EPY60,26,
     #  'PROTONS   AT 60 DEGREE                       ',
     #  ENX60,ENY60,26,
     #  'NEUTRONS  AT 60 DEGREE                       ',1)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'E'
        CALL PRINT_2D(PARNAM,
     #  'N  & P SPECTRA       VERSUS NUCLEON ENERGY                  ',
     #  BR*20.0,XF,YF,26,
     #  EPX90,EPY90,26,
     #  'PROTONS   AT 90 DEGREE                       ',
     #  ENX90,ENY90,26,
     #  'NEUTRONS  AT 90 DEGREE                       ',1)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'F'
        CALL PRINT_2D(PARNAM,
     #  'N  & P SPECTRA       VERSUS NUCLEON ENERGY                  ',
     #  BR*20.0,XF,YF,26,
     #  EPX120,EPY120,26,
     #  'PROTONS  AT 120 DEGREE                       ',
     #  ENX120,ENY120,26,
     #  'NEUTRONS AT 120 DEGREE                       ',1)

        PARNAM=DATNAME(1:INDEX(DATNAME,' ')-1)//'G'
        CALL PRINT_2D(PARNAM,
     #  'N  & P SPECTRA       VERSUS NUCLEON ENERGY                  ',
     #  BR*20.0,XF,YF,26,
     #  EPX160,EPY160,26,
     #  'PROTONS  AT 160 DEGREE                       ',
     #  ENX160,ENY160,26,
     #  'NEUTRONS AT 160 DEGREE                       ',1)

                                ELSEIF(NAN93) THEN
        CALL PRINT_2D('  H1PI11',
     #  'INCLUSIVE SPEC. FOR NUCLEONS                                ',
     #  BR,XA,YA,66,
     #  PXPR,PYPR,66,
     #  'INCLUSIVE SPECTRUM OF PROTONS                ',
     #  PXNE,PYNE,66,
     #  'INCLUSIVE SPECTRUM OF NEUTRONS               ',1)
        CALL PRINT_2D('  H1PI12',
     #  'INCLUSIVE SPEC. FOR  PIPLS, PIMIN                           ',
     #  BR,XA,YA,66,
     #  PXPIP,PYPIP,66,
     #  'INCLUSIVE SPECTRUM OF PIPLS                  ',
     #  PXPIM,PYPIM,66,
     #  'INCLUSIVE SPECTRUM OF PIMIN                  ',1)
        CALL PRINT_2D('  H1PI13',
     #  'INCLUSIVE SPEC. FOR  PI0, ETA                               ',
     #  BR,XA,YA,66,
     #  PXPI0,PYPI0,66,
     #  'INCLUSIVE SPECTRUM OF PI0                    ',
     #  PXETA,PYETA,66,
     #  'INCLUSIVE SPECTRUM OF ETA                    ',1)
        CALL PRINT_2D('  H1PI14',
     #  'INCLUSIVE SPEC. FOR  OMEGA, RO0                             ',
     #  BR,XA,YA,66,
     #  PXOME,PYOME,66,
     #  'INCLUSIVE SPECTRUM OF OMEGA                  ',
     #  PXRO0,PYRO0,66,
     #  'INCLUSIVE SPECTRUM OF RO0                    ',1)
        CALL PRINT_2D('  H1PI15',
     #  'INCLUSIVE SPEC. FOR  PI CHARGED                             ',
     #  BR,XA,YA,66,
     #  PXPIC,PYPIC,66,
     #  'INCLUSIVE SPECTRUM OF PI CHARGED             ',
     #  DX,DY,1,DL,1)

        CALL PRINT_2D('  H1HIS1',
     #  'NUMBER DISTRIBUTION FOR  PROTONS,NEUTRONS                   ',
     #  BR,XB,YB,36,
     #  HXPR,HYPR,36,
     #  'DISTRIBUTION OF PROTONS                      ',
     #  HXNE,HYNE,36,
     #  'DISTRIBUTION OF NEUTRONS                     ',1)
        CALL PRINT_2D('  H1HIS2',
     #  'NUMBER DISTRIBUTION FOR  PIPLS,PIMIN                        ',
     #  BR,XB,YB,36,
     #  HXPIP,HYPIP,36,
     #  'DISTRIBUTION OF PIP                          ',
     #  HXPIM,HYPIM,36,
     #  'DISTRIBUTION OF PIM                          ',1)
        CALL PRINT_2D('  H1HIS3',
     #  'NUMBER DISTRIBUTION FOR  PIP0,ETA                           ',
     #  BR,XB,YB,36,
     #  HXPI0,HYPI0,36,
     #  'DISTRIBUTION OF PI0                          ',
     #  HXETA,HYETA,36,
     #  'DISTRIBUTION OF ETA                          ',1)
        CALL PRINT_2D('  H1HIS4',
     #  'NUMBER DISTRIBUTION FOR  OMEGA,RO0                          ',
     #  BR,XB,YB,36,
     #  HXOME,HYOME,36,
     #  'DISTRIBUTION OF OMEGA                        ',
     #  HXRO0,HYRO0,36,
     #  'DISTRIBUTION OF RO0                          ',1)
C
C ----------------------------------------------------------
!
!          E TOTAL VERSUS P TOTAL 
!
C ----------------------------------------------------------
        CALL PRINT_3D('H1APP2_1',
     #  'TOTAL MOMENTUM VS TOTAL ENERGY OF 2PI+,2PI- AND PROTON      ',
     #  BR,APP2_P1,21,APP2_E1,21,APP2_Z1,1)
C
        CALL PRINT_3D('H1APN2_1',
     #  'TOTAL MOMENTUM VS TOTAL ENERGY OF PI+,2PI- AND PROTON       ',
     #  BR,APN2_P1,21,APN2_E1,21,APN2_Z1,1)
C
        CALL PRINT_3D('H1ANN2_1',
     #  'TOTAL MOMENTUM VS TOTAL ENERGY OF PI+,3PI- AND PROTON       ',
     #  BR,ANN2_P1,21,ANN2_E1,21,ANN2_Z1,1)
C
	CALL CORR(1,CORM,NORM,C)
       CALL PRINT_CORR('  H1COR1',
     #  'PARTICLE CORRELATION    <PROT>/PIch                         ',
     #  C,15,
     #  '<PROT>/PIch                                  ',
     #  C,1,
     #  '<PROT>/PIch                                  ')

	DO 42,J=1,15
        I=J-1
        T1=C(1,J)-C(3,J)
        T2=C(1,J)+C(3,J)
	PRINT 515,I,T1,C(1,J),T2,C(2,J),C(3,J)
  515	FORMAT(2X,I2,5(1X,E10.3))

  42	CONTINUE
C
        DO 8061 K=1,16
        CY22(K)=CY21(K)/(BR*6.28*AK(K))*1000
 8061   CONTINUE
      CALL PRINT_2D('  H1COR2',
     #  'ANGLE CORRELATION                                           ',
     #  1.,XC2,YC2,16,
     #  CX21,CY21,16,
     #  'ANGL COR dN/dTETA                            ',
     #  CX21,CY22,16,
     #  'ANGLE COR dNpi-p/dOMEGA/1000pbar             ',1)
                                ENDIF ! FOR TASK SELECTION
  	RETURN
C***************
C***************
	ENTRY    PRK1(NCAS,INTEL)
C			BARASHENCOV
	NCAS=0
	INTEL=0
C
	SUCH=0.
	SUPIP=0.
	SUPIM=0.
        SUPI0=0.
        SUETA=0.
	SUROM=0.
	SURO0=0.
	SUROP=0.
	SUOMG=0.
	SUPR=0.
	SUN=0.
        FASTN=0.
        FASTP=0.
        STRIP=0.
         O_PP=0.
         O_PN=0.
         O_NN=0.
        SUFR=0. 
        SULI=0.   
	SUCHDE=0.
	SUPIPDE=0.
	SUPIMDE=0.
        SUPI0DE=0.
        SUS=0.
        SUG=0.
        SUH=0.
        SUB=0.
        SUSPR=0.
          PRONONS=0.0
          PROLOWNS=0.0
          AMINUS1=0.0
          ZMINUS1=0.0
           ENUCL=0.0
           EPION=0.0
           ESTAR=0.0
C
         CALL PREP_2D(PXPR,PYPR,66,0.0,6000.)
         CALL PREP_2D(PXNE,PYNE,66,0.0,6000.)
         CALL PREP_2D(PXPIP,PYPIP,66,0.0,1.5)
         CALL PREP_2D(PXPIM,PYPIM,66,0.0,1.5)
         CALL PREP_2D(PXPI0,PYPI0,66,0.0,1.5)
         CALL PREP_2D(PXETA,PYETA,66,0.0,1.5)
         CALL PREP_2D(PXOME,PYOME,66,0.0,1.5)
         CALL PREP_2D(PXRO0,PYRO0,66,0.0,1.5)
         CALL PREP_2D(PXPIC,PYPIC,66,0.0,1.5)
         CALL PREP_2D(EPX,EPY,86,0.0,400.0)
         CALL PREP_2D(ENX,ENY,86,0.0,400.0)
         CALL PREP_2D(ECHX,ECHY,86,0.0,400.0)

         CALL PREP_2D(EXD,EYD,26,0.0,200.0)
         CALL PREP_2D(EXT,EYT,26,0.0,200.0)
         CALL PREP_2D(EXHE3,EYHE3,26,0.0,200.0)
         CALL PREP_2D(EXHE4,EYHE4,26,0.0,200.0)

         CALL PREP_2D(ESTERNX,ESTERNY,26,0.0,400.0)
         CALL PREP_2D(REN,REX,86,0.0,2.0)
         CALL PREP_2D(REN,RMO,86,0.0,2.0)
         CALL PREP_2D(DELT,DELA,86,-4.5,75.5)
         CALL PREP_2D(DELT,DELZ,86,-4.5,75.5)
         CALL PREP_2D(ANG,ANM,86,-0.5,79.5)

         CALL PREP_2D(EPX20,EPY20,26,0.0,400.0)
         CALL PREP_2D(ENX20,ENY20,26,0.0,400.0)

         CALL PREP_2D(EPX30,EPY30,26,0.0,400.0)
         CALL PREP_2D(ENX30,ENY30,26,0.0,400.0)

         CALL PREP_2D(EPX45,EPY45,26,0.0,400.0)
         CALL PREP_2D(ENX45,ENY45,26,0.0,400.0)

         CALL PREP_2D(EPX60,EPY60,26,0.0,400.0)
         CALL PREP_2D(ENX60,ENY60,26,0.0,400.0)

         CALL PREP_2D(EPX90,EPY90,26,0.0,400.0)
         CALL PREP_2D(ENX90,ENY90,26,0.0,400.0)

         CALL PREP_2D(EPX120,EPY120,26,0.0,400.0)
         CALL PREP_2D(ENX120,ENY120,26,0.0,400.0)

         CALL PREP_2D(EPX160,EPY160,26,0.0,400.0)
         CALL PREP_2D(ENX160,ENY160,26,0.0,400.0)


        CALL PREP_2D(HXPR,HYPR,36,-0.5,29.5)
        CALL PREP_2D(HXNE,HYNE,36,-0.5,29.5)
        CALL PREP_2D(HXPIP,HYPIP,36,-0.5,29.5)
        CALL PREP_2D(HXPIM,HYPIM,36,-0.5,29.5)
        CALL PREP_2D(HXPI0,HYPI0,36,-0.5,29.5)
        CALL PREP_2D(HXETA,HYETA,36,-0.5,29.5)
        CALL PREP_2D(HXOME,HYOME,36,-0.5,29.5)
        CALL PREP_2D(HXRO0,HYRO0,36,-0.5,29.5)
        CALL PREP_2D(CX11,CY11,26,-0.5,19.5)
        CALL PREP_2D(CX12,CY12,26,-0.5,19.5)
        CALL PREP_2D(CX21,CY21,16,90.0,190.0)
        CALL PREP_2D(CX22,CY22,16,90.0,190.0)
      
        CALL PREP_2D(FERMI,RADIUS,66,-15.,15.)
        CALL PREP_2D(FERMI,Z_COORD,66,-15.,15.)
        CALL PREP_2D(PART,CH_COUNT,26,-0.5,19.5)
        CALL PREP_2D(PART,T_COUNT,26,-0.5,19.5)

        CALL PREP_2D(SMOMEN,DNDPPL,66,0.0,3.0)
        CALL PREP_2D(SMOMEN,DNDPMN,66,0.0,3.0)
        CALL PREP_2D(ANGLE,DNDTETAPL,26,-1.0,1.0)
        CALL PREP_2D(ANGLE,DNDTETAMN,26,-1.0,1.0)
        CALL PREP_2D(DEGREES,DNDEGPL,36,0.0,300.0)
        CALL PREP_2D(DEGREES,DNDEGMN,36,0.0,300.0)

        CALL PREP_3D(APP2_P1,21,0.0,1.5,APP2_E1,21,0.0,3.0,APP2_Z1)
        CALL PREP_3D(APN2_P1,21,0.0,1.5,APN2_E1,21,0.0,3.0,APN2_Z1)
        CALL PREP_3D(ANN2_P1,21,0.0,1.5,ANN2_E1,21,0.0,3.0,ANN2_Z1)

C
	RETURN
	END

      	SUBROUTINE CORR(I,CORM,NORM,C)
	DIMENSION CORM(15,30),NORM(15,30),C(3,30)
C	
	DO 1 K=1,3
	DO 1 J=1,20
	C(K,J)=0.
  1	CONTINUE
C
	DO 4 J=1,20
	G=CORM(I,J)
	B=NORM(I,J)
	IF(B.LE.0.001) GO TO 4
	C(1,J)=G/B
	C(2,J)=B
	C(3,J)=C(1,J)/SQRT(B)
  4	CONTINUE	
C
	RETURN
	END

      SUBROUTINE HIST(X,A,B,H,RX,N,W)
C     BLOK OF BILDING OF HISTOGRAMMS.
      DIMENSION RX(N)
C      PRINT *,'HIST X,A,B,H,N,W',X,A,B,H,N,W
      RX(N)=RX(N)+X
      IF(X-A) 1,2,2
    1 RX(N-4)=RX(N-4)+W
      RETURN
    2 IF(X-B) 4,3,3
    3 RX(N-2)=RX(N-2)+W
      RETURN
    4 L=(X-A)/H
      RX(L+1)=RX(L+1)+W
      RX(N-1)=RX(N-1)+X
      RX(N-3)=RX(N-3)+W
      RETURN
      END

c      real function acosdd(x)
c      real x,ac
c      pi=acos(-1.)

c      ac=acos(x)
c      acosdd=ac*180./pi

c      return
c      end
      
c      real function cosdd(x)
c      real x,y
c      pi=acos(-1.)
c      y=x*pi/180.
c      cosdd = cos(y)
c      return
c      end
