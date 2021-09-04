      subroutine fill_hls_nt(ierr)
      
      implicit none

#include "bcs.inc"
#include "HLSnt.inc"

      integer ind,indx,ncol,nd,i,ix,j,jj,ierr
      integer vhls,vbit29,vbit30,vbit31,bit29,bit30,bit31
      integer mamind,mlink      

      ierr=0


c----------------------------------------------------------
c get HLS bank       
c----------------------------------------------------------
         ind=0
         nHLS=0
         i=0
         do jj=0,1
            ind = MLINK(IW,'HLS ',jj)
         if(ind.NE.0) Then
            ncol=iw(ind-5)
            nd=iw(ind)
            do ix=1,nd,ncol
               indx=ind+ix-1
               i=i+1
               HLS_bit29(i) = 0
               HLS_bit30(i) = 0
               HLS_bit31(i) = 0
               HLS_clock(i) = 0
               HLS_otr1 (i) = 0
               HLS_otr2 (i) = 0
               HLS_slm  (i) = 0
               HLS_trate(i) = 0
               HLS_Mcoin(i) = 0
               HLS_Macc (i) = 0
               HLS_fcup (i) = 0
               HLS_pmt1 (i) = 0
               HLS_pmt2 (i) = 0
               HLS_pmt3 (i) = 0
               HLS_pmt4 (i) = 0
               HLS_hel  (i) = 0
               HLS_hls  (i) = 0
               if(i.le.maxHLS) then
                  vhls = iw(indx+1 )
                  call mvbits(vhls,29,1,HLS_bit29(i),0)
                  call mvbits(vhls,30,1,HLS_bit30(i),0)
                  call mvbits(vhls,31,1,HLS_bit31(i),0)
                  call mvbits(vhls,0,24,HLS_clock(i),0)
                  vhls = iw(indx+2 )
                  call mvbits(vhls,0,24,HLS_otr1 (i),0)
                  vhls = iw(indx+3 )
                  call mvbits(vhls,0,24,HLS_otr2 (i),0)
                  vhls = iw(indx+4 )
                  call mvbits(vhls,0,24,HLS_slm  (i),0)
                  vhls = iw(indx+5 )
                  call mvbits(vhls,0,24,HLS_trate(i),0)
                  vhls = iw(indx+6 )
                  call mvbits(vhls,0,24,HLS_Mcoin(i),0)
                  vhls = iw(indx+7 )
                  call mvbits(vhls,0,24,HLS_Macc (i),0)
                  vhls = iw(indx+8 )
                  call mvbits(vhls,0,24,HLS_fcup (i),0)
                  vhls = iw(indx+9 )
                  call mvbits(vhls,0,24,HLS_pmt1 (i),0)
                  vhls = iw(indx+10)
                  call mvbits(vhls,0,24,HLS_pmt2 (i),0)
                  vhls = iw(indx+11)
                  call mvbits(vhls,0,24,HLS_pmt3 (i),0)
                  vhls = iw(indx+12)
                  call mvbits(vhls,0,24,HLS_pmt4 (i),0)
                  vhls = iw(indx+15)
                  call mvbits(vhls,0,24,HLS_hel  (i),0)
                  vhls = iw(indx+16) 
                  call mvbits(vhls,0,24,HLS_hls  (i),0)
                  nHLS=i
                  vbit29=0
                  vbit30=0
                  vbit31=0
                  do j=1,16
                     vhls=iw(indx+j)
                     call mvbits(vhls,29,1,bit29,0)
                     call mvbits(vhls,30,1,bit30,0)
                     call mvbits(vhls,31,1,bit31,0)
                     vbit29=vbit29*2+bit29
                     vbit30=vbit30*2+bit30
                     vbit31=vbit31*2+bit31
                  enddo
               else
                  print *,'more than ',maxHLS,' rows in the HLS bank'
                  print *,'truncating to maxHLS'
               endif
               if((vbit29.ne.0.AND.vbit29.ne.65535).OR.
     &            (vbit30.ne.0.AND.vbit30.ne.65535).OR.
     &            (vbit31.ne.0.AND.vbit31.ne.65535)) then
c                  print *,'WARNING: helicity or sync bits not matching in HLS bank at event ',evntid 
                  if(vbit29.ne.0.AND.vbit29.ne.65535) HLS_bit29(i) = -1
                  if(vbit30.ne.0.AND.vbit30.ne.65535) HLS_bit30(i) = -1
                  if(vbit31.ne.0.AND.vbit31.ne.65535) HLS_bit31(i) = -1
               endif
            enddo
         endif
         enddo
