#!/bin/sh

gnome-terminal -t "multi_single_sitl" -x bash -c "source _1_single_sitl.sh;exec bash;"

echo " Start up ... "

echo " Need to wait 30 seconds for the plane to take off... "
sleep 15s
gnome-terminal -t "multi_takeoff_mission" -x bash -c "source _2_single_takeoff.sh;exec bash;"

echo " Need to wait 30 seconds to perform a formation flight... "

sleep 5s
gnome-terminal -t "leader" -x bash -c "source _3_startTest.sh uav1 8002 9001;exec bash;"

sleep 6s
gnome-terminal -t "leader" -x bash -c "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 0 5;exec bash;"

sleep 3s
gnome-terminal -t "leader" -x bash -c "rosrun communication UDP_Send_QGCommand uav1 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0;exec bash;"

echo "end"
