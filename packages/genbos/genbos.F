	PROGRAM GENBOS

C *****************************************************************
C *** Main program
C *****************************************************************
C *** OUTPUT VECTORS
C ***
C *** Final state of particle iii
C *** P(1,iii)=px
C *** P(2,iii)=py
C *** P(3,iii)=pz
C *** P(4,iii)=mass
C ***
C *** Intermediate state of particle iii
C *** P_1(1,iii)=px
C *** P_1(2,iii)=py
C *** P_1(3,iii)=pz
C *** P_1(4,iii)=mass
C ***
C ******************************************************************

	PARAMETER (NH=200000)
	COMMON/PAWC/H(NH)

	integer ev,vt,tk !AHMED
	CHARACTER*20 FILEN,FILEP
      	COMMON/FNAME/FILEN,FILEP

      	COMMON/NACH/IX,IY,YEL


	INTEGER NERR,LOOPV,NCAS,LOOPC,NPROC,JCH
	COMMON /FLAG_GEN/ NERR,LOOPV,NCAS,LOOPC,NPROC

	REAL EGAM, P(4,11),VERTX(3)
	INTEGER I(11),NPART
	COMMON/MONTECARL/ EGAM,I,NPART,P,VERTX

	INTEGER IBEAM,IELET,NCHAIN,ICHAIN(40),ICIBLE,IPOL,ILAM
	REAL ETAG,FWHM
	COMMON/FLAG_COMP/IELET,IBEAM,ICIBLE,ETAG,FWHM,NCHAIN,ICHAIN,IPOL,
     &   	ILAM

	COMMON/NSTATIS/NSTATIS

        CHARACTER*12 PARTIC(40,0:3,0:3,8)
        INTEGER JDEC(40),NCH(40),NPLEV(40,3)
        REAL BR(40,3)
        COMMON /CHANNELS/ PARTIC,JDEC,NCH,NPLEV,BR

	LOGICAL EG,CMSF
	COMMON/LOGEG/EG,CMSF	! Insure compartibility with the INC model.
				! See below.

	CHARACTER*50 NCANAL(40)
	COMMON/CLABEL/NCANAL

C *** common per la ntupla
#include "nt_kine.inc"
#include "control.inc"
#include "bcs.inc"
#include "file_names.inc"


C *** ntuple variables

C *** General of the event
	common/evnt/nev,efot,nreac,vx,vy,vz
	integer nev,nreac
	real efot,vx,vy,vz

C *** final state particles
	common/finst/np,idg(11),idr(11),qch(11),mass(11),imp(11)
     +		    ,cx(11),cy(11),cz(11)
	integer np,idg,idr,qch
	real mass,imp,cx,cy,cz

C *** primary reaction
	common/prim/np1,idg1(11),idr1(11),qch1(11),mass1(11),imp1(11)
     +		    ,cx1(11),cy1(11),cz1(11)
	integer np1,idg1,idr1,qch1
	real mass1,imp1,cx1,cy1,cz1


c *** local variables
	integer id
	real chg,p0(3),v1(4),v2(4)


C ***      memory allocation for ZEBRA & HBOOK

	CALL HLIMIT(NH)

C *** inizialization
c        CALL TC4
        CALL CARDS
        CALL GEN_INIT
	call init_genbos

C *** random generator inizialization
        call rmarin(ix,1000,0)

C *** open log file
	open (unit=15,file=file_log,status='unknown')

	write (15,'(/)')
	write (15,*) 'Number of events:',nstatis
	write (15,'(/)')

	if (ibeam.eq.0) then
	   write (15,62) etag,fwhm
	else if (ibeam.eq.2) then
	   write (15,63) etag+fwhm,etag-fwhm
	else if (ibeam.eq.3) then
	   write (15,64) etag,fwhm
	endif

	if (icible.eq.0) then
	   write (15,65) ' Neutron target'
	else if (icible.eq.1) then
	   write (15,65) ' Proton target'
	else if (icible.eq.2) then
	   write (15,65) ' Deuteron target'
	endif

	if (cmsf) then
	   write (15,*) 'Center of mass system for outgoing particles'
	else
	   write (15,*) 'Laboratory system for outgoing particles'
	endif
	write (15,'(/)')


	WRITE (15,*)'Interaction point extracted in'
	if (targ_type.eq.0) then
	   WRITE (15,67) 
	else if (targ_type.eq.1) then
	   write (15,68) targ_r,targ_l
	else if (targ_type.eq.2) then
	   write (15,69) targ_r,targ_l
	else if (targ_type.eq.3) then
	   write (15,70) targ_r,targ_l
	endif

	write (15,*) ' Selected reaction channels'
	do k=1,nchain
	   if (ichain(k).ne.0) write (15,66) ichain(k),ncanal(ichain(k))
	enddo


	close (15)

 60	format (' ielet=',i2,a,/)
 62	format (' Gaussian spectrum: E=',F10.3,' +/- ',F10.3,/)
 63	format (' Bremsstrahlun spectrum: Emax=',F10.3,' Emin=',F10.3,/)
 64	format (' Uniform spectrum: E=',F10.3,' +/- ',F10.3,/)
 65	format (a,/)
 66	format (' channel n.',i3,3x,a)
 67	format (2x,'pointlike target',/)
 68	format (2x,'cylindrical target:R=',f6.3,' cm, L=',f6.3,' cm',/)
 69	format (2x,'full CLAS target "cuivre":R=',f6.3,' cm, L=',f6.3,' cm',/)
 70	format (2x,'full CLAS target "cigare":R=',f6.3,' cm, L=',f6.3,' cm',/)


