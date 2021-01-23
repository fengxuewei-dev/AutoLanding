#!/bin/sh


# 多机 sitl & takeoff & mission
gnome-terminal --window -e 'roscore' \
--tab -e 'bash -c "sleep 10; rosrun basic takeoff_mission; exec bash"' 