# generated from genmsg/cmake/pkg-genmsg.cmake.em

message(STATUS "communication: 9 messages, 0 services")

set(MSG_I_FLAGS "-Icommunication:/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg;-Istd_msgs:/opt/ros/melodic/share/std_msgs/cmake/../msg;-Igeometry_msgs:/opt/ros/melodic/share/geometry_msgs/cmake/../msg;-Imavros_msgs:/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/mavros/mavros_msgs/msg;-Igeographic_msgs:/opt/ros/melodic/share/geographic_msgs/cmake/../msg;-Isensor_msgs:/opt/ros/melodic/share/sensor_msgs/cmake/../msg;-Iuuid_msgs:/opt/ros/melodic/share/uuid_msgs/cmake/../msg")

# Find all generators
find_package(gencpp REQUIRED)
find_package(geneus REQUIRED)
find_package(genlisp REQUIRED)
find_package(gennodejs REQUIRED)
find_package(genpy REQUIRED)

add_custom_target(communication_generate_messages ALL)

# verify that message/service dependencies have not changed since configure



get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg" ""
)

get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg" NAME_WE)
add_custom_target(_communication_generate_messages_check_deps_${_filename}
  COMMAND ${CATKIN_ENV} ${PYTHON_EXECUTABLE} ${GENMSG_CHECK_DEPS_SCRIPT} "communication" "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg" ""
)

#
#  langs = gencpp;geneus;genlisp;gennodejs;genpy
#

### Section generating for lang: gencpp
### Generating Messages
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)
_generate_msg_cpp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
)

### Generating Services

### Generating Module File
_generate_module_cpp(communication
  ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
  "${ALL_GEN_OUTPUT_FILES_cpp}"
)

add_custom_target(communication_generate_messages_cpp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_cpp}
)
add_dependencies(communication_generate_messages communication_generate_messages_cpp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(communication_generate_messages_cpp _communication_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(communication_gencpp)
add_dependencies(communication_gencpp communication_generate_messages_cpp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS communication_generate_messages_cpp)

### Section generating for lang: geneus
### Generating Messages
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)
_generate_msg_eus(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
)

### Generating Services

### Generating Module File
_generate_module_eus(communication
  ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
  "${ALL_GEN_OUTPUT_FILES_eus}"
)

add_custom_target(communication_generate_messages_eus
  DEPENDS ${ALL_GEN_OUTPUT_FILES_eus}
)
add_dependencies(communication_generate_messages communication_generate_messages_eus)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(communication_generate_messages_eus _communication_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(communication_geneus)
add_dependencies(communication_geneus communication_generate_messages_eus)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS communication_generate_messages_eus)

### Section generating for lang: genlisp
### Generating Messages
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)
_generate_msg_lisp(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
)

### Generating Services

### Generating Module File
_generate_module_lisp(communication
  ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
  "${ALL_GEN_OUTPUT_FILES_lisp}"
)

add_custom_target(communication_generate_messages_lisp
  DEPENDS ${ALL_GEN_OUTPUT_FILES_lisp}
)
add_dependencies(communication_generate_messages communication_generate_messages_lisp)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(communication_generate_messages_lisp _communication_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(communication_genlisp)
add_dependencies(communication_genlisp communication_generate_messages_lisp)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS communication_generate_messages_lisp)

### Section generating for lang: gennodejs
### Generating Messages
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)
_generate_msg_nodejs(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
)

### Generating Services

### Generating Module File
_generate_module_nodejs(communication
  ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
  "${ALL_GEN_OUTPUT_FILES_nodejs}"
)

add_custom_target(communication_generate_messages_nodejs
  DEPENDS ${ALL_GEN_OUTPUT_FILES_nodejs}
)
add_dependencies(communication_generate_messages communication_generate_messages_nodejs)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(communication_generate_messages_nodejs _communication_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(communication_gennodejs)
add_dependencies(communication_gennodejs communication_generate_messages_nodejs)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS communication_generate_messages_nodejs)

### Section generating for lang: genpy
### Generating Messages
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)
_generate_msg_py(communication
  "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg"
  "${MSG_I_FLAGS}"
  ""
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
)

