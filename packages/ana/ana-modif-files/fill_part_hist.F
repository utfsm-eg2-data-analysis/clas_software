      SUBROUTINE FILL_PART_HIST
c
c_begin_doc
c  RCS ID string
c  $Id: fill_part_hist.F,v 1.19 2004/08/03 16:02:02 clasdvcs Exp $
c
c  Documentation for subroutine FILL_PART_HIST
c
c  Purpose:
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
c  Author:         Created:  Wed Jun 11 00:14:11 EDT 1997
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
#include "wcs.inc"
#include "user_control.inc"
#include "seb_ntn.inc"
#include "MVRTnt.inc"
#include "clasmdl.inc"
c_end_inc
c
      real u,qx,qy,qz
      common/photv/u,qx,qy,qz
c
      real mx2,ex,px,p0x,p0y,p0z,thx,phx
      common/mispart/mx2,ex,px,thx,phx,p0x,p0y,p0z
      real mi2,ey,py,p1x,p1y,p1z
      common/recpart/mi2,ey,py,p1x,p1y,p1z
c
c_begin_var
c  input/output variables:
c  -----------------------
c
c  Local pre-defined variables:
c  ---------------------------
c  RCS information: 
      CHARACTER*132  CFILE, CREVIS, CSTATE, CDATE, CAUTHO, CRCSID
      PARAMETER (CFILE = '$RCSfile: fill_part_hist.F,v $')
      PARAMETER (CREVIS = '$Revision: 1.19 $')
      PARAMETER (CSTATE = '$State: Exp $')
      PARAMETER (CDATE = '$Date: 2004/08/03 16:02:02 $')
      PARAMETER (CAUTHO = '$Author: clasdvcs $')
      DATA CRCSID/ 
     +'$Id: fill_part_hist.F,v 1.19 2004/08/03 16:02:02 clasdvcs Exp $'/
c  Module information:
      CHARACTER*(*)  CRNAME, CRAUTH
      CHARACTER*100  CRMESS
      PARAMETER (CRNAME='FILL_PART_HIST')
      PARAMETER (CRAUTH='whoistheauthor')
c
c  Local User defined variables:
c  -----------------------------
      INTEGER NWRITE, mamind
      integer ind,i,hid,sect,secth
      integer iecp,ccphi,ccpmt,scstat
      real    ccsg,ccdt,eec,stv,sc_ec_t,drc
      real    perp(6,3),perp_thickness
      data    perp_thickness/20.7/
      integer npip,npim,npr,ng,nneut
      integer ipip(20),ipim(20),ip(20),in(20),ig(30)
      real    e0,q2,w2,w,pe,thetael,phiel,thetah,phih,thetapr,phipr
      real    thetapip,bpi
      real    rfcor
      real    mp,mn,mpi,r2d,pi
      data    mp,mn,mpi,r2d,pi/0.938,0.940,0.139,57.29578,3.14159/

c_end_var
c
c
c  executable code for routine FILL_PART_HIST:
c----6----------------------------------------------------------------72
c
      IF (NWRITE .LT. 1) THEN
        NWRITE = NWRITE + 1
        CRMESS='This is a DUMMY routine, this message written once'
        CALL RECMES(CRNAME,'I',CRMESS)
      ENDIF
      call hcdir('//PAWC',' ')
      call hcdir('//PAWC/SEB',' ')
      IECP=MAMIND(JW,'ECP ')
      ind=IECP+1
 10   ind=JW(ind-1)
      if(ind.gt.0)then
         sect=jw(ind-2)
         perp(sect,1)=rjw(ind+1)
         perp(sect,2)=rjw(ind+2)
         perp(sect,3)=rjw(ind+3)
         go to 10
      endif


      IF(npart.gt.0)THEN
         qx   = 0.
         qy   = 0.
         qz   = 0.
         w    = 0.
         npr  = 0
         npip = 0
         npim = 0
         ng   = 0
         nneut= 0
c++ general histos 
         call hf1(3101,rf_time,1.)
c	 call hf2(3201,float(raster_x),float(raster_y),1.)
c	 call hf1(3211,float(raster_x),1.)
c	 call hf1(3212,float(raster_y),1.)
c	 call hf1(3301,float(l1bit),1.)
c         call hf1(3302,float(helicity),1.)
c	 call hf1(3303,float(hel_ofl),1.)

c--
c++ particle histos
         if(dc(1).gt.0.and.sc(1).gt.0.and.ec(1).gt.0.and.q(1).lt.0)then
            if(stat(1).gt.0.and.dc_stat(dc(1)).gt.0)then
