#  This script demonstrates various SCAT commands available within swish
#  Please Note: This program will only work if there is a recsis job running

#  sets up the SCAT commands
ScatInit

#  finds the node the program is being run on
set node [exec hostname]

puts "The following SCAT processes are running"

#  returns an array scatProcess of all the SCAT processes running on a node
#  in the event that no jobs are running, the first element scatProcess(1) 
#     is filled with the string "no scat processes"
ScatProbe $node

#  splits up each element of scatProcess(1) and forms a list, chose
set chose [split $scatProcess(1) { }]

#  the jobname is the third element of the list
set jobname [lrange $chose 2 2]

puts "You have connected to $jobname on $node"

#  connects the SCAT enabled tcl script to the recsis job $jobname on $node
ScatLocateProgram $node $jobname

#  ScatSendMsg calls the recsis job which inturn returns a value.  In this 
#     case, we are interested in the number of events processed
puts "The job is on event number [ScatSendMsg {set event_number}]"

#  ScatSendMsgNr calls recsis and receives no reply.  It is used to set 
#     variables in recsis.  In this case we are telling recsis to do a 
#     status dump to the screen.
ScatSendMsgNr {set lstat -1}
exit