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
CMAKE_SOURCE_DIR = /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth

# Include any dependencies generated for this target.
include CMakeFiles/Test.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/Test.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Test.dir/flags.make

CMakeFiles/Test.dir/main.cpp.o: CMakeFiles/Test.dir/flags.make
CMakeFiles/Test.dir/main.cpp.o: main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Test.dir/main.cpp.o"
	/usr/bin/c++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/Test.dir/main.cpp.o -c /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth/main.cpp

CMakeFiles/Test.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Test.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth/main.cpp > CMakeFiles/Test.dir/main.cpp.i

CMakeFiles/Test.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Test.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth/main.cpp -o CMakeFiles/Test.dir/main.cpp.s

CMakeFiles/Test.dir/main.cpp.o.requires:

.PHONY : CMakeFiles/Test.dir/main.cpp.o.requires

CMakeFiles/Test.dir/main.cpp.o.provides: CMakeFiles/Test.dir/main.cpp.o.requires
	$(MAKE) -f CMakeFiles/Test.dir/build.make CMakeFiles/Test.dir/main.cpp.o.provides.build
.PHONY : CMakeFiles/Test.dir/main.cpp.o.provides

CMakeFiles/Test.dir/main.cpp.o.provides.build: CMakeFiles/Test.dir/main.cpp.o


# Object files for target Test
Test_OBJECTS = \
"CMakeFiles/Test.dir/main.cpp.o"

# External object files for target Test
Test_EXTERNAL_OBJECTS =

Test: CMakeFiles/Test.dir/main.cpp.o
Test: CMakeFiles/Test.dir/build.make
Test: CMakeFiles/Test.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable Test"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Test.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Test.dir/build: Test

.PHONY : CMakeFiles/Test.dir/build

CMakeFiles/Test.dir/requires: CMakeFiles/Test.dir/main.cpp.o.requires

.PHONY : CMakeFiles/Test.dir/requires

CMakeFiles/Test.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Test.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Test.dir/clean

CMakeFiles/Test.dir/depend:
	cd /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth /home/hanxinyan/LeetCode/topic/BreadthFirstSearch/maxDepth/CMakeFiles/Test.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Test.dir/depend

