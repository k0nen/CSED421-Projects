# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.13

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
CMAKE_COMMAND = /home/kjhong/CMake/bin/cmake

# The command to remove a file.
RM = /home/kjhong/CMake/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kjhong/InMemoryIndex

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kjhong/InMemoryIndex/build

# Include any dependencies generated for this target.
include CMakeFiles/workload.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/workload.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/workload.dir/flags.make

CMakeFiles/workload.dir/main.cpp.o: CMakeFiles/workload.dir/flags.make
CMakeFiles/workload.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/kjhong/InMemoryIndex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/workload.dir/main.cpp.o"
	/opt/rh/devtoolset-7/root/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/workload.dir/main.cpp.o -c /home/kjhong/InMemoryIndex/main.cpp

CMakeFiles/workload.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/workload.dir/main.cpp.i"
	/opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/kjhong/InMemoryIndex/main.cpp > CMakeFiles/workload.dir/main.cpp.i

CMakeFiles/workload.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/workload.dir/main.cpp.s"
	/opt/rh/devtoolset-7/root/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/kjhong/InMemoryIndex/main.cpp -o CMakeFiles/workload.dir/main.cpp.s

# Object files for target workload
workload_OBJECTS = \
"CMakeFiles/workload.dir/main.cpp.o"

# External object files for target workload
workload_EXTERNAL_OBJECTS =

workload: CMakeFiles/workload.dir/main.cpp.o
workload: CMakeFiles/workload.dir/build.make
workload: CMakeFiles/workload.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kjhong/InMemoryIndex/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable workload"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/workload.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/workload.dir/build: workload

.PHONY : CMakeFiles/workload.dir/build

CMakeFiles/workload.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/workload.dir/cmake_clean.cmake
.PHONY : CMakeFiles/workload.dir/clean

CMakeFiles/workload.dir/depend:
	cd /home/kjhong/InMemoryIndex/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kjhong/InMemoryIndex /home/kjhong/InMemoryIndex /home/kjhong/InMemoryIndex/build /home/kjhong/InMemoryIndex/build /home/kjhong/InMemoryIndex/build/CMakeFiles/workload.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/workload.dir/depend
