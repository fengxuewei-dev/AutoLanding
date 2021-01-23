#!/bin/sh

# gs_id, vehicleNumber, taskType, plane_state, plane_group, gapx, gapy
# rosrun communication UDP_Send uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 1 2 2 5 6
gnome-terminal -t "$1" --window -e "roscore" \
--tab -e "rosrun communication QGC uav0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 7 1 2 0 0" \
--tab -e "rosrun communication QGC uav1 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 7 2 2 0 0" \
# --tab -e "rosrun communication QGC uav2 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 7 2 2 0 0" \
# --tab -e "rosrun communication QGC uav3 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 7 2 2 0 0" \
# --tab -e "rosrun communication QGC uav4 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 7 2 2 0 0" 

# 第一次连接： 
# processor 拿到数据 给 udp_send 发送一个 开始消息标志位 ，， 可以接收到， 
# 接收到之后， 发送数据 udp_receive 也可以收到 （home 84位置) 保存再 updhp_all[] 中

# 第二次任务连接： 
# processor 根据具体的任务进行处理，
# 1. 集群： processor 为主机发送udp_data标志位， 根据主机的id，和当前的id编号，processor 从 receive 拿数据


# 第一次建立链接: 开始广播自己的home位置, tasktype = 7 
# 第二次, 某个飞机开始集群任务, 若当前从机的信号发布了, 获得主句的位置(在第一步建立链接的时候, 就已经开始了接收了)但是主机的位置信息还没有发布, 那么从机会怎么操作 == 等待所有的主机的位置信息发布过来之后, 进行计算
# 主机和从机都要发布自己的当前位置


# 建立链接 tasktype = 7   运行在某一个飞机上
# rosrun communication QGC 0 -mt QC -p 8002 -QCp 2 40 7 1 2 0 0 
# 4 0 2 0 0 0 28 0 7 0 0 0 1 0 2 0 0 0 0 0 ffffffffffffffff ffffffffffffffff ffffffffffffffff 7f 0 0 0 0 0 0 0 0 38 0 0 0 0 0 ffffffffffffffe0 3f 
# rosrun communication QGC 0 -mt QC -p 8002 -QCp 2 40 7 1 2 0 0
# 4 0 2 0 0 0 28 0 7 0 0 0 1 0 2 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 0 38 0 0 0 0 0 0 0 

# 开始集群任务 tasktype = 1
# rosrun communication QGC 0 -mt QC -p 8002 -QCp 2 40 1 1 2 0 0
# rosrun communication QGC 0 -mt QC -p 8002 -QCp 2 40 1 2 2 0 -5

# 开始自组织任务 taskType = 2
# rosrun communication QGC 0 -mt QC -p 8002 -QCp 2 40 2 1 2 0 0
# rosrun communication QGC 0 -mt QC -p 8002 -QCp 2 40 2 1 2 0 0

# 切换任务模式 
# rtl
# rosrun communication QGC 0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 4 2 2 0 0 
# loiter
# rosrun communication QGC 0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 5 2 2 0 0 
# mission
# rosrun communication QGC 0 -mt QC -p 8002 8003 8004 8005 8006 -QCp 2 40 6 2 2 0 0 

# 写一个发送节点, 来进行广播, 看看其他的ip地址端口是否可以接收到数据
