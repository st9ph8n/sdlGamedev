# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

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
CMAKE_COMMAND = /usr/local/bin/cmake

# The command to remove a file.
RM = /usr/local/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /home/stephen/Documents/mathprograms/sdlGamedev

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/stephen/Documents/mathprograms/sdlGamedev/build

# Include any dependencies generated for this target.
include chapter2/CMakeFiles/gameobjlib.dir/depend.make

# Include the progress variables for this target.
include chapter2/CMakeFiles/gameobjlib.dir/progress.make

# Include the compile flags for this target's objects.
include chapter2/CMakeFiles/gameobjlib.dir/flags.make

chapter2/CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.o: chapter2/CMakeFiles/gameobjlib.dir/flags.make
chapter2/CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.o: ../include/gameobject.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/stephen/Documents/mathprograms/sdlGamedev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object chapter2/CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.o"
	cd /home/stephen/Documents/mathprograms/sdlGamedev/build/chapter2 && /usr/bin/g++-5  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.o -c /home/stephen/Documents/mathprograms/sdlGamedev/include/gameobject.cpp

chapter2/CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.i"
	cd /home/stephen/Documents/mathprograms/sdlGamedev/build/chapter2 && /usr/bin/g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/stephen/Documents/mathprograms/sdlGamedev/include/gameobject.cpp > CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.i

chapter2/CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.s"
	cd /home/stephen/Documents/mathprograms/sdlGamedev/build/chapter2 && /usr/bin/g++-5 $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/stephen/Documents/mathprograms/sdlGamedev/include/gameobject.cpp -o CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.s

# Object files for target gameobjlib
gameobjlib_OBJECTS = \
"CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.o"

# External object files for target gameobjlib
gameobjlib_EXTERNAL_OBJECTS =

chapter2/libgameobjlib.so: chapter2/CMakeFiles/gameobjlib.dir/__/include/gameobject.cpp.o
chapter2/libgameobjlib.so: chapter2/CMakeFiles/gameobjlib.dir/build.make
chapter2/libgameobjlib.so: chapter2/CMakeFiles/gameobjlib.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/stephen/Documents/mathprograms/sdlGamedev/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX shared library libgameobjlib.so"
	cd /home/stephen/Documents/mathprograms/sdlGamedev/build/chapter2 && $(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/gameobjlib.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
chapter2/CMakeFiles/gameobjlib.dir/build: chapter2/libgameobjlib.so

.PHONY : chapter2/CMakeFiles/gameobjlib.dir/build

chapter2/CMakeFiles/gameobjlib.dir/clean:
	cd /home/stephen/Documents/mathprograms/sdlGamedev/build/chapter2 && $(CMAKE_COMMAND) -P CMakeFiles/gameobjlib.dir/cmake_clean.cmake
.PHONY : chapter2/CMakeFiles/gameobjlib.dir/clean

chapter2/CMakeFiles/gameobjlib.dir/depend:
	cd /home/stephen/Documents/mathprograms/sdlGamedev/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/stephen/Documents/mathprograms/sdlGamedev /home/stephen/Documents/mathprograms/sdlGamedev/chapter2 /home/stephen/Documents/mathprograms/sdlGamedev/build /home/stephen/Documents/mathprograms/sdlGamedev/build/chapter2 /home/stephen/Documents/mathprograms/sdlGamedev/build/chapter2/CMakeFiles/gameobjlib.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : chapter2/CMakeFiles/gameobjlib.dir/depend

