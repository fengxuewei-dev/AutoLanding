#!/bin/sh

# 1. 一对多端口进行通信 (修改端口号 以及 数据来源 plan_state)

    # 1.1 发送home位置 默认为 UAV0
    # rosrun communication UDP_Send -mt UH -ip 127.0.0.1 -p 8002 8003 8004 8005

    # 1.2 udp_received 
    # rosrun communication UDP_Receive uav1 port_number

    # 1.3 发送位姿态信息
    # rosrun communication UDP_Send -mt UD

# 2. 开启分发节点
# rosrun communication sendDataForFormation uav1

# 3. 开启集群下的 navigator
# rosrun navigator navigator _FORMATION_FLYMODE_ uav1

# 4. 开启集群下的 position controller
# rosrun fw_pos_control FixedwingPositionControl _RC_ATTITUDE_CONTROLLER_ _FORMATION_FLYMODE_ uav1
  
# 5. 开启制导控制器
# rosrun fw_att_control FixedwingAttitudeControl _RC_ATTITUDE_CONTROLLER_ uav1

# gnome-terminal --window -e 'roscore' \
# --tab -e 'rosrun msgsSub msgSubAndPub uav0' \
# --tab -e 'rosrun communication UDP_Send -mt UH -p 8002 8003 8004 8005' \   # 主机
# --tab -e 'rosrun communication sendFormationShap Y'     # 从机 发送编队形状到sendDataForFormation 选择相应的gap
# --tab -e 'rosrun communication UDP_Receive uav1 8002'    # 从机 的编号
# --tab -e 'rosrun communication sendDataForFormation uav1'    # 从机 的编号
# --tab -e 'rosrun communication UDP_Send -mt UD -p 8002 8003 8004 8005'     # 主机 发送数据 

# sendFormationShap
# --tab -e 'rosrun navigator navigator uav1 _FORMATION_FLYMODE_' \
# --tab -e 'rosrun fw_pos_control FixedwingPositionControl uav1 _RC_ATTITUDE_CONTROLLER_ _SINGLE_FLYMODE_' 
# --tab -e 'rosrun fw_att_control FixedwingAttitudeControl uav1 _RC_ATTITUDE_CONTROLLER_'

# source _4_startFormation.sh uav0 掌机
# source _4_startFormation.sh uavX(从机编号) port(8002 - 8005)
leader="uav0"

if [ "$1" == "$leader" ]
then    # 掌机
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun msgsSub msgSubAndPub "$leader"" \
    --tab -e "rosrun communication sendFormationShape V" \
    --tab -e "rosrun processor processor "$leader"" \
    --tab -e "rosrun communication UDP_Send uav0 -mt UH -p 8002 8003 8004 8005" \
    --tab -e "rosrun navigator navigator "$leader"" \
    --tab -e "rosrun fw_pos_control FixedwingPositionControl "$leader"" \
    --tab -e "rosrun fw_att_control FixedwingAttitudeControl "$leader""
else # follower
    gnome-terminal -t "$1" --window -e "roscore" \
    --tab -e "rosrun msgsSub msgSubAndPub "$1"" \
    --tab -e "rosrun processor processor "$1"" \
	--tab -e "rosrun communication UDP_Send "$1" -mt UH -p 8002 8003 8004 8005" \
    --tab -e "rosrun communication UDP_Receive "$2" "$1"" \
    --tab -e "rosrun navigator navigator "$1"" \
    --tab -e "rosrun fw_pos_control FixedwingPositionControl "$1"" \
    --tab -e "rosrun fw_att_control FixedwingAttitudeControl "$1"" 
fi
# leader
# rosrun communication UDP_Send -mt UD -p 8002 8003 8004 8005

# rosrun navigator navigator uav1 _FORMATION_FLYMODE_
# rosrun fw_pos_control FixedwingPositionControl uav1 _RC_ATTITUDE_CONTROLLER_ _FORMATION_FLYMODE_


# others
# rosrun communication sendFormationShap V

# 主机: 正常跑: 在接收消息的时候, 我需要把topic的名字变一下, 加上一个对应的 uavName(代表的飞机的编号)
# 发送端: udp_send 在主机跑 默认为 uav0
# 接收端: udp_received uavName
