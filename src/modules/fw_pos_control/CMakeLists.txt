cmake_minimum_required(VERSION 2.8.3)
project(fw_pos_control)

## Compile as C++11, supported in ROS Kinetic and newer
# add_compile_options(-std=c++11)

## Find catkin macros and libraries
## if COMPONENTS list like find_package(catkin REQUIRED COMPONENTS xyz)
## is used, also find other catkin packages
find_package(catkin REQUIRED COMPONENTS
fw_msgs
  geometry_msgs
  roscpp
  rospy
  std_msgs
  tf2_eigen
  tf2_ros
  mavros    # solve the  "undefined reference to `mavros::ftf::detail::transform_static_frame(Eigen::Matrix<double" problem
)


# 寻找 GeographicLib 的库
list(INSERT CMAKE_MODULE_PATH 0 "${CMAKE_CURRENT_SOURCE_DIR}/../../../cmake")
find_package(GeographicLib REQUIRED)

find_package(Eigen3)

# 设定编译动态链接库的存放路径
SET(CMAKE_LIBRARY_OUTPUT_DIRECTORY ${CMAKE_SOURCE_DIR}/../../bin)

set(LINK_LIB "${CMAKE_SOURCE_DIR}/../../bin")
link_directories(${LINK_LIB})

## System dependencies are found with CMake's conventions
# find_package(Boost REQUIRED COMPONENTS system)


## Uncomment this if the package has a setup.py. This macro ensures
## modules and global scripts declared therein get installed
## See http://ros.org/doc/api/catkin/html/user_guide/setup_dot_py.html
# catkin_python_setup()

################################################
## Declare ROS messages, services and actions ##
################################################

## To declare and build messages, services or actions from within this
## package, follow these steps:
## * Let MSG_DEP_SET be the set of packages whose message types you use in
##   your messages/services/actions (e.g. std_msgs, actionlib_msgs, ...).
## * In the file package.xml:
##   * add a build_depend tag for "message_generation"
##   * add a build_depend and a exec_depend tag for each package in MSG_DEP_SET
##   * If MSG_DEP_SET isn't empty the following dependency has been pulled in
##     but can be declared for certainty nonetheless:
##     * add a exec_depend tag for "message_runtime"
## * In this file (CMakeLists.txt):
##   * add "message_generation" and every package in MSG_DEP_SET to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * add "message_runtime" and every package in MSG_DEP_SET to
##     catkin_package(CATKIN_DEPENDS ...)
##   * uncomment the add_*_files sections below as needed
##     and list every .msg/.srv/.action file to be processed
##   * uncomment the generate_messages entry below
##   * add every package in MSG_DEP_SET to generate_messages(DEPENDENCIES ...)

## Generate messages in the 'msg' folder
# add_message_files(
#   FILES
#   Message1.msg
#   Message2.msg
# )

## Generate services in the 'srv' folder
# add_service_files(
#   FILES
#   Service1.srv
#   Service2.srv
# )

## Generate actions in the 'action' folder
# add_action_files(
#   FILES
#   Action1.action
#   Action2.action
# )

## Generate added messages and services with any dependencies listed here
# generate_messages(
#   DEPENDENCIES
#   std_msgs
# )

################################################
## Declare ROS dynamic reconfigure parameters ##
################################################

## To declare and build dynamic reconfigure parameters within this
## package, follow these steps:
## * In the file package.xml:
##   * add a build_depend and a exec_depend tag for "dynamic_reconfigure"
## * In this file (CMakeLists.txt):
##   * add "dynamic_reconfigure" to
##     find_package(catkin REQUIRED COMPONENTS ...)
##   * uncomment the "generate_dynamic_reconfigure_options" section below
##     and list every .cfg file to be processed

## Generate dynamic reconfigure parameters in the 'cfg' folder
# generate_dynamic_reconfigure_options(
#   cfg/DynReconf1.cfg
#   cfg/DynReconf2.cfg
# )

###################################
## catkin specific configuration ##
###################################
## The catkin_package macro generates cmake config files for your package
## Declare things to be passed to dependent projects
## INCLUDE_DIRS: uncomment this if your package contains header files
## LIBRARIES: libraries you create in this project that dependent projects also need
## CATKIN_DEPENDS: catkin_packages dependent projects also need
## DEPENDS: system dependencies of this project that dependent projects also need
catkin_package(
# INCLUDE_DIRS include
# LIBRARIES fw_pos_control
# CATKIN_DEPENDS roscpp rospy std_msgs
# DEPENDS system_lib
  DEPENDS EIGEN3 GeographicLib
)

###########
## Build ##
###########

## Specify additional locations of header files
## Your package locations should be listed before other locations
include_directories(
# include
  ${catkin_INCLUDE_DIRS}
  ../../../devel/include
  ../../serial/include
)