c+  define variables
               sect = dc_sect(dc(1))
               q2   = 2.*ebeam*p(1)*(1.-cz(1))
               w2   = mp**2+2.*mp*(ebeam-p(1))-q2
               if(w2.gt.0) w = sqrt(w2)
               thetael = acos(cz(1))*r2d
               phiel   = atan2(cy(1),cx(1))*r2d
               if(phiel.lt.-30.)phiel=phiel+360.
               u  =  ebeam-p(1)
               qx = -p(1)*cx(1)
               qy = -p(1)*cy(1)
               qz =  ebeam-p(1)*cz(1)
               eec   = max(etot(ec(1)),ec_ei(ec(1))+ec_eo(ec(1)))
               rfcor = sc_t(sc(1))-sc_r(sc(1))/29.98-tr_time
c-
c++++++++++++  fill histograms ++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++++
c   ELECTRONS
c   RF histograms
               call hf1(3102,rfcor,1.)
               call hf2(3111,rf_time,rfcor,1.)
               call hf2(3112,rfcor,vz(dc(1)),1.)
               call hf2(3120+sect,rfcor,float(sc_pd(sc(1))),1.)
c  Vertex histograms
               call hf1(6041,vz(1),1.)
               call hf2(6043,vz(1),phiel,1.)
c  EC histograms
               call hf1(6300,eec/p(1),1.)
               call hf2(6300+sect,p(1),eec/p(1),1.)
c  CC histograms
               if(cc(1).gt.0)then
                  ccphi=int(float(cc_segm(cc(1)))/1000.)
                  ccsg=float(cc_segm(cc(1))-1000*ccphi)
          ccpmt=int((cc_segm(cc(1))-ccphi*1000)/10.)
       if(ccphi.ne.1.AND.cc_segm(cc(1)).eq.ccphi*1000+ccpmt*10 ) then
          ccpmt=int(ccpmt*2+ccphi/2)
               else
                  ccpmt=0
               endif
               ccdt=cc_t(cc(1))-cc_r(cc(1))/29.97-tr_time
                  if(ccphi.eq.0)ccsg=-ccsg
                  call hf1(6500,float(cc_sect(cc(1))),1.)
                  if(ccphi.ne.1) call hf1(6500+sect,ccsg/10.,1.)
                  call hf1(6510+sect,float(nphe(cc(1))),1.)
                  call hf2(6520+sect,eec/p(1),float(nphe(cc(1))),1.)
                call hf1(6530+sect,ccdt,1.)
                call hf2(6540+sect,float(ccpmt),ccdt,1.)
             endif
c  EC timing histograms
               drc=perp(sect,1)
     +            *(dc_cxsc(dc(1))*cos(pi*(sect-1)/3.)-dc_cysc(dc(1))*
     + sin(pi*(sect-1)/3.))
               drc=drc+perp(sect,2)
     +            *(dc_cysc(dc(1))*cos(pi*(sect-1)/3.)+dc_cxsc(dc(1))*
     + sin(pi*(sect-1)/3.))      
               drc=drc+perp(sect,3)*dc_czsc(dc(1))
               sc_ec_t=ec_t(ec(1))-sc_t(sc(1))-perp_thickness/drc/29.979
               call hf1(6600,sc_ec_t,1.)
               call hf1(6600+sect,sc_ec_t,1.)
               call hf2(6640+sect,float(sc_pd(sc(1))),sc_ec_t,1.)
c  CHARGED HADRONS
               do i=2,npart
                  if(stat(i).gt.0.and.dc(i).gt.0.and.sc(i).gt.0)then
                  if(dc_stat(dc(i)).gt.0) then
                     thetah = acos(cz(i))*r2d
                     phih   = atan2(cy(i),cx(i))*r2d
                     if(phih .lt.-30.)phih =phih +360.
                     scstat=sc_stat(sc(i))-
     +                (100*sc_pd(sc(i))+10000*sc_sect(sc(i)))
c  Vertex histograms
                     call hf1(6042,vz(i),1.)
                     call hf2(6044,vz(i),phih ,1.)
                     if(q(i).gt.0)then
c  SC histograms
             if(m(i).gt.0.and.scstat.eq.33) call hf1(6100,sqrt(m(i)),1.)
            call hf2(6100+sc_sect(sc(i)),float(sc_pd(sc(i))),m(i),1.)
                  call hf2(6200+sc_sect(sc(i)),p(i),thetah,1.)
                  call hf1(6220+sc_sect(sc(i)),float(sc_pd(sc(i))),1.)
                  call hf2(6310,p(i),edep(sc(i)),1.)
                     call hf2(6310+sc_sect(sc(i)),p(i),edep(sc(i)),1.)
