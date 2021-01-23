#include "RC.hpp"


rc::rc(){
	set_parameter = nh.serviceClient<mavros_msgs::ParamSet>("mavros/param/set");
	newRCIn.channels[PITCH_CHANNEL-1] = (RC_MAX+RC_MIN)/2;
	newRCIn.channels[ROLL_CHANNEL-1] = (RC_MAX+RC_MIN)/2;
	newRCIn.channels[YAW_CHANNEL-1] = (RC_MAX+RC_MIN)/2;
	newRCIn.channels[THROTTLE_CHANNEL-1] = RC_MAX-300;
}

void rc::Assignment(float *att_sp){
    newRCIn.channels[ROLL_CHANNEL-1] = att_sp[ROLL_CHANNEL-1];
    newRCIn.channels[PITCH_CHANNEL-1] = att_sp[PITCH_CHANNEL-1];
    newRCIn.channels[YAW_CHANNEL-1] = att_sp[YAW_CHANNEL-1];
	newRCIn.channels[THROTTLE_CHANNEL-1] = att_sp[THROTTLE_CHANNEL-1];
	std::cout << "newRCIn.channels[ROLL_CHANNEL] : " << newRCIn.channels[ROLL_CHANNEL-1] << std::endl;
	std::cout << "newRCIn.channels[PITCH_CHANNEL] : " << newRCIn.channels[PITCH_CHANNEL-1] << std::endl;
	std::cout << "newRCIn.channels[YAW_CHANNEL] : " << newRCIn.channels[YAW_CHANNEL-1] << std::endl;
	std::cout << "newRCIn.channels[THROTTLE_CHANNEL] : " << newRCIn.channels[THROTTLE_CHANNEL-1] << std::endl;
}
void rc::setParameters(){
	

	settingParameter.request.param_id = "RC_MAP_PITCH";
	settingParameter.request.value.integer = PITCH_CHANNEL;
	set_parameter.call(settingParameter);
	if( set_parameter.call(settingParameter) && settingParameter.response.success)  ROS_INFO("Pitch set ok");

	settingParameter.request.param_id = "RC_MAP_ROLL";
	settingParameter.request.value.integer = ROLL_CHANNEL;
	set_parameter.call(settingParameter);
	if( set_parameter.call(settingParameter) && settingParameter.response.success)  ROS_INFO("Roll set ok");

	settingParameter.request.param_id = "RC_MAP_YAW";
	settingParameter.request.value.integer = YAW_CHANNEL;
	set_parameter.call(settingParameter);
	if( set_parameter.call(settingParameter) && settingParameter.response.success)  ROS_INFO("Yaw set ok");

	settingParameter.request.param_id = "RC_MAP_THROTTLE";
	settingParameter.request.value.integer = THROTTLE_CHANNEL;
	set_parameter.call(settingParameter);
	if( set_parameter.call(settingParameter) && settingParameter.response.success)  ROS_INFO("Throttle set ok");
}