#      checks to see if a value has been changed, if not, the variables are 
#    all set to their default values

set tplist {1 2 3 4 5 6 7 8 9 10}
set swlist {1 2 3 4 5 6 7 8 9 10}
set plist {1 2 3 4 5 6 7 8}
set lyr1list {1 2 3 4 5 6 7 8 9 10 11 12 13 14 15 16 17 18} 
set lyr2list {19 20 21 22 23 24 25 26 27 28 29 30 31 32 33 34 35 36}
set ztflist {1 2 3 4 5 6 7 8 9 10}
set zcutlist {1 2 3 4 5 6 7 8 9 10}
foreach i $tplist {incr x [info exists tp($i)]}
foreach i $swlist {incr x [info exists sw($i)]}
foreach i $plist {incr x [info exists p($i)]}
foreach i $lyr1list {incr x [info exists lyr($i)]}
foreach i $lyr2list {incr x [info exists lyr($i)]}
foreach i $ztflist {incr x [info exists ztf($i)]}
foreach i $zcutlist {incr x [info exists zcut($i)]}
if {$x == 0} {
  foreach i $tplist {set tp($i) 0}
  foreach i $swlist {set sw($i) 0}
  foreach i $plist {set p($i) 6}
  set p(1) 4
  set p(2) 0
  set p(3) 4
  foreach i $lyr1list {set lyr($i) 0}
  set lyr(5) 1 
  set lyr(6) 1
  foreach i $lyr2list {set lyr($i) 0} 
  foreach i $ztflist {set ztf($i) 0}
  set ztf(1) 3
  set ztf(3) 1
  set ztf(4) 0.1
  foreach i $zcutlist {set zcut($i) 0}
  set zcut(2) 6
  set zcut(3) 6
  set zcut(4) 10
  set zcut(5) 7
  set zcut(6) 20
  set zcut(7) 1
  set zcut(8) 0.1}

toplevel .trkconfig -bg grey
frame .trkconfig.f1 -bg grey
frame .trkconfig.f2 -bg grey

pack .trkconfig.f1 .trkconfig.f2 

button .trkconfig.f1.print   -bg grey -text "Track Print" 
button .trkconfig.f1.switch   -bg grey -text "Track Switch" 
button .trkconfig.f1.patt   -bg grey -text "Track Pattern" 
button .trkconfig.f1.layer   -bg grey -text "Track Layer" 
button .trkconfig.f1.ztfit   -bg grey -text "Track ZtFit" 
button .trkconfig.f1.zcut   -bg grey -text "Track ZCut" 
button .trkconfig.f2.ok   -bg grey -text "OK" 

pack .trkconfig.f1.print .trkconfig.f1.switch .trkconfig.f1.patt \
   .trkconfig.f1.layer .trkconfig.f1.ztfit .trkconfig.f1.zcut -fill x

pack .trkconfig.f2.ok -padx 2m -pady 2m

#    track print options

bind .trkconfig.f1.print <1> {
  toplevel .print -bg grey
  frame .print.f1 -bg grey
  frame .print.f2 -bg grey
  pack .print.f1 .print.f2

  foreach i $tplist {
     checkbutton .print.f1.tp$i -bg grey -text "Track Print $i" \
       -relief flat -variable tp($i)
     pack .print.f1.tp$i -anchor w}

  button .print.f2.ok -bg grey -text "OK"
  pack .print.f2.ok -padx 2m -pady 2m
  bind .print.f2.ok <1> {
    foreach i $tplist {set cmd(trk_tp$i) "set trk_print($i) $tp($i)"}
    after 10 {destroy .print}}} 

#    track switch options

