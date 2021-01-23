#include "fw_sub_pub.hpp"


    float FW_SUB_PUB::get_ros_time(ros::Time begin)//获取ros时间
    {
        ros::Time time_now = ros::Time::now();
        float currTimeSec = time_now.sec - begin.sec;
        float currTimenSec = time_now.nsec / 1e9 - begin.nsec / 1e9;
        return (currTimeSec + currTimenSec);
    }

    void FW_SUB_PUB::state_cb(const mavros_msgs::State::ConstPtr &msg)
    {// 1
        current_state = *msg;
        cout << "The px4's mode: \t\t" << current_state.mode << endl << endl;
    }

    void FW_SUB_PUB::imu_cb(const sensor_msgs::Imu::ConstPtr &msg)
    {// 1
        imu = *msg;
        float q[4];
        q[0] = msg->orientation.w;
        q[1] = msg->orientation.x;
        q[2] = msg->orientation.y;
        q[3] = msg->orientation.z;
        cout << "The imu: " << endl;
        cout << "orientation[4]: (" << q[0] << ",\t" << q[1] << ",\t" << q[2] << ",\t" << q[3] << ")" << endl;
        mathlib.quaternion_2_euler(q, att_angle_Euler);
        cout << "Euler[3]: (" << att_angle_Euler[0] << ",\t" << att_angle_Euler[1] << ",\t" << att_angle_Euler[2] << ")" << endl << endl;
    }

    void FW_SUB_PUB::global_position_form_px4_cb(const sensor_msgs::NavSatFix::ConstPtr &msg)
    {// 1
        global_position_form_px4 = *msg;
        cout << "The global position: " << endl;
        cout << "latitude: " << global_position_form_px4.latitude << endl;
        cout << "longitude: " << global_position_form_px4.longitude << endl;
        cout << "altitude: " << global_position_form_px4.altitude << endl << endl;
    }

    void FW_SUB_PUB::fixed_wing_global_rel_alt_from_px4_cb(const std_msgs::Float64::ConstPtr &msg)
    { // 1
        global_rel_alt_from_px4 = *msg;
        cout << "Relative altitude: " << endl;
        cout << "data: " << global_rel_alt_from_px4.data << endl << endl;
    }

    void FW_SUB_PUB::umt_position_from_px4_cb(const nav_msgs::Odometry::ConstPtr &msg)
    {// 1
        umt_position_from_px4 = *msg;
        cout << "UTM coords: This represents an estimate of a position and velocity in free space." << endl;
        cout << "Frame this data is associated with: " << umt_position_from_px4.header.frame_id  << endl;
        cout << "umt_position_from_px4.pose.pose.position.x: " << umt_position_from_px4.pose.pose.position.x << endl;
        cout << "umt_position_from_px4.pose.pose.position.y: " << umt_position_from_px4.pose.pose.position.y << endl;
        cout << "umt_position_from_px4.pose.pose.position.z: " << umt_position_from_px4.pose.pose.position.z << endl;
        cout << "umt_position_from_px4.twist.twist.angular.x: " << umt_position_from_px4.twist.twist.angular.x << endl;   
        cout << "umt_position_from_px4.twist.twist.angular.y: " << umt_position_from_px4.twist.twist.angular.y << endl;   
        cout << "umt_position_from_px4.twist.twist.angular.z: " << umt_position_from_px4.twist.twist.angular.z << endl; 
        cout << endl;
    }

    void FW_SUB_PUB::velocity_global_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg)
    { // 1
        velocity_global_fused_from_px4 = *msg;
        cout << "Velocity output from the GPS device." << endl;
        cout << "twist.angular.x: " << velocity_global_fused_from_px4.twist.angular.x << endl;
        cout << "twist.angular.y: " << velocity_global_fused_from_px4.twist.angular.y << endl;
        cout << "twist.angular.z: " << velocity_global_fused_from_px4.twist.angular.z << endl;

        cout << "twist.linear.x: " << velocity_global_fused_from_px4.twist.linear.x << endl;
        cout << "twist.linear.y: " << velocity_global_fused_from_px4.twist.linear.y << endl;
        cout << "twist.linear.z: " << velocity_global_fused_from_px4.twist.linear.z << endl;
        cout << endl;
    }

    void FW_SUB_PUB::velocity_ned_fused_from_px4_cb(const geometry_msgs::TwistStamped::ConstPtr &msg)
    {// 1
        velocity_ned_fused_from_px4 = *msg;

        cout << "Velocity data from FCU: " << endl;
        cout << "ned_vel_x: " << velocity_ned_fused_from_px4.twist.linear.y << endl;
        cout << "ned_vel_y: " << velocity_ned_fused_from_px4.twist.linear.x << endl;
        cout << "ned_vel_z: " << velocity_ned_fused_from_px4.twist.linear.z << endl;
        cout << endl;
    }

    void FW_SUB_PUB::local_position_from_px4_cb(const geometry_msgs::PoseStamped::ConstPtr &msg)
    { // local position  
        local_position_from_px4 = *msg;
        cout << "Local position from FCU: "<< endl;
        // local_x.logPrint(local_position_from_px4.pose.position.x);
        // local_y.logPrint(local_position_from_px4.pose.position.y);
        // cout << "ned.x  " << local_position_from_px4.pose.position.x << endl;
        // cout << "ned.y  " << local_position_from_px4.pose.position.y << endl;
        cout << "ned.z  " << local_position_from_px4.pose.position.z << endl;
        
        cout << endl;
    }

    void FW_SUB_PUB::acc_ned_from_px4_cb(const geometry_msgs::AccelWithCovarianceStamped::ConstPtr &msg)
    {
        acc_ned_from_px4 = *msg;

        cout << "The acceleration from FCU: " << endl;
        cout << "accel.angular.x: " << acc_ned_from_px4.accel.accel.angular.x << endl;
        cout << "accel.angular.y: " << acc_ned_from_px4.accel.accel.angular.y << endl;
        cout << "accel.angular.z: " << acc_ned_from_px4.accel.accel.angular.z << endl;

        cout << "accel.linear.x: " << acc_ned_from_px4.accel.accel.linear.x << endl;
        cout << "accel.linear.y: " << acc_ned_from_px4.accel.accel.linear.y << endl;
        cout << "accel.linear.z: " << acc_ned_from_px4.accel.accel.linear.z << endl;

        cout << endl;
    }

    void FW_SUB_PUB::wind_estimate_from_px4_cb(const geometry_msgs::TwistWithCovarianceStamped::ConstPtr &msg)
    {// 1
        wind_estimate_from_px4 = *msg;
        cout << "Wind estimation from FCU (APM): " << endl;
        cout << " " << wind_estimate_from_px4.twist.twist.angular.x << endl;
        cout << "wind_estimate.twist.angular.x: " << wind_estimate_from_px4.twist.twist.angular.x << endl;
        cout << "wind_estimate.twist.angular.y: " << wind_estimate_from_px4.twist.twist.angular.y << endl;
        cout << "wind_estimate.twist.angular.z: " << wind_estimate_from_px4.twist.twist.angular.z << endl;

        cout << "wind_estimate.twist.linear.x: " << wind_estimate_from_px4.twist.twist.linear.x << endl;
        cout << "wind_estimate.twist.linear.y: " << wind_estimate_from_px4.twist.twist.linear.y << endl;
        cout << "wind_estimate.twist.linear.z: " << wind_estimate_from_px4.twist.twist.linear.z << endl;

        cout << endl;
    }

    void FW_SUB_PUB::battrey_state_from_px4_cb(const sensor_msgs::BatteryState::ConstPtr &msg)
    {// 1
        battrey_state_from_px4 = *msg;
        cout << "FCU battery status report: " << endl;
        cout << "voltage: " << battrey_state_from_px4.voltage << endl;
        cout << "current: " << battrey_state_from_px4.current << endl;
        cout << "charge: " << battrey_state_from_px4.charge << endl;
        cout << "capacity: " << battrey_state_from_px4.capacity << endl;
        cout << "design_capacity: " << battrey_state_from_px4.design_capacity << endl;
        cout << "percentage: " << battrey_state_from_px4.percentage << endl;
        cout << "power_supply_status:: " << battrey_state_from_px4.power_supply_status   << endl;
        cout << "power_supply_health: " << battrey_state_from_px4.power_supply_health << endl;
        cout << "power_supply_technology: " << battrey_state_from_px4.power_supply_technology << endl;

        cout << "present: " << battrey_state_from_px4.present   << endl;
        cout << "location: " << battrey_state_from_px4.location << endl;
        cout << "serial_number: " << battrey_state_from_px4.serial_number << endl;
        for(size_t i = 0; i < battrey_state_from_px4.cell_voltage.size(); i++)
            cout << "cell_voltage[" << i << "]: " << battrey_state_from_px4.cell_voltage[i]  << endl;
        
        cout << endl;
    }

    void FW_SUB_PUB::waypoints_reached_from_px4_cb(const mavros_msgs::WaypointReached::ConstPtr &msg)
    {
        waypoint_reached = *msg;
        cout << "The waypoint_reached seq(from 0) = " << waypoint_reached.wp_seq << endl;
        cout << endl;
    }

    void FW_SUB_PUB::print_wp(const mavros_msgs::Waypoint& wp)
    {
        ROS_INFO("waypoint: x_lat = %f y_long = %f z_alt = %f ", wp.x_lat,wp.y_long,wp.z_alt);
        // ROS_INFO("command = %d frame = %d autocontinue = %d is_current = %d",wp.command,wp.frame,wp.autocontinue,wp.is_current);
        ROS_INFO("command = %d frame = %d autocontinue = %d ",wp.command,wp.frame,wp.autocontinue);
        ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
    }

    void FW_SUB_PUB::waypointlist_from_px4_cb(const mavros_msgs::WaypointList::ConstPtr &msg)
    {
        if(!lock_wps) // 第一次执行, 没有上锁, 可以打印
        {
            waypoint_list = *msg;

            lock_wps = true;

            // 这里的航点列表只是打印一次;        
            for (size_t i = 0; i < waypoint_list.waypoints.size(); i++)
            {
                ROS_INFO("WP: %d",int(i));
                print_wp(waypoint_list.waypoints[i]);
            }
            cout << endl;
        }
    }

    // void waypointlist_from_px4_cb(const mavros_msgs::WaypointList::ConstPtr &msg)
    // {
    //     waypoint_list = *msg;
    // }

    void FW_SUB_PUB::altitude_from_px4_cb(const mavros_msgs::Altitude::ConstPtr &msg)
    {
        altitude_from_px4 = *msg;
        cout << " The altitude from FCU: " << endl;
        cout << "monotonic: \t\t" << altitude_from_px4.monotonic << endl;
        cout << "amsl: \t\t" << altitude_from_px4.amsl << endl;
        cout << "local: \t\t" << altitude_from_px4.local << endl;
        cout << "relative:\t \t" << altitude_from_px4.relative << endl;
        cout << "terrain: \t\t" << altitude_from_px4.terrain << endl;
        cout << endl;
        
    }

    void FW_SUB_PUB::air_ground_speed_from_px4_cb(const mavros_msgs::VFR_HUD::ConstPtr &msg)
    {
        air_ground_speed_from_px4 = *msg;
        cout << "Data for HUD." << endl;
        cout << "airspeed: \t\t" << air_ground_speed_from_px4.airspeed << endl;
        cout << "groundspeed: \t\t" << air_ground_speed_from_px4.groundspeed << endl << endl;
    }

    void FW_SUB_PUB::fixed_wing_states_tran_cb(const mavros_msgs::Formation_fixed_wing::ConstPtr &msg)
    {
        fixed_wing_states_tran = *msg;

        cout << "latitude: " << fixed_wing_states_tran.latitude << endl;
        cout << "longitude: " << fixed_wing_states_tran.longtitude << endl;
        cout << "altitude: " << fixed_wing_states_tran.altitude << endl;

        cout << "ned_vel_x: " << fixed_wing_states_tran.ned_vel_x << endl;
        cout << "ned_vel_y: " << fixed_wing_states_tran.ned_vel_y << endl;
        cout << "ned_vel_z: " << fixed_wing_states_tran.ned_vel_z << endl;
    }