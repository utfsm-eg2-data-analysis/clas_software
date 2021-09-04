      subroutine book_hls_nt(ntid)
      IMPLICIT NONE
      integer ntid
      
#include "HLSnt.inc"

c Helicity related Information
      call hbname(NTID,'HLSB',nHLS,
     +'nHLS[0,500]:I,HLS_bit29(nHLS):I,'//
     +'HLS_bit30(nHLS):I,HLS_bit31(nHLS):I,'//
     +'HLS_clock(nHLS):I,HLS_otr1(nHLS):I,HLS_otr2(nHLS):I,'//
     +'HLS_slm(nHLS):I,HLS_trate(nHLS):I,HLS_Mcoin(nHLS):I,'//
     +'HLS_Macc(nHLS):I,HLS_fcup(nHLS):I,'//
     +'HLS_pmt1(nHLS):I,HLS_pmt2(nHLS):I,'//
     +'HLS_pmt3(nHLS):I,HLS_pmt4(nHLS):I,'//
     +'HLS_hel(nHLS):I,HLS_hls(nHLS):I')

c Helicity related Information
      call hbname(NTID,'HLBB',nHLB,
     +'nHLB[0,500]:I,HLB_bit29(nHLB):I,HLB_bit30(nHLB):I,'//
     +'HLB_bit31(nHLB):I,HLB_b1(nHLB):I,HLB_b2(nHLB):I,'//
     +'HLB_b3(nHLB):I,HLB_b4(nHLB):I,HLB_b5(nHLB):I,'//
     +'HLB_b6(nHLB):I,HLB_b7(nHLB):I,HLB_b8(nHLB):I,'//
     +'HLB_b9(nHLB):I,HLB_b10(nHLB):I,HLB_b11(nHLB):I,'//
     +'HLB_b12(nHLB):I,HLB_b13(nHLB):I,HLB_b14(nHLB):I,'//
     +'HLB_b15(nHLB):I,HLB_b16(nHLB):I')

      return
      end
