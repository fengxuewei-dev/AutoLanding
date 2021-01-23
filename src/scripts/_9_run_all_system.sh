#!/bin/sh
# "$1" 是飞机的个数

vehicleNumer="2"

gnome-terminal -t "multi_sitl" -x bash -c "source _8_multi_sitl.sh;exec bash;"
echo " Start up ... "
echo " Need to wait 30 seconds for the plane to take off... "

sleep 30s
gnome-terminal -t "multi_takeoff_mission" -x bash -c "source _8_multi_takeoff.sh;exec bash;"
echo " Need to wait 30 seconds to perform a formation flight... "

sleep 40s
gnome-terminal -t "uav0" -x bash -c "source _9_Joint.sh uav0 8006 "$vehicleNumer";exec bash;"

sleep 7s
gnome-terminal -t "uav1" -x bash -c "source _9_Joint.sh uav1 8002 "$vehicleNumer";exec bash;"

sleep 7s
gnome-terminal -t "uav2" -x bash -c "source _9_Joint.sh uav2 8003 "$vehicleNumer";exec bash;"

sleep 7s
gnome-terminal -t "uav3" -x bash -c "source _9_Joint.sh uav3 8004 "$vehicleNumer";exec bash;"

sleep 7s
gnome-terminal -t "uav4" -x bash -c "source _9_Joint.sh uav4 8005 "$vehicleNumer";exec bash;"

# sleep 7s
# gnome-terminal -t "QGC_first_connection" -x bash -c "source _9_first_connection_qgc.sh;exec bash;"

# sleep 7s
# gnome-terminal -t "QGC_second_connection" -x bash -c "source _9_second_connection_qgc.sh Formation V;exec bash;"

echo "end"
# sleep 7s
# gnome-terminal -t "QGC_second_connection" -x bash -c "source _9_second_connection_qgc.sh Formation T;exec bash;"
# gnome-terminal -t "QGC_second_connection" -x bash -c "source _9_second_connection_qgc.sh Formation V;exec bash;"
# gnome-terminal -t "QGC_second_connection" -x bash -c "source _9_second_connection_qgc.sh Formation Y;exec bash;"

# gnome-terminal -t "QGC_second_connection" -x bash -c "source _9_second_connection_qgc.sh Organization;exec bash;"

# gnome-terminal -t "QGC_second_connection" -x bash -c "source _9_second_connection_qgc.sh SettingMode uav1 4;exec bash;"
# gnome-terminal -t "QGC_second_connection" -x bash -c "source _9_second_connection_qgc.sh SettingMode uav1 4;exec bash;"
