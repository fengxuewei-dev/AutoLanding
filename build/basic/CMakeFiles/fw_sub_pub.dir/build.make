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
include CMakeFiles/fw_sub_pub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/fw_sub_pub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/fw_sub_pub.dir/flags.make

CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o: CMakeFiles/fw_sub_pub.dir/flags.make
CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic/include/fw_sub_pub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic/include/fw_sub_pub.cpp

CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic/include/fw_sub_pub.cpp > CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.i

CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic/include/fw_sub_pub.cpp -o CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.s

CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o.requires:

.PHONY : CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o.requires

CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o.provides: CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o.requires
	$(MAKE) -f CMakeFiles/fw_sub_pub.dir/build.make CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o.provides.build
.PHONY : CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o.provides

CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o.provides.build: CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o


# Object files for target fw_sub_pub
fw_sub_pub_OBJECTS = \
"CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o"

# External object files for target fw_sub_pub
fw_sub_pub_EXTERNAL_OBJECTS =

/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libfw_sub_pub.so: CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libfw_sub_pub.so: CMakeFiles/fw_sub_pub.dir/build.make
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libfw_sub_pub.so: CMakeFiles/fw_sub_pub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libfw_sub_pub.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/fw_sub_pub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/fw_sub_pub.dir/build: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libfw_sub_pub.so

.PHONY : CMakeFiles/fw_sub_pub.dir/build

CMakeFiles/fw_sub_pub.dir/requires: CMakeFiles/fw_sub_pub.dir/include/fw_sub_pub.cpp.o.requires

.PHONY : CMakeFiles/fw_sub_pub.dir/requires

CMakeFiles/fw_sub_pub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/fw_sub_pub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/fw_sub_pub.dir/clean

CMakeFiles/fw_sub_pub.dir/depend:
	cd /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/basic /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/basic/CMakeFiles/fw_sub_pub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/fw_sub_pub.dir/depend
