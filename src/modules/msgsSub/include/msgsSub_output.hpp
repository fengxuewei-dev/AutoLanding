#define MSGSSUBANDPUBPRE \
    cout << "[MSGSSUBADNPUB]\t[" << string(__TIME__) << "]\t"

#define MSGSSUBADNPUB(a) \
    MSGSSUBANDPUBPRE << a << endl
#define MSGSSUBADNPUB_DOUBLE(a, b) \
    MSGSSUBANDPUBPRE << a << b << endl
#define MSGSSUBADNPUB_TRIPLE(a, b, c) \
    MSGSSUBANDPUBPRE << a << b << c << endl
#define MSGSSUBADNPUB_ERROR(a) \
    ROS_ERROR(a)
#define MSGSSUBANDPUB_INFO \
    (MSGSSUBANDPUBPRE, printf)

// #define MSGSSUBANDPUB_INFO \
//     (printf("%s:%u %s:%s:\t", __FILE__, __LINE__, __DATE__, __TIME__), printf)
// /home/fengxuewei/GitHub/uav_project_1/fixedWing_ws/src/modules/msgsSub/include/SubAndPub.cpp:158 Jul 29 2020:12:18:52:	gps:x_lat = 47.395889 y_long = 8.540304 z_alt = 20.000000 
