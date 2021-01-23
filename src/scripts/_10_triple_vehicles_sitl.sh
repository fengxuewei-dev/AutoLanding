#!/bin/bash

# input the directory of Firmware
# cd ~/src/FirmwareSrc_new
cd ~/src/Firmware_changwei_rc

# uodate the submodules
git submodule update --init --recursive

# build
DONT_RUN=1 make px4_sitl gazebo_plane

# source
source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd):$(pwd)/Tools/sitl_gazebo

# into the launch and run
cd launch
roslaunch multi_uav_mavros_sitl_sdf.launch
# roslaunch five_multi_nav_maros_sitl_sdf.launch


# mavros -- ros :   tgt_system = 2
# ros -- px4 :      ID != 2

# 但是我从qgc设置了px4 id = 2, 不能进行操作,因为 固件里面的参数还是 1 
# 当 id = 1 的时候,可以起飞
# ros -- mavros(设置为2) -- px4(在qgc上面设置为) -- gazebo -- QGC
