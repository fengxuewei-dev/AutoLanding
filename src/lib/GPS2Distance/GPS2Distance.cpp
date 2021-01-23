#include "GPS2Distance.hpp"

// 计算距离(单位 : m)
double getDistance(double lon1, double lat1, double lon2, double lat2)
{
    // 转化为弧度
    double radlon1 = rad(lon1);
    double radlat1 = rad(lat1);
    double radlon2 = rad(lon2);
    double radlat2 = rad(lat2);
    
    // 绝对值
    double a = fabs(radlat1 - radlat2);
    double b = fabs(radlon1 - radlon2);
    
    double h = haverSin(b) + cos(lat1)*cos(lat2)*haverSin(a);
    double distance = 2 * EARTH_RADIUS * asin(sqrt(h));
    return  distance;
}

struct point getDestPoint(struct point lonlat, double brng, int dist) {
    
    long int a = 6378137;
    double b = 6356752.3142, f = 1/298.257223563;

    double lon1 = lonlat.lon;
    double lat1 = lonlat.lat;

    int s = dist;
    double alpha1 = rad(brng);
    double sinAlpha1 = sin(alpha1);
    double cosAlpha1 = cos(alpha1);

    double tanU1 = (1-f) * tan(rad(lat1));
    double cosU1 = 1.0 / sqrt((1 + tanU1*tanU1)), sinU1 = tanU1*cosU1;
    double sigma1 = atan2(tanU1, cosAlpha1);
    double sinAlpha = cosU1 * sinAlpha1;
    double cosSqAlpha = 1 - sinAlpha*sinAlpha;
    double uSq = cosSqAlpha * (a*a - b*b) * 1.0 / (b*b);
    double A = 1 + uSq * 1.0 /16384*(4096+uSq*(-768+uSq*(320-175*uSq)));
    double B = uSq * 1.0 /1024 * (256+uSq*(-128+uSq*(74-47*uSq)));

    double sigma = s / (b*A), sigmaP = 2*PI;
    double cos2SigmaM; 
    double sinSigma; 
    double cosSigma; 
    double deltaSigma; 

    while (fabs(sigma-sigmaP) > 1e-12) {
        cos2SigmaM = cos(2*sigma1 + sigma);
        sinSigma = sin(sigma);
        cosSigma = cos(sigma);
        deltaSigma = B*sinSigma*(cos2SigmaM+B * 1.0/4*(cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)-
                B * 1.0/6*cos2SigmaM*(-3+4*sinSigma*sinSigma)*(-3+4*cos2SigmaM*cos2SigmaM)));
        sigmaP = sigma;
        sigma = s * 1.0 / (b * A) + deltaSigma;
    }

    double tmp = sinU1 * sinSigma - cosU1 * cosSigma * cosAlpha1;
    double lat2 = atan2(sinU1*cosSigma + cosU1*sinSigma*cosAlpha1, (1-f)*sqrt(sinAlpha*sinAlpha + tmp*tmp));
    double lambda = atan2(sinSigma*sinAlpha1, cosU1*cosSigma - sinU1*sinSigma*cosAlpha1);
    double C = f * 1.0/16*cosSqAlpha*(4+f*(4-3*cosSqAlpha));
    double L = lambda - (1-C) * f * sinAlpha * (sigma + C*sinSigma*(cos2SigmaM+C*cosSigma*(-1+2*cos2SigmaM*cos2SigmaM)));

    double revAz = atan2(sinAlpha, -tmp);  // final bearing
    
    point DestPoint{lon1 + deg(L), deg(lat2)};

    // return new OpenLayers.LonLat(lon1+deg(L), deg(lat2));
    return DestPoint;
}
// 计算两个航点之间的方位角
double getBearing(double lat_a, double lng_a, double lat_b, double lng_b) {

       double d = 0;

       lat_a=rad(lat_a);
       lng_a=rad(lng_a);

       lat_b=rad(lat_b);
       lng_b=rad(lng_b);
      
       d = sin(lat_a) * sin(lat_b) + cos(lat_a) * cos(lat_b) * cos(lng_b-lng_a);

       d = sqrt(1-d*d);

       d = cos(lat_b) * sin(lng_b-lng_a)/d;

       d = asin(d)*180 / PI;

       // 返回的是角度
       return d;
}
// 计算航点的夹角
/**
 * @param approachWP_alt: 开始降落航点的高度
 * @param Offset: 允许的距离误差, 默认为 50m
 * @param FW_LND_ANG: 降落的俯冲角度, 默认为 10度
 * 
 * @return land 航点和 approach 航点 连线和水平方向的夹角( < 90 )
*/
// 既可以在类的声明中，也可以在函数定义中声明缺省参数，但不能既在类声明中又在函数定义中同时声明缺省参数。
double CalculationAngle(double approachWP_alt, double Offset = 50.0, double FW_LND_ANG = 10){
    // double H = 50.0; // approach wp's alt
    double X = approachWP_alt / tan(FW_LND_ANG) + 50;

    return atan2(approachWP_alt, X);
}
// 计算 斜线长度
double CalculationDis(double approachWP_alt, double Offset = 50.0, double FW_LND_ANG = 10){
// double CalculationDis(double approachWP_alt, double Offset = 50.0, double FW_LND_ANG = 10){
    // double H = 50.0; // approach wp's alt
    double X = approachWP_alt / tan(FW_LND_ANG) + 50;

    return sqrt(approachWP_alt * approachWP_alt + X * X);
}