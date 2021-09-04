	SUBROUTINE PREP_2D(XA,YA,N,A,B)
!
!                MAKE ARRAY EMPTY
!
	    DIMENSION XA(N),YA(N)
	STEP=(B-A)/(N-6)
           
	
	DO I=1,N-5
	    XA(I)=A+(I-1)*STEP
            YA(I)=0.0
        END DO
        	DO I=N-4,N
	         XA(I)=0.0
                 YA(I)=0.0
                END DO
	RETURN
	END


	SUBROUTINE HIST_2D(X,XA,YA,N,W)
! 
!                  MAKE A HISTOGRAM:
!    XA - ARRAY(N) WITH X
!    YA - ARRAY(N) WITH Y
!    X - VALUE TO BE HISTOGRAMMED
!    W - WEIGHT
!
!                  LAST 5 ELEMENTS OF YA CONTAIN:
!    N-4 - EVENTS LOWER XA(1)
!    N-3 - EVENTS INSIDE [XA(1),XA(N-5)]
!    N-2 - EVENTS UPPER XA(N-5)
!    N-1 - SUM OF X INSIDE [XA(1),XA(N-5)]    
!    N   - SUM OF X (GLOBAL)

        	DIMENSION XA(N),YA(N)
	YA(N)=YA(N)+W
	IK=IDIHOTOMIA(X,XA,N-5)
	 
	IF (IK.EQ.1) THEN
	    YA(N-4)=YA(N-4)+W
	ELSE IF (IK.GT.N-5) THEN
	    YA(N-2)=YA(N-2)+W
	ELSE
	    YA(N-3)=YA(N-3)+W
	    YA(N-1)=YA(N-1)+X
	    YA(IK-1)=YA(IK-1)+W
        END IF
	RETURN
	END


	SUBROUTINE CLEAR(PR,N)
! 	 
	DIMENSION PR(N)
	 
	DO I=1,N
	    PR(I)=1.0E-05
        END DO
	RETURN
	END

 
        SUBROUTINE PRINT_1D(FIRST_LABEL,COUNT,BR,SEC_LABEL,NVOID)
