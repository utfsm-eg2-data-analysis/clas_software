#      This is a recsis gui allowing users to connect to and control recsis 
#   jobs.  Along with configure.tcl, the user can also launch a recsis job.
#      This script uses swish, a SCAT enhanced wish.  For a sample program 
#   illustrating how these commands are used, checkout example.tcl.
#   
#     This program was written by David Turissini.  Please email questions 
#   to Arne Freyberger at freyberg@cebaf.gov or dturissi@indiana.edu
#
#
#      procedure to alert user that no job has been selected

proc needjob {} {toplevel .error -bg grey
       label .error.label -bg grey -text "You must first select a job."
       button .error.ok -bg grey -text "OK" -width 6
       pack .error.label .error.ok -padx 2m -pady 2m
       bind .error.ok <1> {after 10 {destroy .error}}}

#      procedure to toggle button between Pause and Go status

proc ptog {} {global a buttcolor status statcolor
   if {$a == "Pause"} {set a Go
       ScatSendMsgNr {set lpause -1}
       set buttcolor SpringGreen4
       set statcolor red
       set status {Paused}
       .frame.f2.f1.ptog configure -text $a -fg $buttcolor \
           -activeforeground $buttcolor
       statusdis
       return $a}
   if {$a == "Go"} {set a Pause
       ScatSendMsgNr {set lpause 0}
       set buttcolor red
       set statcolor SpringGreen4
       set status {Running}
       .frame.f2.f1.ptog configure -text $a -fg $buttcolor \
           -activeforeground $buttcolor
       statusdis
       return $a}}

#     This procedure calls on get status on a regular interval set by the 
#   variable statusrate in milliseconds

proc callstat {} {global statusrate
   getstatus 
   after $statusrate [list callstat]}

#      procedure to call recsis to check the current status and toggle the 
#    display between Paused and Running

proc getstatus {} {global a havejob statcolor status
   if {$havejob == 0} {return} 
   if {[ScatSendMsg {set lpause}] != 0} {set a Go
       set buttcolor SpringGreen4
       set statcolor red
       set status {Paused}
       .frame.f2.f1.ptog configure -text $a -fg $buttcolor \
           -activeforeground $buttcolor
       statusdis}
   if {[ScatSendMsg {set lpause}] == 0} {set a Pause
       set buttcolor red
       set statcolor SpringGreen4
       set status {Running}
       .frame.f2.f1.ptog configure -text $a -fg $buttcolor \
           -activeforeground $buttcolor
       statusdis}}

#      procedure to update the status display 

proc statusdis {} {global statcolor status
   .frame.f1.f2.f2.status configure -text $status -fg $statcolor}

#     this procedure calls getevent on a regular interval set by eventrate

proc callevent {} {global eventrate
   getevent 
   after $eventrate [list callevent]}

#      procedure to check recsis and receive the event number
#    while the run is paused, it also looks at leof to see if the job is done

proc getevent {} {global eventnum status lpause havejob oldevent statcolor
   if {$havejob == 0} {return}   
   set eventnum [ScatSendMsg {set event_number}]
   if {$oldevent == $eventnum} \
	   {if {[ScatSendMsg {set leof}] != 0} {set status {End of File}
           set statcolor black
           statusdis}}
   set oldevent $eventnum
   .frame.f1.f2.f2.events configure -text $eventnum}

#      procedure that calls get run on an interval set by runrate

proc callrun {} {global runrate
   getrun 
   after $runrate [list callrun]}

#      procedure to check recsis to update the run number

proc getrun {} {global runnum havejob
   if {$havejob == 0} {return}
   set runnum [ScatSendMsg {set run_number}]
   .frame.f1.f2.f2.runs configure -text $runnum}

#      procedure to end recsis job and reset the job and status displays

