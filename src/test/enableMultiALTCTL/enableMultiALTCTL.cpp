
#include "enableMultiALTCTL.hpp"

mavros_msgs::State current_state;
void state_cb(const mavros_msgs::State::ConstPtr& msg){
    current_state = *msg;
}
mavros_msgs::State current_state_uav0;
void state_cb_uav0(const mavros_msgs::State::ConstPtr& msg){
    current_state_uav0 = *msg;
}
mavros_msgs::State current_state_uav1;
void state_cb_uav1(const mavros_msgs::State::ConstPtr& msg){
    current_state_uav1 = *msg;
}
mavros_msgs::State current_state_uav2;
void state_cb_uav2(const mavros_msgs::State::ConstPtr& msg){
    current_state_uav2 = *msg;
}
mavros_msgs::State current_state_uav3;
void state_cb_uav3(const mavros_msgs::State::ConstPtr& msg){
    current_state_uav3 = *msg;
}
mavros_msgs::State current_state_uav4;
void state_cb_uav4(const mavros_msgs::State::ConstPtr& msg){
    current_state_uav4 = *msg;
}

int main(int argc, char **argv){

    // 可以根据参数来指定多机或者是单机
    // 多机需要指定 几架飞机
    // 单机 不需要指定参数
    std::string nodeName = "enableAltctl";
    int vehicle_number = 0;
    int way = -1;
    if(argc >= 2){
        vehicle_number = atoi(argv[1]);
        way = 1;
        nodeName = nodeName + "_multi";
    }
    else
    {
        way = 2;
        nodeName = nodeName + "single";
    }

    ros::init(argc, argv, nodeName);
    ros::NodeHandle nh;
    ros::Rate rate(20.0);

if(way == 1)
{
     std::cout << "执行多机程序" << std::endl;

    ros::Subscriber state_sub_0 = nh.subscribe<mavros_msgs::State>
            ("uav0/mavros/state", 1, state_cb_uav0);
    ros::ServiceClient arming_client_0 = nh.serviceClient<mavros_msgs::CommandBool>
            ("uav0/mavros/cmd/arming");
    ros::ServiceClient set_mode_client_0 = nh.serviceClient<mavros_msgs::SetMode>
            ("uav0/mavros/set_mode");

    ros::Subscriber state_sub_1 = nh.subscribe<mavros_msgs::State>
            ("uav1/mavros/state", 1, state_cb_uav1);
    ros::ServiceClient arming_client_1 = nh.serviceClient<mavros_msgs::CommandBool>
            ("uav1/mavros/cmd/arming");
    ros::ServiceClient set_mode_client_1 = nh.serviceClient<mavros_msgs::SetMode>
            ("uav1/mavros/set_mode");

    ros::Subscriber state_sub_2 = nh.subscribe<mavros_msgs::State>
            ("uav2/mavros/state", 1, state_cb_uav2);
    ros::ServiceClient arming_client_2 = nh.serviceClient<mavros_msgs::CommandBool>
            ("uav2/mavros/cmd/arming");
    ros::ServiceClient set_mode_client_2 = nh.serviceClient<mavros_msgs::SetMode>
            ("uav2/mavros/set_mode");

    ros::Subscriber state_sub_3 = nh.subscribe<mavros_msgs::State>
            ("uav3/mavros/state", 1, state_cb_uav3);
    ros::ServiceClient arming_client_3 = nh.serviceClient<mavros_msgs::CommandBool>
            ("uav3/mavros/cmd/arming");
    ros::ServiceClient set_mode_client_3 = nh.serviceClient<mavros_msgs::SetMode>
            ("uav3/mavros/set_mode");

    ros::Subscriber state_sub_4 = nh.subscribe<mavros_msgs::State>
            ("uav4/mavros/state", 1, state_cb_uav4);
    ros::ServiceClient arming_client_4 = nh.serviceClient<mavros_msgs::CommandBool>
            ("uav4/mavros/cmd/arming");
    ros::ServiceClient set_mode_client_4 = nh.serviceClient<mavros_msgs::SetMode>
            ("uav4/mavros/set_mode");
    while(ros::ok()){

        // if( current_state.mode.compare( set_mode_name.request.custom_mode ) &&
        //     (ros::Time::now() - last_request > ros::Duration(5.0))){
        //     if( set_mode_client.call(set_mode_name) &&
        //         set_mode_name.response.mode_sent){
                
        //         ROS_INFO("\n\t %s enabled", set_mode_name.request.custom_mode.c_str());
               
        //     }
        //     last_request = ros::Time::now();
        // } else {
        //     if( !current_state.armed &&
        //         (ros::Time::now() - last_request > ros::Duration(5.0))){
        //         if( arming_client.call(arm_cmd) &&
        //             arm_cmd.response.success){
        //             ROS_INFO("Vehicle armed");
        //         }
        //         last_request = ros::Time::now();
        //     }
        // }
        // ros::spin();
        // rate.sleep();
    }
}
else if(way == 2){
    
    std::cout << "执行单机程序" << std::endl;
    
    ros::Time last_request;
    mavros_msgs::CommandBool arm_cmd;
    mavros_msgs::SetMode set_mode_name;

    last_request = ros::Time::now();
    arm_cmd.request.value = true;


    ros::Subscriber state_sub = nh.subscribe<mavros_msgs::State>
            ("mavros/state", 1, state_cb);

    ros::ServiceClient arming_client = nh.serviceClient<mavros_msgs::CommandBool>
            ("mavros/cmd/arming");
    ros::ServiceClient set_mode_client = nh.serviceClient<mavros_msgs::SetMode>
            ("mavros/set_mode");

    while(ros::ok()){

        if( current_state.mode.compare( set_mode_name.request.custom_mode ) &&
            (ros::Time::now() - last_request > ros::Duration(5.0))){
            if( set_mode_client.call(set_mode_name) &&
                set_mode_name.response.mode_sent){
                
                ROS_INFO("\n\t %s enabled", set_mode_name.request.custom_mode.c_str());
               
            }
            last_request = ros::Time::now();
        } else {
            if( !current_state.armed &&
                (ros::Time::now() - last_request > ros::Duration(5.0))){
                if( arming_client.call(arm_cmd) &&
                    arm_cmd.response.success){
                    ROS_INFO("Vehicle armed");
                }
                last_request = ros::Time::now();
            }
        }
        ros::spin();
        rate.sleep();
    }
}
    return 0;
}
