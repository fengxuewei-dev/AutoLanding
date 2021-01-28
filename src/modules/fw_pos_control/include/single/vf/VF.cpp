#include "VF.hpp"
#include <iostream>
#define EN_DEBUG 0

using std::cout;
using std::endl;

VF::VF(double newk, double newchi_infinite, double newalpha, unsigned int newdistanceThreshold)
{
    k = newk;
    chi_infinite = newchi_infinite;
    alpha = newalpha;
    distanceThreshold = newdistanceThreshold;
}
VF::VF()
{
    k2_hat_previous = K2_HAT_PREVIOUS; // 37.1341
    

    Lowlimit_2 = LOWLIMIT_2; // k2_hat 的下限值
    Upperlimit_2 = UPPERLIMIT_2;  // 55.7012
    
    k2_hat_previous_O = K2_HAT_PREVIOUS_O;
    Lowlimit_O_2 = LOWLIMIT_O_2;
    Upperlimit_O_2 = UPPERLIMIT_O_2; 
}

VF::~VF()
{
}

double VF::sat(double x){
    if(abs(x) <= 1)                 return x;
    else if(abs(x) > 1 && x > 0)    return 1;
    else if(abs(x) > 1 && x == 0)   return 0;
    else if(abs(x) > 1 && x < 0)    return -1;
}

/* Dubins path */
double VF::mod(double x){ // %
    x = x + 2 * M_PI;
    x = fmod(x, 2 * M_PI);
    return x;
}
// 绕着 Z 轴旋转 theta_ 角度的旋转矩阵
void VF::setRotation_Z(double theta_){
    cout <<"绕z轴旋转矩阵，旋转角度为 " << theta_ << endl;
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
    printRotation();
}

// 绕着 Y' 轴旋转 theta_ 角度的旋转矩阵
void VF::setRotation_Y_(double theta_){
    cout <<"绕y轴旋转矩阵，旋转角度为 " << theta_ << endl;

    double theta = mod(theta_);
    double ang[9] = { 
        cos(theta), 0, sin(theta), 
        0, 1, 0,
        -sin(theta), 1, cos(theta)
    };
    size_t k = 0;
    for(size_t i = 0; i < 3; i++){ 
        for(size_t j = 0; j < 3; j++){ 
            Rotation[i][j] = ang[k++];
        } 
    }
    printRotation();
}
void VF::printRotation(){
    std::cout <<"旋转之后的矩阵为: " << endl;
    for(size_t i = 0; i < 3; i++){
        for(size_t j = 0; j < 3; j++){ cout << Rotation[i][j] << "\t\t"; } cout << endl;
    }
}
// 右手坐标系进行变换时将T与需要变换的点或向量A（列向量）相乘，即TA。也就是说原始矩阵A放右边。
Three_Dimensional_Vector VF::Rotation_multiplied_vector(Three_Dimensional_Vector _vector_){

    Three_Dimensional_Vector Rotation_1(Rotation[0][0], Rotation[0][1], Rotation[0][2]);
    Three_Dimensional_Vector Rotation_2(Rotation[1][0], Rotation[1][1], Rotation[1][2]);
    Three_Dimensional_Vector Rotation_3(Rotation[2][0], Rotation[2][1], Rotation[2][2]);

    Three_Dimensional_Vector reasult;
    reasult.update( Rotation_1 * _vector_, Rotation_2 * _vector_, Rotation_3 * _vector_ );

    return reasult;
}


void VF::getEuler(const sensor_msgs::Imu msg, double& yaw, double& pitch, double& roll){
    std::cout << "3D vf 四元数转欧拉角" << std::endl;
	float q[4];

    q[0] = msg.orientation.w;
    q[1] = msg.orientation.x;
    q[2] = msg.orientation.y;
    q[3] = msg.orientation.z;

    quaternion_2_euler(q, att_angle_Euler);         // get euler radiance
    
    roll = att_angle_Euler[0];
    pitch = -att_angle_Euler[1];

    if (att_angle_Euler[2] + deg_2_rad(90.0) > 0)
        yaw = att_angle_Euler[2] + deg_2_rad(90.0); //添加符号使增加方向相同，而且领先于px490°
    else
        yaw = att_angle_Euler[2] + deg_2_rad(90.0) + deg_2_rad(360.0);
}

