C Calculate angles and the distance to CC imaginary plane  

      subroutine sphere_inter(isec,x0,y0,z0,dx,dy,dz,ar,theta,phi,ires)
      implicit none
      integer isec
      real x0,y0,z0,dx,dy,dz,r,theta
      real point(3),dir(3),cc_pln(3),cc_pln6(3),cross(3)
      real ar,rad2deg,phi
      integer ires
      data rad2deg/57.2957795e0/

c cc_pln6 is for the new cherenkov (sector 6 only, for EG4)
      data cc_pln6/-0.0008302905e0,0.e+0,-0.0017805641e0/ ! distance is 509.0002 cm

c cc_pln is for the old cherenkov
      data cc_pln/-0.0007840784063e0,0.e+0,-0.001681461571e0/ ! distance is 539.0002 cm
c      data cc_pln/-0.0007754463505e0,0.0E+0,-0.001662950067e0/
      point(1)=x0
      point(2)=y0
      point(3)=z0
      dir(1)=dx
      dir(2)=dy
      dir(3)=dz
      if (isec.le.5) then
         call CCVCRPL(point,dir,cc_pln,ires,ar,cross)
      else
         call CCVCRPL(point,dir,cc_pln6,ires,ar,cross)
      endif
      ar=sqrt(cross(1)*cross(1)+cross(2)*cross(2)+cross(3)*cross(3)) 
      if (ar.ne.0) then
         theta=rad2deg*acos(cross(3)/ar) 
c     phi=rad2deg*atan2((cross(1)/ar),(cross(2)/ar))-90. 
c     phi=rad2deg*atan2((cross(2)/ar),(cross(1)/ar)) ! A.V.: no need to divide by ar 
         phi=rad2deg*atan2(cross(2),cross(1)) 
      else 
         theta=0. 
         phi=0. 
      endif 
      return 
      end 
 
c 
      SUBROUTINE CCVCRPL(R0,DIR,P,IRES,S,R) 
c 
c  Documentation for subroutine CCVCRPL(R0,DIR,P,IRES,S,R) 
c 
C---------------------------------------------------------------------- 
C- 
C-   Purpose and Methods : crossing of the stright line(R0,d) 
C-                         with a plane 
C- 
C-   Inputs  :   R0(3) - initial point of line 
C-               D (3) - vector direction: r = R0 + s*D 
C-               P (3) - plane parameters: 
C-               P(1)*x + P(2)*y + P(3)*z + 1 = 0 
C- 
C-   Outputs :   IRES =  0 - no cross with the plane. 
C-                       1 - cross in positive direction 
C-                      -1 - cross in negative direction 
C-               S    =  Distance to the cross point 
C-               R(3) =  Cross point coordinates. 
C- 
C-   Controls: 
C- 
C-   Created    14-APR-1994   Alexander V. Vlassov 
C-   Modified   21-AUG-1995   Alexander V. Vlassov 
C- 
C---------------------------------------------------------------------- 
c 
c_end_doc 
c 
      IMPLICIT NONE 
      SAVE 
c 
c  ----------------------- 
c 
      INTEGER IRES 
      REAL r0(3),dir(3),P(3),R(3),S 
c 
c  Local User defined variables: 
c  ----------------------------- 
c 
      double precision un,a,b,t,c,D(3) 
      real vsmall 
      integer i 
c 
      data un/1.0d000/ 
      data vsmall /0.000001/ 
c 
c_end_var 
c 
c  executable code for routine CCVCRPL 
c---------------------------------------------------------------------- 
      a = 0. 
      b = 0. 
      S = 0. 
      c = 0. 
      r(1)=0.
      r(2)=0.
      r(3)=0.      
c 
      if (dir(1).eq.0.or.dir(2).eq.0.or.dir(3).eq.0) then 
c         print *,'CCVCRPL warning: dir = ',dir(1),dir(2),dir(3) 
         continue
      endif 
      do i = 1,3 
        c = c + un*dir(i)*dir(i) 
      end do 
      if (c.eq.0) then 
c         print *,'CCVCRPL error: c = 0, dir = ',dir(1),dir(2),dir(3) 
         return
      endif 
      c = dsqrt(c) 
c 
      do i = 1,3 
        d(i) = un*dir(i)/c 
      end do 
c 
      do i = 1,3 
        a = a + un*P(i)*d(i) 
        b = b + un*P(i)*r0(i) 
      end do 
c 
      b = b + un 
c 
      if(abs(b).le.vsmall) then  ! point on the plane 
        do i = 1,3 
          r(i) = R0(i) 
        end do 
        IRES = 1 
      else 
        if(abs(a).le.vsmall) then 
          do i = 1,3 
            r(i) = 0. 
          end do 
          IRES = 0 
        else 
          t = -b/a 
          do i = 1,3 
            R(i) = t*d(i) + r0(i) 
          end do 
          IRES = 1 
          S = t 
          if(t.lt.0.) IRES = -1 
        end if 
      end if 
c 
      RETURN 
      END                   