### Generating Services

### Generating Module File
_generate_module_py(communication
  ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
  "${ALL_GEN_OUTPUT_FILES_py}"
)

add_custom_target(communication_generate_messages_py
  DEPENDS ${ALL_GEN_OUTPUT_FILES_py}
)
add_dependencies(communication_generate_messages communication_generate_messages_py)

# add dependencies to all check dependencies targets
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})
get_filename_component(_filename "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg" NAME_WE)
add_dependencies(communication_generate_messages_py _communication_generate_messages_check_deps_${_filename})

# target for backward compatibility
add_custom_target(communication_genpy)
add_dependencies(communication_genpy communication_generate_messages_py)

# register target for catkin_package(EXPORTED_TARGETS)
list(APPEND ${PROJECT_NAME}_EXPORTED_TARGETS communication_generate_messages_py)



if(gencpp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gencpp_INSTALL_DIR}/communication
    DESTINATION ${gencpp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_cpp)
  add_dependencies(communication_generate_messages_cpp std_msgs_generate_messages_cpp)
endif()
if(TARGET geometry_msgs_generate_messages_cpp)
  add_dependencies(communication_generate_messages_cpp geometry_msgs_generate_messages_cpp)
endif()
if(TARGET mavros_msgs_generate_messages_cpp)
  add_dependencies(communication_generate_messages_cpp mavros_msgs_generate_messages_cpp)
endif()

if(geneus_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${geneus_INSTALL_DIR}/communication
    DESTINATION ${geneus_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_eus)
  add_dependencies(communication_generate_messages_eus std_msgs_generate_messages_eus)
endif()
if(TARGET geometry_msgs_generate_messages_eus)
  add_dependencies(communication_generate_messages_eus geometry_msgs_generate_messages_eus)
endif()
if(TARGET mavros_msgs_generate_messages_eus)
  add_dependencies(communication_generate_messages_eus mavros_msgs_generate_messages_eus)
endif()

if(genlisp_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genlisp_INSTALL_DIR}/communication
    DESTINATION ${genlisp_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_lisp)
  add_dependencies(communication_generate_messages_lisp std_msgs_generate_messages_lisp)
endif()
if(TARGET geometry_msgs_generate_messages_lisp)
  add_dependencies(communication_generate_messages_lisp geometry_msgs_generate_messages_lisp)
endif()
if(TARGET mavros_msgs_generate_messages_lisp)
  add_dependencies(communication_generate_messages_lisp mavros_msgs_generate_messages_lisp)
endif()

if(gennodejs_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication)
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${gennodejs_INSTALL_DIR}/communication
    DESTINATION ${gennodejs_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_nodejs)
  add_dependencies(communication_generate_messages_nodejs std_msgs_generate_messages_nodejs)
endif()
if(TARGET geometry_msgs_generate_messages_nodejs)
  add_dependencies(communication_generate_messages_nodejs geometry_msgs_generate_messages_nodejs)
endif()
if(TARGET mavros_msgs_generate_messages_nodejs)
  add_dependencies(communication_generate_messages_nodejs mavros_msgs_generate_messages_nodejs)
endif()

if(genpy_INSTALL_DIR AND EXISTS ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication)
  install(CODE "execute_process(COMMAND \"/usr/bin/python2\" -m compileall \"${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication\")")
  # install generated code
  install(
    DIRECTORY ${CATKIN_DEVEL_PREFIX}/${genpy_INSTALL_DIR}/communication
    DESTINATION ${genpy_INSTALL_DIR}
  )
endif()
if(TARGET std_msgs_generate_messages_py)
  add_dependencies(communication_generate_messages_py std_msgs_generate_messages_py)
endif()
if(TARGET geometry_msgs_generate_messages_py)
  add_dependencies(communication_generate_messages_py geometry_msgs_generate_messages_py)
endif()
if(TARGET mavros_msgs_generate_messages_py)
  add_dependencies(communication_generate_messages_py mavros_msgs_generate_messages_py)
endif()
