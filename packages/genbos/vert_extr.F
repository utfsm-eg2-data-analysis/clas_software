      subroutine vert_extr(p0)

C **********************************
C *** Extract interaction point inside a 
C *** fixed volume.
C *** targ_type=0    pointlike
C *** targ_type=1    tube R=targ_r L=targ_l
C *** targ_type=2    CLAS target "cuivre" tube+end cap
C ***                R=targ_r   TOTAL L=targ_l
C *** targ_type=3    CLAS target "cigare" end cap+tube+end cap
C ***                R=targ_r   TOTAL L=targ_l
C **********************************

      parameter (pig=3.1415926)

#include "nt_kine.inc"

      real p0(3),rnd(3),rnd2(1)


      if (targ_type.eq.0) then
C **********************************
C *** pointlike target
C **********************************

         p0(1)=0.
         p0(2)=0.
         p0(3)=0.

      else if (targ_type.eq.1) then
C **********************************
C *** cylindrical target only
C **********************************

 8       CALL NRAN(RND,3)

C *** x and y
         p0(1)=2.*targ_r*(rnd(1)-0.5)
         p0(2)=2.*targ_r*(rnd(2)-0.5)
         rrx=sqrt(p0(1)**2.+p0(2)**2.)
         if (rrx.gt.targ_r) go to 8
C *** z position
         p0(3)=targ_l*(rnd(3)-0.5)



      else if (targ_type.eq.2) then
C **********************************
C *** CLAS target "cuivre"
C **********************************

C *** volume of cylindrical part
         v1=pig*targ_r*targ_r*(targ_l-targ_r)
C *** volume of spherical part
         v2=2.*pig*targ_r*targ_r*targ_r/3.

C *** Probability for vertex in v1 or v2
         prob1=v1/(v1+v2)
         prob2=1.-prob1

C *** Extraction of volume
         CALL NRAN(RND2,1)



         if (rnd2(1).lt.prob1) then
C *** Cylindrical volume

 9          CALL NRAN(RND,3)

C *** Vertex in the coordinate of cylindrical volume

C *** x and y
            p0(1)=2.*targ_r*(rnd(1)-0.5)
            p0(2)=2.*targ_r*(rnd(2)-0.5)
            rrx=sqrt(p0(1)**2.+p0(2)**2.)
            if (rrx.gt.targ_r) go to 9
C *** z position
            p0(3)=(targ_l-targ_r)*(rnd(3)-0.5)

C *** vertex in CLAS coordinates
            p0(3)=p0(3)-targ_r/2.


         else
C *** Spherical volume

 10         CALL NRAN(RND,3)

C *** Vertex in the coordinate of spherical volume
            p0(1)=2.*targ_r*(rnd(1)-0.5)
            p0(2)=2.*targ_r*(rnd(2)-0.5)
            p0(3)=targ_r*rnd(3)
            rrx=sqrt(p0(1)**2.+p0(2)**2.+p0(3)**2.)
            if (rrx.gt.targ_r) go to 10

C *** vertex in CLAS coordinates
            p0(3)=p0(3)+(targ_l/2.-targ_r)

         endif

      else if (targ_type.eq.3) then
C **********************************
C *** CLAS target "cigare"
C **********************************

C *** volume of cylindrical part
         v1=pig*targ_r*targ_r*(targ_l-2.*targ_r)
C *** volume of two spherical halves
         v2=4.*pig*targ_r*targ_r*targ_r/3.

C *** Probability for vertex in v1 or v2
         prob1=v1/(v1+v2)
         prob2=1.-prob1

C *** Extraction of volume
         CALL NRAN(RND2,1)



         if (rnd2(1).lt.prob1) then
C *** Cylindrical volume

 11         CALL NRAN(RND,3)

C *** CLAS coordinate equal coordinates of cylindrical volume

C *** x and y
            p0(1)=2.*targ_r*(rnd(1)-0.5)
            p0(2)=2.*targ_r*(rnd(2)-0.5)
            rrx=sqrt(p0(1)**2.+p0(2)**2.)
            if (rrx.gt.targ_r) go to 11
C *** z position
            p0(3)=(targ_l-2.*targ_r)*(rnd(3)-0.5)


         else
C *** Two spherical halves

 12         CALL NRAN(RND,3)

C *** Vertex in the coordinate of spherical volume
            p0(1)=2.*targ_r*(rnd(1)-0.5)
            p0(2)=2.*targ_r*(rnd(2)-0.5)
            p0(3)=2.*targ_r*(rnd(3)-0.5)
            rrx=sqrt(p0(1)**2.+p0(2)**2.+p0(3)**2.)
            if (rrx.gt.targ_r) go to 12

C *** vertex in CLAS coordinates
            if (p0(3).lt.0) then    !left side
               p0(3)=p0(3)-(targ_l/2.-targ_r)
            else                    !right side
               p0(3)=p0(3)+(targ_l/2.-targ_r)
            endif

         endif


      endif


      return
      end
