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
CMAKE_SOURCE_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/test

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/test

# Include any dependencies generated for this target.
include CMakeFiles/subNode.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/subNode.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/subNode.dir/flags.make

CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o: CMakeFiles/subNode.dir/flags.make
CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/test/src/testTopic/sub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/test/src/testTopic/sub.cpp

CMakeFiles/subNode.dir/src/testTopic/sub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/subNode.dir/src/testTopic/sub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/test/src/testTopic/sub.cpp > CMakeFiles/subNode.dir/src/testTopic/sub.cpp.i

CMakeFiles/subNode.dir/src/testTopic/sub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/subNode.dir/src/testTopic/sub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/test/src/testTopic/sub.cpp -o CMakeFiles/subNode.dir/src/testTopic/sub.cpp.s

CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o.requires:

.PHONY : CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o.requires

CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o.provides: CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o.requires
	$(MAKE) -f CMakeFiles/subNode.dir/build.make CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o.provides.build
.PHONY : CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o.provides

CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o.provides.build: CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o


# Object files for target subNode
subNode_OBJECTS = \
"CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o"

# External object files for target subNode
subNode_EXTERNAL_OBJECTS =

/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: CMakeFiles/subNode.dir/build.make
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/libTestData.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/mavros/lib/libmavros.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/local/lib/libGeographic.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libdiagnostic_updater.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libeigen_conversions.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/liborocos-kdl.so.1.4.0
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/libmavconn/lib/libmavconn.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libclass_loader.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/libPocoFoundation.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libdl.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libroslib.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/librospack.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libpython2.7.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libboost_program_options.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libtinyxml2.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libtf2_ros.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libactionlib.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libmessage_filters.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libtf2.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libroscpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/librosconsole.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/librostime.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /opt/ros/melodic/lib/libcpp_common.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode: CMakeFiles/subNode.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/test/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/subNode.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/subNode.dir/build: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/test/lib/test/subNode

.PHONY : CMakeFiles/subNode.dir/build

CMakeFiles/subNode.dir/requires: CMakeFiles/subNode.dir/src/testTopic/sub.cpp.o.requires

.PHONY : CMakeFiles/subNode.dir/requires

CMakeFiles/subNode.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/subNode.dir/cmake_clean.cmake
.PHONY : CMakeFiles/subNode.dir/clean

CMakeFiles/subNode.dir/depend:
	cd /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/test && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/test /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/test /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/test /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/test /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/test/CMakeFiles/subNode.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/subNode.dir/depend
