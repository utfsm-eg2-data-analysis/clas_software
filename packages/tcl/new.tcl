#setc rec_output junk2.bfp   
#setc rec_input /clas/cebafb/u2/data/gsimevt.bfp 
setc fpk_cmd(1) "OPEN CLASINPUT  UNIT=01 &"
setc fpk_cmd(2) "FILE=\"/clas/cebafb/u2/data/gsimevt.bfp\" &"
setc fpk_cmd(3) "READ RECL=36000 STATUS=OLD"
#
setc fpk_cmd(4) "OPEN CLASOUTPUT  UNIT=02 FILE=\"myoutput3.evt\" &"
setc fpk_cmd(5) "WRITE RECL=36000 STATUS=NEW" 
#