/***************************************SL VF Estimator START***********************************************/
// T时刻的 计算 k2_hat
// sat 是调用 sat函数的返回值
// Va 是空速度
double VF::cal_sl_K2_hat(
    double chi_tilde, double Gamma, double rho, double epy, double Heading, double chi_q, double va
)
    {

    double b = 0;

    //2 options estimoator of SL Adaptive Law1
    #if defined(adp1_OPTION_1)
        b = Gamma * rho * k_sl * chi_infinite / pow(distanceThreshold,k) * sin(Heading) * chi_tilde;
        b = Gamma * rho * k_sl * chi_infinite / pow(distanceThreshold,k) * sin(Heading - chi_q) * chi_tilde;

    #elif defined(adp1_OPTION_2)
        b = Gamma * rho * abs(chi_tilde);


    // the Estimotor of SL Adaptibe Law2
    #elif defined(AdaptiveLaw2)
        std::cout<<"Apativelaw2_k2_hat"<<std::endl;
        b = -Gamma * chi_tilde * k_sl * chi_infinite/(pow(distanceThreshold,k)) * pow(epy, k-1) * sin(chi_MAVHeading - chi_q);
    #else  
        cout << " NULL " << endl;
    #endif 
    
    double k_ = zeta2;

    // double k_hat_dot = b - k_ * k2_hat_previous + k2_hat_LastItem;
    double k2_hat_dot = b - k_ * k2_hat_previous;

    double k2_hat_new = k2_hat_previous + STEP * k2_hat_dot;

    if(k2_hat_new < Lowlimit_2)
        k2_hat_new = Lowlimit_2;
    else if(k2_hat_new > Upperlimit_2)
        k2_hat_new = Upperlimit_2;

    // 更新前一个的值
    k2_hat_previous = k2_hat_new;
    return k2_hat_new;
}
/***********************************SL VF Estimator END***********************************************/

// sat(x)
double VF::satFunction(double x){
    if(abs(x) < 1)
        return x;
    return x > 0 ? 1 : -1;
}



/***********************************Orbit VF Estimator Start***********************************************/
double VF::cal_o_k2_hat(
    double gamma, double radius, double distance, double chi, double dir, double Gamma, double d_tilde, double chi_tilde
)
{
    double b = 0;
    //the Estimoator of Orbit Adaptive Law1
    #if defined(AdaptiveLaw1)
        b = -Gamma * (sin(chi-gamma)/distance + k_o*M_PI*pow(d_tilde,k-1)*cos(chi-gamma)/(3*pow(radius,k)));

    //the Estimoator of Orbit Adaptive Law2    
    #elif defined(AdaptiveLaw2)
        if(distance > 2*radius)
        {
            b = Gamma * chi_tilde * sin(chi - gamma);
        }else{
            // b = gamma * chi_tilde (-(sin(chi-gamma)/d - dir(k_o* M_PI/(3*(pow(radius,k)))*pow(d_tilde,k-1)*cos(chi - gamma))));    
            // 改动
            b = Gamma * chi_tilde * (-(sin(chi-gamma)/distance - dir * (k_o* M_PI/(3*(pow(radius,k)))*pow(d_tilde,k-1)*cos(chi - gamma))));    
        }
        
    #endif
    double k_ = zeta2;
    double k2_hat_dot = b - k_ * k2_hat_previous_O;

    double k2_hat_new = k2_hat_previous_O + STEP * k2_hat_dot;

    if(k2_hat_new < Lowlimit_O_2)
        k2_hat_new = Lowlimit_O_2;
    else if(k2_hat_new > Upperlimit_O_2)
        k2_hat_new = Upperlimit_O_2;

    // 更新前一个的值
    k2_hat_previous_O = k2_hat_new;
    return k2_hat_new;
}
/***********************************Orbit VF Estimator END***********************************************/