## Declare a C++ library
# add_library(${PROJECT_NAME}
#   src/${PROJECT_NAME}/fw_pos_control.cpp
# )
# add_library(formation
#   include/formation/formationControl/formationControl.cpp
#   ../../lib/mathlib/vector/vector.hpp
# )
add_library(FixedwingPositionSubandPub
  ../../lib/GPS2Distance/GPS2Distance.cpp
  ../../lib/mathlib/mathlib.h
  ../../lib/mathlib/math/mathlib.cpp
  ../../lib/mathlib/vector/vector.hpp

  include/FixedwingPositionSubAndPub/FixedwingPositionSubAndPub.cpp

  include/single/positionControl/TECS/tecs.cpp
  include/single/positionControl/L1/lateralController.cpp
  include/single/positionControl/L1_TECS.cpp
  include/single/PositionControl_L1_TECS.cpp
  include/single/PositionControl_VF.cpp
  include/single/speed/speed_sp/speed_sp.cpp  
  include/single/vf/VF.cpp

  include/formation/PositionControl_FORMATION.cpp
  include/formation/formationControl/formationControl.cpp

  ../communication/include/udp/udpReceive.cpp

  include/single/threeDimensionVF/threeDimensionVF.cpp
)
## Add cmake target dependencies of the library
## as an example, code may need to be generated before libraries
## either from message generation or dynamic reconfigure
# 添加库的cmake目标依赖关系作为示例，在从消息生成或动态重新配置库之前，可能需要生成代码
# add_dependencies(${PROJECT_NAME} ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Declare a C++ executable
## With catkin_make all packages are built within a single CMake context
## The recommended prefix ensures that target names across packages don't collide
# add_executable(${PROJECT_NAME}_node src/fw_pos_control_node.cpp)

## Rename C++ executable without prefix
## The above recommended prefix causes long target names, the following renames the
## target back to the shorter version for ease of user use
## e.g. "rosrun someones_pkg node" instead of "rosrun someones_pkg someones_pkg_node"
# set_target_properties(${PROJECT_NAME}_node PROPERTIES OUTPUT_NAME node PREFIX "")

## Add cmake target dependencies of the executable
## same as for the library above
# add_dependencies(${PROJECT_NAME}_node ${${PROJECT_NAME}_EXPORTED_TARGETS} ${catkin_EXPORTED_TARGETS})

## Specify libraries to link a library or executable target against
# target_link_libraries(${PROJECT_NAME}_node
#   ${catkin_LIBRARIES}
# )

# >>>>>>>>>>>>>>>>>>>>>>>>>>>>> offboard 
# add_executable(posiControlSingle
#   single/postionControlSingle.cpp
# )
# target_link_libraries(posiControlSingle
#   ${catkin_LIBRARIES}
#   mavros
#   PUBLICLIB
# )
# add_dependencies(posiControlSingle ${catkin_EXPORTED_TARGETS})
# offboard <<<<<<<<<<<<<<<<<<<<<<<<<<<<<<

# >>>>>>>>>>>>>>>>>>>>>>>>>>>> formation 
# src/modules/fw_pos_control/formation/rc_handler/rc_handler.cpp
# add_executable(rc_handler
#   formation/rc_handler/rc_handler.cpp
# )
# target_link_libraries(rc_handler
#   formation
#   mavros
#   PUBLICLIB
#   udp
#   ${catkin_LIBRARIES}
# )

# add_dependencies(rc_handler ${catkin_EXPORTED_TARGETS})

# add_executable(rc_vf
#   formation/rc_vf/rc_vf.cpp
# )
# target_link_libraries(rc_vf
#   formation
#   mavros
#   PUBLICLIB
#   udp
#   ${catkin_LIBRARIES}
#   ${GeographicLib_LIBRARIES}
# )

# add_dependencies(rc_vf ${catkin_EXPORTED_TARGETS})


add_executable(FixedwingPositionControl
  FixedwingPositionControl.cpp
)
target_link_libraries(FixedwingPositionControl
  # formation
  mavros
  PUBLICLIB
  # udp
  FixedwingPositionSubandPub
  LOGGER
  ${catkin_LIBRARIES}
  ${GeographicLib_LIBRARIES}
)

add_dependencies(FixedwingPositionControl ${catkin_EXPORTED_TARGETS} ${${PROJECT_NAME}_EXPORTED_TARGETS})

#############
## Install ##
#############

# all install targets should use catkin DESTINATION variables
# See http://ros.org/doc/api/catkin/html/adv_user_guide/variables.html

## Mark executable scripts (Python etc.) for installation
## in contrast to setup.py, you can choose the destination
# install(PROGRAMS
#   scripts/my_python_script
#   DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark executables for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_executables.html
# install(TARGETS ${PROJECT_NAME}_node
#   RUNTIME DESTINATION ${CATKIN_PACKAGE_BIN_DESTINATION}
# )

## Mark libraries for installation
## See http://docs.ros.org/melodic/api/catkin/html/howto/format1/building_libraries.html
# install(TARGETS ${PROJECT_NAME}
#   ARCHIVE DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   LIBRARY DESTINATION ${CATKIN_PACKAGE_LIB_DESTINATION}
#   RUNTIME DESTINATION ${CATKIN_GLOBAL_BIN_DESTINATION}
# )

## Mark cpp header files for installation
# install(DIRECTORY include/${PROJECT_NAME}/
#   DESTINATION ${CATKIN_PACKAGE_INCLUDE_DESTINATION}
#   FILES_MATCHING PATTERN "*.h"
#   PATTERN ".svn" EXCLUDE
# )

## Mark other files for installation (e.g. launch and bag files, etc.)
# install(FILES
#   # myfile1
#   # myfile2
#   DESTINATION ${CATKIN_PACKAGE_SHARE_DESTINATION}
# )

#############
## Testing ##
#############

## Add gtest based cpp test target and link libraries
# catkin_add_gtest(${PROJECT_NAME}-test test/test_fw_pos_control.cpp)
# if(TARGET ${PROJECT_NAME}-test)
#   target_link_libraries(${PROJECT_NAME}-test ${PROJECT_NAME})
# endif()

## Add folders to be run by python nosetests
# catkin_add_nosetests(test)
