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
CMAKE_SOURCE_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication

# Include any dependencies generated for this target.
include CMakeFiles/sendDataForFormation.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/sendDataForFormation.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/sendDataForFormation.dir/flags.make

CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o: CMakeFiles/sendDataForFormation.dir/flags.make
CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/sendDataForFormation/sendDataForFormation.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/sendDataForFormation/sendDataForFormation.cpp

CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/sendDataForFormation/sendDataForFormation.cpp > CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.i

CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/sendDataForFormation/sendDataForFormation.cpp -o CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.s

CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o.requires:

.PHONY : CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o.requires

CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o.provides: CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o.requires
	$(MAKE) -f CMakeFiles/sendDataForFormation.dir/build.make CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o.provides.build
.PHONY : CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o.provides

CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o.provides.build: CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o


# Object files for target sendDataForFormation
sendDataForFormation_OBJECTS = \
"CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o"

# External object files for target sendDataForFormation
sendDataForFormation_EXTERNAL_OBJECTS =

/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: CMakeFiles/sendDataForFormation.dir/build.make
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/libDataForFormationSubandPub.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/libroscpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/librosconsole.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/librostime.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/libcpp_common.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: /opt/ros/melodic/lib/libserial.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation: CMakeFiles/sendDataForFormation.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/sendDataForFormation.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/sendDataForFormation.dir/build: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/sendDataForFormation

.PHONY : CMakeFiles/sendDataForFormation.dir/build

CMakeFiles/sendDataForFormation.dir/requires: CMakeFiles/sendDataForFormation.dir/sendDataForFormation/sendDataForFormation.cpp.o.requires

.PHONY : CMakeFiles/sendDataForFormation.dir/requires

CMakeFiles/sendDataForFormation.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/sendDataForFormation.dir/cmake_clean.cmake
.PHONY : CMakeFiles/sendDataForFormation.dir/clean

CMakeFiles/sendDataForFormation.dir/depend:
	cd /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles/sendDataForFormation.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/sendDataForFormation.dir/depend
