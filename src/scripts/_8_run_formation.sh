#!/bin/sh

RC="RC"
OFFBOARD="OFFBOARD"

# 判断模式
if [ "$1" == "$RC" ]
then 
    echo "执行 RC 模式"
elif [ "$1" == "$OFFBOARD" ]
then 
    echo "执行 OFFBOARD 模式"
else
    echo "缺少一种飞行模式 <RC or OFFBOARD>, 点击任意键退出执行脚本!"
    read EXITFLAG
    exit 0
fi

gnome-terminal -t "multi_sitl" -x bash -c "source _8_multi_sitl.sh;exec bash;"

echo " Start up ... "

echo " Need to wait 30 seconds for the plane to take off... "

sleep 30s
gnome-terminal -t "multi_takeoff_mission" -x bash -c "source _8_multi_takeoff.sh;exec bash;"

# echo " Need to wait 30 seconds to perform a formation flight... "

# sleep 40s
# gnome-terminal -t "leader" -x bash -c "source _4_startFormation.sh uav0 0 0 "$1";exec bash;"

# sleep 7s
# gnome-terminal -t "follower_1" -x bash -c "source _4_startFormation.sh uav1 8002 T "$1";exec bash;"

# sleep 7s
# gnome-terminal -t "follower_2" -x bash -c "source _4_startFormation.sh uav2 8003 T "$1";exec bash;"

# sleep 7s
# gnome-terminal -t "follower_3" -x bash -c "source _4_startFormation.sh uav3 8004 T "$1";exec bash;"

# sleep 7s
# gnome-terminal -t "follower_4" -x bash -c "source _4_startFormation.sh uav4 8005 T "$1";exec bash;"

echo "end"
