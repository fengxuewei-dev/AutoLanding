#!/bin/bash

# input the directory of Firmware

cd ~/src/Firmware_wxm/Firmware
# cd ~/src/Firmware_nochanged_rc
# cd ~/src/multi_sitl/PX4-Autopilot

# uodate the submodules
git submodule update --init --recursive

# build
DONT_RUN=1 make px4_sitl gazebo_plane

# source
source Tools/setup_gazebo.bash $(pwd) $(pwd)/build/px4_sitl_default
export ROS_PACKAGE_PATH=$ROS_PACKAGE_PATH:$(pwd):$(pwd)/Tools/sitl_gazebo

# into the launch and run
cd launch
roslaunch five_multi_nav_maros_sitl_sdf.launch

# roslaunch two_nav_maros_sitl_sdf.launch
