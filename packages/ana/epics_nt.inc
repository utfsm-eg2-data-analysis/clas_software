c Ntuple variables for the EPICS block
      integer run,event,evntime

      real x2c21a,y2c21a,c2c21a,x2c24a,y2c24a,c2c24a,x2h01a,y2h01a,
     + c2h01a,target_type,target_position,polarization,he_level,fcup,
     + half_wave,taggerprobe, psprobe, pscurrent,taggercurrent,ebsya,
     + ebsyb,etiefa,intt,ebad

      common/epics_nt/run,ebad,event,evntime,intt,ebsya,ebsyb,etiefa,
     + x2c21a,y2c21a,c2c21a,x2c24a,y2c24a,c2c24a,x2h01a,y2h01a,c2h01a,
     + target_type,target_position,polarization,he_level,fcup,half_wave,
     + pscurrent,psprobe,taggercurrent,taggerprobe

