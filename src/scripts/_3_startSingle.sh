#!/bin/sh

# # 0. msgSubAndPub
# rosrun msgsSub msgSubAndPub

# # 1. navigator
# rosrun navigator navigator

# # 2. position controller
# rosrun fw_pos_control FixedwingPositionControl _RC_ATTITUDE_CONTROLLER_ _SINGLE_FLYMODE_
# rosrun fw_pos_control FixedwingPositionControl _OFFBOARD_ATTITUDE_CONTROLLER_ _SINGLE_FLYMODE_

# # 3. attitude controller
# rosrun fw_att_control FixedwingAttitudeControl _RC_ATTITUDE_CONTROLLER_


# --tab -e 'rosrun navigator navigator' \

# --tab -e 'rosrun fw_pos_control FixedwingPositionControl _OFFBOARD_ATTITUDE_CONTROLLER_ _SINGLE_FLYMODE_' \

# --tab -e 'rosrun msgsSub msgSubAndPub' \
gnome-terminal --window -e 'roscore' \
--tab -e 'rosrun msgsSub msgSubAndPub' \
--tab -e "rosrun processor processor" \
--tab -e 'rosrun navigator navigator' \
--tab -e 'rosrun fw_pos_control FixedwingPositionControl' \
--tab -e 'rosrun fw_att_control FixedwingAttitudeControl'
