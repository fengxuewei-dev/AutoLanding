#include "algorithms.hpp"

Algorithms::Algorithms()
{
//     circle_.configuration("/home/fengxuewei/log/points", "circle","xy");            // 圆心
//     half_plane.configuration("/home/fengxuewei/log/points", "half_plane","xy");     // 半平面
//     Radius_.configuration("/home/fengxuewei/log/points", "Radius","_");
}
Algorithms::~Algorithms()
{
}
void Algorithms::waypointlist_cb(const mavros_msgs::WaypointList msg)
{
    waypointList = msg;
    ENU_change_NED(); // 转化为NED
    if(waypointList.waypoints.size() != waypointList_previous.waypoints.size()){
        hasNewWaypointList = true;
        waypointList_previous = waypointList;
    }
    else if(!isSame())
    {
        hasNewWaypointList = true;
        waypointList_previous = waypointList;
    }
    else
        hasNewWaypointList = false;
}
bool Algorithms::isSame(){
    for(size_t i = 0; i < waypointList.waypoints.size(); i++){
        if(
            waypointList.waypoints[i].x_lat != waypointList_previous.waypoints[i].x_lat && 
            waypointList.waypoints[i].y_long != waypointList_previous.waypoints[i].y_long && 
            waypointList.waypoints[i].z_alt != waypointList_previous.waypoints[i].z_alt
        ){
            return false;
        }
    }

    return true;
}

void Algorithms::getENUoffset(mavros_msgs::Waypoint startlistposition, mavros_msgs::Waypoint endlistposition, Eigen::Vector3d* enu_offset){
    
    GeographicLib::Geocentric earth(GeographicLib::Constants::WGS84_a(), GeographicLib::Constants::WGS84_f());
			
    Eigen::Vector3d goal_gps(endlistposition.x_lat, endlistposition.y_long, endlistposition.z_alt);
	Eigen::Vector3d point_gps(startlistposition.x_lat, startlistposition.y_long, startlistposition.z_alt);
			
	Eigen::Vector3d goal_ecef;
	Eigen::Vector3d position_ecef;

	earth.Forward(goal_gps.x(), goal_gps.y(), goal_gps.z(),goal_ecef.x(), goal_ecef.y(), goal_ecef.z());
	earth.Forward(point_gps.x(), point_gps.y(), point_gps.z(),position_ecef.x(), position_ecef.y(), position_ecef.z());

	Eigen::Vector3d offset_ecef = goal_ecef - position_ecef;
	*enu_offset = mavros::ftf::transform_frame_ecef_enu(offset_ecef, point_gps);
}

