/**
 * 将经纬度差转换为距离
*/
#pragma once

#include <math.h>
#include <iostream>
using namespace std;

// 俯仰角: 10deg 拉飘高度: 8m 虚拟水平线 10m
// land wp 和 approach wp 之间的最小距离
#define MIN_DISTANCE_BET_WPS    (118.497+6)
#define DIST_BET_WPS            250

// static double getDistance(double lon1, double lat1, double lon2, double lat2);
// point getDestPoint(point lonlat, double brng, int dist);
// // https://blog.csdn.net/chiguyue2107/article/details/100795938
// double getBearing(double lat_a, double lng_a, double lat_b, double lng_b);

#ifndef PI
#define PI 3.141592657
#endif

#define EARTH_RADIUS 6378137

struct point{
    double lon;
    double lat;
};
// 将角度转换为弧度
static inline double rad( double degree ){    return  PI * degree / 180.0; }
// 将弧度转化为角度
static inline double deg( double radian ){    return radian * 180.0 / PI;}
static inline double haverSin(double x){    double v = sin(x / 2.0);    return v * v;}
// 计算距离(单位 : m)
double getDistance(double lon1, double lat1, double lon2, double lat2);

struct point getDestPoint(struct point lonlat, double brng, int dist);
// 计算两个航点之间的方位角
double getBearing(double lat_a, double lng_a, double lat_b, double lng_b);
// 计算航点的夹角
/**
 * @param approachWP_alt: 开始降落航点的高度
 * @param Offset: 允许的距离误差, 默认为 50m
 * @param FW_LND_ANG: 降落的俯冲角度, 默认为 10度
 * 
 * @return land 航点和 approach 航点 连线和水平方向的夹角( < 90 )
*/
double CalculationAngle(double approachWP_alt, double Offset, double FW_LND_ANG);
// 计算 斜线长度
double CalculationDis(double approachWP_alt, double Offset, double FW_LND_ANG);