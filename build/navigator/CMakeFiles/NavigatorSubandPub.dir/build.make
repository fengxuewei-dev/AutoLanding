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
CMAKE_SOURCE_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator

# Include any dependencies generated for this target.
include CMakeFiles/NavigatorSubandPub.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NavigatorSubandPub.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NavigatorSubandPub.dir/flags.make

CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o: CMakeFiles/NavigatorSubandPub.dir/flags.make
CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/General/GeneralMission.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/General/GeneralMission.cpp

CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/General/GeneralMission.cpp > CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.i

CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/General/GeneralMission.cpp -o CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.s

CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o.requires:

.PHONY : CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o.requires

CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o.provides: CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o.requires
	$(MAKE) -f CMakeFiles/NavigatorSubandPub.dir/build.make CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o.provides.build
.PHONY : CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o.provides

CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o.provides.build: CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o


CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o: CMakeFiles/NavigatorSubandPub.dir/flags.make
CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/Loiter/LoiterMission.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/Loiter/LoiterMission.cpp

CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/Loiter/LoiterMission.cpp > CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.i

CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/Loiter/LoiterMission.cpp -o CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.s

CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o.requires:

.PHONY : CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o.requires

CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o.provides: CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o.requires
	$(MAKE) -f CMakeFiles/NavigatorSubandPub.dir/build.make CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o.provides.build
.PHONY : CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o.provides

CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o.provides.build: CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o


CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o: CMakeFiles/NavigatorSubandPub.dir/flags.make
CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp

CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp > CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.i

CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp -o CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.s

CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o.requires:

.PHONY : CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o.requires

CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o.provides: CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o.requires
	$(MAKE) -f CMakeFiles/NavigatorSubandPub.dir/build.make CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o.provides.build
.PHONY : CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o.provides

CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o.provides.build: CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o


CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o: CMakeFiles/NavigatorSubandPub.dir/flags.make
CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp

CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp > CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.i

CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp -o CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.s

CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o.requires:

.PHONY : CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o.requires

CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o.provides: CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o.requires
	$(MAKE) -f CMakeFiles/NavigatorSubandPub.dir/build.make CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o.provides.build
.PHONY : CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o.provides

CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o.provides.build: CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o


CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o: CMakeFiles/NavigatorSubandPub.dir/flags.make
CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/PathManger/algorithms.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o -c /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/PathManger/algorithms.cpp

CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/PathManger/algorithms.cpp > CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.i

CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator/include/PathManger/algorithms.cpp -o CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.s

CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o.requires:

.PHONY : CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o.requires

CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o.provides: CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o.requires
	$(MAKE) -f CMakeFiles/NavigatorSubandPub.dir/build.make CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o.provides.build
.PHONY : CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o.provides

CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o.provides.build: CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o


# Object files for target NavigatorSubandPub
NavigatorSubandPub_OBJECTS = \
"CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o" \
"CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o" \
"CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o" \
"CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o" \
"CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o"

# External object files for target NavigatorSubandPub
NavigatorSubandPub_EXTERNAL_OBJECTS =

/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so: CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so: CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so: CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so: CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so: CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so: CMakeFiles/NavigatorSubandPub.dir/build.make
/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so: CMakeFiles/NavigatorSubandPub.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX shared library /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/NavigatorSubandPub.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NavigatorSubandPub.dir/build: /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/bin/libNavigatorSubandPub.so

.PHONY : CMakeFiles/NavigatorSubandPub.dir/build

CMakeFiles/NavigatorSubandPub.dir/requires: CMakeFiles/NavigatorSubandPub.dir/include/General/GeneralMission.cpp.o.requires
CMakeFiles/NavigatorSubandPub.dir/requires: CMakeFiles/NavigatorSubandPub.dir/include/Loiter/LoiterMission.cpp.o.requires
CMakeFiles/NavigatorSubandPub.dir/requires: CMakeFiles/NavigatorSubandPub.dir/include/NavigatorSubAndPub/NavigatorSubAndPub.cpp.o.requires
CMakeFiles/NavigatorSubandPub.dir/requires: CMakeFiles/NavigatorSubandPub.dir/home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/lib/GPS2Distance/GPS2Distance.cpp.o.requires
CMakeFiles/NavigatorSubandPub.dir/requires: CMakeFiles/NavigatorSubandPub.dir/include/PathManger/algorithms.cpp.o.requires

.PHONY : CMakeFiles/NavigatorSubandPub.dir/requires

CMakeFiles/NavigatorSubandPub.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/NavigatorSubandPub.dir/cmake_clean.cmake
.PHONY : CMakeFiles/NavigatorSubandPub.dir/clean

CMakeFiles/NavigatorSubandPub.dir/depend:
	cd /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/src/modules/navigator /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator /home/fengxuewei/GitHub/uav_project_1/AutoLanding/AutoLanding/build/navigator/CMakeFiles/NavigatorSubandPub.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/NavigatorSubandPub.dir/depend

