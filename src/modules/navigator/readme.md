# 功能描述

## 日志功能

1. 保存航线数据(GPS AND ENU)(方便在matlab分析长机数据的时候使用)  
其中 GPS 数据保存, 起始位置都是以 home 点为基准的, 经纬度动态获取 home 点的经纬度, 高度为一个常数值 100   
ENU 航点数据和 GPS 航点数据相互一一对应  
保存的路径为 "<workspace_path>/src/log/navigator/waypointList/.."

