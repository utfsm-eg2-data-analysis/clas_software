

      SUBROUTINE BINEL(PARTIN,IPATIN,IPATNE,L,MS,MQ,KSI,ME,V,U,
     *TIN1,MV,NP,NIN,NR)
C     BLOCK OF INELASTIC SCATTERING.
      COMMON/MEMORY/PMEMO(9,100),IMEMO(9,100)
     */IRES/IRES,IAN
     */TOCHKA/RA 
     */BLNUCL/ ANUCL,ZNUCL,EPS,VPI,N,RSM,RBIG,RHOP,RHON,AF,TFP,TFN
     */SIG0/SIGOM
     */GAM_CAS/GAM_CAS
      COMMON/CEBAF/FERMI(66),RADIUS(66),   Z_COORD(66),
     #             PART(26), CH_COUNT(26), T_COUNT(26)
      DIMENSION RSM(10),RBIG(10),RHOP(10),RHON(10),
     *TFP(10),TFN(10),AF(10)
      DIMENSION PARTIN(9),IPATIN(9),IPATNE(5),V(3),PROB_TOP(7)
      DIMENSION PIST(3),PNST(3)
      INTEGER*4 TOP_NUMBER
      LOGICAL GAM_CAS
C
      real vran(1)


      NIN=0
      ITQ=IPATIN(4)
      NUM=IPATIN(8)
      IF(NUM.EQ.8.OR.NUM.EQ.17) GO TO 33
      IF(ITQ) 30,32,32
  30  IF(NR-3) 31,389,31
  32  IK = 0

!___________________  GAMMA-QUANTUM COMES  HERE !  ____________ 

      IF(IPATIN(2).EQ.1) THEN

!_________ FIRST OF ALL WE NEED TO SELECT TOPOLOGY..... ________
           S3_9=0.0
           DO I=1,7
               S3_9=S3_9+TOP_GAMN(TIN1,I+2)
               PROB_TOP(I)=S3_9
           ENDDO
           DO I=1,7
               PROB_TOP(I)=PROB_TOP(I)/PROB_TOP(7)
           ENDDO
C *** random
c           TOP_NUMBER=IDIHOTOMIA(RNDM(-1),PROB_TOP,7)+2
           call ranmar(vran,1)
           TOP_NUMBER=IDIHOTOMIA(vran(1),PROB_TOP,7)+2

