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
CMAKE_SOURCE_DIR = "F:\My projects\Numerical\Jacobi"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "F:\My projects\Numerical\Jacobi\cmake-build-debug"

# Include any dependencies generated for this target.
include CMakeFiles/Jacobi.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Jacobi.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Jacobi.dir/flags.make

CMakeFiles/Jacobi.dir/main.cpp.obj: CMakeFiles/Jacobi.dir/flags.make
CMakeFiles/Jacobi.dir/main.cpp.obj: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir="F:\My projects\Numerical\Jacobi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Jacobi.dir/main.cpp.obj"
	F:\CodeBlocks\MinGW\bin\g++.exe  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\Jacobi.dir\main.cpp.obj -c "F:\My projects\Numerical\Jacobi\main.cpp"

CMakeFiles/Jacobi.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Jacobi.dir/main.cpp.i"
	F:\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E "F:\My projects\Numerical\Jacobi\main.cpp" > CMakeFiles\Jacobi.dir\main.cpp.i

CMakeFiles/Jacobi.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Jacobi.dir/main.cpp.s"
	F:\CodeBlocks\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S "F:\My projects\Numerical\Jacobi\main.cpp" -o CMakeFiles\Jacobi.dir\main.cpp.s

# Object files for target Jacobi
Jacobi_OBJECTS = \
"CMakeFiles/Jacobi.dir/main.cpp.obj"

# External object files for target Jacobi
Jacobi_EXTERNAL_OBJECTS =

Jacobi.exe: CMakeFiles/Jacobi.dir/main.cpp.obj
Jacobi.exe: CMakeFiles/Jacobi.dir/build.make
Jacobi.exe: CMakeFiles/Jacobi.dir/linklibs.rsp
Jacobi.exe: CMakeFiles/Jacobi.dir/objects1.rsp
Jacobi.exe: CMakeFiles/Jacobi.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir="F:\My projects\Numerical\Jacobi\cmake-build-debug\CMakeFiles" --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Jacobi.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\Jacobi.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Jacobi.dir/build: Jacobi.exe

.PHONY : CMakeFiles/Jacobi.dir/build

CMakeFiles/Jacobi.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\Jacobi.dir\cmake_clean.cmake
.PHONY : CMakeFiles/Jacobi.dir/clean

CMakeFiles/Jacobi.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" "F:\My projects\Numerical\Jacobi" "F:\My projects\Numerical\Jacobi" "F:\My projects\Numerical\Jacobi\cmake-build-debug" "F:\My projects\Numerical\Jacobi\cmake-build-debug" "F:\My projects\Numerical\Jacobi\cmake-build-debug\CMakeFiles\Jacobi.dir\DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/Jacobi.dir/depend

