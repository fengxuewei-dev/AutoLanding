#define POSITIONCONTROLLER(a) \
    cout << "[POSITIONCONTROLLER]\t" << a << endl
#define POSITIONCONTROLLER_DOUBLE(a, b) \
    cout << "[POSITIONCONTROLLER]\t" << a << b << endl
#define POSITIONCONTROLLER_TRIPLE(a, b) \
    cout << "[POSITIONCONTROLLER]\t" << a << b << c << endl
#define POSITIONCONTROLLER_ERROR(a) \
    ROS_ERROR(a)