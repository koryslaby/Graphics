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
CMAKE_COMMAND = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake

# The command to remove a file.
RM = /opt/clion-2018.3.4/bin/cmake/linux/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/kory/CLionProjects/graphics3.1

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/kory/CLionProjects/graphics3.1/cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/GL.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/GL.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/GL.dir/flags.make

# Object files for target GL
GL_OBJECTS =

# External object files for target GL
GL_EXTERNAL_OBJECTS =

libGL.a: CMakeFiles/GL.dir/build.make
libGL.a: CMakeFiles/GL.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/kory/CLionProjects/graphics3.1/cmake-build-debug/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Linking CXX static library libGL.a"
	$(CMAKE_COMMAND) -P CMakeFiles/GL.dir/cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/GL.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/GL.dir/build: libGL.a

.PHONY : CMakeFiles/GL.dir/build

CMakeFiles/GL.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/GL.dir/cmake_clean.cmake
.PHONY : CMakeFiles/GL.dir/clean

CMakeFiles/GL.dir/depend:
	cd /home/kory/CLionProjects/graphics3.1/cmake-build-debug && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/kory/CLionProjects/graphics3.1 /home/kory/CLionProjects/graphics3.1 /home/kory/CLionProjects/graphics3.1/cmake-build-debug /home/kory/CLionProjects/graphics3.1/cmake-build-debug /home/kory/CLionProjects/graphics3.1/cmake-build-debug/CMakeFiles/GL.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/GL.dir/depend