proc losejob {} {global havejob statcolor status filein fileout       
       set havejob 0
       set statcolor black
       set status {Not Attached}
       set jobname None
       set filein {}
       set fileout {}
       set flash 0
       statusdis
       .frame.f1.f2.f2.runs configure -text {}
       .frame.f1.f2.f2.events configure -text {}
       .frame.f1.f1.f2.job configure -text $jobname
       .frame.f1.f1.f2.filein configure -text $filein
       .frame.f1.f1.f2.fileout configure -text $fileout}

#      this procedure calls getmess on an interval set by messrate

proc callmess {} {global messrate
   getmess 
   after $messrate [list callmess]}

#      procedure to check recsis for messages and then fill the message 
#    listbox with the messages

proc getmess {} {global messlist havejob flash oldlast
       if {$havejob == 0} {return}
       set messages [ScatSendMsg {setc ctcl_buff}]
       ScatSendMsgNr {setc ctcl_buff { }}
       set messlist [split $messages `]
       set last [expr ([llength $messlist] + $oldlast)]
       foreach i $messlist {
         if {[string match *W:* $i] == 1} {warn red grey}
	 .frame.f2.f2.f2.messages insert end $i}
       set oldlast "$last"
       if {$last > 0} {.frame.f2.f2.f2.messages yview $last}}

#      procedure to create the flashing warning button when a warning appears 
#    in the message box

proc warn {col1 col2} {global flash
       if {$flash == 0} {set flash 1
       .frame.f2.f2.f1.warn configure -fg grey -relief flat 
           return}
       .frame.f2.f2.f1.warn configure -fg $col1 -relief raised
       after 1000 [list warn $col2 $col1]}

#      procedure to create the message listbox and its scrollbars

proc buildmess {} {
   listbox .frame.f2.f2.f2.messages -bg grey -relief sunken \
        -width 60 -height 20 -bg grey -borderwidth 2 \
        -yscrollcommand ".frame.f2.f2.f2.yscroll set" \
        -xscrollcommand ".frame.f2.f2.f3.xscroll set"
   scrollbar .frame.f2.f2.f2.yscroll -bg grey -relief flat\
      -command ".frame.f2.f2.f2.messages yview"
   scrollbar .frame.f2.f2.f3.xscroll -bg grey -orient horizontal \
	   -command ".frame.f2.f2.f2.messages xview" -relief flat

   pack .frame.f2.f2.f2.messages .frame.f2.f2.f2.yscroll -side left -fill y
   pack .frame.f2.f2.f3.xscroll -fill x}  

#      command to setup SCAT  

ScatInit

#      defaults stating that the program is currently not connected to a job

set havejob 0
set status {Not Attached}
set jobname None
set filein {}
set fileout {}
set runnum {}
set eventnum {}

#      defaults for program to start in the pause status

set a Pause
set buttcolor red
set statcolor SpringGreen4

#      find the username and node of the user

set node [exec hostname]
set uname [lindex [split [exec id] ()] 1]

#      defaults for histogram values

set id 0
set dir //PAWC/MYDIR

#     default filter for job connection listbox

set filt rec

#     variable to help check if job has stopped in getevent procedure

set oldevent 1

#     variable to allow message box to display new messages at top of display

set oldlast -20

#     variable to allow warning button to flash

set flash 1

#     defaults for update rates

set statusrate 10000
set eventrate 5000
set runrate 300000
set messrate 60000

#     frame definitions for positioning widgets

frame .frame -bg grey
pack .frame

frame .frame.f1 -bg grey
frame .frame.f2 -bg grey
pack .frame.f1 .frame.f2 -pady 2m -fill x

frame .frame.f1.f1 -bg grey
frame .frame.f1.f2 -bg grey
pack .frame.f1.f1 -side left -padx 5m
pack .frame.f1.f2 -side right -padx 5m

frame .frame.f1.f1.f1 -bg grey
frame .frame.f1.f1.f2 -bg grey
pack .frame.f1.f1.f1 .frame.f1.f1.f2 -side left

frame .frame.f1.f2.f1 -bg grey
frame .frame.f1.f2.f2 -bg grey
pack .frame.f1.f2.f1 .frame.f1.f2.f2 -side left

frame .frame.f2.f1 -bg grey
frame .frame.f2.f2 -bg grey
pack .frame.f2.f1 .frame.f2.f2 -fill y -side left

frame .frame.f2.f2.f1 -bg grey
frame .frame.f2.f2.f2 -bg grey
frame .frame.f2.f2.f3 -bg grey
pack .frame.f2.f2.f1 .frame.f2.f2.f2 -fill both -padx 2m
pack .frame.f2.f2.f3 -fill x

#      definitions for runtime widgets

label .frame.f1.f1.f1.ljob -text "Current Job" -bg grey
label .frame.f1.f1.f1.lfilein -text "Input File" -bg grey
label .frame.f1.f1.f1.lfileout -text "Output File" -bg grey
label .frame.f1.f1.f2.job -relief sunken -bg grey -width 32 -text "$jobname"
label .frame.f1.f1.f2.filein -relief sunken  -bg grey -width 32 -text $filein
label .frame.f1.f1.f2.fileout -relief sunken -bg grey -width 32 -text $fileout
label .frame.f1.f2.f1.lstatus -text "Current Status" -bg grey
label .frame.f1.f2.f1.run -text "Current Run" -bg grey
label .frame.f1.f2.f1.event -text "Current Event" -bg grey 
label .frame.f1.f2.f2.status -relief sunken -width 12 -bg grey -text $status
label .frame.f1.f2.f2.runs -relief sunken -width 12 -bg grey -text $runnum
label .frame.f1.f2.f2.events -relief sunken -width 12 -bg grey -text $eventnum 
button .frame.f2.f1.start -text "Start" -bg grey -width 14
button .frame.f2.f1.ptog -text $a -bg grey -width 14 -fg $buttcolor \
    -activeforeground $buttcolor
button .frame.f2.f1.display -text "Display" -bg grey -width 14
button .frame.f2.f1.histb -text "Hist" -bg grey -width 14
button .frame.f2.f1.stat -bg grey -text "Status Dump" -width 14
button .frame.f2.f1.fstat -bg grey -text "FPACK Status" -width 14
button .frame.f2.f1.update -bg grey -text "Update Rates" -width 14
button .frame.f2.f1.ced -bg grey -text "ced" -width 14
button .frame.f2.f1.cust -text "Custom Command" -bg grey -width 14
button .frame.f2.f1.discon -text "Disconnect" -width 14 -bg grey
button .frame.f2.f1.exitb -text "Exit Recsis" -width 14 -bg grey
button .frame.f2.f1.quitb -text "Quit Recsis" -width 14 -bg grey
button .frame.f2.f1.quit -bg grey -text "Quit" -width 14
label .frame.f2.f2.f1.warn -fg grey -width 14 -text Warning -bg grey

pack .frame.f1.f1.f1.ljob .frame.f1.f1.f1.lfilein .frame.f1.f1.f1.lfileout \
     .frame.f1.f1.f2.job .frame.f1.f1.f2.filein .frame.f1.f1.f2.fileout \
     -padx 1m -pady 1m  
pack .frame.f2.f1.start .frame.f2.f1.ptog .frame.f2.f1.display \
     .frame.f2.f1.histb .frame.f2.f1.stat .frame.f2.f1.fstat \
     .frame.f2.f1.update .frame.f2.f1.ced .frame.f2.f1.cust \
     .frame.f2.f1.discon .frame.f2.f1.exitb .frame.f2.f1.quitb \
     .frame.f2.f1.quit -padx 2m
pack .frame.f1.f2.f1.lstatus .frame.f1.f2.f1.run .frame.f1.f2.f1.event -pady 1m 
pack .frame.f1.f2.f2.status .frame.f1.f2.f2.runs .frame.f1.f2.f2.events \
     -pady 1m -padx 1m
pack .frame.f2.f2.f1.warn -padx 1m -pady 1m

buildmess

#      button that brings up window giving the user the choice of starting a 
#    new recsis job or connecting to an existing job

bind .frame.f2.f1.start <1> {toplevel .job -bg grey -width 36
       button .job.initiate -bg grey -text "Initiate Job"
       button .job.connect -bg grey -text "Connect to Existing Job"
       button .job.cancel -bg grey -text "Cancel" -width 6

       pack .job.initiate .job.connect .job.cancel -fill x -pady 1m
       pack .job.cancel  -padx 10m -pady 2m

       bind .job.initiate <1> {after 10 {destroy .job}
        if {[file isfile configure.tcl] == 1} {source configure.tcl}
        if {[file isfile configure.tcl] == 0} {source [$env(RECSIS)/tcl/configure.tcl]}}
       bind .job.cancel <1> {after 10 {destroy .job}}
       bind .job.connect <1> {after 10 {destroy .job}

#      fills listbox with curerent jobs and allows user to select process

          proc fillbox {} {global node filt uname
             ScatProbe $node
             set s [array size scatProcess]
             while {$s > 0} {
               append size "$s "
	       incr s -1}
	     foreach i $size {set c $scatProcess($i)
               if {[lsearch $c *$filt*] == 1 && [lsearch $c *$uname*] == 0} \
                     {append xy "{$scatProcess($i)} "}}
	     if {[info exists xy] == 0} {set xy {"no scat processes"}
                set scatProcess(1) "no scat processes"}
             foreach i $xy {.connect.f3.f1.list insert end $i}
             if {$scatProcess(1) != "no scat processes"} {
                destroy .frame.f2.f2.f2.messages .frame.f2.f2.f2.yscroll \
                   .frame.f2.f2.f3.xscroll  
                buildmess
                set oldlast -20
                bind .connect.f3.f1.list <Double-Button-1> \
                   {set chose [split [selection get] { }]
                set jobname [lrange $chose 2 2]
                ScatLocateProgram $node $jobname
                after 10 {destroy .connect}
                set havejob 1
                append jobname " $node"
                after 1000 {callstat}
                callrun
                after 15000 {getrun}
                callevent
                callmess
                .frame.f1.f1.f2.job configure -text $jobname
                set filein [ScatSendMsg {setc rec_input}]
                .frame.f1.f1.f2.filein configure -text $filein
                set fileout [ScatSendMsg {setc rec_output}]
                if {$fileout == {}} {set fileout None}
                .frame.f1.f1.f2.fileout configure -text $fileout
       puts $fileout}}}

#        creates selection listbox

	  proc buildbox {} {listbox .connect.f3.f1.list \
               -relief sunken -borderwidth 2 -width 64 -height 8 \
               -yscrollcommand ".connect.f3.f1.yscroll set" -bg grey \
               -xscrollcommand ".connect.f3.f2.xscroll set"
             scrollbar .connect.f3.f1.yscroll -relief flat \
                 -command ".connect.f3.f1.list yview" -bg grey
             scrollbar .connect.f3.f2.xscroll -orient horizontal \
                 -command ".connect.f3.f1.list xview" -bg grey -relief flat
             pack .connect.f3.f1.list .connect.f3.f1.yscroll \
                 -side left -fill y
             pack .connect.f3.f2.xscroll -fill x
             fillbox}

#        disconnects from current job when connect job window is brought up

          losejob

          toplevel .connect -bg grey
          frame .connect.f1 -bg grey
          frame .connect.f2 -bg grey
          frame .connect.f3 -bg grey
          frame .connect.f4 -bg grey
          pack .connect.f1 .connect.f2 .connect.f3 .connect.f4 \
                -padx 2m -pady 2m

          frame .connect.f2.f1 -bg grey
          frame .connect.f2.f2 -bg grey
          pack .connect.f2.f1 .connect.f2.f2 -pady 1m -side left -padx 3m

          frame .connect.f3.f1 -bg grey
          frame .connect.f3.f2 -bg grey
          pack .connect.f3.f1 .connect.f3.f2 -padx 2m -fill x 

          label .connect.f1.lnode -bg grey -text "Node"
          entry .connect.f1.node -bg grey -relief sunken -textvariable node
          label .connect.f2.f1.luser -bg grey -text "Username"
          entry .connect.f2.f1.user -bg grey -relief sunken -textvariable uname
          label .connect.f2.f2.lfilt -bg grey -text "Filter"
          entry .connect.f2.f2.filt -bg grey -relief sunken -textvariable filt
          button .connect.f4.cancel -width 6 -text "Cancel" -bg grey

          pack .connect.f1.lnode .connect.f1.node .connect.f2.f1.luser \
               .connect.f2.f1.user .connect.f2.f2.lfilt .connect.f2.f2.filt \
               -side left -padx 1m -pady 1m
          pack .connect.f4.cancel -side left -padx 2m -pady 2m
 
          bind .connect.f1.node <Return> {
             destroy .connect.f3.f1.list .connect.f3.f1.yscroll \
                 .connect.f3.f2.xscroll 
             buildbox}
          bind .connect.f2.f1.user <Return> {
             destroy .connect.f3.f1.list .connect.f3.f1.yscroll \
                 .connect.f3.f2.xscroll 
             buildbox}
          bind .connect.f2.f2.filt <Return> {
             destroy .connect.f3.f1.list .connect.f3.f1.yscroll \
                 .connect.f3.f2.xscroll 
             buildbox}
          bind .connect.f4.cancel <1> {after 10 {destroy .connect}}          
          buildbox}}

#    button that allows user to pause or run a job

bind .frame.f2.f1.ptog <1> {if {$havejob == 0} {needjob}
          if {$havejob == 1} {ptog
              after 2000 [getstatus
              getevent
              getrun
              getmess]}}

#    button that allows user to display info

bind .frame.f2.f1.display <1> {if {$havejob == 0} {needjob}
       if {$havejob == 1} {ScatSendMsgNr {set ldisplay -1}}}

#    button that accesses histogram options

bind .frame.f2.f1.histb <1> {if {$havejob == 0} {needjob}
   if {$havejob == 1} {toplevel .histo -bg grey
       frame .histo.h1 -bg grey
       frame .histo.h2 -bg grey
       frame .histo.h3 -bg grey
       pack .histo.h1 .histo.h2 .histo.h3 -fill x -pady 2m
 
       label .histo.h1.hid -bg grey -text "Histogram ID"
       entry .histo.h1.id -relief sunken -bg grey -textvariable id
       label .histo.h2.hdir -bg grey -text "Histogram Directory"
       entry .histo.h2.dir -bg grey -relief sunken -textvariable dir
       button .histo.h3.view -bg grey -text "View" -width 6
       button .histo.h3.cancel -bg grey -text "Cancel" -width 6

       pack .histo.h1.hid .histo.h1.id .histo.h2.hdir .histo.h2.dir  -padx 2m 
       pack .histo.h3.view .histo.h3.cancel -padx 2m -pady 2m -side right

       bind .histo.h1.id <Return> {ScatSendMsgNr {set hist_id $id}}
       bind .histo.h2.dir <Return> {ScatSendMsgNr {setc hist_dir $dir}}
       bind .histo.h3.view <1> {ScatSendMsgNr {set lhist -1}}
       bind .histo.h3.cancel <1> {after 10 {destroy .histo}}}}

#      this button gives status dumps in the message box

bind .frame.f2.f1.stat <1> {if {$havejob == 0} {needjob}
          if {$havejob == 1} {ScatSendMsgNr {set lstat -1}
              after 2000 [getmess]}}

#      FPACK status

bind .frame.f2.f1.fstat <1> {if {$havejob == 0} {needjob}
          if {$havejob == 1} {ScatSendMsgNr {set fstat -1}}}

#      allows user to set update rates for various processes

bind .frame.f2.f1.update <1> {if {$havejob == 0} {needjob}
   if {$havejob == 1} {global statusrate eventrate runrate messrate
   set srate [expr $statusrate / 1000]
   set erate [expr $eventrate / 1000]
   set rrate [expr $runrate / 1000]
   set mrate [expr $messrate / 1000]
   toplevel .update -bg grey
   frame .update.f1 -bg grey
   frame .update.f2 -bg grey
   frame .update.f3 -bg grey
   frame .update.f4 -bg grey
   frame .update.f5 -bg grey
   pack .update.f1 .update.f2 .update.f3 .update.f4 .update.f5 -pady 1m -fill x

   label .update.f1.lstatus -bg grey -text "Status Rate (sec)"
   label .update.f2.levent -bg grey -text "Event Rate (sec)"
   label .update.f3.lrun -bg grey -text "Run Rate (sec)"
   label .update.f4.lmess -bg grey -text "Message Rate (sec)"
   entry .update.f1.status -bg grey -textvariable srate -relief sunken
   entry .update.f2.event -bg grey -textvariable erate -relief sunken
   entry .update.f3.run -bg grey -textvariable rrate -relief sunken
   entry .update.f4.mess -bg grey -textvariable mrate -relief sunken
     
   pack .update.f1.lstatus .update.f2.levent .update.f3.lrun .update.f4.lmess \
     .update.f1.status .update.f2.event .update.f3.run .update.f4.mess -padx 2m
 
   button .update.f5.ok -bg grey -text OK -width 8
   pack .update.f5.ok -pady 2m
   bind .update.f5.ok <1> {
   set statusrate [expr $srate * 1000]
   set eventrate [expr $erate * 1000]
   set runrate [expr $rrate * 1000]
   set messrate [expr $mrate * 1000]
   after 10 {destroy .update}}}}

#     runs ced

bind .frame.f2.f1.ced <1> {if {$havejob == 0} {needjob}
   if {$havejob == 1} {exec ~heddle/ced2.0/ced > /dev/null &}}
   #       $env(CTEST_EXE)/ced}

#      binding to button that creates a window allowing custom commands to be 
#    passed to recsis

bind .frame.f2.f1.cust <1> {if {$havejob == 0} {needjob}
     if {$havejob == 1} {toplevel .cust -bg grey
        entry .cust.comm -textvariable custcomm -relief sunken -bg grey
        button .cust.cancel -bg grey -text "Cancel"
        
        pack .cust.comm .cust.cancel -padx 2m -pady 2m

        bind .cust.comm <Return> {if {$havejob == 0} {needjob}
	   if {$havejob == 1} {ScatSendMsgNr "$custcomm"}
	     after 10 {destroy .cust}}
	bind .cust.cancel <1> {after 10 {destroy .cust}}}}

#    disconnects from current job

bind .frame.f2.f1.discon <1> {losejob}

#    exits recsis 

bind .frame.f2.f1.exitb <1> {if {$havejob == 0} {needjob}
       if {$havejob == 1} {getstatus
          getevent
          getrun
          getmess
          ScatSendMsgNr {set lexit -1}
          losejob}}
         
#        quits recsis

bind .frame.f2.f1.quitb <1> {if {$havejob == 0} {needjob}
       if {$havejob == 1} {getstatus
          getevent
          getrun
          getmess
          ScatSendMsgNr {set lquit -1}
          losejob}}

#       quits program

bind .frame.f2.f1.quit <1> {exit}

#        destroys warning button when it is clicked on 

bind .frame.f2.f2.f1.warn <1> {set flash 0}