void Algorithms::ENU_change_NED(){
    mavros_msgs::Waypoint waypoint_;
    for(size_t i = 0; i < waypointList.waypoints.size(); i++){
        waypoint_ = waypointList.waypoints[i];
        waypointList.waypoints[i].x_lat = waypoint_.y_long;
        waypointList.waypoints[i].y_long = waypoint_.x_lat;
        waypointList.waypoints[i].z_alt = -waypoint_.z_alt;
    }
}
bool Algorithms::arrive_half_plane(Three_Dimensional_Vector waypoint_, Three_Dimensional_Vector n_i, Three_Dimensional_Vector position){
    cout << "waypoint_: "; waypoint_.print_vec();
    cout <<"position: ";  position.print_vec();
    Three_Dimensional_Vector dis =  position - waypoint_;
    cout << "dist: ";  dis.print_vec();

    double h = dis.getX()*n_i.getX() + dis.getY() * n_i.getY() + dis.getZ() * n_i.getZ(); // 数量积
    cout << "dis * n_i: " << h << endl;

    if(h >= 0)
        return true;

    return false;
}
void Algorithms::StraightLineSwitching(mavros_msgs::WaypointList waypointList_, geometry_msgs::PoseStamped position, uint16_t &i){
    // 判断航点列表是否更新
    ROS_ERROR("Enter the algorithm5!");
    double y;
    waypointlist_cb(waypointList_); // --> ned
    if(hasNewWaypointList){
        i = 1;
    }
    else if(waypointList_.waypoints.size() <= 3){
        ROS_INFO("cannot use the algorithm 5");
        return;
    }
    r = waypointList.waypoints[i - 1];

    Three_Dimensional_Vector q_i_minis_1(
        waypointList.waypoints[i].x_lat - waypointList.waypoints[i - 1].x_lat,
        waypointList.waypoints[i].y_long - waypointList.waypoints[i - 1].y_long,
        waypointList.waypoints[i].z_alt - waypointList.waypoints[i - 1].z_alt
    );
    q_i_minis_1 = q_i_minis_1.normalized();
     
    Three_Dimensional_Vector q_i(
        waypointList.waypoints[i+1].x_lat - waypointList.waypoints[i].x_lat,
        waypointList.waypoints[i+1].y_long - waypointList.waypoints[i].y_long,
        waypointList.waypoints[i+1].z_alt - waypointList.waypoints[i].z_alt
    );
    q_i = q_i.normalized();
    Three_Dimensional_Vector n_i = q_i_minis_1 + q_i;
    n_i = n_i.normalized(); // 模长为１

    /* arguments */
    wp_.update(
        waypointList.waypoints[i].x_lat,
        waypointList.waypoints[i].y_long,
        waypointList.waypoints[i].z_alt
    );
    n_i_ = n_i;
    // position是　enu的距离　需要转化为　ＮＥＤ
    position_.update(
        position.pose.position.y,
        position.pose.position.x,
        position.pose.position.z
    );
    cout << "arrive_half_plane: wp_";
    wp_.print_vec();
    if(arrive_half_plane(wp_, n_i_, position_)){
        if(i < waypointList.waypoints.size() - 1)
            ++i;
    }
}
// Waypoint path WaypointList = {w1, . . . , wN}, 
// MAV position position = (pn, pe, pd), 
// fillet radius R.
void Algorithms::StraightLineSwitching_Fillet(mavros_msgs::WaypointList waypointList_, geometry_msgs::PoseStamped position, float radius, uint16_t &i){
    ROS_ERROR("Enter the algorithm6!");
    waypointlist_cb(waypointList_);
    if(hasNewWaypointList){
        i = 1;
        state = 1;
    }else if(waypointList.waypoints.size() < 3){
        ROS_INFO("cannot use the algorithm 6");
        return;
    }
    Three_Dimensional_Vector z;

    Three_Dimensional_Vector q_i_minis_1( 
        waypointList.waypoints[i].x_lat - waypointList.waypoints[i - 1].x_lat,
        waypointList.waypoints[i].y_long - waypointList.waypoints[i - 1].y_long,
        waypointList.waypoints[i].z_alt - waypointList.waypoints[i - 1].z_alt
    );
    q_i_minis_1 = q_i_minis_1.normalized();
    Three_Dimensional_Vector q_i(   
        waypointList.waypoints[i+1].x_lat - waypointList.waypoints[i].x_lat,
        waypointList.waypoints[i+1].y_long - waypointList.waypoints[i].y_long,
        waypointList.waypoints[i+1].z_alt - waypointList.waypoints[i].z_alt
    );
    q_i = q_i.normalized();

    float varrho = acosf(-1.0f * (q_i_minis_1 * q_i)); //　两条直线的角度
    ROS_INFO("state: %d", state);
    if(1 == state){ // state == 1当前所在直线的逻辑里面; state == 2当前所在的fillet逻辑例

        // 在第一条直线
        flag = 1;
        r = waypointList.waypoints[i - 1];
        q = q_i_minis_1;

        // 判断是否到了第一个半平面(直线 --> 圆角)
        double x = radius / tanf(varrho / 2);
        // double x = radius / tanf(varrho / 2) + 30;
        Three_Dimensional_Vector wp(
            waypointList.waypoints[i].x_lat,
            waypointList.waypoints[i].y_long,
            waypointList.waypoints[i].z_alt
        );
        z = wp - q_i_minis_1 * x; // 第一个半平面
        z1 = z;         // 修正
        wp_ = z;
        n_i_ = q_i_minis_1,
        position_.update(
            position.pose.position.y,
            position.pose.position.x,
            position.pose.position.z
        );
        cout << "wp_ 的坐标为: ";
        wp_.print_vec();
        cout << "wp_ - q_i_minis_1 * ADVANCE_DISTANCE: ";
        (wp_ - q_i_minis_1 * ADVANCE_DISTANCE).print_vec(); 
        if(arrive_half_plane(wp_ - q_i_minis_1 * ADVANCE_DISTANCE, n_i_, position_)){
            state = 2;
        }
    }
    else if(2 == state){
        flag = 2;
        Three_Dimensional_Vector wp(
            waypointList.waypoints[i].x_lat,
            waypointList.waypoints[i].y_long,
            waypointList.waypoints[i].z_alt
        );

        // 圆角中心坐标生成
        Three_Dimensional_Vector y = q_i_minis_1 - q_i; y = y.normalized();
        // c为圆角中心 fillet 半径为rho
        c = wp - y * (radius / sin(varrho / 2)); // radius * sin(varrho / 2) 圆角中心和Wi的距离
        rho = radius;
        /* >>>> 计算新的 Center *****/
        // c = z1 + (c - z1).normalized() * RADIUS_COEFFICIENT * radius; 
        // rho = RADIUS_COEFFICIENT *radius;

        /**** 计算新的 Center <<<< */
        lamda = q_i_minis_1.getX() * q_i.getY() - q_i_minis_1.getY() * q_i.getX() > 0 ? 1 : -1;
        generateFilletCenter(c, lamda * rho);

        // 判断是否到了第二个半平面
        // double x = RADIUS_COEFFICIENT * radius / tanf(varrho/2); // 半平面和直线所交航点到下一个航点的直线距离
        double x = radius / tanf(varrho/2);                      // 半平面和直线所交航点到下一个航点的直线距离
        z2 = wp + q_i * x;

        wp_ = z2;
        n_i_ = q_i;
        position_.update( // enu --> ned
            position.pose.position.y,
            position.pose.position.x,
            position.pose.position.z
        );
        if(arrive_half_plane(wp_, n_i_, position_))
        {
            if(i < waypointList.waypoints.size() - 2){
                ++i;        // size() - 2 倒数第2个航点
                state = 1;  
            }// 1 ---- 2 ---- 3
            else // 最后一个航点 home 点: size() - 1; 倒数第二个航点: size() - 2
            { // 到了倒数第1个航点的
                i++; // 倒数第1个航点
                state = 1;
            }
        }
    }
}
void Algorithms::generateFilletCenter(Three_Dimensional_Vector center, float R){
    fillet_center.command = MAV_CMD_NAV_LOITER_UNLIM; // 普通的loiter
    fillet_center.x_lat = center.getY();
    fillet_center.y_long = center.getX();
    fillet_center.z_alt = -center.getZ();
    fillet_center.param3 = R;
}

