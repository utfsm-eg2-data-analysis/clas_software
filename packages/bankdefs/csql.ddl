!-----------------------------------------------------------------------
!       BANKname BANKtype      !Comments
 TABLE   CSQL   B32   ! create write display delete ! Data bank for mySQL
!
!COL ATT-name FMT Min    Max   !Comments
   1 EVID     I    1    100000 ! Event ID (number of triggers)
   2 NPROC    I    1    100000 ! Number of processed triggers
   3 NWRIT    I    1  10000000 ! Number of written events
   4 CPU      F    0.    99999.! CPU used (sec)
   5 FC       F    0.      999.! Faraday Cup (K)
   6 FCG      F    0.      999.! Faraday Cup Gated (K)
   7 TG       F    0.      999.! Clock Gated
   8 IBEAM    F    0.      999.! Beam current
   9 NeS1     I    0    100000 !  Number of electrons in sect 1
  10 NeS2     I    0    100000 !  Number of electrons in sect 2
  11 NeS3     I    0    100000 !  Number of electrons in sect 3 
  12 NeS4     I    0    100000 !  Number of electrons in sect 4 
  13 NeS5     I    0    100000 !  Number of electrons in sect 5  
  14 NeS6     I    0    100000 !  Number of electrons in sect 6
  15 Nhb      I    0   1000000 ! Number of HB 
  16 Ntb      I    0   1000000 ! Number of TB
  17 Nprot    I    0   1000000 ! Number of protons
  18 Npip     I    0   1000000 ! number of pip
  19 Npim     I    0   1000000 ! number of pim
  20 Ndeut    I    0   1000000 ! number of deutrons
  21 Nphot    I    0   1000000 ! number of photons	
  22 Nelhp    I    0   1000000 ! Number of electrons at pos. Helic.
  23 Nelhn    I    0   1000000 ! Number of electrons at neg. helic.
  24 NprS1    I    0    100000 !  Number of protons in sect 1
  25 NprS2    I    0    100000 !  Number of protons in sect 2
  26 NprS3    I    0    100000 !  Number of protons in sect 3
  27 NprS4    I    0    100000 !  Number of protons in sect 4
  28 NprS5    I    0    100000 !  Number of protons in sect 5
  29 NprS6    I    0    100000 !  Number of protons in sect 6
  30 Eff_ofl  F    0.      100.!  Online/Offline helicity matching efficiency
  31 Eff_hsl  F    0.      100.!  TGBI/HLS helicity matching efficiency
  32 as_fcpu  F -100.      100.!  Ungated FCup charge asymmetry
  33 as_slmu  F -100.      100.!  Ungated SLM charge asymmetry
  34 as_fcpg  F -100.      100.!  Gated FCup charge asymmetry
  35 as_slmg  F -100.      100.!  Gated SLM charge asymmetry
!
 END TABLE
