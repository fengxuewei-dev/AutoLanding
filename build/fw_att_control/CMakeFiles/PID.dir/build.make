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
CMAKE_SOURCE_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/fw_att_control

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/fw_att_control

# Include any dependencies generated for this target.
include CMakeFiles/PID.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/PID.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/PID.dir/flags.make

CMakeFiles/PID.dir/include/PID/pidControl.cpp.o: CMakeFiles/PID.dir/flags.make
CMakeFiles/PID.dir/include/PID/pidControl.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/fw_att_control/include/PID/pidControl.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/fw_att_control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/PID.dir/include/PID/pidControl.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/PID.dir/include/PID/pidControl.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/fw_att_control/include/PID/pidControl.cpp

CMakeFiles/PID.dir/include/PID/pidControl.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/PID.dir/include/PID/pidControl.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/fw_att_control/include/PID/pidControl.cpp > CMakeFiles/PID.dir/include/PID/pidControl.cpp.i

CMakeFiles/PID.dir/include/PID/pidControl.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/PID.dir/include/PID/pidControl.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/fw_att_control/include/PID/pidControl.cpp -o CMakeFiles/PID.dir/include/PID/pidControl.cpp.s

CMakeFiles/PID.dir/include/PID/pidControl.cpp.o.requires:

.PHONY : CMakeFiles/PID.dir/include/PID/pidControl.cpp.o.requires

CMakeFiles/PID.dir/include/PID/pidControl.cpp.o.provides: CMakeFiles/PID.dir/include/PID/pidControl.cpp.o.requires
	$(MAKE) -f CMakeFiles/PID.dir/build.make CMakeFiles/PID.dir/include/PID/pidControl.cpp.o.provides.build
.PHONY : CMakeFiles/PID.dir/include/PID/pidControl.cpp.o.provides

CMakeFiles/PID.dir/include/PID/pidControl.cpp.o.provides.build: CMakeFiles/PID.dir/include/PID/pidControl.cpp.o


# Object files for target PID
PID_OBJECTS = \
"CMakeFiles/PID.dir/include/PID/pidControl.cpp.o"

# External object files for target PID
PID_EXTERNAL_OBJECTS =

/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libPID.so: CMakeFiles/PID.dir/include/PID/pidControl.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libPID.so: CMakeFiles/PID.dir/build.make
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libPID.so: CMakeFiles/PID.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/fw_att_control/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libPID.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/PID.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/PID.dir/build: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libPID.so

.PHONY : CMakeFiles/PID.dir/build

CMakeFiles/PID.dir/requires: CMakeFiles/PID.dir/include/PID/pidControl.cpp.o.requires

.PHONY : CMakeFiles/PID.dir/requires

CMakeFiles/PID.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/PID.dir/cmake_clean.cmake
.PHONY : CMakeFiles/PID.dir/clean

CMakeFiles/PID.dir/depend:
	cd /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/fw_att_control && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/fw_att_control /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/fw_att_control /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/fw_att_control /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/fw_att_control /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/fw_att_control/CMakeFiles/PID.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/PID.dir/depend