/************************************ DUBINS PATH **************************************/
void Algorithms::getMapYaw(){
    Three_Dimensional_Vector la;
    Three_Dimensional_Vector lb;
    for(size_t i = 1; i < waypointList.waypoints.size(); i++)
    {
        la.update(waypointList.waypoints[i - 1].x_lat,waypointList.waypoints[i - 1].y_long,waypointList.waypoints[i - 1].z_alt);
        lb.update(waypointList.waypoints[i].x_lat, waypointList.waypoints[i].y_long, waypointList.waypoints[i].z_alt);
        double angle = atan2((lb - la).normalized().getY(), (lb - la).normalized().getX());
        waypointYaw[i - 1] = angle;
    }

    cout << "yaw sps: ";
    map<int, double>::iterator iter;
 
    for(iter = waypointYaw.begin(); iter != waypointYaw.end(); iter++)
       cout<<iter->first<<' '<<iter->second<<endl;
}
/**
 * param4 ==> Yaw	
 * Desired yaw angle at waypoint (rotary wing). 
 * NaN to use the current system yaw heading mode (e.g. yaw towards next waypoint, yaw to home, etc.).
 * 1. configuration path P{(W1, chi_1), (W2, chi_2) .... } 
 * 2. MAV NED position(local position)
 * 3. fillet radius(R)
*/
// H1: z_1 q_1
// H2: z_2 q_1
// H3: z_3(position_e_) q_3
void Algorithms::dubins_path(
    mavros_msgs::WaypointList waypointList_, 
    geometry_msgs::PoseStamped position,        // ENU
    float radius, 
    uint16_t &i
){
    ROS_ERROR("Enter the dubins path!");
    waypointlist_cb(waypointList_);  // 转为ned  waypointList 为ned航点
    
    getMapYaw();            // yaw

    if(hasNewWaypointList){
        i = 1;
        state = 1;
    }else if(waypointList.waypoints.size() < 3){
        ROS_INFO("Cannot use the dubins path!");
        return;
    }

    /* >>>>>>>>>>>>>> 这里需要通过参数传入进来 */ 
    double chi_s_ = waypointYaw[i - 1];
    double chi_e_ = waypointYaw[i];
    /* 这里需要通过参数传入进来 <<<<<<<<<<<<<< */  
    
    // 求出dubins path的参数 ned
    findDubinsParameters(waypointList.waypoints[i-1], waypointList.waypoints[i],chi_s_, chi_e_, radius);

    cout << "i = " << i << endl;
    cout << "state: " << state << endl;

    // the start circle is followed in state = 1 until crossing into the part of circle opposite H1,
    if(1 == state){ // start circle 直到到半平面 half plane 1
        flag = 2;   // 开始生成loiter

        c = Center_s;  rho = radius;   lamda = lamda_s;
        generateFilletCenter(c, lamda * rho);

        wp_ = z_1;
        n_i_ = -q_1;
        position_.update(
            position.pose.position.y,
            position.pose.position.x,
            position.pose.position.z
        );
        if(arrive_half_plane(wp_, n_i_, position_)){
            state = 2;
        }
    }else if(2 == state){ // state == 1 || 2 都是在第一个loiter圆上面
        wp_ = z_1;
        n_i_ = q_1;
        position_.update(
            position.pose.position.y,
            position.pose.position.x,
            position.pose.position.z
        );
        if(arrive_half_plane(wp_, n_i_, position_)){
            state = 3;
        }
    }else if(3 == state){ // 直线部分
        flag = 1;
        
        r.command = 16; r.x_lat = z_1.getY(); r.y_long = z_1.getX(); r.z_alt = -z_1.getZ(); 
        q = q_1;

        wp_ = z_2;
        n_i_ = q_1;
        position_.update(
            position.pose.position.y,
            position.pose.position.x,
            position.pose.position.z
        );
        if(arrive_half_plane(wp_, n_i_, position_)){
            state = 4;
        }
    }else if(4 == state){
        flag = 2;        c = Center_e;        rho = radius;        lamda = lamda_e;
        generateFilletCenter(c, lamda * rho);

        wp_ = z_3;
        n_i_ = -q_3;     // 取在最终的初始化位置的相反平面法线
        position_.update(
            position.pose.position.y,
            position.pose.position.x,
            position.pose.position.z
        );
        if(arrive_half_plane(wp_, n_i_, position_)){
            state = 5;
        }
    }else if(5 == state){
        wp_ = z_3;
        n_i_ = q_3;
        position_.update(
            position.pose.position.y,
            position.pose.position.x,
            position.pose.position.z
        );
        if(arrive_half_plane(wp_, n_i_, position_)){
            state = 1;
            cout << "waypointList.waypoints.size() ; " << waypointList.waypoints.size() << endl;
            cout << "i; " << i << endl;
            
            if(i <= waypointList.waypoints.size() - 1)
                ++i;

            double chi_s_ = waypointYaw[i - 1];
            double chi_e_ = waypointYaw[i];
            findDubinsParameters( waypointList.waypoints[i - 1],waypointList.waypoints[i],
                chi_s_, chi_e_, radius );
        }
    }
    
}
void Algorithms::print_wp(const mavros_msgs::Waypoint& wp)
{
    ROS_INFO("waypoint: x_lat = %f y_long = %f z_alt = %f ", wp.x_lat,wp.y_long,wp.z_alt);
    ROS_INFO("command = %d frame = %d autocontinue = %d ",wp.command,wp.frame,wp.autocontinue);
    ROS_INFO("param:%f %f %f %f", wp.param1,wp.param2,wp.param3,wp.param4);
}
// X-shell 6
/**
 * findDubinsParameters();
 * 
 * 1. constant altitude & constant groundspeed 
 * 2. circle arcs's radius = R(at least as large as the minimum turn radius of the uav)
 * 3. configuration (inertial position(ned), course angle(radian)--> chi)
 *         start configuration : (position_s_, chi_s)
 *         end   configuration : (position_e_, chi_e)  
 */