C *** book the ntuple
	if (.not.no_nt_out) call hropen(2,'generator',file_nt,'N',1024,istat)

	call hbnt (10,'generator',' ')

	call hbname (10,'evnt',nev,
     +               'nev:I, efot:R, nreac:I, vx:R, vy:R, vz:R')

C *** final state particles
        call hbname (10,'finst',np,'np[0,11]:I, 
     +               idg(np):I, idr(np):I, qch(np):I,
     +               mass(np):R, imp(np):R,
     +               cx(np):R, cy(np):R, cz(np):R')

C *** primary interaction particle
        call hbname (10,'prim',np1,'np1[0,11]:I, 
     +               idg1(np1):I, idr1(np1):I, qch1(np1):I,
     +               mass1(np1):R, imp1(np1):R,
     +               cx1(np1):R, cy1(np1):R, cz1(np1):R')

	chg = 0

c	open(1,file='genbos.out',status='unknown')
	DO  IDO=1,NSTATIS
c	   print *,'***** evento  ',ido,'  **********'

C *** event generation
	   CALL MONTECARLO

c	   write (*,13) amx,amx,efot,efot,amx
c 13	   format (1x,'gamma ',5(1x,f8.5))
c	   print *,' '
c	   print *,'   canale',j_channel

C ****************************
C *** fill BOS and ntuple
C ****************************


C *****************************************
C *** dati generali evento 
C *****************************************

	   nev=ido		!ev.number
	   efot=egam		!photon en.
	   nreac=j_channel	!reaction chan.
	   np=npart		!number of secondaries

C *** Vertex coordinates
	  if (targ_type.eq.0) then
	     p0(1)=0.
	     p0(2)=0.
	     p0(3)=0.
	  else
	     call vert_extr(p0)
	  endif
	  vx=p0(1)
	  vy=p0(2)
	  vz=p0(3)

	  call hfntb(10,'evnt')


	  call bos_head(15,0,IDO)
	  ev=nbank('MCEV',0,2,1)
	  vt=nbank('MCVX',0,5,1)
          tk=nbank('MCTK',0,11,NPART)

C ********************************************
C *** Filling TAG bank

	  iTAGR = nbank('TAGR',0,6,1)

	  rw(iTAGR+1)= efot	! photon energy
	  rw(iTAGR+2)= 0.	! Time of the photon has reconstructed in the Tagger
	  rw(iTAGR+3)= 0.	! Time of the photon after RF correction
	  iw(iTAGR+4)= 7	! Status ( 7 or 15 are Good)
	  iw(iTAGR+5)= 0	! T counter Id
	  iw(iTAGR+6)= 0	! E counter Id 
	                        !modified: is reac channel

C ********************************************

	  iw(ev+1)=111
	  iw(ev+2)=111           !random seeds fixed (?)

C *** Vertex coordinates
	  rw(vt+1)=p0(1)
	  rw(vt+2)=p0(2)
	  rw(vt+3)=p0(3)

	  rw(vt+4)=0.0           !tof max (or should be minimum?)
	  iw(vt+5)=IDO           !trak number equal ev number (or could it be
c                                 a fixed number ?
c	  write(1,*)IDO,NPART


	  amx=0.

C ***************************************
C *** Final state
C ***************************************

c	   print *,'GENBOS   stato finale'
	   DO III=1,NPART

c            write(1,*)I(III),P(1,III),P(2,III),P(3,III),P(4,III)
c	     ene=sqrt( P(1,III)**2.+P(2,III)**2.+P(3,III)**2.+P(4,III)**2.)
c	     print *,I(III),' LAB',P(1,III),P(2,III),P(3,III),P(4,III),ene
c	     write (*,12) I(III),P(1,III),P(2,III),P(3,III),ene,P(4,III)
c 12	     format (4x,i3,5(1x,f8.5))

C *** variabili per la ntupla
	    idg(iii)=i(iii)
	    call idchg(I(III),chg,id)
	    idr(iii)=id
	    qch(iii)=chg
c	    print *,'2,i,chg,id', I(III),chg,id
	    mass(iii)=p(4,iii)

C ***************************************************
C *** Lorentz transformation from LAB to CM, if needed
	    if (cmsf) then
	       xx=0.
	       do k=1,3
		  v1(k)=p(k,iii)
		  xx=xx+v1(k)**2.
	       enddo
	       v1(4)=sqrt(xx+p(4,iii)*p(4,iii))

	       call gloren (beta_cm,v1,v2)

	       xx=0.
	       do k=1,3
		  p(k,iii)=v2(k)
		  xx=xx+v2(k)**2.
	       enddo
	       p(4,iii)=sqrt(v2(4)*v2(4)-xx)

	    endif
c	    ene=sqrt( P(1,III)**2.+P(2,III)**2.+P(3,III)**2.+P(4,III)**2.)
c	    print *,I(III),' CM ',P(1,III),P(2,III),P(3,III),P(4,III),ene
C ***************************************************

	    pmom=sqrt(P(1,III)*P(1,III)+P(2,III)*P(2,III)+
     &                   P(3,III)*P(3,III))
	    imp(iii)=pmom
	    cx(iii)=P(1,III)/pmom
	    cy(iii)=P(2,III)/pmom
	    cz(iii)=P(3,III)/pmom




	    rw(tk+1+(III-1)*11)=P(1,III)/pmom
	    rw(tk+2+(III-1)*11)=P(2,III)/pmom
	    rw(tk+3+(III-1)*11)=P(3,III)/pmom
	    rw(tk+4+(III-1)*11)=pmom
	    rw(tk+5+(III-1)*11)=P(4,III)
	    rw(tk+6+(III-1)*11)=chg              ! deve essere real
	    iw(tk+7+(III-1)*11)=id
	    iw(tk+8+(III-1)*11)=I(III)           !tk flag = n. part sec.
	    iw(tk+9+(III-1)*11)=1              !n. do vertice
	    iw(tk+10+(III-1)*11)=0               !sem ending vx flag
	    iw(tk+11+(III-1)*11)=0.              !sem parent vx flag


          ENDDO

c	  write(1,*)' '

	  call hfntb(10,'finst')

C ***************************************
C *** cinematica della reazione primaria
C ***************************************

	  if ( ((j_channel.le.14).and.(j_channel.ge.5))
     1      .or.(j_channel.eq.35) ) then
c             print *,'j_channel=',j_channel
	     np1=npart_1

c	     print *, 'GENBOS   stato intermedio'
	     do iii=1,np1
		idg1(iii)=I_1(iii)
c		print *,'1,i,chg,id', I_1(III),chg,id
		call idchg(I_1(III),chg,id)
		idr1(iii)=id
		qch1(iii)=chg
		mass1(iii)=p_1(4,iii)

c		ene=sqrt(P_1(1,III)**2.+P_1(2,III)**2.+P_1(3,III)**2.+P_1(4,III)**2.)
c		print *, I_1(III),' LAB',P_1(1,III),P_1(2,III),P_1(3,III),P_1(4,III),ene

C ***************************************************
C *** Lorentz transformation from LAB to CM, if needed
		if (cmsf) then
		   xx=0.
		   do k=1,3
		      v1(k)=p_1(k,iii)
		      xx=xx+v1(k)**2.
		   enddo
		   v1(4)=sqrt(xx+p_1(4,iii)*p_1(4,iii))
		   
		   call gloren (beta_cm,v1,v2)

		   xx=0.
		   do k=1,3
		      p_1(k,iii)=v2(k)
		      xx=xx+v2(k)**2.
		   enddo
		   p_1(4,iii)=sqrt(v2(4)*v2(4)-xx)

		endif
C ***************************************************

		imp1(iii)=sqrt( p_1(1,iii)*p_1(1,iii)+
     1	      p_1(2,iii)*p_1(2,iii)+ p_1(3,iii)*p_1(3,iii) )
		cx1(iii)=P_1(1,III)/imp1(iii)
		cy1(iii)=P_1(2,III)/imp1(iii)
		cz1(iii)=P_1(3,III)/imp1(iii)

c		ene=sqrt(P_1(1,III)**2.+P_1(2,III)**2.+P_1(3,III)**2.+P_1(4,III)**2.)
c		print *, I_1(III),' CM ',P_1(1,III),P_1(2,III),P_1(3,III),P_1(4,III),ene
c		write (*,12) I_1(III),P_1(1,III),P_1(2,III),P_1(3,III),P_1(4,III),mass1(iii)
	     enddo

	  else
	     np1=0
	  endif

	  call hfntb(10,'prim')

C *** fill BOS file
	  call genbos_out

	ENDDO
	close(1)

C *** out BOS
        call genbos_last

C *** ntuple output
	if (.not.no_nt_out) call hrout (10,icycle,' ')
	if (.not.no_nt_out) call hrend ('generator')
c	call hrput (0,'genbos_d.hbook','N')

	STOP 
	END




