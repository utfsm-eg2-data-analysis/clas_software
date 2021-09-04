# Define the histogram numbers
set HB_time 3300
set HB_Chi2 3400
set HB_Mom  3500
set HB_Xv   3600
set HB_Yv   3700
set HB_Zv   3800
set HB_Cx   3900
set HB_Cy   4000
set HB_Cz   4100
set HB_Q    4200

cdir //PAWC/TRK

# 2 dimensional histogram booking not yet implemented 
#do while {$Reg <= 3}
#{
#   do while {$Sec <= 6}
#   {
#      set HistID [expr 3200 + 10*$Sec + $Reg]
#      book $HistID "HBT occupancy" 195 0. 195. 37 0. 37.
#      incr Sec
#   }
#   incr Reg
#}

# Hit based time histograms indexed on region and sector
# from the DCLA bank
set Sec 1
while {$Sec <=6} {
   set Reg 1
   set HistID [expr $HB_time + 10*$Reg + $Sec]
   book $HistID "HBT time" 200 500. 3500.
   fill $HistID DCLA.$Sec.TIME
   set Reg 2
   set HistID [expr $HB_time + 10*$Reg + $Sec]
   book $HistID "HBT time" 200 1500. 6500.
   fill $HistID DCLA.$Sec.TIME
   set Reg 3
   set HistID [expr $HB_time + 10*$Reg + $Sec]
   book $HistID "HBT time" 200 1500. 8500.
   fill $HistID DCLA.$Sec.TIME
   incr Sec
}

# histograms from HBTR bank.  Not indexed on region or sector
# book
book $HB_Chi2 "HBT Chi squared" 100 0. 20.
book $HB_Mom "HBT track momentum" 100 0. 10
book $HB_Xv "HBT x at vertex" 100 -100. 100.
book $HB_Yv "HBT y at vertex" 100 -100. 100.
book $HB_Zv "HBT z at vertex" 100 -100. 100.
book $HB_Cx "HBT x direction cosine" 100 -1. 1.
book $HB_Cy "HBT y direction cosine" 100 -1. 1.
book $HB_Cz "HBT z direction cosine" 100 -1. 1.
book $HB_Q "HBT track charge" 5 -2. 2.
# fill
fill $HB_Q HBTR.0.Q
fill $HB_Chi2 HBTR.0.CHI2
fill $HB_Mom HBTR.0.P
fill $HB_Xv HBTR.0.X
fill $HB_Yv HBTR.0.Y
fill $HB_Zv HBTR.0.Z
fill $HB_Cx HBTR.0.CX
fill $HB_Cy HBTR.0.CY
fill $HB_Cz HBTR.0.CZ