/**
 * It returns the new heading in radians based on the VF 
 * */
/*************************************SL VF START***************************************************/

// 计算三维的 中间量
// 计算三维的距离误差    double& horizontalDistance, double& verticalDistance
void VF::getErrorXYZ(
    Three_Dimensional_Vector P, Three_Dimensional_Vector Start, Three_Dimensional_Vector End,   
    double& horizontalDistance, double& verticalDistance
){
    std::cout << "计算三维误差" << std::endl;

    // 1. 计算在当前航线的投影点
    double length_to_start = (End - Start) * (P - Start) / (End - Start).len();
    std::cout << "在当前航线上的投影距离起始长度的距离： " << length_to_start << std::endl;
    Three_Dimensional_Vector p_project = (End - Start).normalized() * length_to_start;      // 起始点为 Start 航点
    p_project = Start + p_project;                                                          // 起始点为 Home 点
    std::cout << "在当前航线上的投影点： "; p_project.print_vec();

    // 2. 计算距离向量
    // 差别的距离 大于0 ， 表明是在期望位置点的下面
    Three_Dimensional_Vector error = p_project - P;
    std::cout << "当前位置的距离误差向量： "; error.print_vec();

    // 3. 得到 两个平面的距离误差(水平方向是垂直误差，垂直方向是距离误差)
    horizontalDistance = sqrt(pow(error.getX(),2) + pow(error.getY(), 2));
    verticalDistance = error.getZ();
    std::cout << "水平距离误差(绝对值): \t" << horizontalDistance << std::endl;
    std::cout << "垂直距离误差(带有正负号): \t" << verticalDistance << std::endl;
}
// 计算三维中的水平平面和垂直平面 位于的哪一侧
void VF::getMAV_side(
    Three_Dimensional_Vector P, Three_Dimensional_Vector Start, Three_Dimensional_Vector End, 
    double& horizontalSide, double& verticalSide
){
    std::cout << "计算三维位于哪一侧" << std::endl;
    // 计算 水平面位于哪一侧
    Point W_i(Start.getX(), Start.getY());
    Point W_i_plus_1(End.getX(), End.getY());
    Point position(P.getX(), P.getY());

    horizontalSide = (((W_i_plus_1.x - W_i.x) * (position.y - W_i.y)) - ((W_i_plus_1.y - W_i.y) * (position.x - W_i.x))) >= 0 ? 1 : -1; 
    std::cout << "水平面：当前位置位于期望航线的；" ;
    horizontalSide > 0 ? std::cout << "上方" : std::cout << "下方";
    std::cout << std::endl;

    // 计算 垂直平面内位于哪一侧
    W_i.update(Start.getX(), Start.getZ());
    W_i_plus_1.update(End.getX(), End.getZ());
    position.update(P.getX(), P.getZ());

    verticalSide = (((W_i_plus_1.x - W_i.x) * (position.y - W_i.y)) - ((W_i_plus_1.y - W_i.y) * (position.x - W_i.x))) >= 0 ? 1 : -1;   
    std::cout << "垂直面：当前位置位于期望航线的；" ;
    verticalSide > 0 ? std::cout << "上方" : std::cout << "下方";
    std::cout << std::endl;
}

