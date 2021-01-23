#!/bin/sh

gnome-terminal --window -e 'bash -c "cd ~/GitHub/uav_project_1/fixedWing_ws/src/scripts; source _8_clean.sh; source _8_multi_vehicles_sitl.sh; exec bash"' \
--tab -e 'bash -c "cd ~/GitHub/uav_project_1/fixedWing_ws; catkin build; sleep 18; exec bash"' \
--tab -e 'bash -c "cd ~/UAV/OldQgc; ./QGroundControl.AppImage; exec bash"' 
