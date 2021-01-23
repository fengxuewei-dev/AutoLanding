#!/bin/sh

echo " >>>>>>>>>>>>>> basic/
rosrun basic DisplayInfoFMU
rosrun basic GetHomePosition
rosrun basic GetWaypointList

rosrun basic OneClickLanding 47.3942960 8.5514208 45 200

# 节点 SendNewWaypoints
# 8字形轨道
gnome-terminal --window -e 'roscore' \
--tab -e 'rosrun basic SendNewWaypoints NAN 0 
3 22 15 0 0 nan 47.39693832 8.540036201 20  
3 19 45 0 100 0 47.3997879 8.538474083 20 
3 19 32 0 200 1 47.39989853 8.550296783 20 
3 19 65 0 -200 1 47.39979935 8.555843353 20 
3 19 40 0 200 1 47.39989853 8.550296783 20 
EXIT' 

rosrun basic mode_setting 
rosrun basic takeoff_mission

# basic/src tree
├── AboutWaypoint
│   ├── DisplayInfoFMU.cpp 
│   ├── GetHomeWaypoint.cpp 
│   ├── GetWaypointList.cpp 
│   ├── OneClickLanding.cpp 
│   └── SendNewWaypoints.cpp
└── SetMode
    ├── modeSet.cpp
    └── takeoff_mission.cpp
"