bind .trkconfig.f1.switch <1> {
  toplevel .switch -bg grey
  frame .switch.f1 -bg grey
  frame .switch.f2 -bg grey
  pack .switch.f1 .switch.f2

  foreach i $swlist {
     checkbutton .switch.f1.sw$i -bg grey -text "Switch Print $i" \
       -relief flat -variable sw($i)
     pack .switch.f1.sw$i -anchor w}

  button .switch.f2.ok -bg grey -text "OK"
  pack .switch.f2.ok -padx 2m -pady 2m
  bind .switch.f2.ok <1> {
    foreach i $swlist {set cmd(trk_sw$i) "set trk_switch($i) $sw($i)"}
    after 10 {destroy .switch}}} 

#    track pattern options

bind .trkconfig.f1.patt <1> {
  toplevel .pattern -bg grey
  foreach i $plist {
    frame .pattern.f$i -bg grey
    pack .pattern.f$i
    label .pattern.f$i.lp$i -bg grey -text "Track Pattern $i"
    entry .pattern.f$i.p$i -bg grey -textvariable p($i) -relief sunken
      pack .pattern.f$i.lp$i .pattern.f$i.p$i -side left -padx 2m -pady 2m}
  bind .pattern.f1.p1 <Return> {set cmd(trk_patt1) "set trk_patt(1) $p(1)"}
  bind .pattern.f2.p2 <Return> {set cmd(trk_patt2) "set trk_patt(2) $p(2)"}
  bind .pattern.f3.p3 <Return> {set cmd(trk_patt3) "set trk_patt(3) $p(3)"}
  bind .pattern.f4.p4 <Return> {set cmd(trk_patt4) "set trk_patt(4) $p(4)"}
  bind .pattern.f5.p5 <Return> {set cmd(trk_patt5) "set trk_patt(5) $p(5)"}
  bind .pattern.f6.p6 <Return> {set cmd(trk_patt6) "set trk_patt(6) $p(6)"}
  bind .pattern.f7.p7 <Return> {set cmd(trk_patt7) "set trk_patt(7) $p(7)"}
  bind .pattern.f8.p8 <Return> {set cmd(trk_patt8) "set trk_patt(8) $p(8)"}

  frame .pattern.f9 -bg grey
  pack .pattern.f9 
  button .pattern.f9.ok -bg grey -text "OK"
  pack .pattern.f9.ok -padx 2m -pady 2m
    bind .pattern.f9.ok <1> {after 10 {destroy .pattern}}}

#     track layer options

bind .trkconfig.f1.layer <1> {
  toplevel .layer -bg grey
  frame .layer.f1 -bg grey
  frame .layer.f2 -bg grey 
  pack .layer.f1 .layer.f2
 
  frame .layer.f1.f1 -bg grey
  frame .layer.f1.f2 -bg grey
  pack .layer.f1.f1 .layer.f1.f2 -side left -padx 1m

  foreach i $lyr1list {
     checkbutton .layer.f1.f1.lyr$i -bg grey -text "Track Layer $i" \
       -relief flat -variable lyr($i)
     pack .layer.f1.f1.lyr$i -anchor w}

  foreach i $lyr2list {
     checkbutton .layer.f1.f2.lyr$i -bg grey -text "Track Layer $i" \
       -relief flat -variable lyr($i)
     pack .layer.f1.f2.lyr$i -anchor w}

  button .layer.f2.ok -bg grey -text "OK"
  pack .layer.f2.ok -padx 2m -pady 2m
  bind .layer.f2.ok <1> {
    foreach i $lyr1list {set cmd(trklayer$i) "set trklayer($i) $lyr($i)"}
    foreach i $lyr2list {set cmd(trklayer$i) "set trklayer($i) $lyr($i)"}
    after 10 {destroy .layer}}}

#     ztfit options

