c  from patch gcdes in file /usr/site3/cern/hp700_ux90/94a/src/car/geant321.car on Thu Nov 10 11:00:38 EST 1994
c  this is seq: GCBANK & GCLINK

      INTEGER IQ,LQ,NZEBRA,IXSTOR,IXDIV,IXCONS,LMAIN,LR1,JCG
      INTEGER KWBANK,KWWORK,IWS
      REAL GVERSN,ZVERSN,FENDQ,WS,Q
C
#ifdef DEBUG

      PARAMETER (KWBANK=3000000,KWWORK=5200)
      DIMENSION IQ(kwbank-6+1000),Q(kwbank-6+1000),
     1     LQ(kwbank+2+1000),IWS(kwbank+1000)

#else

      PARAMETER (KWBANK=69000,KWWORK=5200)
      DIMENSION IQ(2),Q(2),LQ(8000),IWS(2)

#endif

      EQUIVALENCE (Q(1),IQ(1),LQ(9)),(LQ(1),LMAIN),(IWS(1),WS(1))
      EQUIVALENCE (JCG,JGSTAT)

      COMMON/GCBANK/NZEBRA,GVERSN,ZVERSN,IXSTOR,IXDIV,IXCONS,FENDQ(16)
     +             ,LMAIN,LR1,WS(KWBANK)


      INTEGER       JDIGI ,JDRAW ,JHEAD ,JHITS ,JKINE ,JMATE ,JPART
     +      ,JROTM ,JRUNG ,JSET  ,JSTAK ,JGSTAT,JTMED ,JTRACK,JVERTX
     +      ,JVOLUM,JXYZ  ,JGPAR ,JGPAR2,JSKLT
C
      COMMON/GCLINK/JDIGI ,JDRAW ,JHEAD ,JHITS ,JKINE ,JMATE ,JPART
     +      ,JROTM ,JRUNG ,JSET  ,JSTAK ,JGSTAT,JTMED ,JTRACK,JVERTX
     +      ,JVOLUM,JXYZ  ,JGPAR ,JGPAR2,JSKLT
C
C