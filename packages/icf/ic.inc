       INTEGER length_ic,dbtclflag
       PARAMETER (length_ic = 529)
       real deep,w0,xstep,ystep,zt0
       real ehitmin,egrplmin,egrpmin
       real encorr(3,16)
       common/recon/deep,ehitmin,egrplmin,egrpmin,w0,xstep,ystep,zt0,
     + encorr
