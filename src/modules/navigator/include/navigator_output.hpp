#define NAVIGATOR(a) \
    std::cout << "[NAVIGATOR]\t" << a << std::endl
#define NAVIGATOR_DOUBLE(a, b) \
    std::cout << "[NAVIGATOR]\t" << a << b << std::endl
#define NAVIGATOR_TRIPLE(a, b) \
    std::cout << "[NAVIGATOR]\t" << a << b << c << std::endl
#define NAVIGATOR_ERROR(a) \
    ROS_ERROR(a)