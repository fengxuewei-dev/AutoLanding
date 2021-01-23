# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "fw_msgs: 23 messages, 0 services")

set(MSG_I_FLAGS "-Ifw_msgs:/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Imavros_msgs:/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros_msgs/msg;-Igeographic_msgs:/opt/ros/melodic/share/geographic_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/melodic/share/sensor_msgs/cmake/../msg;-Iuuid_msgs:/opt/ros/melodic/share/uuid_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(fw_msgs_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg" "mavros_msgs/Waypoint"
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg" NAME_WE)
add_custom_target(_fw_msgs_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "fw_msgs" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg"
  "${MSG_I_FLAGS}"
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros_msgs/msg/Waypoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)
_generate_msg_cpp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
)

### Generating Services

### Generating Module File
_generate_module_cpp(fw_msgs
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(fw_msgs_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(fw_msgs_generate_messages fw_msgs_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_cpp _fw_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fw_msgs_gencpp)
add_dependencies(fw_msgs_gencpp fw_msgs_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fw_msgs_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg"
  "${MSG_I_FLAGS}"
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros_msgs/msg/Waypoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)
_generate_msg_eus(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
)

### Generating Services

### Generating Module File
_generate_module_eus(fw_msgs
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(fw_msgs_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(fw_msgs_generate_messages fw_msgs_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_eus _fw_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fw_msgs_geneus)
add_dependencies(fw_msgs_geneus fw_msgs_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fw_msgs_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg"
  "${MSG_I_FLAGS}"
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros_msgs/msg/Waypoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)
_generate_msg_lisp(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
)

### Generating Services

### Generating Module File
_generate_module_lisp(fw_msgs
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(fw_msgs_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(fw_msgs_generate_messages fw_msgs_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_lisp _fw_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fw_msgs_genlisp)
add_dependencies(fw_msgs_genlisp fw_msgs_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fw_msgs_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg"
  "${MSG_I_FLAGS}"
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros_msgs/msg/Waypoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)
_generate_msg_nodejs(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
)

### Generating Services

### Generating Module File
_generate_module_nodejs(fw_msgs
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(fw_msgs_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(fw_msgs_generate_messages fw_msgs_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_nodejs _fw_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fw_msgs_gennodejs)
add_dependencies(fw_msgs_gennodejs fw_msgs_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fw_msgs_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg"
  "${MSG_I_FLAGS}"
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros_msgs/msg/Waypoint.msg"
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)
_generate_msg_py(fw_msgs
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
)

### Generating Services

### Generating Module File
_generate_module_py(fw_msgs
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(fw_msgs_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(fw_msgs_generate_messages fw_msgs_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACK.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/EXITflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/processer.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/formations.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ProtectFlag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/position_setpoint_triplet.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/NormalSwitchMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ACKflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/flyMode.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/ModeSetting.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uavflag.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/Yaw.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/target.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/uav_ids.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/QgcCommands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/commands.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UDPData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/UpdHP.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/DataLinkDown.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/fw_msgs/msg/FormationData.msg" NAME_WE)
add_dependencies(fw_msgs_generate_messages_py _fw_msgs_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(fw_msgs_genpy)
add_dependencies(fw_msgs_genpy fw_msgs_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS fw_msgs_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/fw_msgs
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(fw_msgs_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(fw_msgs_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET mavros_msgs_generate_messages_cpp)
  add_dependencies(fw_msgs_generate_messages_cpp mavros_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/fw_msgs
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(fw_msgs_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(fw_msgs_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET mavros_msgs_generate_messages_eus)
  add_dependencies(fw_msgs_generate_messages_eus mavros_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/fw_msgs
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(fw_msgs_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(fw_msgs_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET mavros_msgs_generate_messages_lisp)
  add_dependencies(fw_msgs_generate_messages_lisp mavros_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/fw_msgs
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(fw_msgs_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(fw_msgs_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET mavros_msgs_generate_messages_nodejs)
  add_dependencies(fw_msgs_generate_messages_nodejs mavros_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/fw_msgs
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(fw_msgs_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(fw_msgs_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET mavros_msgs_generate_messages_py)
  add_dependencies(fw_msgs_generate_messages_py mavros_msgs_generate_messages_py)
endif()
