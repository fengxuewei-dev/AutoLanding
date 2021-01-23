#!/bin/sh


# 多机 sitl & takeoff & mission
gnome-terminal --window -e 'roscore' \
--tab -e 'bash -c "sleep 10; rosrun basic takeoff_mission uav0; exec bash"' 
# --tab -e 'bash -c "sleep 10; rosrun basic takeoff_mission uav1; exec bash"' \
# --tab -e 'bash -c "sleep 10; rosrun basic takeoff_mission uav2; exec bash"' 
# --tab -e 'bash -c "sleep 10; rosrun basic takeoff_mission uav3; exec bash"' \
# --tab -e 'bash -c "sleep 10; rosrun basic takeoff_mission uav4; exec bash"' 
