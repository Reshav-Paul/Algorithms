# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.13

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

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = "F:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "F:\CLion 2018.3.4\bin\cmake\win\bin\cmake.exe" -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "F:\My projects\Numerical\LPP\NWCM"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\My projects\Numerical\LPP\NWCM\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/NWCM.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/NWCM.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/NWCM.dir/flags.make

CMakeFiles/NWCM.dir/main.cpp.obj: CMakeFiles/NWCM.dir/flags.make
CMakeFiles/NWCM.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\My projects\Numerical\LPP\NWCM\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/NWCM.dir/main.cpp.obj"
	F:\CodeBlocks\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\NWCM.dir\main.cpp.obj -c "F:\My projects\Numerical\LPP\NWCM\main.cpp"

CMakeFiles/NWCM.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/NWCM.dir/main.cpp.i"
	F:\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\My projects\Numerical\LPP\NWCM\main.cpp" > CMakeFiles\NWCM.dir\main.cpp.i

CMakeFiles/NWCM.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/NWCM.dir/main.cpp.s"
	F:\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\My projects\Numerical\LPP\NWCM\main.cpp" -o CMakeFiles\NWCM.dir\main.cpp.s

# Object files for target NWCM
NWCM_OBJECTS = \
"CMakeFiles/NWCM.dir/main.cpp.obj"

# External object files for target NWCM
NWCM_EXTERNAL_OBJECTS =

NWCM.exe: CMakeFiles/NWCM.dir/main.cpp.obj
NWCM.exe: CMakeFiles/NWCM.dir/build.make
NWCM.exe: CMakeFiles/NWCM.dir/linklibs.rsp
NWCM.exe: CMakeFiles/NWCM.dir/objects1.rsp
NWCM.exe: CMakeFiles/NWCM.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\My projects\Numerical\LPP\NWCM\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable NWCM.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\NWCM.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/NWCM.dir/build: NWCM.exe

.PHONY : CMakeFiles/NWCM.dir/build

CMakeFiles/NWCM.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\NWCM.dir\cmake_clean.cmake
.PHONY : CMakeFiles/NWCM.dir/clean

CMakeFiles/NWCM.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\My projects\Numerical\LPP\NWCM" "F:\My projects\Numerical\LPP\NWCM" "F:\My projects\Numerical\LPP\NWCM\cmake-build-debug" "F:\My projects\Numerical\LPP\NWCM\cmake-build-debug" "F:\My projects\Numerical\LPP\NWCM\cmake-build-debug\CMakeFiles\NWCM.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/NWCM.dir/depend