c  EC histograms
                        if(ec(i).gt.0)then
                           secth=ec_sect(ec(i))
            drc=perp(secth,1)*
     *        (dc_cxsc(dc(i))*cos(pi*(secth-1)/3.)-dc_cysc(dc(i))*
     +          sin(pi*(secth-1)/3.))
            drc=drc+perp(secth,2)*
     +      (dc_cysc(dc(i))*cos(pi*(secth-1)/3.)+dc_cxsc(dc(i))*
     + sin(pi*(secth-1)/3.))      
            drc=drc+perp(secth,3)*dc_czsc(dc(i))
         sc_ec_t=ec_t(ec(i))-sc_t(sc(i))-perp_thickness/drc/b(i)/29.979
         call hf1(6610+secth,sc_ec_t,1.)
        endif
       elseif(q(i).lt.0)then
         call hf2(6210+sc_sect(sc(i)),p(i),thetah,1.)
         call hf1(6230+sc_sect(sc(i)),float(sc_pd(sc(i))),1.)
       endif
c  Proton
                     if(id(i).eq.2212) then
                        npr     = npr+1
                        ip(npr) = i
                        thetapr = thetah
                        phipr   = phih
         stv=(sc_t(sc(i))-tr_time)-sc_r(sc(i))/29.979/
     +    (p(i)/sqrt(p(i)**2+mp**2))
         call hf1(6110,stv,1.)
         call hf2(6110+sc_sect(sc(i)),float(sc_pd(sc(i))),stv,1.)
c  Piplus
                     elseif(id(i).eq.211)then
                        npip      = npip+1
                        ipip(npip)= i
                        thetapip  = thetah
         stv = (sc_t(sc(i))-tr_time)-sc_r(sc(i))/29.979/(p(i)/
     +     sqrt(p(i)**2+mpi**2))
               call hf1(6120,stv,1.)
               call hf2(6120+sc_sect(sc(i)),float(sc_pd(sc(i))),stv,1.)
                     elseif(id(i).eq.-211) then
                        npim      = npim+1
                        ipim(npim)= i
         stv = (sc_t(sc(i))-tr_time)-sc_r(sc(i))/29.979/(p(i)/
     +       sqrt(p(i)**2+mpi**2))
            call hf1(6130,stv,1.)
            call hf2(6130+sc_sect(sc(i)),float(sc_pd(sc(i))),stv,1.)
             endif
            endif
c Neutrals
                  elseif(q(i).eq.0.and.ec(i).gt.0)then
                     if(b(i).gt.0.85)then
                        ng        = ng+1
                        ig(ng)    = i
             else
                nneut = nneut+1
                        in(nneut) = i
                     endif
                     call hf1(6620+ec_sect(ec(i)),b(i),1.)
                     call hf1(6620,               b(i),1.)
                     eec=max(etot(ec(i)),ec_ei(ec(i))+ec_eo(ec(i)))
                     call hf2(6630+ec_sect(ec(i)),b(i),eec,1.)
                  endif
               enddo
            endif
         endif
      ENDIF
c
      if(w.gt.0) then
c  W histograms
         call hf1(10000     ,w,1.)
         call hf1(10000+sect,w,1.)
         if(evntclas.gt.0)then
            call hf1(10011,w,1.)
         elseif(evntclas.lt.0)then
            call hf1(10012,w,1.)
         endif
c  Elastic and ep->e'pX
         if(npr.eq.1.AND.npip.eq.0.AND.npim.eq.0) then
            call miss_mass(ip(1),0,0,0,mp,0,0.,0.,mp)            
            if(abs(w-0.95).lt.0.15) then
               call hf1(10101,mx2,1.)
               call hf1(10102,abs(phiel-phipr),1.)
            elseif(w.gt.1.1) then
               call hf1(10201,mx2,1.)
            endif
         endif
c  ep->epi+n
         if(npr.eq.0.AND.npip.eq.1.AND.npim.eq.0) then
            call miss_mass(ipip(1),0,0,0,mpi,0.,0.,0.,mp)   
            call hf1(10202,mx2,1.)
         endif

c  invariant mass for gg
         if(ng.ge.2) then
            if(ec(ig(1)).gt.0.AND.ec(ig(2)).gt.0) then
               call inv_mass(ig(1),ig(2),0,0,0.,0.,0.,0.)
               call hf1(10300                   ,sqrt(mi2),1.)
               call hf1(10300+ec_sect(ec(ig(1))),sqrt(mi2),1.)
            endif
         endif