void Algorithms::findDubinsParameters(
    mavros_msgs::Waypoint position_s,       // 开始的初始位置(ned)
    mavros_msgs::Waypoint position_e,       // 最终的初始位置(ned)
    double chi_s,                           // 开始的航向角 弧度
    double chi_e,                           // 最终的航向角 弧度
    float radius                            // circle的半径
){
    position_s_.update( position_s.x_lat, position_s.y_long, position_s.z_alt );
    position_e_.update( position_e.x_lat, position_e.y_long, position_e.z_alt );
    dubins_path_radius = radius;

    if((position_e_ - position_s_).len() < 3 * radius){ ROS_INFO("Cannot use the findDubinsParameters()!"); return; }

    // 2. 计算四种情况的长度的最小值
    getMiniLengthAndNumber();
    if(1 == Length_min_number){
        Center_s = Center_R_S;        lamda_s = 1;
        Center_e = Center_R_E;        lamda_e = 1;

        q_1 = (Center_e - Center_s).normalized();

        setRotation(-M_PI / 2);

        z_1 = Center_s + Rotation_multiplied_vector(q_1) * dubins_path_radius;
        z_2 = Center_e + Rotation_multiplied_vector(q_1) * dubins_path_radius;
        cout << "offset: "; 
        (Rotation_multiplied_vector(q_1) * dubins_path_radius).print_vec();
    }else if(2 == Length_min_number){
        // 应该是 右 - 直 - 左
        // 但是打印出来的数据是 左 - 直 - 右
        Center_s = Center_R_S;       lamda_s = 1;
        Center_e = Center_L_E;       lamda_e = -1;

        LENGTH = (Center_e - Center_s).len();

        vartheta = atan2((Center_e - Center_s).getY(), (Center_e - Center_s).getX());

        double vartheta_2 = vartheta - M_PI / 2 + asinf(2 * dubins_path_radius / LENGTH);

        // 反三角函数的返回值都是弧度制，要换成角度制，需要 *180/π 
        setRotation(vartheta_2 + M_PI / 2);
        q_1 = Rotation_multiplied_vector(e_1);  // 直线的斜率

        setRotation(vartheta_2);
        z_1 = Center_s + Rotation_multiplied_vector(e_1) * dubins_path_radius;
        
        setRotation(vartheta_2 + M_PI); 
        z_2 = Center_e + Rotation_multiplied_vector(e_1) * dubins_path_radius;
        cout << "LENGTH: " << LENGTH << endl;
        cout << "vartheta: " << vartheta << endl;
        cout << "vartheta_2: " << vartheta_2 << endl;
        cout << "Rotation_multiplied_vector(e_1): ";Rotation_multiplied_vector(e_1).print_vec();
        cout << "offset: "; 
        (Rotation_multiplied_vector(e_1) * dubins_path_radius).print_vec();

    }else if(3 == Length_min_number){
        Center_s = Center_L_S;     lamda_s = -1;
        Center_e = Center_R_E;     lamda_e = 1;

        LENGTH = (Center_e - Center_s).len();

        vartheta = atan2((Center_e - Center_s).getY(), (Center_e - Center_s).getX());

        double vartheta_2 = acosf(2 * dubins_path_radius / LENGTH);

        //  反三角函数的返回值都是弧度制，要换成角度制，需要 *180/π 
        setRotation(vartheta + vartheta_2 - M_PI / 2);
        q_1 = Rotation_multiplied_vector(e_1); // 线的斜率

        setRotation(vartheta + vartheta_2);
        z_1 = Center_s + Rotation_multiplied_vector(e_1) * dubins_path_radius;
        
        setRotation(vartheta + vartheta_2 - M_PI);
        z_2 = Center_e + Rotation_multiplied_vector(e_1) * dubins_path_radius;
        cout << "offset: "; 
        (Rotation_multiplied_vector(e_1) * dubins_path_radius).print_vec();

    }else if(4 == Length_min_number){ // z2 z3 是一样的, 也就是说z2并不是计算出来的是错误的,那么z2是怎么计算的
        Center_s = Center_L_S;     lamda_s = -1;
        Center_e = Center_L_E;     lamda_e = -1;

        q_1 = (Center_e - Center_s).normalized();

        setRotation(M_PI / 2);
        z_1 = Center_s + Rotation_multiplied_vector(q_1) * dubins_path_radius;
        z_2 = Center_e + Rotation_multiplied_vector(q_1) * dubins_path_radius;  // 书上面是 q_2 ? 
        cout << "offset: "; 
        (Rotation_multiplied_vector(q_1) * dubins_path_radius).print_vec();
    }
    z_3 = position_e_;
    setRotation(chi_e);
    q_3 = Rotation_multiplied_vector(e_1);
    cout << "position_s_";      position_s_.print_vec();
    cout << "center_s: ";       Center_s.print_vec();
    cout << "z_1: ";            z_1.print_vec();
    cout << "position_e_: ";    position_e_.print_vec();
    cout << "Center_e: ";       Center_e.print_vec();
    cout << "z_2: ";            z_2.print_vec();
    cout << "z_3: ";            z_3.print_vec();
    cout << "q_3: ";            q_3.print_vec();
}
// 右手坐标系进行变换时将T与需要变换的点或向量A（列向量）相乘，即TA。也就是说原始矩阵A放右边。
Three_Dimensional_Vector Algorithms::Rotation_multiplied_vector(Three_Dimensional_Vector _vector_){

    Three_Dimensional_Vector Rotation_1(Rotation[0][0], Rotation[0][1], Rotation[0][2]);
    Three_Dimensional_Vector Rotation_2(Rotation[1][0], Rotation[1][1], Rotation[1][2]);
    Three_Dimensional_Vector Rotation_3(Rotation[2][0], Rotation[2][1], Rotation[2][2]);

    Three_Dimensional_Vector reasult;
    reasult.update( Rotation_1 * _vector_, Rotation_2 * _vector_, Rotation_3 * _vector_ );

    return reasult;
}
// 右手旋转矩阵 绕z轴旋转
void Algorithms::setRotation(double theta_){

    double theta = mod(theta_);
    double ang[9] = { 
        cos(theta), -sin(theta), 0, 
        sin(theta), cos(theta), 0, 
        0, 0, 1 
    };
    size_t k = 0;
    for(size_t i = 0; i < 3; i++){ 
        for(size_t j = 0; j < 3; j++){ 
            Rotation[i][j] = ang[k++];
        } 
    }
}
void Algorithms::printRotation(){
    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 3; j++){ cout << Rotation[i][j] << "\t\t"; } cout << endl;
    }
}
/* Dubins path */
double Algorithms::mod(double x){ // %
    x = x + 2 * M_PI;
    x = fmod(x, 2 * M_PI);
    return x;
}

