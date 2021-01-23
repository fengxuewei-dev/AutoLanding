#!/bin/sh
# 发送 
# gs_id, vehicleNumber, taskType, plane_state, plane_group, gapx, gapy
# rosrun communication UDP_Send uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 1 2 2 5 6
# gapy : E
# gapx : N
# 集群: Formation T 
# 自组织: Organization
# 设置模式: SettingMode uav1 4
startFormation="Formation"
startOrganization="Organization"
startSettingMode="SettingMode"
shape_T="T"
shape_V="V"
shape_Y="Y"
# 开始集群
if [ "$1" == "$startFormation" ] 
then
    if [ "$2" == "$shape_Y" ]   #Y字形编队
    then
        echo "formation y"
        gnome-terminal -t "$1" --window -e "roscore" \
        --tab -e "rosrun communication QGC uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 1 2 0 0" \
        --tab -e "rosrun communication QGC uav1 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 5 5" \
        # --tab -e "rosrun communication QGC uav2 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 5 -5" \
        # --tab -e "rosrun communication QGC uav3 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -5 0" \
        # --tab -e "rosrun communication QGC uav4 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -10 0" 
    elif [ "$2" == "$shape_T" ]   #Ｔ字形编队
    then
        echo "formation t"
         gnome-terminal -t "$1" --window -e "roscore" \
        --tab -e "rosrun communication QGC uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 1 2 0 0" \
        --tab -e "rosrun communication QGC uav1 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 0 -5" \
        # --tab -e "rosrun communication QGC uav2 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 0 5" \
        # --tab -e "rosrun communication QGC uav3 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -5 0" \
        # --tab -e "rosrun communication QGC uav4 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -10 0" 
 elif [ "$2" == "$shape_V" ]   #V字形编队
    then
        echo "formation v"
        gnome-terminal -t "$1" --window -e "roscore" \
        --tab -e "rosrun communication QGC uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 1 2 0 0" \
        --tab -e "rosrun communication QGC uav1 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -5 5" \
        # --tab -e "rosrun communication QGC uav2 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -5 -5" \
        # --tab -e "rosrun communication QGC uav3 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -10 10" \
        # --tab -e "rosrun communication QGC uav4 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -10 -10" 
    fi
elif [ "$1" == "$startOrganization" ] 
then
    echo "startOrganization"
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun communication QGC uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 2 2 2 0 0" \
    --tab -e "rosrun communication QGC uav1 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 2 2 2 0 0" \
    # --tab -e "rosrun communication QGC uav2 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 2 2 2 0 0" \
    # --tab -e "rosrun communication QGC uav3 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 2 2 2 0 0" \
    # --tab -e "rosrun communication QGC uav4 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 2 2 2 0 0"
elif [ "$1" == "$startSettingMode" ] 
then
    echo "startSettingMode"
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun communication QGC "$2" -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 "$3" 2 2 0 0" 
fi

# Point gaps[4][3] = {
#             { {5,   5},  {0,   -5}, {-5,   5}},  // uav1: Y, T, V
#             { {5,  -5},  {0,    5}, {-5,  -5}},  // uav2: Y, T, V
#             { {-5,  0},  {-5,   0}, {-10, 10}},  // uav3: Y, T, V
#             { {-10, 0},  {-10,  0}, {-10, -10}}  // uav4: Y, T, V
#         };
# echo "formation t"
#         gnome-terminal -t "$1" --window -e "roscore" \
#         --tab -e "rosrun communication QGC uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 1 2 0 0" \
#         --tab -e "rosrun communication QGC uav1 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 0 -5" \
#         --tab -e "rosrun communication QGC uav2 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 0 5" \
#         --tab -e "rosrun communication QGC uav3 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -5 0" \
#         --tab -e "rosrun communication QGC uav4 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -10 0" 

# gnome-terminal -t "$1" --window -e "roscore" \
#         --tab -e "rosrun communication QGC uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 1 2 0 0" \
#         --tab -e "rosrun communication QGC uav1 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 -5 0" \
#         --tab -e "rosrun communication QGC uav2 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 5 0" \
#         --tab -e "rosrun communication QGC uav3 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 0 -5" \
#         --tab -e "rosrun communication QGC uav4 -mt QC -p 8002 8003 8004 8005 8006 -QCp 1 40 1 2 2 0 -10" 