!_________ ISOBAR MAY BE PRODUCED FOR TOP_NUMBER=3 _____________
           
           call ranmar(vran,1)
           IF((TOP_NUMBER.EQ.3).AND.(vran(1).LE.QINTS(TIN1,26)/              
     #     TOP_GAMN(TIN1,3))) THEN
               CALL ISOBAR (U,V,TIN1,PARTIN,IPATNE,MV,NP)
           ELSE
               CALL STAT_SU2(TOP_NUMBER,PARTIN,IPATNE,TIN1,MV,NP)
           ENDIF

!  MAKE HISTOGRAMS RIGHT NOW ...
        CALL HIST_2D(FLOAT(NP),PART,T_COUNT,26,1.0)
        ! NORMALIZED TO UNITY 
        TOPOLOGY=0.0  
      DO IJ=1,NP
        TOPOLOGY=TOPOLOGY+ABS(FLOAT(IQ(IMEMO(8,MV+IJ))))
      ENDDO
        IF(GAM_CAS) THEN
          HIST_WEIGHT=SIGOM/ANUCL   !TOPOLOGICAL IN MB ...
        ELSE
          HIST_WEIGHT=1.0     !TOPOLOGICAL TO UNITY IF ANY ...
        ENDIF
        CALL HIST_2D(TOPOLOGY,PART,CH_COUNT,26,HIST_WEIGHT)

           GO TO 222
      ENDIF

!___________________    END OF GAMMA PATH    __________________

      IF(TIN1-4.)12,24,24
   24 SIGTH=0.
      GO TO 13
   12 SIGTH=SIGMAT(L,MS,MQ,ME,KSI,7,TIN1,ITQ)
   13 SIGNEL=SIGMAT(L,MS,MQ,ME,KSI,0,TIN1,ITQ)-SIGMAT(L,MS,MQ,ME,KSI,
     *1,TIN1,ITQ)-SIGMAT(L,MS,MQ,ME,KSI,2,TIN1,ITQ)
      CALL SIGPI(TIN1,IPATIN,IPATNE,SIG1,SIG2)
      BETATH=SIGTH/SIGNEL
      BET1=SIG1/SIGNEL
      BET2=SIG2/SIGNEL
C
      call ranmar(vran,1)
      TEMP=vran(1)
      IF(TEMP-BET1)55,50,50
  50  IF(TEMP-(BET1+BET2))56,51,51
  51  IF(TEMP-BETATH)14,15,15
C-----------NPI=1
   14 ITH=1
      TH=1.
      GO TO 16
C-----------NPI GE 2
   15 ITH=0
      TH=2.
   16 IF(U-PARTIN(9)-0.14*TH-0.96)19,19,17
   17 CALL VMNSP (PARTIN,IPATIN,U,MV,NP,ITH,MQ,TIN1,LP)
      IF (NP) 19,19,27
   27 CONTINUE
      IF (LP) 19,22,19
   22 CALL DIRECT (V,U,TIN1,MQ,MV,NP,PARTIN,KP,ITH)
      IF (KP) 23,18,23
   23 IK = IK+1
      IF (IK-50) 17,19,19
   18 CALL CHINEL (IPATIN,L,MS,MQ,KSI,NP,MV,TIN1,ME,IPATNE)
C
  222 DO I=MV+1,MV+NP
      CALL PNUM(PMEMO(9,I),IMEMO(1,I),0,IMEMO(3,I),IMEMO(4,I),NUM)
      IMEMO(8,I)=NUM
      END DO
      RETURN
C
   19 NIN = 2
      RETURN
C--------------------------------------------------------------------
   33 CALL REZ2PI(PARTIN,IPATIN,IPATNE,TIN1,MV,NP,NIN)
      RETURN
C---------------------------------------------------------------------
C  PI+NUCLEON ===> REZ+NUCLEON
 55   NCMI=8
      NET=NET+1
      GO TO 59
 56   NCMI=17
      NOM=NOM+1
      GO TO 59
 59   CMI=AMREZ(NCMI)
      CMN=0.94
      EI=(U**2+CMI**2-CMN**2)/(2.*U)
      IF(EI.LT.CMI) GO TO 59
      call ranmar(vran,1)
      CTSTI=-1.+2.*vran(1)
      IE=0
      NE = ME
      CALL PNUM(CMN,NE,0,0,1,NUM)
      NCMN=NUM
      GO TO 60
 60   call ranmar(vran,1)
      FISTI = 6.283185*vran(1)
      CALL ABEL(PARTIN,V,U,PIST,PNST,CTSTI,FISTI,CMI,CMN)
      IF(MV-97)61,61,62
   62 NP = 0
      PRINT 201
  201 FORMAT (45X,29H MEMORY IS EXCEEDED IN CASCAD)
      RETURN
   61 CONTINUE
      PMEMO(1,MV+3) = PIST(1)
      PMEMO(2,MV+3) = PIST(2)
      PMEMO(3,MV+3) = PIST(3)
      PMEMO(9,MV+3)=CMI
      IMEMO(1,MV+3)=IE
      IMEMO(2,MV+3)=0
      IMEMO(3,MV+3) = IPATIN(3)
      IMEMO(4,MV+3) = IPATIN(4)
      IMEMO(8,MV+3) = NCMI
      IF(NCMI.EQ. 8) IMEMO(9,MV+3) = NET
      IF(NCMI.EQ.17) IMEMO(9,MV+3) = NOM
C
      PMEMO(1,MV+1) = PNST(1)
      PMEMO(2,MV+1) = PNST(2)
      PMEMO(3,MV+1) = PNST(3)
      PMEMO(9,MV+1)=CMN
      IMEMO(1,MV+1)=NE
      IMEMO(2,MV+1)=0
      IMEMO(3,MV+1) = 0
      IMEMO(4,MV+1) = 1
      IMEMO(8,MV+1) = NCMN
      NP = 2
      RETURN
C--------------------------------------------------------------------
C   ANTINUCLEON INELASTIC INTERACTION
  31  SIGNEL=SIGMAT(L,MS,MQ,ME,KSI,0,TIN1,ITQ)-SIGMAT(L,MS,MQ,ME,KSI,
     *1,TIN1,ITQ)-SIGMAT(L,MS,MQ,ME,KSI,2,TIN1,ITQ)
      BETATH=SIGMAT(L,MS,MQ,ME,KSI,5,TIN1,ITQ)/SIGNEL
      BETATN=SIGMAT(L,MS,MQ,ME,KSI,6,TIN1,ITQ)/SIGNEL
      BETABS=SIGMAT(L,MS,MQ,ME,KSI,3,TIN1,ITQ)/SIGNEL
      call ranmar(vran,1)
      TEMP1=vran(1)
      IF(TEMP1-BETATH) 14,40,40
  40  IF(TEMP1-(BETATN+BETATH)) 15,41,41
  41  IF(TEMP1-(BETATN+BETATH+BETABS)) 14,15,389
C
 389  CONTINUE
      RA=SQRT(PARTIN(1)**2+PARTIN(2)**2+PARTIN(3)**2)
      IF(IAN.EQ.1) CALL ANGREZ(PARTIN,IPATIN,IPATNE,TIN1,MV,NP)
      IF(IAN.EQ.0) CALL ANGPI (PARTIN,IPATIN,IPATNE,TIN1,U,V,MV,NP)
      RETURN
      END



      SUBROUTINE STAT_SU2(TOP_NUMBER,PARTIN,IPATNE,TIN1,MV,ND)
C+
C 
C FUNCTIONAL DESCRIPTION:	
C 
C    This subroutine is a generator of outgoing particles
C    for gamma-nucleon interaction:
C              
C                  gamma + N ---> N + mpi   m=2,....8 
C
C CREATION DATE: 
C 
C     11.03.94       by Igor Pshenichnov 
C 
C-
      COMMON/UTIL/PLACE(150),WEIGHT(150),NP,TECM,AMASS(18),PCM(5,18),WT
     */BEAM/PRM,TARGM,PBM,ETA,GAM,DPBM
     */KAJBYK/KAJBYK,A(18),UCUT(18),BCUT(18),NN
     */MEMORY/PME(9,100),IME(9,100)
     */BLNUCL/ ANUCL,ZNUCL,EPS,VPI,N,RSM,RBIG,RHOP,RHON,AF,TFP,TFN
      DIMENSION RSM(10),RBIG(10),RHOP(10),RHON(10),
     *TFP(10),TFN(10),AF(10)
      DIMENSION PARTIN(9),IPATNE(5)
      INTEGER*4 TOP_NUMBER,PART_NUMB(10)
C
  10  NN=0
      IR=0
      AMM=0.0
      
      CALL GAMN_CHARG(TOP_NUMBER,IPATNE(1),PART_NUMB)    !  SELECT A CHANNEL

      I=1
      DO WHILE (PART_NUMB(I).GT.0)
               NP=I
               MTEMP=MV+I
               IME(8,MTEMP)=PART_NUMB(I)
               AMASS(I)=AMAS(PART_NUMB(I))
               AMM=AMM+AMASS(I)
         I=I+1
      ENDDO
      

      DO IW=1,150
         WEIGHT(IW)=1.0
      ENDDO

      PRM=0.000001
      TARGM=0.94
      PBM=SQRT(TIN1*(TIN1+2.*PRM))
      E=SQRT(PBM**2+PRM**2)
      ECMS=TARGM**2+PRM**2+2.0*TARGM*E
      TECM=SQRT(ECMS)

      IF(AMM.GT.TECM) THEN
         PRINT 100,PART_NUMB
 100     FORMAT(1X,'A WRONG THRES. VALUE, NUMBERS ARE: ',10I3)         
         GOTO 10
      ENDIF

      ETA=PBM/TECM
      GAM=(E+TARGM)/TECM
      KAJBYK =0
      CALL GENEV
C 
      DO IJ=1,NP
        MTEMP=MV+IJ
        NUM=IME(8,MTEMP)
        PME(1,MTEMP)=PCM(1,IJ)
        PME(2,MTEMP)=PCM(2,IJ)
        PME(3,MTEMP)=PCM(3,IJ)
        PME(9,MTEMP)=AMASS(IJ)
        IME(1,MTEMP)=IQ(NUM)
        IME(2,MTEMP)=0
        IME(3,MTEMP)=IS(NUM)
        IME(4,MTEMP)=IB(NUM)
      ENDDO

         ND=NP

      RETURN
      END




	REAL*4 FUNCTION TOP_GAMN(KIN_ENERGY,TOP_NUMBER)
C+
C 
C FUNCTIONAL DESCRIPTION:	
C 
C    The function presents a calculation of gamma-
C    nucleon TOPOLOGICAL cross sections by means of approximation
C    of cross sections of certain channel and SU(2) statistical model
C
C CREATION DATE: 
C 
C     18.03.94       by Igor Pshenichnov 
C 
C FORMAL PARAMETERS:
C 
C    KIN_ENERGY  - projectile kinetic energy (GeV) 
C 
C    TOP_NUMBER  - topology (number of particles in the final
C                  state (n=3,...,9)).
C 
C COMMON BLOCKS:
C
C    none 
C 
C FUNCTION VALUE:
C 
C    cross-section value (mb)
C 
C-
	REAL*4 KIN_ENERGY
        INTEGER*4 TOP_NUMBER
        
                IF(TOP_NUMBER.EQ.3) THEN
                      TOP_GAMN=GAMN(KIN_ENERGY,6)/0.7
                ELSEIF(TOP_NUMBER.EQ.4) THEN
                      TOP_GAMN=GAMN(KIN_ENERGY,9)/0.75
                ELSEIF(TOP_NUMBER.EQ.5) THEN
                      TOP_GAMN=GAMN(KIN_ENERGY,14)/0.2667
                ELSEIF(TOP_NUMBER.EQ.6) THEN
                      TOP_GAMN=GAMN(KIN_ENERGY,19)/0.4381
                ELSEIF(TOP_NUMBER.EQ.7) THEN
                      TOP_GAMN=GAMN(KIN_ENERGY,26)/0.125
                ELSEIF(TOP_NUMBER.EQ.8) THEN
                      TOP_GAMN=GAMN(KIN_ENERGY,33)/0.2755
                ELSEIF(TOP_NUMBER.EQ.9) THEN
                      TOP_GAMN=GAMN(KIN_ENERGY,42)/0.05614
                ELSE
                   PRINT 1,TOP_NUMBER
 1                 FORMAT(' A WRONG TOPOLOGY NUMBER: ',I4)
                   TOP_GAMN=0.0
                   RETURN
                ENDIF
 
        RETURN
	END



	REAL*4 FUNCTION GAMN(KIN_ENERGY,TAB_NUMBER)
C+
C 
C FUNCTIONAL DESCRIPTION:	
C 
C    The function presents a calculation of approximation gamma-
C    nucleon partial cross-sections from experiments:
C    S.I.Alekhin et al., CERN-HERA 87-01
C
C CREATION DATE: 
C 
C     16.03.94       by Igor Pshenichnov 
C 
C FORMAL PARAMETERS:
C 
C    KIN_ENERGY  - projectile kinetic energy (GeV) 
C 
C    TAB_NUMBER  - reaction number (see table)
C 
C COMMON BLOCKS:
C 
C    /LAGERR/PL(0:20) - Lagerr polinom values
C
C    /RE_NAME/RE_NAME - reaction notation in output
C 
C FUNCTION VALUE:
C 
C    cross-section value (mb)
C 
C-
	REAL*4 PL(0:20),KIN_ENERGY,TK(7),A(0:4,7)
        REAL*4 ALFA,C_UNI,C_DPI
        INTEGER*4 TAB_NUMBER,RE_NUMBER,MAX_POWER(7)
        CHARACTER*45 RE_NAME,ST_NAMES(7)

        COMMON /LAGERR/PL
	COMMON /RE_NAME/RE_NAME
C ...............................................
	DATA ST_NAMES/' 6: g p ==> p pi+ pi-',
     #                ' 9: g p ==> p pi+ pi- pi0',
     #                '14: g p ==> p pi+ pi+ pi- pi-',
     #                '19: g p ==> p pi+ pi+ pi- pi- pi0',
     #                '26: g p ==> p pi+ pi+ pi+ pi- pi- pi-',
     #                '33: g p ==> p pi+ pi+ pi+ pi- pi- pi- pi0',     
     #                '42: g p ==> p pi+ pi+ pi+ pi+ pi- pi- pi- pi-'/        
     
		DATA TK/  321.00,   506.00,  727.00,   952.00,
     #                   1215.00,  1481.00, 1788.00/

C               .....................   6  ...........................
	DATA A/ 0.3317900,-0.0821800, 0.0997600, 0.0001300, 0.0000000,
C               .....................   9  ...........................
     #          0.0537900, 0.1350400,-0.0317300, 0.0000000, 0.0000000,
C               .....................  14  ...........................
     #         -0.0009800, 0.0983250,-0.0475448, 0.0000000, 0.0000000,
C               .....................  19  ...........................
     #          0.2056800,-0.0629900, 0.0000000, 0.0000000, 0.0000000,
C               .....................  26  ...........................
     #          0.0619000,-0.0192100, 0.0000000, 0.0000000, 0.0000000,
C               .....................  33  ...........................
     #          0.1113700,-0.0409400, 0.0000000, 0.0000000, 0.0000000,
C               .....................  42  ...........................
     #          0.0336780,-0.0130250, 0.0000000, 0.0000000, 0.0000000/

		DATA MAX_POWER/  3,  2,  2,  1,  1,  1,  1/    

                      ALFA=2.0
                      C=1.0

                IF(TAB_NUMBER.EQ.6) THEN
                      RE_NUMBER=1
                ELSEIF(TAB_NUMBER.EQ.9) THEN
                      RE_NUMBER=2
                ELSEIF(TAB_NUMBER.EQ.14) THEN
                      RE_NUMBER=3
                ELSEIF(TAB_NUMBER.EQ.19) THEN
                      RE_NUMBER=4
                ELSEIF(TAB_NUMBER.EQ.26) THEN
                      RE_NUMBER=5
                ELSEIF(TAB_NUMBER.EQ.33) THEN
                      RE_NUMBER=6
                ELSEIF(TAB_NUMBER.EQ.42) THEN
                      RE_NUMBER=7
                ELSE
                   PRINT 100,TAB_NUMBER
 100               FORMAT('   THIS IS NOT A BASE REACTION: ',I4)
                   GAMN=0.0
                   RETURN
                ENDIF
 
                RE_NAME=ST_NAMES(RE_NUMBER)
                IF(KIN_ENERGY*1000.0.LE.TK(RE_NUMBER)) THEN
                     GAMN=0.0
                     RETURN
                ENDIF

        X=C*ALOG(KIN_ENERGY*1000./TK(RE_NUMBER))   
	ALV=AL(MAX_POWER(RE_NUMBER),ALFA,X)
                      F=0.0
        DO 1 N=0,MAX_POWER(RE_NUMBER)
        F=F+A(N,RE_NUMBER)*PL(N)
 1      CONTINUE
        F=F*(X**(ALFA/2.0))/EXP(X/2.0)
        GAMN=F**2 
	RETURN 
	END


	REAL*4 FUNCTION AL(N,ALFA,X)
C+
C 
C FUNCTIONAL DESCRIPTION:	
C
C The recurrent calculation of LAGERR's polinoms up to order=20 
C (See for details: Handbook of mathematical functions. Ed. by 
C M.Abramowitz and I.A.Stegun)
C
C CREATION DATE: 
C 
C     08.02.93       by Igor Pshenichnov 
C 
C FORMAL PARAMETERS:
C 
C    N    -  polinom's order
C    ALFA -  parameter
C    X    -  point to be calculated 
C 
C COMMON BLOCKS:
C 
C    /LAGERR/PLAGERR(0:20) array contais polinom's values from 
C                      zero oder to N 
C 
C FUNCTION VALUE:
C 
C    AL   -  N-oder value of LAGERR's polinom    
C 
C-
	COMMON /LAGERR/PLAGERR(0:20)

        DO INDEX=0,20
          PLAGERR(INDEX)=0.0
        END DO
	 
	PLAGERR(0) = 1.
        AL = PLAGERR(0)
	IF (N.EQ.0) RETURN
C
	PLAGERR(1) = ALFA+1-X
        AL = PLAGERR(1)
        IF (N.EQ.1) RETURN
C       
        DO 1 M=1,N-1 
               PLAGERR(M+1) = ((2*M+ALFA+1-X)*PLAGERR(M)-
     #                             (M+ALFA)*PLAGERR(M-1))/(M+1)
  1     CONTINUE
        AL = PLAGERR(N)
        RETURN
	END



        SUBROUTINE GAMN_CHARG(TOP_NUMBER,CHARGE,PART_NUMB)
C+
C 
C FUNCTIONAL DESCRIPTION:	
C 
C    This subroutine is a generator of charges of outgoing particles.
C    It contains SU(2) coefficients table for N+mpi
C 
C CREATION DATE: 
C 
C     14.03.94       by Igor Pshenichnov
C
C FORMAL PARAMETERS:
C 
C 
C    TOP_NUMBER  - topology (number of particles in the final
C                  state (m=3,...,9)).
C 
C    CHARGE      - charge of the taget nucleon   
C 
C    PART_NUMB   - outgoing particle numbers, nucleon comes first
C    
C 
C COMMON BLOCKS:
C
C    /LOGEG/EG,CMSF   - governs the mode of operation: 
C
C   EG:
C   PARTICLE NUMBERS ARE AS IN INC (.FALSE.) OR AS IN GEANT (.TRUE.)
C   
C   CMSF:
C   All the momenta of particles are in CMS (.TRUE.)
C   or in LAB system (.FALSE.)
C    
C-
        
        INTEGER*4 TOP_NUMBER, PART_NUMB(10), NI, NF, NUMPI(3)
        INTEGER*4 NUMNUC(2),CHARGE,IRENUM(7)
        INTEGER*2 CHARG_DAT(4,42)
        REAL*4 SU2(42), PROBAB(9)
        LOGICAL EG,CMSF
        COMMON/LOGEG/EG,CMSF ! Insure compartibility with the INC model.

        real vran(1)


	DATA CHARG_DAT/
C --------- notation is : N(p=1, n=0) kpi+ lpi- mpi0 --------
C ________________________ 3 PARTICLES ______________________
     # 1, 0, 0, 2,   1, 1, 1, 0,   0, 1, 0, 1,        
C ________________________ 4 PARTICLES ______________________
     # 1, 0, 0, 3,   1, 1, 1, 1,   0, 1, 0, 2,   0, 2, 1, 0,
C ________________________ 5 PARTICLES ______________________
     # 1, 0, 0, 4,   1, 1, 1, 2,   1, 2, 2, 0,   0, 1, 0, 3,
     # 0, 2, 1, 1,
C ________________________ 6 PARTICLES ______________________
     # 1, 0, 0, 5,   1, 1, 1, 3,   1, 2, 2, 1,   0, 1, 0, 4,
     # 0, 2, 1, 2,   0, 3, 2, 0, 
C ________________________ 7 PARTICLES ______________________
     # 1, 0, 0, 6,   1, 1, 1, 4,   1, 2, 2, 2,   1, 3, 3, 0,
     # 0, 1, 0, 5,   0, 2, 1, 3,   0, 3, 2, 1,
C ________________________ 8 PARTICLES ______________________
     # 1, 0, 0, 7,   1, 1, 1, 5,   1, 2, 2, 3,   1, 3, 3, 1,
     # 0, 1, 0, 6,   0, 2, 1, 4,   0, 3, 2, 2,   0, 4, 3, 0,
C ________________________ 9 PARTICLES ______________________                  
     # 1, 0, 0, 8,   1, 1, 1, 6,   1, 2, 2, 4,   1, 3, 3, 2,
     # 1, 4, 4, 0,   0, 1, 0, 7,   0, 2, 1, 5,   0, 3, 2, 3,
     # 0, 4, 3, 1/

	DATA SU2/
C ________________________ 3 PARTICLES ______________________
     # 0.10000000,   0.70000000,   0.20000000,
C ________________________ 4 PARTICLES ______________________
     # 0.01000000,   0.75000000,   0.04000000,   0.20000000,
C ________________________ 5 PARTICLES ______________________
     # 0.03333000,   0.36670000,   0.26670000,   0.06667000,
     # 0.26670000,
C ________________________ 6 PARTICLES ______________________
     # 0.00476200,   0.22380000,   0.43810000,   0.02857000,
     # 0.20950000,   0.09524000,
C ________________________ 7 PARTICLES ______________________
     # 0.00476000,   0.11550000,   0.42140000,   0.12500000,
     # 0.01190000,   0.14290000,   0.17860000,
C ________________________ 8 PARTICLES ______________________
     # 0.00061000,   0.05632000,   0.33420000,   0.27550000,
     # 0.00488400,   0.08425000,   0.20150000,   0.04273000,
C ________________________ 9 PARTICLES ______________________
     # 0.00061050,   0.02624000,   0.22600000,   0.35770000,
     # 0.05614000,   0.00383100,   0.09195000,   0.35630000,
     # 0.21460000/


        IF (EG) THEN
          NUMNUC(1)=14  ! proton number
          NUMNUC(2)=13  ! neutron number
          NUMPI(1)=8
          NUMPI(2)=9
          NUMPI(3)=7
          SU2(4)=0.090902
          SU2(5)=0.0  ! since it is simulating via different branch
          SU2(6)=0.363552
          SU2(7)=0.545464
        ELSE   ! "as was"
          NUMNUC(1)=37  ! proton number
          NUMNUC(2)=38  ! neutron number
          NUMPI(1)=1
          NUMPI(2)=2
          NUMPI(3)=7
          SU2(4)=0.01
          SU2(5)=0.75
          SU2(6)=0.04
          SU2(7)=0.2     
        ENDIF

        DO I=1,10
          PART_NUMB(I)=0.0
        ENDDO

C ____ DETERMINE POSITIONS OF CERTAIN MULTIPLICITY IN THE TABLE ___

        NF=TOP_NUMBER*(TOP_NUMBER+1)/2+1
        NI=NF-TOP_NUMBER+1
        SUM=0.
            DO I=1,TOP_NUMBER
                  SUM=SUM+SU2(NI+I-5)
                  PROBAB(I)=SUM
            ENDDO
        call ranmar(vran,1)
        TEMP1=vran(1)
        IABSOL=IDIHOTOMIA(TEMP1,PROBAB,TOP_NUMBER)+NI-1
 
        IF(CHARG_DAT(1,IABSOL-4).EQ.1) THEN
            PART_NUMB(1)=NUMNUC(1)
        ELSEIF(CHARG_DAT(1,IABSOL-4).EQ.0) THEN
            PART_NUMB(1)=NUMNUC(2)
        ENDIF

        IPOSITION=1

        DO K=1,3

        IF (CHARG_DAT(K+1,IABSOL-4).GT.0) THEN
           DO I=1,CHARG_DAT(K+1,IABSOL-4)
               IPOSITION=IPOSITION+1
               PART_NUMB(IPOSITION)=NUMPI(K)
           ENDDO
        ENDIF

        ENDDO
   
                  
      IF(CHARGE.EQ.0) THEN   ! CASE OF GAMMA + NEUTRON
      I=1
      DO WHILE (PART_NUMB(I).GT.0)
        IF(PART_NUMB(I).EQ.NUMNUC(1)) THEN
              PART_NUMB(I)=NUMNUC(2)
        ELSEIF(PART_NUMB(I).EQ.NUMNUC(2)) THEN
              PART_NUMB(I)=NUMNUC(1)
        ELSEIF(PART_NUMB(I).EQ.NUMPI(2)) THEN
              PART_NUMB(I)=NUMPI(1)
        ELSEIF(PART_NUMB(I).EQ.NUMPI(1)) THEN
              PART_NUMB(I)=NUMPI(2)
        ENDIF
         I=I+1
      ENDDO
      ENDIF
        
        RETURN
	END




      SUBROUTINE GENER(PARTIN,IPATIN,IPATNE,TIN1,V,U,MV,ND)
C+
C 
C FUNCTIONAL DESCRIPTION:	
C 
C    This subroutine calls gamma-nucleon event generator,
C    makes a rotation from C-system to CMS-system
C    and fills in memory with produced particles.
C
C
C CREATION DATE: 
C 
C     26.05.95       by Igor Pshenichnov 
C 
      LOGICAL EG,CMSF
      COMMON/LOGEG/EG,CMSF ! Insure compartibility with the INC model.
                           ! See below.
      REAL EGAM,P(4,11),VERTX(3)
      INTEGER I(11),NPART
      COMMON/MONTECARL/ EGAM,I,NPART,P,VERTX
      COMMON/MEMORY/PME(9,100),IME(9,100)
      DIMENSION PARTIN(9),IPATIN(9),IPATNE(5),V(3)
      DIMENSION BETA(4),P_IN(4),P_OUT(4)
      DIMENSION PINS(3),PI(3),PIST(3)
      CHARACTER*12 TARGET,TARGFERMI
      COMMON /TARGET/ ITARG,IIDH,TARGET,TARGFERMI


       EG=.FALSE.   ! NUMBERING AS IN INC (.FALSE.) OR AS IN GEANT (.TRUE.)
       CMSF=.TRUE.  ! All the momenta of particles are in CMS  (.TRUE.)
                    ! or in LAB system (.FALSE.)

       IF (IPATNE(1).EQ.0) THEN       ! NEUTRON AS A TARGET
         TARGET = 'neutron     '
       ELSEIF (IPATNE(1).EQ.1) THEN   ! PROTON AS A TARGET
         TARGET = 'proton      '
       ENDIF

       EGAM=TIN1
       CALL EV_NUC
!      P contains outgoing particles now ... 


! Find incoming particle momentum in CMS system

       DO IDO=1,3
         BETA(IDO)=V(IDO)
       ENDDO
         BETA(4)  = 1./SQRT(1.-(BETA(1)*BETA(1)+BETA(2)*BETA(2)
     &                       +BETA(3)*BETA(3)))
         P_MOD=SQRT(PARTIN(8)*(PARTIN(8)+2.*PARTIN(9)))
         P_IN(1)=P_MOD*PARTIN(4)*PARTIN(7)
         P_IN(2)=P_MOD*PARTIN(4)*PARTIN(6)
         P_IN(3)=P_MOD*PARTIN(5)
         P_IN(4)=PARTIN(8)+PARTIN(9)
         CALL GLOREN(BETA,P_IN,P_OUT)
       DO IDO=1,3
         PINS(IDO)=P_OUT(IDO)
       ENDDO

! Rotate and fill in memory for each particle         
      DO IJ=1,NPART
        DO IDO=1,3
          PI(IDO)=P(IDO,IJ)
        ENDDO
        CALL ROTOR(PINS,V,PI,PIST)

        MTEMP=MV+IJ
        NUM=I(IJ)
        PME(1,MTEMP)=PIST(1)
        PME(2,MTEMP)=PIST(2)
        PME(3,MTEMP)=PIST(3)
        PME(9,MTEMP)=P(4,IJ)  
        
        IME(1,MTEMP)=IQ(NUM)
        IME(2,MTEMP)=0
        IME(3,MTEMP)=IS(NUM)
        IME(4,MTEMP)=IB(NUM)
        IME(8,MTEMP)=NUM
      ENDDO  ! OVER PARTICLES ...

C    NPART=2 CASE SHOULD BE TREATED SEPARATELY
      IF(NPART.EQ.2) THEN
        DO IDO=1,9
          PME(IDO,MTEMP+1)=PME(IDO,MTEMP)
          IME(IDO,MTEMP+1)=IME(IDO,MTEMP)
        ENDDO
      ENDIF

        ND=NPART

      RETURN
      END



      SUBROUTINE IN_GENER
C+
C 
C FUNCTIONAL DESCRIPTION:	
C 
C    This subroutine makes initialization of gamma-nucleon
C    generator.
C
C
C CREATION DATE: 
C 
C     27.05.95       by Igor Pshenichnov 
C 
      INTEGER ITARG,IIDH
      CHARACTER*12 TARGET,TARGFERMI
      COMMON /TARGET/ ITARG,IIDH,TARGET,TARGFERMI
      INTEGER IBEAM,IELET,NCHAIN,ICHAIN(40),ICIBLE,IPOL,ILAM
      REAL ETAG,FWHM
      COMMON/FLAG_COMP/IELET,IBEAM,ICIBLE,ETAG,FWHM,NCHAIN,ICHAIN,IPOL,
     &   ILAM
      INTEGER JCH,INW,INTH,IE
      REAL XSECT(40,50,0:18)
      COMMON /SIGMA/ XSECT,IE

C
C ***      Count processes selected for simulation
C

      DO IDO=1,28
         ICHAIN(IDO)=IDO  
      ENDDO


      NCHAIN = 0
      ILLA  = 0
      DO I = 1,40
         IF (ICHAIN(I).GT.0 ) NCHAIN = NCHAIN + 1
         IF (ICHAIN(I).EQ.29) ILLA  = 1
      ENDDO
      IF (ILLA.NE.1.OR.NCHAIN.GT.1) ILAM  = 0
C
C ***      writes reaction and Lambda polarization header to output
c      PRINT 10, '     Reactions : ',(ICHAIN(I),I=1,NCHAIN)
c      PRINT 11, '     Lambdapol : ',P,SIGM,T,CX,CZ,OX,OZ
10    FORMAT (A17,/1X,20I3/1X,20I3)
11    FORMAT (A17,7(1X,F7.3))


C ***   Beam profile and spectrum depending on beam polarization
C ***   (rudimentary)

      CALL PROFILES

C ***      Read differential cross section data file
      OPEN (UNIT=55,FILE='ch.mat',status='OLD')
         DO JCH=1,40
            READ(55,2323)
            DO INW=1,50
               READ(55,7) (XSECT(JCH,INW,INTH),INTH=0,4)
               READ(55,8) (XSECT(JCH,INW,INTH),INTH=5,18)
            END DO
         END DO
      CLOSE (UNIT=55)
2323  FORMAT (1X)
   7  FORMAT (20X,5G10.3)
   8  FORMAT (7G10.3)

C ***      defines polarized Lambda and histo for diff. cross section
         IF (ILAM.NE.0) THEN
            CALL GSPART(18,'LAMPOL',3,1.11563,0.,2.631E-10,0.,0)
            CALL HBOOK2(105,'SECPOL',18,0.,180.,60,0.,6.2831,0.)
            PRINT*
            PRINT*
         ENDIF

! Put particle names for each channel

         CALL CHANNELDEF

C ***   Verification of reaction channels both for proton or neutron
C       as an example.

                  TARGET = 'proton      '
         CALL TOTALSECT


      RETURN
      END
