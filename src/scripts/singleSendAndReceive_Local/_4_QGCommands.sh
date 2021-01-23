#!/bin/sh

# 多机 sitl & takeoff & mission
gnome-terminal --window -e 'roscore' \
--tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 -5 5"' \
--tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav1 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0"' 

# T
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0"' \
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav1 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 0 -5"' \
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav2 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 0 5"' \
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav3 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 -5 0"' \
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav4 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 -10 0"' 

# Y
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0"' \
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav1 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 5 5"' \
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav2 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 5 -5"' \
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav3 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 -5 0"' \
# --tab -e 'bash -c "rosrun communication UDP_Send_QGCommand uav4 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 -10 0"' 

#             { {5,   5},  {0,   -5}, {-5,   5}},  // uav1: Y, T, V
#             { {5,  -5},  {0,    5}, {-5,  -5}},  // uav2: Y, T, V
#             { {-5,  0},  {-5,   0}, {-10, 10}},  // uav3: Y, T, V
#             { {-10, 0},  {-10,  0}, {-10, -10}}  // uav4: Y, T, V