!
!         PRINT THE RESULT AND ERROR WITH NOTATIONS AND UNITS     
!               APPROPRIATE FORMAT HAS TO BE SELECTED
!
        COMMON/MODE/MODE,PATH
        COMMON/W_MODE/COMPACT
        CHARACTER*20 FIRST_LABEL,F
        CHARACTER*10 SEC_LABEL,S
        CHARACTER*5 PP
        CHARACTER*45 PATH
        LOGICAL COMPACT
 
        IF ((MODE.EQ.0).AND.(NVOID.EQ.1).AND.COMPACT) THEN

             IF(COUNT.GT.0.) THEN
               REL_ERR=1./SQRT(COUNT)
             ELSE
               REL_ERR=0.
             ENDIF
          WRITE(20,4)FIRST_LABEL,COUNT,REL_ERR,SEC_LABEL
 4        FORMAT(5X,A20,':',E14.7,' +/- ',E14.7,' ',A10)

        ELSEIF((NVOID.EQ.1).AND.COMPACT) THEN

          READ(20,5)F,COUNT,PP,REL_ERR,S
 5        FORMAT(A26,E14.7,A5,E14.7,A11)

        ENDIF


        IF (MODE.EQ.0) THEN 
 
        IF (BR.EQ.0.) RETURN
                   VALUE=COUNT/BR
                             ERROR=SQRT(COUNT)/BR
        IF ((VALUE.LE.100.).AND.(VALUE.GE.0.001)) THEN
          PRINT 1, FIRST_LABEL,VALUE,ERROR,SEC_LABEL
 1        FORMAT(5X,A20,':',F12.4,' +/- ',F12.6,' ',A10)
        ELSE
          PRINT 2, FIRST_LABEL,VALUE,ERROR,SEC_LABEL
 2        FORMAT(5X,A20,':',E12.4,' +/- ',E12.6,' ',A10)
        ENDIF

        ENDIF    

        RETURN
        END

	SUBROUTINE PRINT_2D(FILENAME,MESSAGE,ANCAS,XA,YA,NMAX,
     #                                     XA1,YA1,N1,LABEL1,
     #                                     XA2,YA2,N2,LABEL2,
     #                                     NVOID)
        COMMON/MODE/MODE,PATH

	DIMENSION PR(10),PP(10),NDIM(2)
	DIMENSION XE(2,3),YE(2,3),YD(2,3),XA(2,NMAX),YA(2,NMAX)
	DIMENSION XA1(N1),YA1(N1),XA2(N2),YA2(N2)
        DIMENSION NX(3),NY(3)
	CHARACTER*8 FILENAME
	CHARACTER*60 MESSAGE
	CHARACTER*45 LABEL1,LABEL2,LD(2),PATH
	DATA NX/0,1,1/ NY/0,0,1/

        IF ((MODE.EQ.0).AND.(NVOID.EQ.1)) THEN

	OPEN (
     1 UNIT=30,
     1   FILE = PATH//FILENAME//'.XH2',
     1   STATUS = 'UNKNOWN')
        WRITE(30,30),MESSAGE
 30     FORMAT(1X,A60)

        DO I=1,NMAX

          IF(I.LE.N1)THEN
             R1=XA1(I)
                    R2=YA1(I)
             IF(YA1(I).GT.0.0) THEN
                R3=1./SQRT(YA1(I))
             ELSE
                R3=0.0
             ENDIF
          ELSE
             R1=0.0
                R2=0.0
                    R3=0.0
          ENDIF

          IF(I.LE.N2)THEN
             R4=XA2(I)
                    R5=YA2(I)
             IF(YA2(I).GT.0.0) THEN
                R6=1./SQRT(YA2(I))
             ELSE
                R6=0.0
             ENDIF
          ELSE
             R4=0.0
                R5=0.0
                    R6=0.0
          ENDIF

          WRITE(30,31)R1,R2,R3,R4,R5,R6
 31       FORMAT(1X,2(3(1X,E14.7),1X))
        
        ENDDO

        ELSEIF(NVOID.EQ.1) THEN

	OPEN (
     1 UNIT=30,
     1   FILE = PATH//FILENAME//'.XH2',
     1   STATUS = 'UNKNOWN')
        READ(30,30)MSS
   
        DO I=1,NMAX
          READ(30,32)R1,R2,R3,R4,R5,R6
 32       FORMAT(2(3(1X,E14.7),1X))
          IF (I.LE.N1) THEN
             XA1(I)=R1
             YA1(I)=R2
          ENDIF
          IF (I.LE.N2) THEN
             XA2(I)=R4
             YA2(I)=R5
          ENDIF
        ENDDO

        ENDIF


        IF (MODE.EQ.0) THEN 

	LEVEL=8
	      NDIM(1)=N1
	      NDIM(2)=N2
                   LD(1)=LABEL1
                   LD(2)=LABEL2
        NHOR=0
           DO L=1,2
             IF(NDIM(L).GT.9) NHOR=L
           ENDDO
	 
	OPEN (
     1 UNIT=16,
     1   FILE = FILENAME//'.DAT',
     1   STATUS = 'UNKNOWN',
     1   RECL = 255)
	OPEN (
     1 UNIT=17,
     1   FILE = FILENAME//'.TXT',
     1   STATUS = 'UNKNOWN')
        	WRITE (UNIT=17, FMT=1)
  	        WRITE (UNIT=17, FMT=2)
        	WRITE (UNIT=17, FMT=3)
	        WRITE (UNIT=17, FMT=4),NHOR
        DO L=1,NHOR
              WRITE(17,21)L,LD(L)
        ENDDO

1	FORMAT (1X,'1244')
2	FORMAT (1X,'"SET10" "DEFAULT" 76 1')
3	FORMAT (1X,'3.305e+000 7.192e+000 0.000e+000 1.500e-001')
4	FORMAT (1X,I1)
21      FORMAT(1X,I1,' 45 "',A45,'"')

	        WRITE(17,17),MESSAGE,FILENAME//'.DAT'
17	FORMAT (/////1X,A60/3X,'WAS PRINTED INTO FILE: ',A12)

        DO I=1,2
          DO J=1,3
             XE(I,J)=0.0
             YD(I,J)=0.0
          ENDDO
          DO J=1,NMAX
             XA(I,J)=0.0
             YA(I,J)=0.0
          ENDDO
        ENDDO
 
        DO J=1,N1
           XA(1,J)=XA1(J)
           YA(1,J)=YA1(J)
        ENDDO
        DO J=1,N2
           XA(2,J)=XA2(J)
           YA(2,J)=YA2(J)
        ENDDO
        
        DO L=1,NHOR
           IF(NDIM(L).GT.9) THEN
              WRITE(17,18),LD(L),XA(L,1),XA(L,NDIM(L)-5),
     #        YA(L,NDIM(L)-4),YA(L,NDIM(L)-3),YA(L,NDIM(L)-2)
              IF(YA(L,NDIM(L)-3).GT.0.0) THEN
                 WRITE(17,19),YA(L,NDIM(L)-1)/YA(L,NDIM(L)-3)
                 NMIDL=(NDIM(L)-5)/2
                 I=1
                 NBEGIN=I
                 DO WHILE ((YA(L,I).LT.LEVEL).AND.(I.LE.NMIDL))
                     NBEGIN=I
                     I=I+1
                 ENDDO
                 I=NDIM(L)-5
                 NEND=I
                 DO WHILE ((YA(L,I).LT.LEVEL).AND.(I.GE.NMIDL))
                     NEND=I
                     I=I-1
                 ENDDO
                      WRITE(17,45),NBEGIN,NMIDL,NEND
45              FORMAT(11X,'NBEGIN=',I4,'  NMIDL=',I4,'  NEND=',I4)
                   YD(L,1)=SQRT(YA(L,NBEGIN))/YA(L,NDIM(L)-3)                 
                   YD(L,2)=SQRT(YA(L,NMIDL))/YA(L,NDIM(L)-3)                 
                   YD(L,3)=SQRT(YA(L,NEND))/YA(L,NDIM(L)-3)                 
                   XE(L,1)=(XA(L,NBEGIN)+XA(L,NBEGIN+1))/2.
                   XE(L,2)=(XA(L,NMIDL)+XA(L,NMIDL+1))/2.
                   XE(L,3)=(XA(L,NEND)+XA(L,NEND+1))/2.
                   YE(L,1)=YA(L,NBEGIN)
                   YE(L,2)=YA(L,NMIDL)
                   YE(L,3)=YA(L,NEND)
              ENDIF
                 WRITE(17,20),YA(L,NDIM(L))
           ENDIF
        ENDDO

 18     FORMAT(/1X,A45,'  : '/1X,' LOW LIMIT: ',E10.3,5X,
     # ' UPPER LIMIT: ',E10.3/1X,'EVENTS LOWER:',E10.3,3X,
     # 'EVENTS INSIDE: ',E10.3,3X,'EVENTS UPPER:',E10.3)
 19     FORMAT(11X,'MEAN VALUE INSIDE: ',E10.3)
 20     FORMAT(11X,'TOTAL NUM. EVENTS: ',E10.3)
 22     FORMAT(1X,10(E10.3,1X))
 23     FORMAT(1X,2(2(E10.3,1X),(3(4(' '),'00',4(' '),1X))))

        DO I=1,3
          CALL CLEAR(PR,10)
          DO L=1,NHOR
             IF((YA(L,NDIM(L)-3).GT.0.0).AND.(NDIM(L).GT.9)) THEN
                  PR((L-1)*5+1)=XA(L,1+NX(I))
                  PR((L-1)*5+2)=YA(L,1+NY(I))/ANCAS
                  PR((L-1)*5+3)=XE(L,I)
                  PR((L-1)*5+4)=YE(L,I)/ANCAS
                  PR((L-1)*5+5)=YD(L,I)
             ENDIF
          ENDDO
          WRITE(16,22),(PR(K),K=1,NHOR*5)
        ENDDO
        CALL CLEAR(PR,10)
          DO L=1,NHOR
             IF((YA(L,NDIM(L)-3).GT.0.0).AND.(NDIM(L).GT.10)) THEN
                  PR((L-1)*2+1)=XA(L,3)
                  PR((L-1)*2+2)=YA(L,2)/ANCAS
             ENDIF
          ENDDO
        WRITE(16,23),(PR(K),K=1,NHOR*2)

        DO I=3,NMAX-7
           CALL CLEAR(PR,10)
           CALL CLEAR(PP,10)
           DO L=1,NHOR
            IF((YA(L,NDIM(L)-3).GT.0.0).AND.(I.LE.NDIM(L)-5)) THEN
               PR((L-1)*2+1)=XA(L,I)
               PR((L-1)*2+2)=YA(L,I)/ANCAS
               PP((L-1)*2+1)=XA(L,I+1)
               PP((L-1)*2+2)=YA(L,I)/ANCAS
            ENDIF
           ENDDO
           WRITE(16,23),(PR(K),K=1,NHOR*2)
           WRITE(16,23),(PP(K),K=1,NHOR*2)
        ENDDO
            CLOSE(16)
            CLOSE(17)

        ENDIF

	RETURN
	END

	SUBROUTINE PREP_3D(X,NX,AX,BX,Y,NY,AY,BY,Z)
	DIMENSION X(NX),Y(NX),Z(NX,NY)

            STEPX=(BX-AX)/(NX-6)
            STEPY=(BY-AY)/(NY-6)

             DO I=1,NX-5
                 X(I)=AX+(I-1)*STEPX
             ENDDO
             
             DO I=1,NY-5
                 Y(I)=AY+(I-1)*STEPY  
             ENDDO
              
             DO I=NX-4,NX
               X(I)=0.0
             ENDDO

             DO I=NY-4,NY
               Y(I)=0.0
             ENDDO
  
             DO I=1,NX
             DO J=1,NY
               Z(I,J)=0.0
             ENDDO
             ENDDO
	RETURN
	END


	SUBROUTINE HIST_3D(XS,YS,X,NX,Y,NY,Z,W)
!
!                     MAKE A 3D-HISTOGRAMM:
! X(NX) - ARRAY WITH 1ST COORDINATE
! Y(NY) - ARRAY WITH 2ND COORDINATE
! XS,YS - POINT TO BE HISTOGRAMMED
! W     - WEIGHT
! Z(NX,NY) - ARRAY FOR ACCUMULATION
!
!         LAST 5 ELEMENTS OF EDGE OF Z(NX,NY) CONTAIN
!         FOR EVERY REGION: [Y(L-1);Y(L)]
! NX-4  - EVENTS LOWER X(1)
! NX-3  - EVENTS INSIDE [X(1),X(NX-5)]
! NX-2  - EVENTS UPPER X(NX-5)
! NX-1  - SUM OF XS INSIDE [X(1),X(NX-5)]
! NX    - SUM OF XS
!         (THE SAME FOR Y)
!

	DIMENSION X(NX),Y(NY),Z(NX,NY)

	IX=IDIHOTOMIA(XS,X,NX-5)
        IY=IDIHOTOMIA(YS,Y,NY-5)
	 
	IF ((IX.EQ.1).AND.(IY.EQ.1)) THEN
	    Z(NX-4,NY-4)=Z(NX-4,NY-4)+W
	ELSE IF ((IX.EQ.1).AND.(IY.GT.NY-5)) THEN
	    Z(NX-4,NY-2)=Z(NX-4,NY-2)+W
	ELSE IF ((IX.GT.NX-5).AND.(IY.EQ.1)) THEN
	    Z(NX-2,NY-4)=Z(NX-2,NY-4)+W
	ELSE IF ((IX.GT.NX-5).AND.(IY.GT.NY-5)) THEN
	    Z(NX-2,NY-2)=Z(NX-2,NY-2)+W
	ELSE IF (IX.EQ.1) THEN
	    Z(NX-4,NY-3)=Z(NX-4,NY-3)+W
            Z(NX-4,NY-1)=Z(NX-4,NY-1)+XS
            Z(NX-4,IY-1)=Z(NX-4,IY-1)+W
	ELSE IF (IX.GT.NX-5) THEN
	    Z(NX-2,NY-3)=Z(NX-2,NY-3)+W
            Z(NX-2,NY-1)=Z(NX-2,NY-1)+XS
            Z(NX-2,IY-1)=Z(NX-2,IY-1)+W	    
	ELSE IF (IY.EQ.1) THEN
	    Z(NX-3,NY-4)=Z(NX-3,NY-4)+W
            Z(NX-1,NY-4)=Z(NX-1,NY-4)+YS
            Z(IX-1,NY-4)=Z(IX-1,NY-4)+W
	ELSE IF (IY.GT.NX-5) THEN
	    Z(NX-3,NY-2)=Z(NX-3,NY-2)+W
            Z(NX-1,NY-2)=Z(NX-1,NY-2)+YS
            Z(IX-1,NY-2)=Z(IX-1,NY-2)+W
	ELSE
            Z(IX-1,NY-3)=Z(IX-1,NY-3)+W
            Z(IX-1,NY-1)=Z(IX-1,NY-1)+XS
            Z(NX-3,IY-1)=Z(NX-3,IY-1)+W
            Z(NX-1,IY-1)=Z(NX-1,IY-1)+YS
            Z(IX-1,IY-1)=Z(IX-1,IY-1)+W
	    END IF
	RETURN
	END


	SUBROUTINE PRINT_3D(FILENAME,MESSAGE,ANCAS,X,NX,Y,NY,Z,NVOID)
	DIMENSION X(NX),Y(NY),Z(NX,NY)
	CHARACTER*8 FILENAME
	CHARACTER*60 MESSAGE
	 
	OPEN (
     1 UNIT=16,
     1   FILE = FILENAME//'.DAT',
     1   STATUS = 'UNKNOWN')
	OPEN (
     1 UNIT=17,
     1   FILE = FILENAME//'.TXT',
     1   STATUS = 'UNKNOWN')

	WRITE(17,17), MESSAGE,FILENAME//'.DAT'
17	FORMAT (//1X,A60/3X,'WAS PRINTED IN FILE: ',A12)
        HORISON=-1.0
	DO I=1,NX-6
	    DO J=1,NY-6
		IF (Z(I,J).GT.HORISON) THEN
	WRITE(16,18),((X(I)+X(I+1))/2.),((Y(J)+Y(J+1))/2.),Z(I,J)/ANCAS
18        FORMAT(1X,3E10.3)
		    END IF
		END DO
	    END DO
            CLOSE(16)
            CLOSE(17)
	RETURN
	END

	SUBROUTINE PRINT_CORR(FILENAME,MESSAGE,
     #                                         C1,N1,LABEL1,
     #                                         C2,N2,LABEL2)
	DIMENSION PR(10),PP(10),NDIM(2)
	DIMENSION C(10,60),C1(3,30),C2(3,30)
	CHARACTER*8 FILENAME
	CHARACTER*60 MESSAGE
	CHARACTER*45 LABEL1,LABEL2,LD(2)

	      NDIM(1)=N1
	      NDIM(2)=N2
         NMAX=N1
         IF(N2.GT.NMAX) NMAX=N2

                   LD(1)=LABEL1
                   LD(2)=LABEL2
        NHOR=0
           DO L=1,2
             IF(NDIM(L).GT.1) NHOR=L
           ENDDO
	 
	OPEN (
     1 UNIT=16,
     1   FILE = FILENAME//'.DAT',
     1   STATUS = 'UNKNOWN',
     1   RECL = 255)
	OPEN (
     1 UNIT=17,
     1   FILE = FILENAME//'.TXT',
     1   STATUS = 'UNKNOWN')
        	WRITE (UNIT=17, FMT=1)
  	        WRITE (UNIT=17, FMT=2)
        	WRITE (UNIT=17, FMT=3)
	        WRITE (UNIT=17, FMT=4),NHOR
        DO L=1,NHOR
              WRITE(17,21)L,LD(L)
        ENDDO

1	FORMAT (1X,'1244')
2	FORMAT (1X,'"SET10" "DEFAULT" 76 1')
3	FORMAT (1X,'3.305e+000 7.192e+000 0.000e+000 1.500e-001')
4	FORMAT (1X,I1)
21      FORMAT(1X,I1,' 45 "',A45,'"')

	        WRITE(17,17),MESSAGE,FILENAME//'.DAT'
17	FORMAT (//1X,A60/3X,'WAS PRINTED INTO FILE: ',A12)

        DO I=1,10
          DO J=1,60
             C(I,J)=0.0
          ENDDO
        ENDDO
 
        DO K=1,N1

           C(1,2*K-1) =  K-1.5
           C(1,2*K)   =  K-0.5

           C(2,2*K-1) =  C1(1,K)
           C(2,2*K)   =  C1(1,K)

           C(3,2*K-1) =  K-1.0
           C(3,2*K)   =  K-1.0

           C(4,2*K-1) =  C1(1,K)
           C(4,2*K)   =  C1(1,K)

           C(5,2*K-1) =  C1(3,K)
           C(5,2*K)   =  C1(3,K)

        ENDDO
        
        DO K=1,N2

           C(1,2*K-1) =  2*K-2.5
           C(1,2*K)   =  2*K-1.5

           C(2,2*K-1) =  C2(1,K)
           C(2,2*K)   =  C2(1,K)

           C(3,2*K-1) =  K-1.0
           C(3,2*K)   =  K-1.0

           C(4,2*K-1) =  C2(1,K)
           C(4,2*K)   =  C2(1,K)

           C(5,2*K-1) =  C2(3,K)
           C(5,2*K)   =  C2(3,K)

        ENDDO
        
        DO L=1,NHOR
              WRITE(17,18),LD(L)
        ENDDO

 18     FORMAT(/1X,A45,'    ')
 22     FORMAT(1X,10(E10.3,1X))

        DO J=1,NMAX*2
          WRITE(16,22),(C(M,J),M=1,NHOR*5)
        ENDDO

            CLOSE(16)
            CLOSE(17)
	RETURN
	END




            INTEGER FUNCTION IDIHOTOMIA(TRY,ARRAY,NA)
C
C                FIND THE NUMBER ID SATISFIED:
C                ARRAY(ID-1).LT.TRY.LE.ARRAY(ID)
C                
C

         REAL*4 ARRAY(NA)
         IF(TRY.LE.ARRAY(1)) THEN
           IDIHOTOMIA=1
         ELSE IF(TRY.GT.ARRAY(NA)) THEN
           IDIHOTOMIA=NA+1
         ELSE
                             NBEGIN=1
                             NEND=NA
                      NRANGE=(NEND-NBEGIN)/2+NBEGIN
                 DO WHILE ((NEND-NBEGIN).GT.1)
                    IF(TRY.GT.ARRAY(NRANGE)) THEN
                        NBEGIN=NRANGE
                    ELSE
                        NEND=NRANGE
                    END IF
                    NRANGE=(NEND-NBEGIN)/2+NBEGIN
                 END DO
         IDIHOTOMIA=NEND
         END IF
         RETURN 
         END         


                 REAL*4 FUNCTION ALI(X,T,B,N)
C  
C          MAKE A LINEAR INTERPOLATION OF THE B(N) ARRAY 
C                     AT X ABSCISSA VALUE
C
                 REAL*4 B(N),T(N)

        IK=IDIHOTOMIA(X,T,N)
        IF (IK.EQ.1) THEN
           ALI=B(1)
           RETURN
        ELSE IF (IK.GT.N) THEN
           ALI=B(N)
           RETURN
        ELSE 
        ALI=((B(IK)-B(IK-1))/(T(IK)-T(IK-1)))*(X-T(IK-1))+B(IK-1)
        END IF
        RETURN
        END
