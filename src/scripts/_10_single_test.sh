#!/bin/sh

# $1 vehicle number 
# $2 接收端口号
gnome-terminal -t "$1" --window -e "roscore" \
--tab -e "rosrun msgsSub msgSubAndPub" \
--tab -e "rosrun basic mode_setting" \
--tab -e "rosrun processor processor "$1"" \
--tab -e "rosrun processor protect" \
--tab -e "rosrun communication UDP_Send 0 -mt UH -p 8002 8003 8004 8005 8006" \
--tab -e "rosrun communication UDP_Receive "$2"" \
--tab -e "rosrun navigator navigator "$1"" \
--tab -e "rosrun fw_pos_control FixedwingPositionControl" \
--tab -e "rosrun fw_att_control FixedwingAttitudeControl" 

# 第一次链接： taskType = 7 发布自己的home位置
# rosrun communication QGC 0 0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 7 1 2 0 0
# rosrun communication QGC 0 1 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 7 1 2 0 0

# 第二次进行任务处理 0 0 发送给第一个 自组织
# rosrun communication QGC 0 0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 2 1 2 0 0
