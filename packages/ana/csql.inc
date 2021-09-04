c Include file for csql bank.
      real q_t_l, q_t, t_l_t,I_fc,totcpu
      INTEGER nelect(6),ntbttrk,nhbttrk,nelectp,nelectn
      INTEGER nprot,npip,npim,ndeut,nkaon,nphoton,nproton(6)
      INTEGER nel,npos,nneg,nph
      integer nhel,nhelmax
      integer nev(20000),lev(20000),tcount(20000),tt(20000)
      integer thel(20000),truehel(20000),tr26hel(20000)
      integer tsync(20000),tmps(20000),tqrt(20000)
      integer tscal(20000)
      integer hls(20000,0:3),clk(20000,0:3),trt(20000,0:3)
      integer slm(20000,0:3),fcp(20000,0:3)
      integer bp1(20000,0:3),bp2(20000,0:3),bp3(20000,0:3)
      real    tgood(20000)
      parameter (nhelmax=20000)
c
      common/csql/q_t_l, q_t, t_l_t,I_fc,totcpu,nelect
     +,ntbttrk,nhbttrk,nelectp,nelectn,nprot,npip,npim,ndeut,nkaon
     +,nphoton,nproton,nel,npos,nneg,nph
     +,nhel
     +,nev,lev,tcount,tt,thel,tgood,truehel,tr26hel,tsync,tmps,tqrt
     +,tscal,hls,clk,trt,slm,fcp,bp1,bp2,bp3
