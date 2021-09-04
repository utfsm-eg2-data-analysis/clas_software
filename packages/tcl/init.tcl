#
# RECSIS initialization file, if it looks like Tcl, that's because it IS Tcl.
# There are defaults set within RECSIS, so this file could be empty and RECSIS
# will run just fine.  For example typing the following line:
#
#         > recsis -i[nput] myinput.bfp -o[utput] myoutput.bfp -np
#
# will result in RECSIS executing with defaults using myinput.bfp as input
# and myoutput.bfp as output.  The -np flag (nopause) tells RECSIS not to wait
# for commands  at the beginning of the job. 
#
# To invoke an initialization script type:
#         > recsis -i myinput.bfp -o myoutput.bfp -np -t[cl] myscript.tcl
# where myscript.tcl is a tcl script that looks like this file. IF myscript.tcl
# contains the input and output file as described below, then:
#         > recsis -t myscript.tcl -np 
# suffices to get the ball rolling. 
#
# for backwards compatibility you can still use your old FPACK command files
# by entering:
#         > recsis -f recsis.ctr -np
#
# or you can define a fpack command file in the character string 
# FPK_FILE as described below.
#
# Every RUN_CONTROL variable is listed here to show you what the possible 
# control functions are.  Your typical initialization script need only
# contain those variables you wish to change/set at the beginning of the
# job.   You of course can ADD YOUR variables you wish to have access to
# within the subroutine USER_TCL_INIT.  More variables/control/functionality
# is added daily, guarantying that this is a subset of what is actually 
# available.
# 
# the following variables are useful run control variables, they allow to
# process(skip) events and runs.  The lpause variable allows you to 
# suspend processing. The lquit logical will stop the job immediately, 
# while the lexit will stop the job at the end of the event and exit
# gracefully.
#
# the logical lstat and fstat will dump information to the screen/log
# file.
#
set nevt_to_process 0;  # how many events to process set to .le. 0 to process
                        # all the events and set to 50 to process 50 events 
                        # recsis will pause once nevt_to_process has been
                        # reached (with only [nevt_to_process-nevt_to_skip]
                        # being run through the event loop)
set nevt_to_skip 0;     # how many events to SKIP set to .le. 0 to NOT SKIP
                        # events and set to 50 to skip 50 events
                        # NOTE:     set nevt_to_skip 5 
                        #           set nevt_to_process 10 
                        # results in the next FIVE events being skipped, 
                        # followed by 5 events being processed followed by
                        # a pause.
set nrun_to_process 0;  # set to 1 in order to process ONE run, then pause
                        # 
set nrun_to_skip 0;     # set to 1 in order to skip an entire run, 2 to skip 2
                        # runs

set lstat 0;            # set this to true -1 anytime that you want a status
                        # dump, that is enter: set lstat -1 
set fstat 0;            # set this true anytime you want an FPACK status 
                        # dump (FPSTAT)

#set lpause 0;          # set to true (-1) if you want to pause processing
set lquit 0;            # set to true (-1) if you wish to quit immediately
set lexit 0;            # set to true (-1) if you wish to exit at the end
                        # of the event.

#
# the following two variables are READ ONLY, you can not modify them, but
# you can examine them
#
set run_number;        # this will cause the current run number to be returned
set event_number;      # this will cause the current run number to be returned

# the following set of variables turn on and off processors, currently only
# the egn processor is implemented.
#
set ltrk_do    -1;     # set false=0 to turn OFF the TRK processer
set legn_do    -1;     # set false=0 to turn OFF the EGN processer
set lcc_do     -1;     # set false=0 to turn OFF the CC processer
set ltof_do    -1;     # set false=0 to turn OFF the TOF processer
set lst_do     -1;     # set false=0 to turn OFF the ST processer
set ltime_do   -1;     # set false=0 to turn OFF the TIME processer
set ltagger_do -1;     # set false=0 to turn OFF the TAGGER processer
                       # additional processors will be added once they
                       # become available
                       #
                       #  There are TWO user event routines.
set lusr0_do   -1;     #  lusr0_do will call USER_BEVT at the BEGINNING
                       #  of the event, while lusr1_do will call USER_EVNT
set lusr1_do   -1;     #  AFTER all the event processing has been 
                       #  performed, this is the typical case.