double VF::getHeading(
    Point Z, Point Start, Point End, 
    double S_groundSpeed, double chi_MAVHeading, double chi_MAVTheta, 
    double airspeed, const double horizontalDistance, const double horizontalSide
)
{
    // 打印输出　各种角度
    //　相同航线的时候　chi_c, chi_d
    // heading 是角度还是弧度
    // chi_f 的方向
    std::cout<<"SL VF"<<std::endl; 
    cout << "chi_MAVHeading: " << chi_MAVHeading << endl;
    //  // The angle between start and end point: 航线的方向
    double chi_f = atan2(End.y - Start.y, End.x - Start.x); 
    if(EN_DEBUG) std::cout<<"chi_f:\n"<<chi_f<<std::endl;

    /* >>>>>>>>>>>>>>>>>>>>>>>>>>>> 计算 epsilon begin <<<<<<<<<<<<<<<<<<<<<<<<<<<*/
    // //Projection of the point Z on the line start-end
    // 当前位置在期望航线上的投影点距离起始点的长度
    // double Z_proj = ((Z.x - Start.x) * (End.x - Start.x) + (Z.y - Start.y) * (End.y - Start.y)) 
    //     / (pow(End.y - Start.y, 2) + pow(End.x - Start.x, 2)); 

    // Distance of the point Z from the line start-end
    // 当前位置到期望航线的距离
    // double epsilon = sqrt(
    //     pow((Z.x - (Z_proj * (End.x - Start.x) + Start.x)),2) + 
    //     pow((Z.y - (Z_proj * (End.y - Start.y) + Start.y)),2)
    // ); 
    // std::cout << "二维距离偏差：" << epsilon << std::endl;  
    double epsilon = horizontalDistance;         
    // 算当、前位置为航线的哪一侧
    // int MAV_side = (((End.x - Start.x) * (Z.y - Start.y)) - ((End.y - Start.y) * (Z.x - Start.x))) >= 0 ? 1 : -1;  
    int MAV_side = horizontalSide;
    epsilon = ((double)MAV_side) * epsilon;
 

    //VF heading
    double chi_d = 0;
           
    //MAV commanded heading
    double chi_c =  0;   
    double k2_hat = 0;

    // 飞机到当前航线的距离大于 距离的阈值
    if (abs(epsilon) > distanceThreshold)
    {
        chi_d = chi_f - MAV_side * (chi_infinite);
        chi_c = chi_d;
    }
    else if (epsilon == 0)
    {
        chi_d = chi_f - chi_infinite * pow((epsilon / distanceThreshold), k);
        chi_c = chi_d;
    }
    else
    {
        chi_d = chi_f - chi_infinite * pow((epsilon / distanceThreshold), k);

    #if defined(AdaptiveLaw1)
        
        std::cout<<"SL AdaptiveLaw1 VF"<<std::endl;
        double chi_tilde = chi_MAVHeading - chi_d;
        logPrint("chi_tilde", chi_tilde);
        double Gamma = 0.5;
        double rho = pow(50.0/M_PI,2);
        k2_hat = cal_sl_K2_hat(chi_tilde, Gamma, rho, epsilon, chi_MAVHeading, chi_f,  airspeed);  // Y    
        logPrint("k2_hat", k2_hat);
        // chi_c = chi_d - (k * chi_infinite/pow(distanceThreshold,k) * k2_hat * pow(epsilon, k-1) * sin(chi_MAVHeading - chi_f));
        // 改动： 
        chi_c = chi_d - (k_sl * chi_infinite/pow(distanceThreshold,k) * k2_hat * pow(epsilon, k_sl-1) * sin(chi_MAVHeading - chi_f));

    #elif defined(AdaptiveLaw2)
        
        std::cout<<"SL AdaptiveLaw2 VF"<<std::endl;
        double chi_tilde = chi_d - chi_MAVHeading;
        logPrint("chi_tilde", chi_tilde);
        //double Beta_sl = (k_sl / (1 + pow(k_sl * epsilon, 2)));
        double Gamma = 0.5;
        double rho = pow(50.0/M_PI,2);
        k2_hat = cal_sl_K2_hat(chi_tilde, Gamma, rho, epsilon, chi_MAVHeading, chi_f, airspeed);  
        chi_c = chi_d + (k * chi_infinite/pow(distanceThreshold,k) * k2_hat * pow(epsilon, k-1) * sin(chi_MAVHeading - chi_f));
        /* <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<< END >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>> */
    #else
        std::cout<<"SL Standard VF"<<std::endl;
        chi_c = chi_d - (k * chi_infinite * S_groundSpeed / (alpha * pow(distanceThreshold, k))) * pow(epsilon, (k - 1)) * cos(chi_MAVTheta) * sin(chi_MAVHeading);
    #endif
    }

    if(EN_DEBUG) std::cout<<"chi_d:\n"<<chi_d<<std::endl;
    if(EN_DEBUG) std::cout<<"chi_c:\n"<<chi_c<<std::endl;

    return chi_c;

}