c----------------------------------------------------------
c get HLB bank       
c----------------------------------------------------------
         ind=0
         nHLB=0
         i=0
         do jj=0,1
            ind = MLINK(IW,'HLB ',jj)
         if(ind.NE.0) Then
            ncol=iw(ind-5)
            nd=iw(ind)
            do ix=1,nd,ncol
               indx=ind+ix-1
               i=i+1
               HLB_bit29(i) = 0
               HLB_bit30(i) = 0
               HLB_bit31(i) = 0
               HLB_b1   (i) = 0
               HLB_b2   (i) = 0
               HLB_b3   (i) = 0
               HLB_b4   (i) = 0
               HLB_b5   (i) = 0
               HLB_b6   (i) = 0
               HLB_b7   (i) = 0
               HLB_b8   (i) = 0
               HLB_b9   (i) = 0
               HLB_b10  (i) = 0
               HLB_b11  (i) = 0
               HLB_b12  (i) = 0
               HLB_b13  (i) = 0
               HLB_b14  (i) = 0
               HLB_b15  (i) = 0
               HLB_b16  (i) = 0
               vhls = iw(indx+1)
               call mvbits(vhls,29,1,HLB_bit29(i),0)
               call mvbits(vhls,30,1,HLB_bit30(i),0)
               call mvbits(vhls,31,1,HLB_bit31(i),0)
               call mvbits(vhls,0,24,HLB_b1(i),0)
               vhls = iw(indx+2)
               call mvbits(vhls,0,24,HLB_b2(i),0)
               vhls = iw(indx+3)
               call mvbits(vhls,0,24,HLB_b3(i),0)
               vhls = iw(indx+4)
               call mvbits(vhls,0,24,HLB_b4(i),0)
               vhls = iw(indx+5)
               call mvbits(vhls,0,24,HLB_b5(i),0)
               vhls = iw(indx+6)
               call mvbits(vhls,0,24,HLB_b6(i),0)
               vhls = iw(indx+7)
               call mvbits(vhls,0,24,HLB_b7(i),0)
               vhls = iw(indx+8)
               call mvbits(vhls,0,24,HLB_b8(i),0)
               vhls = iw(indx+9)
               call mvbits(vhls,0,24,HLB_b9(i),0)
               vhls = iw(indx+10)
               call mvbits(vhls,0,24,HLB_b10(i),0)
               vhls = iw(indx+11)
               call mvbits(vhls,0,24,HLB_b11(i),0)
               vhls = iw(indx+12)
               call mvbits(vhls,0,24,HLB_b12(i),0)
               vhls = iw(indx+13)
               call mvbits(vhls,0,24,HLB_b13(i),0)
               vhls = iw(indx+14)
               call mvbits(vhls,0,24,HLB_b14(i),0)
               vhls = iw(indx+15)
               call mvbits(vhls,0,24,HLB_b15(i),0)
               vhls = iw(indx+16)
               call mvbits(vhls,0,24,HLB_b16(i),0)
               nHLB=i
               vbit29=0
               vbit30=0
               vbit31=0
               do j=1,16
                  vhls=iw(indx+j)
                  call mvbits(vhls,29,1,bit29,0)
                  call mvbits(vhls,30,1,bit30,0)
                  call mvbits(vhls,31,1,bit31,0)
                  vbit29=vbit29*2+bit29
                  vbit30=vbit30*2+bit30
                  vbit31=vbit31*2+bit31
               enddo
               if((vbit29.ne.0.AND.vbit29.ne.65535).OR.
     &            (vbit30.ne.0.AND.vbit30.ne.65535).OR.
     &            (vbit31.ne.0.AND.vbit31.ne.65535)) then
c                  print *,'WARNING: helicity or sync bits not matching in HLB bank at event ',evntid 
                  if(vbit29.ne.0.AND.vbit29.ne.65535) HLB_bit29(i) = -1
                  if(vbit30.ne.0.AND.vbit30.ne.65535) HLB_bit30(i) = -1
                  if(vbit31.ne.0.AND.vbit31.ne.65535) HLB_bit31(i) = -1
               endif
            enddo
         endif
         enddo

         
         if(nHLS.ne.0.OR.nHLB.ne.0) ierr=1
        
 99   return
      end
