#!/bin/sh

gnome-terminal -t "single_sitl" -x bash -c "source _0_waypoint_test.sh;exec bash;"

echo " Start up ... "

echo " Need to wait 30 seconds for the plane to take off... "

sleep 20s
gnome-terminal -t "single_takeoff_mission" -x bash -c "rosrun basic takeoff_mission;exec bash;"

echo " Need to wait 30 seconds to perform a single flight... "

sleep 10s
gnome-terminal -t "leader" -x bash -c "source _0_singleTest.sh; exec bash;"
