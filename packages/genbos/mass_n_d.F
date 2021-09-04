      real function mass_n_d(pf)

C ******************************
C *** This function computes reduced mass
C *** of a nucleon inside the deuteron
C *** from fermi motion so that energy
C *** is conserved
C ******************************

      rmn=rmass('deuteron    ')/2.

      x=sqrt(rmn*rmn-pf*pf)

      mass_n_d=x


      return
      end
