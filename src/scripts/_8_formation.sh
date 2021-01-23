#!/bin/sh

# 多机 sitl & takeoff & mission
gnome-terminal --window -e 'roscore' \
--tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0"' \
--tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 -5 0"' 
--tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 -5"' 