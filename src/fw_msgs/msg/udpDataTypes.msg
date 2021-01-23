# udpDataTypes.msg


int8 startUDP_Data
int8 startUPD_HOME
int8 startACK

# 数据分发
# 数据控制

# taskType_sub = nh.advertise<fw_msgs::udpDataTypes>
#           ("communication/taskTypes/udpDataTypes", 1);

# taskType_sub = nh.subscribe<fw_msgs::QgcCommands>
#           (uavName + "/communication/QgcCommands" + s_i,1, handler_taskType);
# 
