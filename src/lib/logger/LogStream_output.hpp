#define LOGGERPUBPRE \
    cout << "[LOGGERSTREAM]\t" 

#define LOGGERSTREAM(a) \
    LOGGERPUBPRE << a << endl
#define LOGGERSTREAM_DOUBLE(a, b) \
    LOGGERPUBPRE << a << b << endl
#define LOGGERSTREAM_TRIPLE(a, b, c) \
    LOGGERPUBPRE << a << b << c << endl
#define LOGGERSTREAM_ERROR(a) \
    ROS_ERROR(a)
#define LOGGERSTREAME_INFO \
    (LOGGERPUBPRE, printf)
