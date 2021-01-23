#!/bin/sh
OFFBOARD="off"
RC="rc"

# 进行测试单机节点的启动 主机或从机
if [ "$1" == "$OFFBOARD" ]
then    # 掌机
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun msgsSub msgSubAndPub" \
    --tab -e "rosrun navigator navigator _OFFBOARD_ATTITUDE_CONTROLLER_ _SINGLE_FLYMODE_" \
    --tab -e "rosrun fw_pos_control FixedwingPositionControl _OFFBOARD_ATTITUDE_CONTROLLER_ _SINGLE_FLYMODE_" \
    --tab -e "rosrun fw_att_control FixedwingAttitudeControl _OFFBOARD_ATTITUDE_CONTROLLER_" \
    --tab -e "rosrun basic mode_setting" 
elif [ "$1" == "$RC" ] # follower
then
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun msgsSub msgSubAndPub" \
    --tab -e "rosrun communication UDP_Send 0 -mt UH -p 8002" \
    --tab -e "rosrun navigator navigator _RC_ATTITUDE_CONTROLLER_ _SINGLE_FLYMODE_" \
    --tab -e "rosrun fw_pos_control FixedwingPositionControl _RC_ATTITUDE_CONTROLLER_ _SINGLE_FLYMODE_" \
    --tab -e "rosrun fw_att_control FixedwingAttitudeControl _RC_ATTITUDE_CONTROLLER_" \
    --tab -e "rosrun basic enableALTCTL" \
    --tab -e "rosrun processor protect" 
else
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun msgsSub msgSubAndPub" \
    --tab -e "rosrun navigator navigator" \
    --tab -e "rosrun fw_pos_control FixedwingPositionControl" \
    --tab -e "rosrun fw_att_control FixedwingAttitudeControl" \
    --tab -e "rosrun communication UDP_Send 0 -mt UH -p 8002" \
    --tab -e "rosrun processer processer" \
    # --tab -e "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0" 

    # --tab -e "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 0 5" \

    # --tab -e "rosrun communication UDP_Send 0 -mt UH -p 8002" \
    # 0: 是否执行定高模式
    # 9004: 接收 QGC command 的端口号
    # 0: 初始化 QGC message flag
    # uav1: 飞机的编号


    # --tab -e "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0" 
    # --tab -e "rosrun msgsSub msgSubAndPub" \
    # --tab -e "rosrun communication UDP_Send 0 -mt UH -p 8002" \
    # --tab -e "rosrun navigator navigator" \
    # --tab -e "rosrun fw_pos_control FixedwingPositionControl" \
    # --tab -e "rosrun fw_att_control FixedwingAttitudeControl" \
    # --tab -e "rosrun processer processer 0" \
    # --tab -e "rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0" 
    # source _4_startFormation.sh uav4 8005 9004
fi
# rosrun communication UDP_Send_QGCommand uav0 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 1 1 0 0
# rosrun communication UDP_Send_QGCommand uav1 -mt QC -p 9000 9001 9002 9003 9004 -QCp 2 40 1 2 1 5 5

# _FORMATION_FLYMODE_
# _SINGLE_FLYMODE_
#  rosrun basic enableALTCTL

# _RC_ATTITUDE_CONTROLLER_
# _OFFBOARD_ATTITUDE_CONTROLLER_
    # --tab -e "rosrun communication UDP_Send 0 -mt UH -p 8002" \
# --tab -e "rosrun basic enableALTCTL" \ 进入 ALTCTL 模式



