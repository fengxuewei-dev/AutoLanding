#include "paramsLearning.hpp"

int main(int argc, char **argv)
{
    ros::init(argc, argv, "param_demo");
    ros::NodeHandle nh;
    int parameter1, parameter2, parameter3, parameter4, parameter5;
    
    // get param
    bool ifget1 = ros::param::get("param1", parameter1);
    
    // set param
    parameter4 = 4;
    ros::param::set("param4", parameter4);
    
    
    // check param
    bool ifparam6 = ros::param::has("param6");
    if(ifparam6) { 
        ROS_INFO("Param6 exists"); 
    }
    else { 
        ROS_INFO("Param6 doesn't exist"); 
    }
    

    // delete param
    bool ifdeleted6 = ros::param::del("param6");
    if(ifdeleted6) { 
        ROS_INFO("Param6 deleted"); 
    } 
    else { 
        ROS_INFO("Param6 not deleted"); 
    }
    
    // get all param names.     New in ROS indigo
    std::vector<std::string> keys;
    ros::param::search(keys);
    
    return 0;
}
