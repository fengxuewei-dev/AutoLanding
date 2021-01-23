#!/bin/sh

gnome-terminal -t "leader" -x bash -c "source _4_startFormation.sh uav0 9000;exec bash;"

sleep 7s
gnome-terminal -t "follower_1" -x bash -c "source _4_startFormation.sh uav1 8002 9001;exec bash;"

# sleep 7s
# gnome-terminal -t "follower_2" -x bash -c "source _4_startFormation.sh uav2 8003 9002;exec bash;"

# sleep 7s    
# gnome-terminal -t "follower_3" -x bash -c "source _4_startFormation.sh uav3 8004 9003;exec bash;"

# sleep 7s
# gnome-terminal -t "follower_4" -x bash -c "source _4_startFormation.sh uav4 8005 9004;exec bash;"

sleep 10s
gnome-terminal -t "forma" -x bash -c "source _8_formation.sh;exec bash;"
