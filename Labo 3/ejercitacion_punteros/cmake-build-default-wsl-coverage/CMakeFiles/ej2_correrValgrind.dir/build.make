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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/mnt/c/Users/aschw/CLionProjects/Algoritmos 2/Labo 3/ejercitacion_punteros"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/mnt/c/Users/aschw/CLionProjects/Algoritmos 2/Labo 3/ejercitacion_punteros/cmake-build-default-wsl-coverage"

# Utility rule file for ej2_correrValgrind.

# Include the progress variables for this target.
include CMakeFiles/ej2_correrValgrind.dir/progress.make

CMakeFiles/ej2_correrValgrind: ej1
	valgrind --leak-check=full -v ./ej1 2>&1

ej2_correrValgrind: CMakeFiles/ej2_correrValgrind
ej2_correrValgrind: CMakeFiles/ej2_correrValgrind.dir/build.make

.PHONY : ej2_correrValgrind

# Rule to build all files generated by this target.
CMakeFiles/ej2_correrValgrind.dir/build: ej2_correrValgrind

.PHONY : CMakeFiles/ej2_correrValgrind.dir/build

CMakeFiles/ej2_correrValgrind.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/ej2_correrValgrind.dir/cmake_clean.cmake
.PHONY : CMakeFiles/ej2_correrValgrind.dir/clean

CMakeFiles/ej2_correrValgrind.dir/depend:
	cd "/mnt/c/Users/aschw/CLionProjects/Algoritmos 2/Labo 3/ejercitacion_punteros/cmake-build-default-wsl-coverage" && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" "/mnt/c/Users/aschw/CLionProjects/Algoritmos 2/Labo 3/ejercitacion_punteros" "/mnt/c/Users/aschw/CLionProjects/Algoritmos 2/Labo 3/ejercitacion_punteros" "/mnt/c/Users/aschw/CLionProjects/Algoritmos 2/Labo 3/ejercitacion_punteros/cmake-build-default-wsl-coverage" "/mnt/c/Users/aschw/CLionProjects/Algoritmos 2/Labo 3/ejercitacion_punteros/cmake-build-default-wsl-coverage" "/mnt/c/Users/aschw/CLionProjects/Algoritmos 2/Labo 3/ejercitacion_punteros/cmake-build-default-wsl-coverage/CMakeFiles/ej2_correrValgrind.dir/DependInfo.cmake" --color=$(COLOR)
.PHONY : CMakeFiles/ej2_correrValgrind.dir/depend

