#include "LogStream.hpp"
/**
 * Using this file to printf considerable variables for debugging in matlab.
*/
class logger_leader{
    public:
        std::string         pathName;
        std::string         uavName;
        logStream<double>   local_x;
        logStream<double>   local_y;
        logStream<double>   local_z;

        logStream<double>   log_gps_waypointslist_x_lat;
        logStream<double>   log_gps_waypointslist_y_lon;
        logStream<double>   log_gps_waypointslist_z_alt;

        logStream<double>   log_enu_waypointslist_x;
        logStream<double>   log_enu_waypointslist_y;
        logStream<double>   log_enu_waypointslist_z;

        logStream<double>   log_generate_loiter_waypoints_x;
        logStream<double>   log_generate_loiter_waypoints_y;
        logStream<double>   log_generate_loiter_Radius;

        logStream<double>   log_publish_currentWaypoint_x;
        logStream<double>   log_publish_currentWaypoint_y;
        logStream<double>   log_publish_currentWaypoint_z;

        logStream<double>   log_publish_nextWaypoint_x;
        logStream<double>   log_publish_nextWaypoint_y;
        logStream<double>   log_publish_nextWaypoint_z;


        logStream<double>   log_publish_enu_currentWaypoint_x;
        logStream<double>   log_publish_enu_currentWaypoint_y;
        logStream<double>   log_publish_enu_currentWaypoint_z;

        logStream<double>   log_publish_enu_nextWaypoint_x;
        logStream<double>   log_publish_enu_nextWaypoint_y;
        logStream<double>   log_publish_enu_nextWaypoint_z;

        logStream<float>    log_publish_Throttle;
        logStream<int>      log_publish_ExistNext;

        logger_leader(std::string);
        ~logger_leader();
};
logger_leader::logger_leader(std::string _uavName_):uavName(_uavName_){
    pathName = "leader";

    // enu waypoint list
    log_enu_waypointslist_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/waypointList", "enu_waypointList", "East");
    log_enu_waypointslist_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/waypointList", "enu_waypointList", "North");
    log_enu_waypointslist_z.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/waypointList", "enu_waypointList", "Upper");

    // gps waypoint list
    log_gps_waypointslist_x_lat.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/waypointList", "gps_waypointList", "x_lat");
    log_gps_waypointslist_y_lon.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/waypointList", "gps_waypointList", "y_long");
    log_gps_waypointslist_z_alt.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/waypointList", "gps_waypointList", "z_alt");

    log_generate_loiter_waypoints_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/GenerateLoiter", "generate_loiter_waypointList", "East");
    log_generate_loiter_waypoints_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/GenerateLoiter", "generate_loiter_waypointList", "North");
    log_generate_loiter_Radius.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "leader/GenerateLoiter", "generate_loiter_waypointList", "Radius");

    log_publish_currentWaypoint_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "gps_currentWaypoint", "x");
    log_publish_currentWaypoint_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "gps_currentWaypoint", "y");
    log_publish_currentWaypoint_z.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "gps_currentWaypoint", "z");

    log_publish_nextWaypoint_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "gps_nextWaypoint", "x");
    log_publish_nextWaypoint_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "gps_nextWaypoint", "y");
    log_publish_nextWaypoint_z.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "gps_nextWaypoint", "z");


    log_publish_enu_currentWaypoint_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "enu_currentWaypoint", "x");
    log_publish_enu_currentWaypoint_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "enu_currentWaypoint", "y");
    log_publish_enu_currentWaypoint_z.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "enu_currentWaypoint", "z");

    log_publish_enu_nextWaypoint_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "enu_nextWaypoint", "x");
    log_publish_enu_nextWaypoint_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "enu_nextWaypoint", "y");
    log_publish_enu_nextWaypoint_z.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "enu_nextWaypoint", "z");

    log_publish_ExistNext.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "ExistNext");
    log_publish_Throttle.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ + "navigator/publish",  "Throttle");


    local_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"local", "x");
    local_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"local", "y");
    local_z.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"local", "z");
}

logger_leader::~logger_leader(){

}
class logger_follower{
    public:
        std::string pathName;
        std::string uavName;
        logStream<double> local_x;
        logStream<double> local_y;
        logStream<double> local_z;

        logStream<float> gap_x;
        logStream<float> gap_y;

        logStream<double> finalPosition_x;
        logStream<double> finalPosition_y;
        logStream<double> finalPosition_z;

        logger_follower(std::string);
        ~logger_follower();
};
logger_follower::logger_follower(std::string _uavName_):uavName(_uavName_){
    pathName = "follower";
    local_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"local", "x");
    local_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"local", "y");
    local_z.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"local", "z");

    gap_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"gap", "x");
    gap_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"gap", "y");

    finalPosition_x.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"finalPosition", "x");
    finalPosition_y.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"finalPosition", "y");
    finalPosition_z.configuration
        (string(LOGGERPATH)  + "/" + _uavName_ +  pathName + "/" +"finalPosition", "z");
}
logger_follower::~logger_follower(){
    
}