c  en->enX
         if(nneut.eq.1) then
            call miss_mass(in(1),0,0,0,mn,0.,0.,0.,mp)
            call hf1(10310,mx2,1.)
         endif
      endif
c
c Multivertex
      if(vidMVRT.gt.0.AND.ntrMVRT.gt.1) then
         if(ch2MVRT.lt.10) then
            call hf1(6051,xMVRT,1.)
            call hf1(6052,yMVRT,1.)
            call hf2(6053,xMVRT,yMVRT,1.)
         endif
      endif

      RETURN
      END
c
c-----------------------------------------------------------------------

C=======================================================================
      Subroutine miss_mass(id1,id2,id3,id4,s1,s2,s3,s4,mtarg)
c
      IMPLICIT NONE
c
      integer ids(4),i
      integer id1,id2,id3,id4
      real ms(4)
      real s1,s2,s3,s4,mtarg,e0
c
#include "seb_nt.inc"
c
      real pi,r2d
      data pi,r2d/3.141592,57.29578/
c
      real u,qx,qy,qz
      common/photv/u,qx,qy,qz
c
      real mx2,ex,px,p0x,p0y,p0z,thx,phx
      common/mispart/mx2,ex,px,thx,phx,p0x,p0y,p0z
      real mi2,ey,py,p1x,p1y,p1z
      common/recpart/mi2,ey,py,p1x,p1y,p1z
c
      ids(1)=id1
      ids(2)=id2
      ids(3)=id3
      ids(4)=id4
      ms(1)=s1
      ms(2)=s2
      ms(3)=s3
      ms(4)=s4
      ex=u+mtarg
      p0x=qx
      p0y=qy
      p0z=qz
      Do i=1,4
         if(ids(i).gt.0)then
            p0x=p0x-p(ids(i))*cx(ids(i))
            p0y=p0y-p(ids(i))*cy(ids(i))
            p0z=p0z-p(ids(i))*cz(ids(i))
            e0=sqrt(p(ids(i))**2+ms(i)**2)
            ex=ex-e0
         elseif(ids(i).lt.0)then
            p0x=p0x-p1x
            p0y=p0y-p1y
            p0z=p0z-p1z
            ex=ex-ey
         endif
      enddo
      px=sqrt(p0x**2+p0y**2+p0z**2)
      mx2=ex**2-px**2
c
      end

C=======================================================================
      Subroutine inv_mass(ip1,ip2,ip3,ip4,s1,s2,s3,s4)
c
      IMPLICIT NONE
c
      integer ip(4),ip1,ip2,ip3,ip4
      real ms(4),s1,s2,s3,s4
      integer i
c
#include "seb_nt.inc"
c
      real pi,r2d
      data pi,r2d/3.141592,57.29578/
c
      real u,qx,qy,qz
      common/photv/u,qx,qy,qz
c
      real mx2,ex,px,p0x,p0y,p0z,thx,phx
      common/mispart/mx2,ex,px,thx,phx,p0x,p0y,p0z
      real mi2,ey,py,p1x,p1y,p1z
      common/recpart/mi2,ey,py,p1x,p1y,p1z
c
      ip(1)=ip1
      ip(2)=ip2
      ip(3)=ip3
      ip(4)=ip4
      ms(1)=s1
      ms(2)=s2
      ms(3)=s3
      ms(4)=s4
      p1x=0.
      p1y=0.
      p1z=0.
      ey=0.
c mass m1 is a invariant mass of ip(1) and ip(2), m2 is a mass of ip(1) and ip(3)
      do i=1,4
         if(ip(i).gt.0)then
            p1x=p1x+p(ip(i))*cx(ip(i))
            p1y=p1y+p(ip(i))*cy(ip(i))
            p1z=p1z+p(ip(i))*cz(ip(i))
            ey=sqrt(p(ip(i))**2+ms(i)**2)+ey
         elseif(ip(i).lt.0)then
            p1x=p1x+p0x
            p1y=p1y+p0y
            p1z=p1z+p0z
            ey=sqrt(px**2+ms(i)**2)+ey
         else
c            p1x=0.
c            p1y=0.
c            p1z=0.
c            ey=100.
         endif
      enddo
      py=sqrt(p1x**2+p1y**2+p1z**2)
      mi2=ey**2-py**2

      return
      end
C=======================================================================