/*****************************************SL VF END***********************************************/

// Yaw = vectorField.getHeading(
// 		currentPosition,
// 		wayPointStart,
// 		wayPointEnd,
// 		M_PI/100.0, 
// 		current_vfr_hud.heading * (M_PI / 180.0),
// 		current_vfr_hud.airspeed
// 	)-(M_PI/2.0); // chi_c
/**
 * 输入:
 *      当前位置 P(x, z)
 *      开始航点的坐标值 Start(x, z)
 *      最后航点的坐标值 End(x, z)
 *      当前无人机的地速度 S_groundSpeed
 *      当前无人机 Theta 角度(欧拉角) theta_MAV
*/
double VF::getPitch(
    Three_Dimensional_Vector P, Three_Dimensional_Vector Start, Three_Dimensional_Vector End,   
    double S_groundSpeed, double theta_MAV, double psi_MAV
    , const double verticalDistance, const double verticalSide
){

#ifndef NEW_PITCH_CONTROLLER
    std::cout<<"SL VF getPitch"<<std::endl; 

    cout << "当前的pitch角度(欧拉角): " << theta_MAV << endl;
    
    cout << "Start: ";      Start.print_vec();
    cout << "P: ";          P.print_vec();
    cout << "End: ";        End.print_vec();
    cout << "S_groundSpeed: " << S_groundSpeed << endl; 
    
    double theta_f = atan2(
        End.getZ() - Start.getZ(), 
        sqrt(pow(End.getX() - Start.getX(),2) + pow(End.getY() - Start.getY(),2))
    ); 
    std::cout<< "迎角: theta_f: " << theta_f <<std::endl;      // 期望角度

    
    // 当前位置在期望航线上的投影点距离起始点的长度
    // double P_proj = ((P.getX() - Start.getX()) * (End.getX() - Start.getX()) + (P.getZ() - Start.getZ()) * (End.getZ() - Start.getZ())) / (pow(End.getZ() - Start.getZ(), 2) + pow(End.getX() - Start.getX(), 2)); 

    // 当前位置到期望航线所在平面的垂直距离
    // double epsilon = sqrt(
    //     pow((P.getX() - (P_proj * (End.getX() - Start.getX()) + Start.getX())),2) + 
    //     pow((P.getZ() - (P_proj * (End.getZ() - Start.getZ()) + Start.getZ())),2)
    // );             
    // std::cout << "垂直距离: epsilon:  " << epsilon << std::endl;
    double epsilon = verticalDistance;
    // 算当前位置为航线的哪一侧
    // int MAV_side = (((End.getX() - Start.getX()) * (P.getZ() - Start.getZ())) - ((End.getZ() - Start.getZ()) * (P.getX() - Start.getX()))) >= 0 ? 1 : -1;  
    int MAV_side = verticalSide;
    std::cout << "位于航线的一侧: MAV_side:  " << MAV_side << std::endl;
    
    epsilon = ((double)MAV_side) * epsilon;
    std::cout << "叠加正负号的 epsilon:  " << epsilon << std::endl;
  
    // 向量场中的矢量方向
    double theta_d = 0;
           
    //MAV commanded theta
    double theta_c =  0;   
    std::cout << "abs(epsilon): " << abs(epsilon) << std::endl;
    std::cout << "height_distanceThreshold: " << height_distanceThreshold << std::endl;

    // 飞机到当前航线的距离大于 距离的阈值
    if (abs(epsilon) > height_distanceThreshold)
    {
        std::cout << "进入航线的垂直距离 大于 距离阈值分支! " << std::endl;
        theta_d = theta_f - MAV_side * (height_theta_infinite);
        theta_c = theta_d;
    }
    else if (epsilon == 0)
    {
        std::cout << "进入航线的垂直距离 等于 距离阈值分支! " << std::endl;
        theta_d = theta_f - height_theta_infinite * pow((epsilon / height_distanceThreshold), k_pitch);
        theta_c = theta_d;
    }
    else
    {   // alpha_pitch: 
        // k_pitch: 决定了 收敛的速度
        theta_d = theta_f - height_theta_infinite * pow((epsilon / distanceThreshold), k_pitch);
        
        theta_c = theta_d - (k_pitch * height_theta_infinite * S_groundSpeed / (alpha_pitch * pow(height_distanceThreshold, k_pitch))) * pow(epsilon, (k_pitch - 1)) * sin(theta_MAV);
    }
    std::cout<<"theta_d: "<<theta_d<<std::endl;
    std::cout<<"theta_c: "<<theta_c<<std::endl;
    return -1.0f * theta_c;

#else 
    
    std::cout << "3D vf 控制核心逻辑执行" << std::endl;


    cout << "Start: ";      Start.print_vec();
    cout << "P: ";          P.print_vec();
    cout << "End: ";        End.print_vec();

    Three_Dimensional_Vector current_waypoint(End);
    Three_Dimensional_Vector previous_waypoint(Start);
    Three_Dimensional_Vector local_position(P);
    current_waypoint.update(End.getY(), End.getX(), -End.getZ());
    previous_waypoint.update(Start.getY(), Start.getX(), -Start.getZ());
    local_position.update(P.getY(), P.getX(), -P.getZ());

    cout << "变量定义之后>>(ENU TO NED): " << endl;
    cout << "Start: ";      previous_waypoint.print_vec();
    cout << "P: ";          local_position.print_vec();
    cout << "End: ";        current_waypoint.print_vec();
    cout << "S_groundSpeed: " << S_groundSpeed << endl; 

    // 1. 角度转换, 变量赋值
    course_alpha = atan2(
        current_waypoint.getY() - previous_waypoint.getY(),
        current_waypoint.getX() - previous_waypoint.getX()
    );
    cout << "course_alpha: " << course_alpha << endl;
    setRotation_Z(-1.0f * course_alpha);
    cout << "printRotation: " << endl; printRotation();

    Previous_Waypoint_R = Rotation_multiplied_vector(previous_waypoint);
    Current_Waypoint_R  = Rotation_multiplied_vector(current_waypoint);

    course_beta = atan2(
        Current_Waypoint_R.getZ() - Previous_Waypoint_R.getZ(),
        sqrt(
            pow(Current_Waypoint_R.getX() - Previous_Waypoint_R.getX(), 2) + 
            pow(Current_Waypoint_R.getY() - Previous_Waypoint_R.getY(), 2)
        )
    );
    std::cout << "course_beta : " << course_beta << std::endl;

    Three_Dimensional_Vector error_enu; // enu坐标系下的 当前位置和 previous 航点的矢量误差
    error_enu = (local_position - previous_waypoint);

    setRotation_Z(-1.0f * course_alpha);
    _error_ = Rotation_multiplied_vector(error_enu);
    setRotation_Y_(course_beta);
    _error_ = Rotation_multiplied_vector(_error_);

    // double psi_R = psi_MAV - course_alpha;
    double theta_R = theta_MAV - course_beta;
    
    // double tilde_chi_psi;   // VF 定义的期望角速度; XY 平面
    double tilde_chi_theta;   // VF 定义的期望角速度; XZ 平面
    
    // 2. 控制律计算
    // tilde_chi_psi = psi_R - (-chi_psi_inf * 2 / M_PI * atan(s_psi * _error_.getY()));
    tilde_chi_theta = theta_R - (-chi_theta_inf * 2 / M_PI * atan(s_theta * _error_.getY()));

    double v = S_groundSpeed;

    // double psi_d = 
    //     psi_R - 
    //     chi_psi_inf / k_psi * 2 / M_PI * (s_psi * v * sin(psi_MAV)) / (1 - pow(s_psi * _error_.getY(), 2)) - 
    //     kappa_psi / k_psi * sat(tilde_chi_psi / epsilon_psi);
    
    double theta_d = 
        theta_R - 
        chi_theta_inf / k_theta * 2 / M_PI * (s_theta * v * sin(theta_MAV)) / (1 + pow(s_theta * _error_.getY(), 2)) - 
        kappa_theta / k_theta * sat(tilde_chi_theta / epsilon_theta);
    
    // psi_d = psi_d + course_alpha;
    theta_d = theta_d + course_beta;

    // r_d = k_psi * (psi_d - psi_MAV);
    // q_d = k_theta * (theta_d - theta_MAV);

    return theta_d; // 返回 期望值
#endif

}

