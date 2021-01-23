#!/bin/sh

gnome-terminal -t "multi_sitl" -x bash -c "source _8_multi_sitl.sh;exec bash;"

echo " Start up ... "

echo " Need to wait 30 seconds for the plane to take off... "
sleep 30s
gnome-terminal -t "multi_takeoff_mission" -x bash -c "source _8_multi_takeoff.sh;exec bash;"

echo " Need to wait 30 seconds to perform a formation flight... "

sleep 40s
gnome-terminal -t "leader" -x bash -c "source _8_start_multi_uavs.sh;exec bash;"

echo "end"
