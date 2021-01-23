# Install script for directory: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication

# Set the install prefix
if(NOT DEFINED CMAKE_INSTALL_PREFIX)
  set(CMAKE_INSTALL_PREFIX "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install")
endif()
string(REGEX REPLACE "/$" "" CMAKE_INSTALL_PREFIX "${CMAKE_INSTALL_PREFIX}")

# Set the install configuration name.
if(NOT DEFINED CMAKE_INSTALL_CONFIG_NAME)
  if(BUILD_TYPE)
    string(REGEX REPLACE "^[^A-Za-z0-9_]+" ""
           CMAKE_INSTALL_CONFIG_NAME "${BUILD_TYPE}")
  else()
    set(CMAKE_INSTALL_CONFIG_NAME "")
  endif()
  message(STATUS "Install configuration: \"${CMAKE_INSTALL_CONFIG_NAME}\"")
endif()

# Set the component getting installed.
if(NOT CMAKE_INSTALL_COMPONENT)
  if(COMPONENT)
    message(STATUS "Install component: \"${COMPONENT}\"")
    set(CMAKE_INSTALL_COMPONENT "${COMPONENT}")
  else()
    set(CMAKE_INSTALL_COMPONENT)
  endif()
endif()

# Install shared libraries without execute permission?
if(NOT DEFINED CMAKE_INSTALL_SO_NO_EXE)
  set(CMAKE_INSTALL_SO_NO_EXE "1")
endif()

# Is this installation the result of a crosscompile?
if(NOT DEFINED CMAKE_CROSSCOMPILING)
  set(CMAKE_CROSSCOMPILING "FALSE")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
        file(MAKE_DIRECTORY "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}")
      endif()
      if (NOT EXISTS "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin")
        file(WRITE "$ENV{DESTDIR}${CMAKE_INSTALL_PREFIX}/.catkin" "")
      endif()
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/_setup_util.py")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install" TYPE PROGRAM FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/_setup_util.py")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/env.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install" TYPE PROGRAM FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/env.sh")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/setup.bash;/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/local_setup.bash")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install" TYPE FILE FILES
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/setup.bash"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/local_setup.bash"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/setup.sh;/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/local_setup.sh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install" TYPE FILE FILES
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/setup.sh"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/local_setup.sh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/setup.zsh;/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/local_setup.zsh")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install" TYPE FILE FILES
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/setup.zsh"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/local_setup.zsh"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  list(APPEND CMAKE_ABSOLUTE_DESTINATION_FILES
   "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install/.rosinstall")
  if(CMAKE_WARN_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(WARNING "ABSOLUTE path INSTALL DESTINATION : ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
  if(CMAKE_ERROR_ON_ABSOLUTE_INSTALL_DESTINATION)
    message(FATAL_ERROR "ABSOLUTE path INSTALL DESTINATION forbidden (by caller): ${CMAKE_ABSOLUTE_DESTINATION_FILES}")
  endif()
file(INSTALL DESTINATION "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/install" TYPE FILE FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/.rosinstall")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/communication/msg" TYPE FILE FILES
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationNavigator.msg"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationPositionContoller.msg"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/FormationData.msg"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/udpDataTypes.msg"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/ACK.msg"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/Yaw.msg"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/QgcCommands.msg"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UpdHP.msg"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/msg/UDPData.msg"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/communication/cmake" TYPE FILE FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/communication-msg-paths.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/include" TYPE DIRECTORY FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/include/communication")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/roseus/ros" TYPE DIRECTORY FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/share/roseus/ros/communication")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/common-lisp/ros" TYPE DIRECTORY FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/share/common-lisp/ros/communication")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/gennodejs/ros" TYPE DIRECTORY FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/share/gennodejs/ros/communication")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  execute_process(COMMAND "/usr/bin/python2" -m compileall "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/python2.7/dist-packages/communication")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/python2.7/dist-packages" TYPE DIRECTORY FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/python2.7/dist-packages/communication")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/lib/pkgconfig" TYPE FILE FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/communication.pc")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/communication/cmake" TYPE FILE FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/communication-msg-extras.cmake")
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/communication/cmake" TYPE FILE FILES
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/communicationConfig.cmake"
    "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/catkin_generated/installspace/communicationConfig-version.cmake"
    )
endif()

if("x${CMAKE_INSTALL_COMPONENT}x" STREQUAL "xUnspecifiedx" OR NOT CMAKE_INSTALL_COMPONENT)
  file(INSTALL DESTINATION "${CMAKE_INSTALL_PREFIX}/share/communication" TYPE FILE FILES "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/package.xml")
endif()

if(NOT CMAKE_INSTALL_LOCAL_ONLY)
  # Include the install script for each subdirectory.
  include("/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/gtest/cmake_install.cmake")

endif()

if(CMAKE_INSTALL_COMPONENT)
  set(CMAKE_INSTALL_MANIFEST "install_manifest_${CMAKE_INSTALL_COMPONENT}.txt")
else()
  set(CMAKE_INSTALL_MANIFEST "install_manifest.txt")
endif()

string(REPLACE ";" "\n" CMAKE_INSTALL_MANIFEST_CONTENT
       "${CMAKE_INSTALL_MANIFEST_FILES}")
file(WRITE "/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/${CMAKE_INSTALL_MANIFEST}"
     "${CMAKE_INSTALL_MANIFEST_CONTENT}")
