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
include CMakeFiles/ReceiveLib.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/ReceiveLib.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ReceiveLib.dir/flags.make

CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o: CMakeFiles/ReceiveLib.dir/flags.make
CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/include/communication/ReceiveLib.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/include/communication/ReceiveLib.cpp

CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/include/communication/ReceiveLib.cpp > CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.i

CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication/include/communication/ReceiveLib.cpp -o CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.s

CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o.requires:

.PHONY : CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o.requires

CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o.provides: CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o.requires
	$(MAKE) -f CMakeFiles/ReceiveLib.dir/build.make CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o.provides.build
.PHONY : CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o.provides

CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o.provides.build: CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o


# Object files for target ReceiveLib
ReceiveLib_OBJECTS = \
"CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o"

# External object files for target ReceiveLib
ReceiveLib_EXTERNAL_OBJECTS =

/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: CMakeFiles/ReceiveLib.dir/build.make
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/libroscpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libboost_filesystem.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/librosconsole.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/librosconsole_log4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/librosconsole_backend_interface.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/liblog4cxx.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libboost_regex.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/libxmlrpcpp.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/libroscpp_serialization.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/librostime.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/libcpp_common.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libboost_system.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libboost_thread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libboost_chrono.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libboost_date_time.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libboost_atomic.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libpthread.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /usr/lib/x86_64-linux-gnu/libconsole_bridge.so.0.4
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: /opt/ros/melodic/lib/libserial.so
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so: CMakeFiles/ReceiveLib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/ReceiveLib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ReceiveLib.dir/build: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libReceiveLib.so

.PHONY : CMakeFiles/ReceiveLib.dir/build

CMakeFiles/ReceiveLib.dir/requires: CMakeFiles/ReceiveLib.dir/include/communication/ReceiveLib.cpp.o.requires

.PHONY : CMakeFiles/ReceiveLib.dir/requires

CMakeFiles/ReceiveLib.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ReceiveLib.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ReceiveLib.dir/clean

CMakeFiles/ReceiveLib.dir/depend:
	cd /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/communication/CMakeFiles/ReceiveLib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ReceiveLib.dir/depend

