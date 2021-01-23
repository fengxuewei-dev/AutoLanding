#!/bin/sh
gnome-terminal --window -e 'roscore' \
--tab -e 'rosrun msgsSub msgSubAndPub' \
--tab -e 'rosrun processor processor' \
--tab -e 'rosrun navigator navigator' \
--tab -e 'rosrun fw_pos_control FixedwingPositionControl' \
--tab -e 'rosrun fw_att_control FixedwingAttitudeControl'
