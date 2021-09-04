#
# init file for RECSIS
#

#  load in  Tcl procedures, first check to see if the user is working
#  from the stand recsis_proc.tcl or has their own

if { [file exists ../../tcl/recsis_proc.tcl] } {
    puts "Using local version of recsis_proc.tcl in ../../tcl\n";
    source ../../tcl/recsis_proc.tcl
} else {
    puts "Using standard version of recsis_proc.tcl in $env(RECSIS)/tcl\n";
    source $env(RECSIS)/tcl/recsis_proc.tcl
}

# define packages
#set prescale $true;
#set prescale_factor 10;
#set nevt_to_process 100;
turnoff ALL;


# Tagger stuff:

#set lrf_do -1;
set lcall_do -1;
set ltagger_do -1;
set lusr0_do   -1;
set lusr1_do   -1;

set ltagger_h_do -1;
set lusr0_h_do   -1;
set lusr1_h_do   -1;

#
# default tagger tcl switch seting:
# UNCOMMENT THE FOLLOWING "set XXXX ,value> LINES AND CHANGES THE VALUES IF WANTED:
#to change the Adjacent T time coincidence window (ns) :
#set Tagger_TTwin 10
#to change the  Adjacent E time coincidence window(ns) :
#set Tagger_EEwin 20
#to change the  E/ T time coincidence window (ns)      :
#set Tagger_ETwin 30
#to change the E TDC minimum accepted value       :
#set Tagger_ETDCmin 700
#to change the E TDC maximum accepted value       :
#set Tagger_ETDCmax 1200
#to change the T- DSD time coincidence window  (ns)   :
#set Tagger_DSDwin 15
#to change the PS paddles time coincidence window(ns) :
#set Tagger_PSOSwin 30


# If you don't want to use the E-counter to do your analysis, set the next switch to 1:
#set Tagger_NO_E 0
# dump on screen switches:
#set Tagger_debug_begin 0
#set Tagger_debug_end -1
# <value min> and <value max> let you choose which steps of the processing you want to dump on the screen:
# those values are:
#-1 : processing default parameters
# 0 : RAW T counters and E counters 
# 1 : T & E counters after filtering 
# 2 : T & E counters after geometric matching 
# 3 : T & E counters after time matching 
# 4 : T & E counters after binning 
# 5 : T & E counters after RF correction 
# 6 : TAGR Bank
# Dump on screen the DSD infos (set to 1 to see something):
#set Tagger_DSD_debug 0
# DSD analysis switches, set them to 0 to have DSD ADC analysed even though ther is no
# TDC hit.
#set Tagger_PC_TDC 1
#set Tagger_PS_TDC 1 
#set Tagger_TAC_TDC 1 
# Warning tagger switch: defines how often the warning messages are
#printed to the screen
#set Tagger_warning 10
#every X warning, there will be a message on the screen,
#this is to avoid in some cases having the screen filled
#with warning messages which slows down the analysis.

# get some banks generated "by hand" from raw (ROC)  banks
#set Tagger_Raw_Format 0

#<value> let you select which BOS bank you want to generate from the raw Bank.
#This value is passed as a parameter (pattern) to the routine tag_raw_2_BOS.
#this comments in this routine for more information:

# Set where to look for parameters and calibration files:
# set to 1 to look in your local directory first

#set Tagger_parms_input 0


#
# other detectors & tracking switches. set them to -1 to turn them on.
#

set ltrk_do    0;
set lcc_do     0;
set ltof_do    0;
set lst_do     0;
set ltime_do   0;
set lec1_do    0;

set ltrk_h_do    0;
set lcc_h_do     0;
set ltof_h_do    0;
set lst_h_do     0;
set ltime_h_do   0;
set lec1_h_do    0;

#
# EGN stuff
#
set legn_do      0;
set legn_h_do    0;
set lfec_hist    0;
set lfec_echb    0;
#
# SEB... .stuff...
#
set lseb_do      0;
set lseb_h_do    0;
set lseb_hist    0;
set lseb_ntup    0;
#
#
set lall_nt_do   0;
#
set lntupmake_do 0;
#
#LTRK_H_DO, LEGN_H_DO, LCC_H_DO, LTOF_H_DO, LST_H_DO, 
#     1         LUSR0_H_DO,  LUSR1_H_DO, LUSR2_H_DO, LTIME_H_DO, LTAGGER_H_DO,
#     2         LEC1_H_DO, LSEB_H_DO, 
#     3         LFEC_HIST, LFEC_ECHB, LSEB_HIST, LSEB_NTUP, LALL_NT_DO

inputfile /work/clas/calib/tag_cal/Work/clas_012874.A00
#inputfile /work/clas/disk5/g6/data/clas_012282.A00
#inputfile $env(CLAS_DATA)/clas_sector6_000781.b01
#inputfile $env(CLAS_DATA)/benchmark.evt
#outputfile /scratch/roudot/junk.evt

# clasbanks
# uncomment and update this line ot use your own .ddl file.
#setc ddl_file ../bankdefs/clasbanks.ddl;

# Tracking tcl setting

#histo and ntuple level 3:raw hbt tbt 2:hbt tbt 1:hbt
set trk_ntuple 1
set trk_histo 1

#level of analysis 0: raw  2: hbt 4: tbt 
set trk_patt(1) 2

# tbt stuff realistic curve for drift time to drift distance.
set dc_xvst_choice 1

#for TBT test
#set trk_zcut(5) 50
#set trk_zcut(6) 30


# EGN Tcl setting (from stepan)

#set lpart_do -1;
#set part_his_out 0;
#set m2_ecel_cut 1000.;
#set m3_ecel_cut 10000.;
#set trkec_match 5.;
#set EcFitEdge_strip_threshold 0.001; 
#set EcFitEdge_peak_threshold 0.003; 
#set EcFitEdge_hit_threshold 0.010; 
#
#set anal_opt 2;
#set touch_id 2;
#set def_geom -1;
#set def_adc 0;
#set def_atten 0;
#SET whole_surf 16.; 
#set inner_surf 1.; 
#set outer_surf 28.; 
#
#set test_ec 0;
#set ltest  0;
#set test_sect 6;


# tell FPACK not to stop if it thinks you are running out of time

fpack "timestop -999999999"

# do not send events to event display
set lscat $false;
set ldisplay_all $false;

# tell recsis to pause or go
#go 1
pause

#  define the prompt for the user...they can change it later if 
#  they don't like it

setc rec_prompt "[exec whoami]_recsis> "

