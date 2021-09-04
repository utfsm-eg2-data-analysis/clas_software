
if {[info exists cmd(egn1)] + [info exists cmd(egn2)] + [info exists cmd(egn3)] == 0} {
set strip 0.001
set peak 0.003
set hit 0.010}

toplevel .egnconfig -bg grey
frame .egnconfig.f1 -bg grey
frame .egnconfig.f2 -bg grey
frame .egnconfig.f3 -bg grey
frame .egnconfig.f4 -bg grey
pack .egnconfig.f1 .egnconfig.f2 .egnconfig.f3 .egnconfig.f4

label .egnconfig.f1.lstrip -bg grey -text "Minimum threshold for strip"
label .egnconfig.f2.lpeak -bg grey -text "Minimum threshold for peaks"
label .egnconfig.f3.lhit -bg grey -text "Minimum threshold for hit"

entry .egnconfig.f1.strip -bg grey -textvariable "strip" -relief sunken
entry .egnconfig.f2.peak -bg grey -textvariable "peak" -relief sunken
entry .egnconfig.f3.hit -bg grey -textvariable "hit" -relief sunken
button .egnconfig.f4.ok -text "OK" -bg grey

pack .egnconfig.f1.lstrip .egnconfig.f2.lpeak .egnconfig.f3.lhit \
     .egnconfig.f1.strip .egnconfig.f2.peak .egnconfig.f3.hit \
     -side left -pady 2m -padx 2m
pack .egnconfig.f4.ok -pady 2m

bind .egnconfig.f1.strip <Return> {set cmd(egn1) "set EcFitEdge_strip_threshold $strip"} 
bind .egnconfig.f2.peak <Return> {set cmd(egn2) "set EcFitEdge_peak_threshold $peak"} 
bind .egnconfig.f3.hit <Return> {set cmd(egn3) "set EcFitEdge_hit_threshold $hit"}
bind .egnconfig.f4.ok <1> {after 10 {destroy .egnconfig}}  