/**************************************Orbit VF START***********************************************/
    // 盘旋VF。   dir: 盘旋的方向      ==> 1.0 : 正; -1.0 : 逆
    double VF::getHeadingOrbit(
        Point Z, Point Center, 
        double radius, double groundSpeed, double chi_MAVHeading,
        float dir, double airspeed
    ){
        std::cout<<"Orbit VF"<<std::endl;        
        double gamma = atan2(Z.y - Center.y, Z.x - Center.x);                                                                                            // The angle between start and end point
        if(EN_DEBUG) std::cout<<"gamma:\n"<<gamma<<std::endl;
        double distance = Point::norm(Z-Center);
    
        if(EN_DEBUG) std::cout<<"gamma:\n"<<gamma<<std::endl;
        double k2_hat = 0;


        //VF heading
        double chi_d = 0;                                                                                                                                  
        double chi_c =  0;   
        double chi_tilde = 0;
        double d_tilde = distance - radius;// 当前位置到圆心的距离 - 半径
        double Gamma = 0.5;
        double rho = pow(50.0/M_PI,2);
        double epsilon = 0;

        if(distance > 2*radius){
            // 改动：修改了 宏定义的判断方式
            #if defined(AdaptiveLaw2)
                std::cout << "the distance > 2 * radius, so no dir" <<std::endl;
                std::cout<<"Orbit AdaptiveLaw2 VF"<<std::endl;
                /*calculate chi_d*/
                chi_d = gamma - 5.0*M_PI/6.0;

                chi_tilde = chi_d - chi_MAVHeading; // 当前的和航向角 - gamma 
                
                /*Estimetor K2_hat*/
                k2_hat = cal_o_k2_hat(gamma, radius, distance, chi_MAVHeading, dir, Gamma, d_tilde, chi_tilde);
                
                /*calculate chi_c*/
                chi_c = chi_d + k2_hat *sin(chi_MAVHeading-gamma)/distance;
            
            #else
                std::cout << "the distance > 2 * radius, so no dir" <<std::endl;
                std::cout<<"Orbit Starndard VF"<<std::endl;
                /*calculate chi_d*/
                chi_d = gamma - 5.0*M_PI/6.0;
                /*calculate chi_c*/
                chi_c = chi_d + (groundSpeed/distance) * sin(chi_MAVHeading-gamma);

            #endif

        }else
        {                            
            #if defined(AdaptiveLaw1)
                std::cout<<"Orbit AdaptiveLaw1 VF"<<std::endl;

                double chi_tilde = chi_MAVHeading - chi_d;
                logPrint("chi_tilde", chi_tilde);

                std::cout << "dir = " << dir << std::endl;
                chi_d = gamma - dir * ((M_PI/2.0) + (M_PI/3)* pow(((distance-radius)/radius),k));
 
                k2_hat = cal_o_k2_hat(gamma, radius, distance, chi_MAVHeading, dir, Gamma, d_tilde, chi_tilde);  // Y    
                logPrint("k2_hat", k2_hat);
                chi_c = chi_d - 
                        k2_hat*(sin(chi_MAVHeading - gamma)  - 
                        ((k*M_PI)/(3*(pow(radius,k))))*((d_tilde),k-1)*cos(chi_MAVHeading - gamma));

            #elif defined(AdaptiveLaw2)
                std::cout<<"Orbit AdaptiveLaw2 VF"<<std::endl;
                
                double chi_tilde = chi_d - chi_MAVHeading;
                logPrint("chi_tilde", chi_tilde);

                std::cout << "dir = " << dir << std::endl;
                chi_d = gamma - dir * ((M_PI/2.0) + (M_PI/3)* pow(((distance-radius)/radius),k));
                
                k2_hat = cal_o_k2_hat(gamma, radius, distance, chi_MAVHeading, dir, Gamma, d_tilde, chi_tilde); 
                logPrint("k2_hat", k2_hat);
                chi_c = chi_d - 
                        k2_hat*(sin(chi_MAVHeading - gamma)/distance  - 
                        ((k*M_PI)/(3*(pow(radius,k))))*((d_tilde),k-1)*cos(chi_MAVHeading - gamma));

                
            #else
                std::cout<<"Orbit Starndard VF"<<std::endl;
                std::cout << "dir = " << dir << std::endl;

                chi_d = gamma - dir * ((M_PI/2.0) + (M_PI/3)* pow(((distance-radius)/radius),k));
                // chi_d = gamma - (M_PI/2.0) - (M_PI/3)* pow(((distance-radius)/radius),k);
                chi_c = chi_d - 
                        ((groundSpeed/(alphaOrbit*distance))*sin(chi_MAVHeading - gamma)) - 
                    ((k*groundSpeed*M_PI)/(3*(pow(radius,k))*alphaOrbit))*((d_tilde),k-1)*cos(chi_MAVHeading - gamma);
                    //((k*groundSpeed*M_PI)/(3*(pow(radius,k))*alphaOrbit))*((distance-2*radius),k-1)*cos(chi_MAVHeading - gamma);
            #endif
        }
        /* <<<<<<<<<<<<<<<<<<<<<<< 赋值 begin >>>>>>>>>>>>>>>>>>>>>>>  */ 
        // com1.d_tilde = d_tilde;
        // com1.distance = distance;
        // com1.epy = epsilon;
        /* <<<<<<<<<<<<<<<<<<<<<<<  赋值 end  >>>>>>>>>>>>>>>>>>>>>>>  */ 

        // // 发布
        // publishCom();
        return chi_c;
    }