// 计算一个position位置的 右转圆心
void Algorithms::getCenter_R(Three_Dimensional_Vector position, double chi){
    setRotation(1.0f * M_PI / 2);
    Three_Dimensional_Vector _vec( cos(chi), sin(chi), 0 );
    Three_Dimensional_Vector offset_R = Rotation_multiplied_vector(_vec);
    Center_R =  position + offset_R * dubins_path_radius;
}
// 计算一个position位置的 左转圆心
void Algorithms::getCenter_L(Three_Dimensional_Vector position, double chi){
    setRotation(-1.0f * M_PI / 2); // y
    Three_Dimensional_Vector _vec( cos(chi), sin(chi), 0 );
    Three_Dimensional_Vector offset_L = Rotation_multiplied_vector(_vec);
    Center_L =  position + offset_L * dubins_path_radius;
}
void Algorithms::_length_R_S_R(){   // L1
    
    getCenter_R(position_s_, chi_s);  Center_R_S = Center_R;
    getCenter_R(position_e_, chi_e);  Center_R_E = Center_R;
    ROS_ERROR("_length_R_S_R");
    cout << "Center_R_S: "; Center_R_S.print_vec();
    cout << "Center_R_E: "; Center_R_E.print_vec();
    double distance_s_e = (Center_R_S - Center_R_E).len();   
    // cout << "distance_s_e: " << distance_s_e << endl;                                   // 计算长度 
    // cout << "Center_R_S - Center_R_E : "; (Center_R_S - Center_R_E).print_vec();
    vartheta = atan2((Center_R_E - Center_R_S).getY(), (Center_R_E - Center_R_S).getX());        // 计算向量的角度
    
    double start_arc_length = dubins_path_radius * mod(2 * M_PI + mod(vartheta - M_PI / 2) - mod(chi_s - M_PI / 2));
    double end_arc_length = dubins_path_radius * mod(2 * M_PI + mod(chi_e - M_PI / 2) - mod(vartheta - M_PI / 2));
    // cout << "start_arc_length : " << start_arc_length << endl;
    // cout << "end_arc_length : " << end_arc_length << endl;
    Length_1 = start_arc_length + distance_s_e + end_arc_length;
    // cout << "Length_1 : " << Length_1 << endl;
}
void Algorithms::_length_R_S_L(){   // L2
    getCenter_R(position_s_, chi_s);  Center_R_S = Center_R;
    getCenter_L(position_e_, chi_e);  Center_L_E = Center_L;
    ROS_ERROR("_length_R_S_L");
    cout << "Center_R_S: "; Center_R_S.print_vec();
    cout << "Center_L_E: "; Center_L_E.print_vec();
    double L = (Center_R_S - Center_L_E).len();                                      
    double distance_ = sqrt(pow(L, 2) - 4 * pow(dubins_path_radius, 2));// 计算长度

    vartheta = atan2((Center_L_E - Center_R_S).getY(), (Center_L_E - Center_R_S).getX());        // 计算向量的角度
    double vartheta_2 = vartheta - (M_PI / 2 - asinf(2 * dubins_path_radius / L));
    
    double start_arc_length = dubins_path_radius * mod(2 * M_PI + mod(vartheta_2) - mod(chi_s - M_PI / 2));
    double end_arc_length = dubins_path_radius * mod(2 * M_PI + mod(vartheta_2 + M_PI) - mod(chi_e + M_PI / 2));
    
    Length_2 = start_arc_length + distance_ + end_arc_length;
}
void Algorithms::_length_L_S_R(){       // L3

    getCenter_L(position_s_, chi_s);  Center_L_S = Center_L;
    getCenter_R(position_e_, chi_e);  Center_R_E = Center_R;
    ROS_ERROR("_length_L_S_R");
    cout << "Center_L_S: "; Center_L_S.print_vec();
    cout << "Center_R_E: "; Center_R_E.print_vec();
    double L = (Center_L_S - Center_R_E).len();                                      
    double distance_ = sqrt(pow(L, 2) - 4 * pow(dubins_path_radius, 2));                         // 计算长度

    vartheta = atan2((Center_R_E - Center_L_S).getY(), (Center_R_E - Center_L_S).getX());        // 计算向量的角度
    double vartheta_2 = acosf(2.0f * dubins_path_radius / L);
    
    double start_arc_length = dubins_path_radius * mod(2 * M_PI + mod(chi_s + M_PI / 2) - mod(vartheta + vartheta_2));
    double end_arc_length = dubins_path_radius * mod(2 * M_PI + mod(chi_e - M_PI / 2) - mod(vartheta + vartheta_2 - M_PI));
    
    Length_3 = start_arc_length + distance_ + end_arc_length;
}
void Algorithms::_length_L_S_L(){       // L4
    getCenter_L(position_s_, chi_s);  Center_L_S = Center_L;
    getCenter_L(position_e_, chi_e);  Center_L_E = Center_L;
    ROS_ERROR("_length_L_S_L");
    cout << "Center_L_S: "; Center_L_S.print_vec();
    cout << "Center_L_E: "; Center_L_E.print_vec();
    
    double distance_s_e = (Center_L_S - Center_L_E).len();                                       // 计算长度
    vartheta = atan2((Center_L_E - Center_L_S).getY(), (Center_L_E - Center_L_S).getX());        // 计算向量的角度
    
    
    double start_arc_length = dubins_path_radius * mod(2 * M_PI + mod(chi_s + M_PI / 2) - mod(vartheta + M_PI / 2)); 
    double end_arc_length = dubins_path_radius * mod(2 * M_PI + mod(vartheta + M_PI / 2) - mod(chi_e + M_PI / 2));
    
    Length_4 = start_arc_length + distance_s_e + end_arc_length;
}

double Algorithms::min(double x, double y){  return x > y ? y : x; }

// 再计算的时候, 左右的圆点半径都颠倒了
void Algorithms::getMiniLengthAndNumber(){
    cout << "position_s_: "; position_s_.print_vec(); 
    cout << "position_e_: "; position_e_.print_vec(); 
    _length_R_S_R(); _length_R_S_L();
    _length_L_S_R(); _length_L_S_L();

    cout << "Length_1: " << Length_1 << endl;
    cout << "Length_2: " << Length_2 << endl;
    cout << "Length_3: " << Length_3 << endl;
    cout << "Length_4: " << Length_4 << endl;
    Length_min = min(Length_1, Length_2);
    Length_min = min(Length_min, Length_3);
    Length_min = min(Length_min, Length_4);

    if(Length_min == Length_1)      Length_min_number = 1;
    else if(Length_min == Length_2) Length_min_number = 2;
    else if(Length_min == Length_3) Length_min_number = 3;
    else                            Length_min_number = 4;
    cout << "Length_min_number: " << Length_min_number << endl;
}
