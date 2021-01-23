#!/bin/sh

gnome-terminal --window -e 'roscore' \
--tab -e 'bash -c "cd ~/GitHub/uav_project_1/fixedWing_ws; catkin build; sleep 18; exec bash"' \
--tab -e 'bash -c "sleep 3; cd ~/src/Firmware; make px4_sitl gazebo_plane;  exec bash"' \
--tab -e 'bash -c "sleep 10; roslaunch mavros px4.launch fcu_url:=udp://:14540@127.0.0.1:14557; exec bash"' \
--tab -e 'bash -c "cd ~/UAV/OldQgc; ./QGroundControl.AppImage; exec bash"' \
--tab -e 'bash -c "sleep 12; rosrun basic takeoff_mission; exec bash"' 
