#!/usr/local/bin/wish
proc recsis_copy {in out n} {
puts "$in $out $n"
set scriptfile [open reccp_tmp.tcl w]
puts $scriptfile "source ~/work/tcl/recsis_proc.tcl"
puts $scriptfile "turnoff ALL"
puts $scriptfile "inputfile $in"
puts $scriptfile "outputfile $out"
puts $scriptfile "go $n"
puts $scriptfile "exit_pend"
close $scriptfile
set log [exec ~/work/bin/Linux/recsis_debug -b -t reccp_tmp.tcl]
toplevel .log
text .log.text -yscrollcommand ".log.scroll set"
scrollbar .log.scroll -command ".log.text yview"
pack .log.scroll -side right -fill y
pack .log.text -side left
.log.text insert end $log
return
}
label .inputlabel -text "Input file name" 
entry .inputentry -textvariable inputfile
label .outputlabel -text "Output file name" 
entry .outputentry -textvariable outputfile
label .eventslabel -text "Number of events to copy" 
entry .eventsentry -textvariable ncopy
set inputfile /scratch/data/clas_007787.A00
set outputfile /scratch/data/clas_007787.A00.short
set ncopy 100
button .go -text "Go" -command {recsis_copy $inputfile $outputfile $ncopy}
button .quit -text "Quit" -command exit
pack .inputlabel .inputentry .outputlabel .outputentry .eventslabel .eventsentry .go .quit
