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
include CMakeFiles/UDP_Send_justhome.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/UDP_Send_justhome.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UDP_Send_justhome.dir/flags.make

CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o: CMakeFiles/UDP_Send_justhome.dir/flags.make
CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/src/UDP_Send/UDP_Send_justhome.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/src/UDP_Send/UDP_Send_justhome.cpp

CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/src/UDP_Send/UDP_Send_justhome.cpp > CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.i

CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/src/UDP_Send/UDP_Send_justhome.cpp -o CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.s

CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o.requires:

.PHONY : CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o.requires

CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o.provides: CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o.requires
	$(MAKE) -f CMakeFiles/UDP_Send_justhome.dir/build.make CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o.provides.build
.PHONY : CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o.provides

CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o.provides.build: CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o


# Object files for target UDP_Send_justhome
UDP_Send_justhome_OBJECTS = \
"CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o"

# External object files for target UDP_Send_justhome
UDP_Send_justhome_EXTERNAL_OBJECTS =

/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: CMakeFiles/UDP_Send_justhome.dir/build.make
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libSendLib.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/libroscpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/librosconsole.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/librostime.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/libcpp_common.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: /opt/ros/melodic/lib/libserial.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome: CMakeFiles/UDP_Send_justhome.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/UDP_Send_justhome.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UDP_Send_justhome.dir/build: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/devel/.private/communication/lib/communication/UDP_Send_justhome

.PHONY : CMakeFiles/UDP_Send_justhome.dir/build

CMakeFiles/UDP_Send_justhome.dir/requires: CMakeFiles/UDP_Send_justhome.dir/src/UDP_Send/UDP_Send_justhome.cpp.o.requires

.PHONY : CMakeFiles/UDP_Send_justhome.dir/requires

CMakeFiles/UDP_Send_justhome.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/UDP_Send_justhome.dir/cmake_clean.cmake
.PHONY : CMakeFiles/UDP_Send_justhome.dir/clean

CMakeFiles/UDP_Send_justhome.dir/depend:
	cd /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles/UDP_Send_justhome.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UDP_Send_justhome.dir/depend

