#!/bin/sh

gnome-terminal -t "multi_sitl" -x bash -c "source _10_triple_sitl.sh;exec bash;"

echo " Start up ... "

echo " Need to wait 30 seconds for the plane to take off... "

sleep 30s
gnome-terminal -t "multi_takeoff_mission" -x bash -c "source _10_triple_takeoff.sh;exec bash;"

# echo " Need to wait 30 seconds to perform a formation flight... "

# sleep 40s
# gnome-terminal -t "leader" -x bash -c "source _4_startFormation.sh uav0;exec bash;"

# sleep 7s
# gnome-terminal -t "follower_1" -x bash -c "source _4_startFormation.sh uav1 8002 T;exec bash;"

# sleep 7s
# gnome-terminal -t "follower_2" -x bash -c "source _4_startFormation.sh uav2 8003 T;exec bash;"

# sleep 7s
# gnome-terminal -t "follower_3" -x bash -c "source _4_startFormation.sh uav3 8004 T;exec bash;"

# sleep 7s
# gnome-terminal -t "follower_4" -x bash -c "source _4_startFormation.sh uav4 8005 T;exec bash;"

echo "end"
