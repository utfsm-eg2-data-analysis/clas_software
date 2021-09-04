
#      procedure for toggling Display buttton
set fpkfil {none}

proc dispall {} {global dispal dis
              if {$dispal == "Display All"} {set dispal {Don't Display All}
                  set dis {set ldisplay_all 0}
                  return $dispal}
              if {$dispal == "Don't Display All"} {set dispal {Display All}
                  set dis {set ldisplay_all -1}
                  return $dispal}}

#    procedure for toggling communicate button  

proc communicate {} {global comm com
              if {$comm == "Don't Communicate"} {set comm {Communicate}
                  set com {set lscat -1}
                  return $comm}
              if {$comm == "Communicate"} {set comm {Don't Communicate}
                  set com {set lscat 0}
                  return $comm}}

#     procedure to alert users that the selected option is not available

proc notyet {} {toplevel .notyet -bg grey
	   label .notyet.label -bg grey -text "Sorry, this is currently not \
               available."
           button .notyet.ok -bg grey -text "OK"
           pack .notyet.label .notyet.ok -padx 2m -pady 2m
	bind .notyet.ok <1> {after 10 {destroy .notyet}}}

#      defaults for file locations

set clasparms "$env(CLAS_PARMS)"
set ddlfil "$clasparms/clasbanks.ddl"
set rcin {/clas/cebafb/u2/data/gsimevt.bfp}
set home [pwd]
set rcout {junk2.bfp}
set sfile test.tcl

#      default values for lines to be sent to recsis

set evp "set nevt_to_process 0"
set evs "set nevt_to_skip 0"
set nrp "set nrun_to_process 0"
set nrs "set nrun_to_skip 0"
set ddl "setc ddl_file $clasparms/clasbanks.ddl"
set pro "setc rec_prompt [exec uname]_rs>"
set fpf {}
set proclist {trk egn cc tof st time tagger usr0 usr1}
foreach i $proclist {set p($i) "set l[set i]_do -1"}
set classlist {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18 19 20}
foreach i $classlist {
   set ec($i) "set levent_class($i) -1"}
set dis {set ldisplay_all -1}
set hid {set hist_id 0}
set hdr {setc hist_dir //PAWC/MYDIR}
set rci {}
set rco {}
set com "set lscat -1"

#     default values for run and event variables

set nprocess 0
set nskip 0
set rprocess 0
set rskip 0

#     default names for toggling buttons

set dispal {Display All}
set comm {Communicate}

#     sets prompt default to include username

set promp "[exec uname]_rs>"

#      default values for eventclass and processor packages checkbuttons

foreach i $proclist {set b($i) 1}
foreach i $classlist {set ev($i) 1}

#    used to see if any options have been selected in trk.tcl

set x 0

#    helps set array for custom commands

set n 0

#    insures that cmd array is not empty

set cmd(0) {}

toplevel .config -bg grey

#      frames to help position widgets

frame .config.f1 -bg grey
frame .config.f2 -bg grey
frame .config.f3 -bg grey
frame .config.f4 -bg grey
pack  .config.f1 .config.f2 .config.f3 .config.f4 -fill x -padx 2m

frame .config.f1.f1 -bg grey
frame .config.f1.f2 -bg grey
frame .config.f3.f1 -bg grey
pack .config.f1.f1 -side left -fill both
pack .config.f1.f2 -side right -fill both
pack .config.f3.f1 -side left 

frame .config.f1.f1.f1 -bg grey
frame .config.f1.f1.f2 -bg grey
frame .config.f1.f1.f3 -bg grey
frame .config.f1.f2.f1 -bg grey
frame .config.f1.f2.f2 -bg grey
frame .config.f1.f2.f3 -bg grey
pack .config.f1.f1.f1 .config.f1.f1.f2 .config.f1.f1.f3 .config.f1.f2.f1 \
   .config.f1.f2.f2 .config.f1.f2.f3 -padx 1m -fill x

#       widget definitions

label .config.f1.f1.f1.levtproc -text "Events to Process" -bg grey
label .config.f1.f2.f1.levtskip -text "Events to Skip" -bg grey
label .config.f1.f1.f2.lrunproc -text "Runs to Process" -bg grey
label .config.f1.f2.f2.lrunskip -text "Runs to Skip" -bg grey
label .config.f1.f1.f3.lprompt -text "Prompt" -bg grey
entry .config.f1.f1.f1.evtproc -bg grey -textvariable nprocess \
    -relief sunken -width 6
entry .config.f1.f2.f1.evtskip -bg grey -textvariable nskip \
    -relief sunken -width 6
entry .config.f1.f1.f2.runproc -textvariable rprocess -bg grey \
    -relief sunken -width 6
entry .config.f1.f2.f2.runskip -textvariable rskip -bg grey \
    -relief sunken -width 6
entry .config.f1.f1.f3.prompt -textvariable promp -bg grey \
    -relief sunken -width 12
label .config.f2.lddlfile -text "ddl Definition" -bg grey
entry .config.f2.ddlfile -textvariable ddlfil -bg grey \
    -relief sunken -width 36
button .config.f3.f1.fpack -text "FPACK" -bg grey
button .config.f3.f1.procpack -text "Processor Packages" -bg grey
button .config.f3.f1.evclass -bg grey -text "Event Classes"
button .config.f3.f1.dispall -bg grey -text "$dispal"
button .config.f3.f1.histo -bg grey -text "Histograms"
button .config.f3.f1.recin -text "Input File" -bg grey 
button .config.f3.f1.recout -text "Output File" -bg grey 
button .config.f3.f1.custom -bg grey -text "Custom Command"
button .config.f3.f1.comm -bg grey -text "$comm" 
button .config.f4.wrscr -bg grey -text "Write Script"
button .config.f4.launch -bg grey -text "Launch"
button .config.f4.exit -bg grey -text "Exit"

pack .config.f1.f1.f1.levtproc .config.f1.f2.f1.levtskip \
    .config.f1.f1.f2.lrunproc .config.f1.f2.f2.lrunskip  \
    .config.f1.f1.f3.lprompt -side left -pady 2m -fill x 

pack .config.f1.f1.f1.evtproc .config.f1.f2.f1.evtskip \
    .config.f1.f1.f2.runproc .config.f1.f2.f2.runskip  \
    .config.f1.f1.f3.prompt -side left -fill x

pack .config.f2.lddlfile .config.f2.ddlfile -side left -pady 2m -fill x


pack .config.f3.f1.fpack .config.f3.f1.procpack .config.f3.f1.evclass \
    .config.f3.f1.dispall .config.f3.f1.histo .config.f3.f1.recin \
    .config.f3.f1.recout .config.f3.f1.custom .config.f3.f1.comm \
    -fill x -pady 1m -padx 2m
pack .config.f4.wrscr .config.f4.launch .config.f4.exit \
    -padx 8m -side left -pady 2m

#     bindings to set variables to set values for entry boxes covering event 
#   and run values, prompt name, and ddl definition

bind .config.f1.f1.f1.evtproc <Return> {set evp "set nevt_to_process $nprocess"}

bind .config.f1.f2.f1.evtskip <Return> {set evs "set nevt_to_skip $nskip"}

bind .config.f1.f1.f2.runproc <Return> {set nrp "set nrun_to_process $rprocess"}

bind .config.f1.f2.f2.runskip <Return> {set nrs "set nrun_to_skip $rskip"}

bind .config.f1.f1.f3.prompt <Return> {set pro "setc rec_prompt $promp"}

bind .config.f2.ddlfile <Return> {set ddl "setc ddl_file $ddlfil"}

#    fpack options

bind .config.f3.f1.fpack <1> {notyet}

#     processor packages options

bind .config.f3.f1.procpack <1> {
    toplevel .processors -bg grey
    frame .processors.f1 -bg grey
    frame .processors.f2 -bg grey
    pack .processors.f1 .processors.f2 -padx 2m -pady 2m

    frame .processors.f1.f1 -bg grey
    frame .processors.f1.f2 -bg grey
    pack .processors.f1.f1 .processors.f1.f2 -padx 1m -pady 1m -side left   

    foreach i $proclist {
       checkbutton .processors.f1.f1.l$i -text "$i Processor" -bg grey \
           -variable b($i) -relief flat
       button .processors.f1.f2.c$i -text "Configure" -bg grey 
       pack .processors.f1.f1.l$i .processors.f1.f2.c$i \
           -pady 1m -anchor w}

    button .processors.f2.ok -bg grey -text "OK" -width 6          
    pack .processors.f2.ok -pady 2m

    bind .processors.f1.f2.ctrk <1> {if {[file isfile trk.tcl] == 1} \
       {source trk.tcl}
	  if {[file isfile trk.tcl] == 0} \
             {source [$env(RECSIS)/tcl/trk.tcl]}}
    bind .processors.f1.f2.cegn <1> {if {[file isfile egn.tcl] == 1} \
       {source egn.tcl}
	  if {[file isfile egn.tcl] == 0} \
             {source [$env(RECSIS)/tcl/egn.tcl]}}
    bind .processors.f1.f2.ccc <1> {notyet}
    bind .processors.f1.f2.ctof <1> {notyet}
    bind .processors.f1.f2.cst <1> {notyet}
    bind .processors.f1.f2.ctime <1> {notyet}
    bind .processors.f1.f2.ctagger <1> {notyet}
    bind .processors.f1.f2.cusr0 <1> {notyet}
    bind .processors.f1.f2.cusr1 <1> {notyet}

    bind .processors.f2.ok <1> {
	foreach i $proclist {if {$b($i) == 0} {set p($i) "set l[set i]_do 0"}}
        after 10 {destroy .processors}}}

#      Creates Window to Enable/Disable Event Classes

bind .config.f3.f1.evclass <1> {
   toplevel .events -bg grey
   foreach i $classlist {
      checkbutton .events.ev$i -bg grey -text "Event Class $i" -relief flat \
         -variable ev($i)
      pack .events.ev$i -anchor w}

   button .events.ok -bg grey -text "OK"
   pack .events.ok -pady 2m
   bind .events.ok <1> {
   foreach i $classlist {
      if {$ev($i) == 0} {set ec($i) "set levent_class($i) 0"}}
   after 10 {destroy .events}}} 

bind .config.f3.f1.dispall <1> {dispall
         .config.f3.f1.dispall configure -text $dispal}

#      Creates window to select histogram information.

bind .config.f3.f1.histo <1> {toplevel .hist -bg grey
       frame .hist.h1 -bg grey
       frame .hist.h2 -bg grey
       frame .hist.h3 -bg grey
       pack .hist.h1 .hist.h2 .hist.h3 -fill x -pady 2m

       label .hist.h1.hid -bg grey -text "Histogram ID"
       entry .hist.h1.id -relief sunken -bg grey -textvariable id
       label .hist.h2.hdir -bg grey -text "Histogram Directory"
       entry .hist.h2.dir -bg grey -relief sunken -textvariable dir
       button .hist.h3.ok -bg grey -text "OK" -width 6

       pack .hist.h1.hid .hist.h1.id  -padx 2m 
       pack .hist.h2.hdir .hist.h2.dir  -padx 2m 
       pack .hist.h3.ok -pady 2m

       bind .hist.h1.id <Return> {set hid "set hist_id $id"}
       bind .hist.h2.dir <Return> {set hdr "setc hist_dir $dir"}
       bind .hist.h3.ok <1> {after 10 {destroy .hist}}}

#      Creates window where Input File is selected

bind .config.f3.f1.recin <1> {toplevel .input -bg grey

#      procedure defining listbox and scrollbar

        proc ilb {} {listbox .input.f2.list -relief sunken -borderwidth 2 \
           -yscrollcommand ".input.f2.scroll set" -bg grey
               scrollbar .input.f2.scroll -command ".input.f2.list yview" \
           -bg grey
               pack .input.f2.list .input.f2.scroll -side left -fill both} 

#      procedure to fill listbox with files in the current directory that match
 
#      the specifications of  "search" which is entered in the filter entrybox.

	proc ifilt {} {global ifilter idir isearch
	   set idir [file dirname $ifilter]
	   set isearch [file tail $ifilter]
	   cd $idir
           foreach i [lsort [glob -nocomplain $isearch]] \
           {if {[file isdirectory $i] > 0} {append i /}
	   .input.f2.list insert end $i}
	   ibindlist}

#      procedure binding listbox elements.  If a directory is selected, then 
#    the directory name is saved as the variable  "dir"  contents of that 
#    directory are displayed.  If a file is selected, it is stored in the 
#    variable "file" displayed in the file entrybox.
      
	proc ibindlist {} {global idir
	     bind .input.f2.list <Double-Button-1> {          
               if {[file isdirectory [selection get]] > 0} { 
                     append idir / [selection get]
		     set ifilter [append idir / $isearch]
                     destroy .input.f2.list .input.f2.scroll
                     ilb
                     ifilt                                
                     return}
               if {[file isfile [selection get]] > 0} {
                     set ifile [selection get]
		     append idir / $ifile
		     set ifile $idir}}}
 
#      default directory for search

	set ifilter "$env(CLAS_DATA)/*.evt"

	frame .input.f1 -bg grey
	frame .input.f2 -bg grey -width 40
	frame .input.f3 -bg grey
	frame .input.f4 -bg grey
	pack .input.f1 .input.f2 .input.f3 .input.f4 

	label .input.f1.lfilter -bg grey -text "Filter"
	entry .input.f1.filter -bg grey -textvariable ifilter -relief sunken \
              -width 32 -bg grey

	pack .input.f1.lfilter .input.f1.filter -pady 1m -side left

	set idir [file dirname $ifilter]
	set isearch [file tail $ifilter]
	ilb

	label .input.f3.lfile -bg grey -text "File"
	entry .input.f3.file -bg grey -textvariable ifile -relief sunken \
             -width 32 

	pack .input.f3.lfile .input.f3.file -side left -pady 1m

#      After a file is selected, "rci"  is set so it will pass the file name on
#    to recsis.  The program then returns to the directory the program was
#    started from.  The other variables are erased since they appear again in 
#    the file output selection window.

	bind .input.f3.file <Return> {set rci "setc rec_input $ifile"
	   cd $home
        after 10 {destroy .input}}

	button .input.f4.cancel -bg grey -text "Cancel"
	button .input.f4.ok -bg grey -text "OK"

	pack .input.f4.ok .input.f4.cancel -side left -padx 8m -pady 2m

	bind .input.f4.cancel <1> {cd $home
	   after 10 {destroy .input}}
	bind .input.f4.ok <1> {set rci "setc rec_input $ifile"
	   cd $home
           after 10 {destroy .input}}

#      When a directory is selected in the filter box, the directory name is 
#      saved as "dir" and the listbox displays the contents of the directory.  
#      If the directory does not exist, the filter returns to the previous
#      directory.

	bind .input.f1.filter <Return> {set idir [file dirname $ifilter]
	      set isearch [file tail $ifilter]
              if {[file isdirectory $idir] < 1} {set idir [pwd]
	      set ifilter [append idir / $isearch]}
              destroy .input.f2.list .input.f2.scroll
              ilb
              ifilt}
	ibindlist
	ifilt}
	
#      Creates file where output file is selected

bind .config.f3.f1.recout <1> {toplevel .output -bg grey

#      procedure to create listbox and scrollbar

	proc olb {} {listbox .output.f2.list -relief sunken -borderwidth 2 \
           -yscrollcommand ".output.f2.scroll set" -bg grey
               scrollbar .output.f2.scroll -command ".output.f2.list yview" \
           -bg grey
               pack .output.f2.list .output.f2.scroll -side left -fill y}

#      procedure to fill listbox with files in the current directory that match
#   the specifications of  "search" which is entered in the filter entrybox.
      
	proc ofilt {} {global ofilter odir osearch
	   set odir [file dirname $ofilter]
	   set osearch [file tail $ofilter]
	   cd $odir
           foreach i [lsort [glob -nocomplain $osearch]] \
           {if {[file isdirectory $i] > 0} {append i /}
	   .output.f2.list insert end $i}
	   obindlist}

#     procedure binding listbox elements.  If a directory is selected, then th 
#   directory name is saved as the variable  "dir"  contents of that directory
#   are displayed.  If a file is selected, it is stored in the variable "file"
#   and displayed in the file entrybox.
     
	proc obindlist {} {global odir
	     bind .output.f2.list <Double-Button-1> {          
               if {[file isdirectory [selection get]] > 0} { 
                     append odir / [selection get]
		     set ofilter [append odir / $osearch]
                     destroy .output.f2.list .output.f2.scroll
                     olb
                     ofilt                                
                     return}
               if {[file isfile [selection get]] > 0} {
                     set ofile [selection get]
		     append odir / $ofile
		     set ofile $odir}}} 

	set ofilter $home/*.evt

	frame .output.f1 -bg grey
	frame .output.f2 -bg grey
	frame .output.f3 -bg grey
	frame .output.f4 -bg grey
	pack .output.f1 .output.f2 .output.f3 .output.f4

	label .output.f1.lfilter -bg grey -text "Filter"
	entry .output.f1.filter -bg grey -textvariable ofilter -relief sunken \
              -width 32

	pack .output.f1.lfilter .output.f1.filter -side left -pady 1m

	set odir [file dirname $ofilter]
	set osearch [file tail $ofilter]
	olb

	label .output.f3.lfile -bg grey -text "File"
	entry .output.f3.file -bg grey -textvariable ofile -relief sunken \
             -width 32

	pack .output.f3.lfile .output.f3.file -side left -pady 1m

#      After a file is selected, "rco"  is set so it will pass the file name on
#    to recsis.  The program then returns to the directory the program was
#    started from.  The other variables are erased since they appear again in
#    the file input selection window.
      
	bind .output.f3.file <Return> {set rco "setc rec_output $ofile"
	   cd $home
           after 10 {destroy .output}}

	button .output.f4.cancel -bg grey -text "Cancel"
	button .output.f4.ok -bg grey -text "OK"

	pack .output.f4.ok .output.f4.cancel -pady 2m -side left -padx 8m

	bind .output.f4.cancel <1> {cd $home
	   after 10 {destroy .output}}
	bind .output.f4.ok <1> {set rco "setc rec_output $ofile"
	   cd $home
           after 10 {destroy .output}}

#     When a directory is selected in the filter box, the directory name is 
#   saved as "dir" and the listbox displays the contents of the directory.  
#   If the directory does not exist, the filter returns to the previous
#   directory.

	bind .output.f1.filter <Return> {set odir [file dirname $ofilter]
	      set osearch [file tail $ofilter]
              if {[file isdirectory $odir] < 1} {set odir [pwd]
	      set ofilter [append odir / $osearch]}
              destroy .output.f2.list .output.f2.scroll
              olb
              ofilt}
	obindlist
	ofilt}

#      adds custom commands to an array that is eventually passed on to the 
#    script file

bind .config.f3.f1.custom <1> {toplevel .custom -bg grey
        entry .custom.comm -textvariable command -relief sunken -bg grey
        button .custom.cancel -bg grey -text "Cancel"

        pack .custom.comm .custom.cancel -padx 2m -pady 2m

        bind .custom.comm <Return> {incr n
              set custom($n) $command
              set command {}
              after 10 {destroy .custom}}
        bind .custom.cancel <1> {after 10 {destroy .custom}}}

bind .config.f3.f1.comm <1> {communicate
         .config.f3.f1.comm configure -text $comm}

#      Creates Window asking for file to print commands into

bind .config.f4.wrscr <1> {toplevel .script -bg grey
        frame .script.f1 -bg grey
        frame .script.f2 -bg grey
        pack .script.f1 .script.f2 

	label .script.f1.lsave -bg grey -text "Save to File"
	entry .script.f1.save -bg grey -relief sunken -textvariable sfile
	button .script.f2.ok -bg grey -text "OK"

        pack .script.f1.lsave .script.f1.save -side left -pady 2m        
        pack .script.f2.ok -pady 2m -padx 2m

        bind .script.f2.ok <1> {after 10 {destroy .script}}
        bind .script.f1.save <Return> {after 10 {destroy .script}}}

#      Button to launch recsis

bind .config.f4.launch <1> {if {$rci == {}} {toplevel .error -bg grey
        label .error.lab1 -bg grey -text "You have not selected an input file." 
        label .error.lab2 -bg grey -text "Please do so before lauching."
        button .error.ok -bg grey -text "OK"
        pack .error.lab1 .error.lab2 .error.ok -padx 2m -pady 2m
        bind .error.ok <1> {after 10 {destroy .error}}}

        if {[file isfile $sfile] >0} {exec mv $sfile $sfile.BAK}
	if {$rci != {}} {
	set f [open $sfile w]
	puts $f "#Variable" 
	puts $f $dis
	puts $f {}
	puts $f "#Allows recsis to communicate using SCAT"
        puts $f $com
	puts $f {}
	puts $f "#Number of events to process"
	puts $f $evp
	puts $f {}
	puts $f "#Number of events to skip"
	puts $f $evs
	puts $f {}
	puts $f "#Number of runs to process"
	puts $f $nrp
	puts $f {}
	puts $f "#Number of runs to skip"
	puts $f $nrs
	puts $f {}
	puts $f "# Processor packages for recsis to use"
	foreach i $proclist {puts $f $p($i)}
	puts $f {}
	puts $f "# Eventclasses for recsis to use"
	foreach i $classlist {puts $f $ec($i)}
	puts $f {}
	puts $f "#Histogram ID"
	puts $f $hid
	puts $f {}
	puts $f "#Histogram directory"
	puts $f $hdr
	puts $f {}
	puts $f "#FPACK"
	puts $f $fpf
	puts $f {}
	puts $f "#ddl definition"
	puts $f $ddl
	puts $f {}
	puts $f "#recsis prompt"
	puts $f $pro
	puts $f {}
	puts $f "#recsis input file" 
	puts $f $rci
	puts $f {}
	puts $f "#recsis output file"
	puts $f $rco
	puts $f {}
        set commands [array names cmd]	
	foreach i $commands {puts $f $cmd($i)}
	while {$n >> 0} {puts $f $custom($n)
	     incr n -1}
	close $f
 
     toplevel .launch -bg grey
     frame .launch.f1 -bg grey
     frame .launch.f2 -bg grey
     pack .launch.f1 .launch.f2 -fill x -pady 2m

     label .launch.f1.label -bg grey -text "Node"
     entry .launch.f1.node -bg grey -textvariable node -relief sunken
     button .launch.f2.fore -bg grey -text "Foreground"
     button .launch.f2.back -bg grey -text "Background"
     button .launch.f2.cancel -bg grey -text "Cancel"

     pack .launch.f1.label .launch.f1.node -side left -padx 2m 
     pack .launch.f2.fore .launch.f2.back .launch.f2.cancel -pady 2m -padx 2m

     bind .launch.f1.node <Return> {set newnode $node}
     bind .launch.f2.fore <1> {after 10 {destroy .launch
               destroy .config}
         exec remsh $node xterm -cr blue -title recsis  -ls -ms red +s -sb -n \
         recsis -e $home/run_recsis recsis -t $sfile  > /dev/null &}
     bind .launch.f2.back <1> {after 10 {destroy .launch
               destroy .config}
         exec remsh $node $home/run_recsis  recsis -t $sfile \
		 > /dev/null &}
     bind .launch.f2.cancel <1> {after 10 {destroy .launch}}}}

bind .config.f4.exit <1> {after 10 {destroy .config}}






