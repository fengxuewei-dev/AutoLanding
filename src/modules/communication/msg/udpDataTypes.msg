# udpDataTypes.msg

int8 startUDP_Data
int8 startUPD_HOME
int8 startACK

# taskType_sub = nh.advertise<communication::udpDataTypes>
#           ("communication/taskTypes/udpDataTypes", 1);

# taskType_sub = nh.subscribe<communication::QgcCommands>
#           (uavName + "/communication/QgcCommands" + s_i,1, handler_taskType);
# 