bind .trkconfig.f1.ztfit <1> {toplevel .ztfit -bg grey
  foreach i $ztflist {
    frame .ztfit.f$i -bg grey
    pack .ztfit.f$i
    label .ztfit.f$i.lztf$i -bg grey -text "Track Ztfit $i"
    entry .ztfit.f$i.ztf$i -bg grey -textvariable ztf($i) -relief sunken
    pack .ztfit.f$i.lztf$i .ztfit.f$i.ztf$i -side left -padx 2m -pady 2m}
  bind .ztfit.f1.ztf1 <Return> {set cmd(trk_ztf1) "set trkztfit(1) $ztf(1)"}
  bind .ztfit.f2.ztf2 <Return> {set cmd(trk_ztf2) "set trkztfit(2) $ztf(2)"}
  bind .ztfit.f3.ztf3 <Return> {set cmd(trk_ztf3) "set trkztfit(3) $ztf(3)"}
  bind .ztfit.f4.ztf4 <Return> {set cmd(trk_ztf4) "set trkztfit(4) $ztf(4)"}
  bind .ztfit.f5.ztf5 <Return> {set cmd(trk_ztf5) "set trkztfit(5) $ztf(5)"}
  bind .ztfit.f6.ztf6 <Return> {set cmd(trk_ztf6) "set trkztfit(6) $ztf(6)"}
  bind .ztfit.f7.ztf7 <Return> {set cmd(trk_ztf7) "set trkztfit(7) $ztf(7)"}
  bind .ztfit.f8.ztf8 <Return> {set cmd(trk_ztf8) "set trkztfit(8) $ztf(8)"}
  bind .ztfit.f9.ztf9 <Return> {set cmd(trk_ztf9) "set trkztfit(9) $ztf(9)"}
  bind .ztfit.f10.ztf10 <Return> {set cmd(trk_ztf10) "set trkztfit(10) $ztf(10)"}

  frame .ztfit.f11 -bg grey
  pack .ztfit.f11
  button .ztfit.f11.ok -bg grey -text "OK"
  pack .ztfit.f11.ok -padx 2m -pady 2m
  bind .ztfit.f11.ok <1> {after 10 {destroy .ztfit}}}

#      zcut options
 
bind .trkconfig.f1.zcut <1> {toplevel .zcut -bg grey
  foreach i $zcutlist {
    frame .zcut.f$i -bg grey
    pack .zcut.f$i
    label .zcut.f$i.lzcut$i -bg grey -text "Track Zcut $i"
    entry .zcut.f$i.zcut$i -bg grey -textvariable zcut($i) -relief sunken
    pack .zcut.f$i.lzcut$i .zcut.f$i.zcut$i -side left -padx 2m -pady 2m}
  bind .zcut.f1.zcut1 <Return> {set cmd(trk_zcut1) "set trkzcut(1) $zcut(1)"}
  bind .zcut.f2.zcut2 <Return> {set cmd(trk_zcut2) "set trkzcut(2) $zcut(2)"}
  bind .zcut.f3.zcut3 <Return> {set cmd(trk_zcut3) "set trkzcut(3) $zcut(3)"}
  bind .zcut.f4.zcut4 <Return> {set cmd(trk_zcut4) "set trkzcut(4) $zcut(4)"}
  bind .zcut.f5.zcut5 <Return> {set cmd(trk_zcut5) "set trkzcut(5) $zcut(5)"}
  bind .zcut.f6.zcut6 <Return> {set cmd(trk_zcut6) "set trkzcut(6) $zcut(6)"}
  bind .zcut.f7.zcut7 <Return> {set cmd(trk_zcut7) "set trkzcut(7) $zcut(7)"}
  bind .zcut.f8.zcut8 <Return> {set cmd(trk_zcut8) "set trkzcut(8) $zcut(8)"}
  bind .zcut.f9.zcut9 <Return> {set cmd(trk_zcut9) "set trkzcut(9) $zcut(9)"}
  bind .zcut.f10.zcut10 <Return> {set cmd(trk_zcut10) "set trkzcut(10) $zcut(10)"}

  frame .zcut.f11 -bg grey
  pack .zcut.f11
  button .zcut.f11.ok -bg grey -text "OK"
  pack .zcut.f11.ok -padx 2m -pady 2m
  bind .zcut.f11.ok <1> {after 10 {destroy .zcut}}}

bind .trkconfig.f2.ok <1> {after 10 {destroy .trkconfig}}  


