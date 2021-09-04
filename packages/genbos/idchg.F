      subroutine idchg(i,chg,id)

C **************************************
C *** Tranforms GEANT to LUND ID and find 
C *** particle charge
C **************************************

      parameter (ngeant=28)

      dimension geantid(ngeant),lundid(ngeant),charge(ngeant)
      integer geantid,lundid,i,id
      real charge,chg


c      gamma, elec+,elec-,mu+,mu-,pi0,pi+,pi-,K0,K+,K-,n,p,eta,Lambda,sigma+,
c      sigma0,sigma-,omega

c                  g, e+, e-, mu+, mu-, pi0, pi+, pi-, K0L, K+, K-, n,
      data geantid/1, 2,  3,  5,   6,   7,   8,   9,   10,  11, 12, 13,
c                  p, K0S,eta,Lambda,sigma+,
     &             14,16, 17, 18,    19,
c               sigma0,sigma-,omega,rho+,rho0,rho-
     &             20,  21,   60,   58,  57,  59
C               del++,del+,del0,del-, deuteron
     &           ,101 ,102 ,103 ,104, 45/     ! Ronchetti: Adding the ID for deuteron

c                gamma, e+,e-,mu+,mu-,pi0,pi+, pi-,K0L, K+,  K-,
      data lundid/22,  -11,11,-13, 13,111,211,-211,130,321,-321,
c                  n   , p,  K0S,eta,Lambda,sigma+,
     &             2112,2212,310,221,3122,  3222,
c                sigma0,sigma-,omega,rho+,rho0,rho-
     &             3212,3112,  223,   213, 113,-213
C               del++,del+,del0,del-,deuteron
     &          ,2224 ,2214,2114,1114,1145/   ! Ronchetti: inventing a LUND for deuteron

      data charge/0.,1.,-1.,1.,-1.,0.,1.,-1.,0.,1.,-1.,0.,1.,0.,0.,0.
     &             ,1.,0.,-1.,0.,1.,0.,-1.,2.,1.,0.,-1.,1./   ! Ronchetti: Adding D charge


      j=1
      k=0
      do while (k.eq.0.and.j.le.ngeant)
         if (i.eq.geantid(j)) then
            id=lundid(j)
            chg=charge(j)
            k=1
         endif
         j=j+1
      enddo
      if (j.eq.(ngeant+1).and.k.eq.0) then
         print*,' '
         print*,'idchg error:particle not found in geant id list= ',i
         print *,'i=',i
         print *,'id=',id,' chg=',chg
         print*,' '
      endif

c      print*,'idchg: i,id,chg= ',i,id,chg

      return

      end

