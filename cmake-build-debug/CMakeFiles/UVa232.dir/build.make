# CMAKE generated file: DO NOT EDIT!
# Generated by "MinGW Makefiles" Generator, CMake Version 3.20

# Delete rule output on recipe failure.
.DELETE_ON_ERROR:

#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:

# Disable VCS-based implicit rules.
% : %,v

# Disable VCS-based implicit rules.
% : RCS/%

# Disable VCS-based implicit rules.
% : RCS/%,v

# Disable VCS-based implicit rules.
% : SCCS/s.%

# Disable VCS-based implicit rules.
% : s.%

.SUFFIXES: .hpux_make_needs_suffix_list

# Command-line flag to silence nested $(MAKE).
$(VERBOSE)MAKESILENT = -s

#Suppress display of executed commands.
$(VERBOSE).SILENT:

# A target that is always out of date.
cmake_force:
.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

SHELL = cmd.exe

# The CMake executable.
CMAKE_COMMAND = D:\jetbrains\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe

# The command to remove a file.
RM = D:\jetbrains\apps\CLion\ch-0\212.5457.51\bin\cmake\win\bin\cmake.exe -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = D:\github\mktbhhh\Algorithmic-competition-entry-classic

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = D:\github\mktbhhh\Algorithmic-competition-entry-classic\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/UVa232.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/UVa232.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/UVa232.dir/flags.make

CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.obj: CMakeFiles/UVa232.dir/flags.make
CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.obj: ../ch3/exercises/UVa232/UVa232.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=D:\github\mktbhhh\Algorithmic-competition-entry-classic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.obj"
	D:\program\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles\UVa232.dir\ch3\exercises\UVa232\UVa232.cpp.obj -c D:\github\mktbhhh\Algorithmic-competition-entry-classic\ch3\exercises\UVa232\UVa232.cpp

CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.i"
	D:\program\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E D:\github\mktbhhh\Algorithmic-competition-entry-classic\ch3\exercises\UVa232\UVa232.cpp > CMakeFiles\UVa232.dir\ch3\exercises\UVa232\UVa232.cpp.i

CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.s"
	D:\program\MinGW\bin\g++.exe $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S D:\github\mktbhhh\Algorithmic-competition-entry-classic\ch3\exercises\UVa232\UVa232.cpp -o CMakeFiles\UVa232.dir\ch3\exercises\UVa232\UVa232.cpp.s

# Object files for target UVa232
UVa232_OBJECTS = \
"CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.obj"

# External object files for target UVa232
UVa232_EXTERNAL_OBJECTS =

UVa232.exe: CMakeFiles/UVa232.dir/ch3/exercises/UVa232/UVa232.cpp.obj
UVa232.exe: CMakeFiles/UVa232.dir/build.make
UVa232.exe: CMakeFiles/UVa232.dir/linklibs.rsp
UVa232.exe: CMakeFiles/UVa232.dir/objects1.rsp
UVa232.exe: CMakeFiles/UVa232.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=D:\github\mktbhhh\Algorithmic-competition-entry-classic\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable UVa232.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\UVa232.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/UVa232.dir/build: UVa232.exe
.PHONY : CMakeFiles/UVa232.dir/build

CMakeFiles/UVa232.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\UVa232.dir\cmake_clean.cmake
.PHONY : CMakeFiles/UVa232.dir/clean

CMakeFiles/UVa232.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" D:\github\mktbhhh\Algorithmic-competition-entry-classic D:\github\mktbhhh\Algorithmic-competition-entry-classic D:\github\mktbhhh\Algorithmic-competition-entry-classic\cmake-build-debug D:\github\mktbhhh\Algorithmic-competition-entry-classic\cmake-build-debug D:\github\mktbhhh\Algorithmic-competition-entry-classic\cmake-build-debug\CMakeFiles\UVa232.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/UVa232.dir/depend

