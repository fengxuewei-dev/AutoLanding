#!/bin/sh

leader="uav0"
isFormation="1"

if [ "$1" == "$leader" ]
then    # 掌机
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun msgsSub msgSubAndPub "$leader"" \
    --tab -e "rosrun basic mode_setting "$leader"" \
    --tab -e "rosrun processor processor "$leader" "$3"" \
    --tab -e "rosrun processor protect "$leader"" \
    --tab -e "rosrun communication UDP_Send "$leader" -p 8002 8003 8004 8005 8006" \
    --tab -e "rosrun communication UDP_Receive "$2" "$leader"" \
    --tab -e "rosrun navigator navigator "$leader" "$3"" \
    --tab -e "rosrun fw_pos_control FixedwingPositionControl "$leader"" \
    --tab -e "rosrun fw_att_control FixedwingAttitudeControl "$leader""
else # follower
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun msgsSub msgSubAndPub "$1"" \
    --tab -e "rosrun basic mode_setting "$1"" \
    --tab -e "rosrun processor processor "$1" "$3"" \
    --tab -e "rosrun processor protect "$1"" \
	--tab -e "rosrun communication UDP_Send "$1" -mt UH -p 8002 8003 8004 8005 8006" \
    --tab -e "rosrun communication UDP_Receive "$2" "$1"" \
    --tab -e "rosrun navigator navigator "$1" "$3"" \
    --tab -e "rosrun fw_pos_control FixedwingPositionControl "$1"" \
    --tab -e "rosrun fw_att_control FixedwingAttitudeControl "$1"" 
fi
# 飞机编号 端口号 飞机的总个数
# if [ "$1" == "$leader" ]
# then    # 掌机
#     gnome-terminal -t "$1" --window -e "roscore" \
#     --tab -e "rosrun msgsSub msgSubAndPub "$leader"" \
#     --tab -e "rosrun communication sendFormationShape T" \
#     --tab -e "rosrun communication UDP_Send 0 -p 8002 8003 8004 8005 8006" \
#     --tab -e "rosrun processor processor "$leader"" \
#     --tab -e "rosrun navigator navigator "$leader"" \
#     --tab -e "rosrun fw_pos_control FixedwingPositionControl "$leader"" \
#     --tab -e "rosrun fw_att_control FixedwingAttitudeControl "$leader""
# else # follower
#     gnome-terminal -t "$1" --window -e "roscore" \
#     --tab -e "rosrun msgsSub msgSubAndPub "$1"" \
#     --tab -e "rosrun communication UDP_Send 0 -p 8002 8003 8004 8005 8006" \
#     --tab -e "rosrun processor processor "$1"" \
#     --tab -e "rosrun communication UDP_Receive "$2" "$1"" \
#     --tab -e "rosrun communication sendDataForFormation "$1"" \
#     --tab -e "rosrun navigator navigator "$1"" \
#     --tab -e "rosrun fw_pos_control FixedwingPositionControl "$1"" \
#     --tab -e "rosrun fw_att_control FixedwingAttitudeControl "$1"" 
# fi
# leader
# rosrun communication UDP_Send -mt UD -p 8002 8003 8004 8005

# rosrun navigator navigator uav1 _FORMATION_FLYMODE_
# rosrun fw_pos_control FixedwingPositionControl uav1 _RC_ATTITUDE_CONTROLLER_ _FORMATION_FLYMODE_


# others
# rosrun communication sendFormationShap V

# 主机: 正常跑: 在接收消息的时候, 我需要把topic的名字变一下, 加上一个对应的 uavName(代表的飞机的编号)
# 发送端: udp_send 在主机跑 默认为 uav0
# 接收端: udp_received uavName