/***********************************Orbit VF END***********************************************/

/**
 * This function returns a value from 0 to 1, where 0 means that the UAV is at the beginning of the path
 * and 1 means that the uav is over the line
 * */

double VF::getPositionOnLine(Point Z, Point Start, Point End){
    double chi_f = atan2(End.y - Start.y, End.x - Start.x);                                                                                            // The angle between start and end point
    if(EN_DEBUG) std::cout<<"chi_f:\n"<<chi_f<<std::endl;

    double Z_proj = ((Z.x - Start.x) * (End.x - Start.x) + (Z.y - Start.y) * (End.y - Start.y)) / (pow(End.y - Start.y, 2) + pow(End.x - Start.x, 2)); //Projection of the point Z on the line start-end
    if(EN_DEBUG) std::cout<<"Z_proj:\n"<<Z_proj<<std::endl;

    return Z_proj;
}

// 书上的 公式 10.8
double VF::getHeading_10_8(Point Z, Point Start, Point End, double S_groundSpeed, double chi_MAVHeading, double airspeed){
    double chi_c =  0;  
    
    // 变量声明
    double chi_q = 0;
    double K_path = 0.2; // 越大， 代表接近航线的速度越快
    double err_py = 0;

    // 1. 计算 chi_q : 航线的航向  q_e, q_n 航线的方向的 n 和 e
    Point waypoints_direction = (End - Start).normalized();
    chi_q = atan2(waypoints_direction.x, waypoints_direction.y); // 加上 m 个 2*M_PI 目的是使得 chi_q - chi 在 （-M_PI ~ M_PI)
    while(chi_q - chi_MAVHeading >= M_PI || chi_q - chi_MAVHeading <= -M_PI){
        chi_q += 2 * M_PI;
    }
    
    // 2. 计算 err_py
    err_py = (-sin(chi_q) * (Z.x - Start.x) + cos(chi_q) * (Z.y - Start.y));

    // 3. 计算 chi_c
    chi_c = chi_q - chi_infinite * (2.0 / M_PI) * atanf(K_path * err_py);

    return chi_c;
}   
