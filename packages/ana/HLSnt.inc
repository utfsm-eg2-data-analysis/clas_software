c      include file HLSnt

c----6----------------------------------------------------------------72
      integer maxHLS
      parameter (maxHLS=500)
      INTEGER nHLS
      INTEGER HLS_bit29(maxHLS)
      INTEGER HLS_bit30(maxHLS)
      INTEGER HLS_bit31(maxHLS)
      INTEGER HLS_clock(maxHLS)
      INTEGER HLS_otr1(maxHLS)
      INTEGER HLS_otr2(maxHLS)
      INTEGER HLS_slm(maxHLS)
      INTEGER HLS_trate(maxHLS)
      INTEGER HLS_Mcoin(maxHLS)
      INTEGER HLS_Macc(maxHLS)
      INTEGER HLS_fcup(maxHLS)
      INTEGER HLS_pmt1(maxHLS)
      INTEGER HLS_pmt2(maxHLS)
      INTEGER HLS_pmt3(maxHLS)
      INTEGER HLS_pmt4(maxHLS)
      INTEGER HLS_hel(maxHLS)
      INTEGER HLS_hls(maxHLS)       
      COMMON/HLS_NT/nHLS,HLS_bit29,HLS_bit30,HLS_bit31,HLS_clock
     +,HLS_otr1,HLS_otr2,HLS_slm,HLS_trate,HLS_Mcoin,HLS_Macc
     +,HLS_fcup,HLS_pmt1,HLS_pmt2,HLS_pmt3,HLS_pmt4,HLS_hel,HLS_hls

      INTEGER nHLB
      INTEGER HLB_bit29(maxHLS)
      INTEGER HLB_bit30(maxHLS)
      INTEGER HLB_bit31(maxHLS)
      INTEGER HLB_b1(maxHLS)
      INTEGER HLB_b2(maxHLS)
      INTEGER HLB_b3(maxHLS)
      INTEGER HLB_b4(maxHLS)
      INTEGER HLB_b5(maxHLS)
      INTEGER HLB_b6(maxHLS)
      INTEGER HLB_b7(maxHLS)
      INTEGER HLB_b8(maxHLS)
      INTEGER HLB_b9(maxHLS)
      INTEGER HLB_b10(maxHLS)
      INTEGER HLB_b11(maxHLS)
      INTEGER HLB_b12(maxHLS)
      INTEGER HLB_b13(maxHLS)
      INTEGER HLB_b14(maxHLS)       
      INTEGER HLB_b15(maxHLS)
      INTEGER HLB_b16(maxHLS)       
      COMMON/HLB_NT/nHLB,HLB_bit29,HLB_bit30,HLB_bit31,HLB_b1,
     +HLB_b2,HLB_b3,HLB_b4,HLB_b5,HLB_b6,HLB_b7,HLB_b8,HLB_b9,HLB_b10
     +,HLB_b11,HLB_b12,HLB_b13,HLB_b14,HLB_b15,HLB_b16
c----6----------------------------------------------------------------72