set levent_class(1) -1;   # levent_class(n) allows users to select trigger types
set levent_class(2) -1; 
set levent_class(3) -1;   
set levent_class(4) -1; 
set levent_class(5) -1; 
set levent_class(6) -1; 
set levent_class(7) -1; 
set levent_class(8) -1; 
set levent_class(9) -1; 
set levent_class(10) -1; 
set levent_class(11) -1; 
set levent_class(12) -1; 
set levent_class(13) -1; 
set levent_class(14) -1; 
set levent_class(15) -1; 
set levent_class(16) -1;    # CODA sync event
set levent_class(17) -1;    # CODA prestart event  = CLAS BEGIN RUN
set levent_class(18) -1;    # CODA go event
set levent_class(19) -1;    # CODA pause event
set levent_class(20) -1;    # CODA end event = CLAS END RUN
#
#  The following logical OVERRIDES the individual logicals and ALL event types
#  will be selected.
#
set levent_all 0;   
#
#  To send a specific event to the CED event buffer set the following 
#  logical TRUE either in your code or via the interface
#
set ldisplay 0; 
#
#  to send EVERY event to the CED event buffer set the following logical TRUE
#
set ldisplay_all 0; 
#
#  you should define your input and outfile files in this initialization script
#  or on the command line via the -i[nput] and -o[utput] flags
#  REMEMBER a -noutput will override any output files listed in this
#  script.
#
#  here's the easy way to define input and output, commented out
#
setc rec_output junk2.bfp;   
setc rec_input /clas/cebafb/u2/data/nickolai13.evt; 
#setc rec_input /clas/cebafb/u2/data/gsimevt.bfp; 
#setc rec_input /usr/user3/cmeyer/sda_evt.bfp; 
#
#  The following is the hard way to define the input file, but it provides
#  an example of how to enter FPACK commands.  Note the \" syntax needed to
#  get the " into the fpk_cmd string and the & FPACK continuation marker.
#  the following script lines perform the same functions as those above.
#  NOTE: that FPACK SELECT commands are to be entered in this manner
#  see page 17 in the FPACK mannual for examples of the SELECT commands. 
#
#setc fpk_cmd(1) "OPEN CLASINPUT  UNIT=01 &";
#setc fpk_cmd(2) "FILE=\"/clas/cebafb/u2/data/gsim1000.bfp,&";
#setc fpk_cmd(3) "/clas/cebafb/u2/data/gsim1000.bfp,&";
#setc fpk_cmd(4) "/clas/cebafb/u2/data/gsim1000.bfp,&";
#setc fpk_cmd(5) "/clas/cebafb/u2/data/gsim1000.bfp,&";
#setc fpk_cmd(6) "/clas/cebafb/u2/data/gsim1000.bfp,&";
#setc fpk_cmd(7) "/clas/cebafb/u2/data/gsim1000.bfp,&";
#setc fpk_cmd(8) "/clas/cebafb/u2/data/gsim1000.bfp\" &";
#setc fpk_cmd(9) "READ RECL=36000 STATUS=OLD";
#
#  The following is the hard way to define the output file via FPACK commands
#  note the use of the FPACK continuation character &
#
#setc fpk_cmd(10) "OPEN CLASOUTPUT  UNIT=02 FILE=\"myoutput3.evt\" &";
#setc fpk_cmd(11) "WRITE RECL=36000 STATUS=NEW";
#
#  instead of using the fpk_cmd strings, you can tell recsis about a file that
#  contains  FPACK commands.
#
#setc fpk_file recsis.ctr;
#
# if you wish to override the OFFICIAL  ddl definition of the BOS banks
# you can do so here.
#
#setc ddl_file myclasbanks.ddl;
#
# you can customize your prompt if your are running in terminal mode
#
setc rec_prompt arne_rs>;    
#
# below are variables that give run time access to histograms
#
setc hist_dir "//PAWC/TRK";     # directory that contains your histogram
set  hist_id 0;           # histogram ID 0 means all histograms will be dumped
#set  lhist   0;           # set to true (-1) any time you wish a hist dump
#
#
set lscat -1;   # -1=true  TURNS on scat communications 
#setc scat_host clas02;
#




