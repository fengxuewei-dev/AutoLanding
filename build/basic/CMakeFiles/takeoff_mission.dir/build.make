# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic

# Include any dependencies generated for this target.
include CMakeFiles/takeoff_mission.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/takeoff_mission.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/takeoff_mission.dir/flags.make

CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o: CMakeFiles/takeoff_mission.dir/flags.make
CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic/src/SetMode/takeoff_mission.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic/src/SetMode/takeoff_mission.cpp

CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic/src/SetMode/takeoff_mission.cpp > CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.i

CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic/src/SetMode/takeoff_mission.cpp -o CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.s

CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o.requires:

.PHONY : CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o.requires

CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o.provides: CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o.requires
	$(MAKE) -f CMakeFiles/takeoff_mission.dir/build.make CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o.provides.build
.PHONY : CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o.provides

CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o.provides.build: CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o


# Object files for target takeoff_mission
takeoff_mission_OBJECTS = \
"CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o"

# External object files for target takeoff_mission
takeoff_mission_EXTERNAL_OBJECTS =

/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: CMakeFiles/takeoff_mission.dir/build.make
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libbasic_library.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libfw_sub_pub.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libPUBLICLIB.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /opt/ros/melodic/lib/libroscpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /opt/ros/melodic/lib/librosconsole.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /opt/ros/melodic/lib/librostime.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /opt/ros/melodic/lib/libcpp_common.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission: CMakeFiles/takeoff_mission.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/takeoff_mission.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/takeoff_mission.dir/build: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/basic/lib/basic/takeoff_mission

.PHONY : CMakeFiles/takeoff_mission.dir/build

CMakeFiles/takeoff_mission.dir/requires: CMakeFiles/takeoff_mission.dir/src/SetMode/takeoff_mission.cpp.o.requires

.PHONY : CMakeFiles/takeoff_mission.dir/requires

CMakeFiles/takeoff_mission.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/takeoff_mission.dir/cmake_clean.cmake
.PHONY : CMakeFiles/takeoff_mission.dir/clean

CMakeFiles/takeoff_mission.dir/depend:
	cd /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic/CMakeFiles/takeoff_mission.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/takeoff_mission.dir/depend
