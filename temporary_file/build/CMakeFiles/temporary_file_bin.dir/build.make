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
CMAKE_COMMAND = /usr/local/Cellar/cmake/3.14.5/bin/cmake

# The command to remove a file.
RM = /usr/local/Cellar/cmake/3.14.5/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/evgenstf/external_sorter/temporary_file

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/evgenstf/external_sorter/temporary_file/build

# Include any dependencies generated for this target.
include CMakeFiles/temporary_file_bin.dir/depend.make

# Include the progress variables for this target.
include CMakeFiles/temporary_file_bin.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/temporary_file_bin.dir/flags.make

CMakeFiles/temporary_file_bin.dir/main.cpp.o: CMakeFiles/temporary_file_bin.dir/flags.make
CMakeFiles/temporary_file_bin.dir/main.cpp.o: ../main.cpp
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/Users/evgenstf/external_sorter/temporary_file/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/temporary_file_bin.dir/main.cpp.o"
	/Library/Developer/CommandLineTools/usr/bin/g++  $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -o CMakeFiles/temporary_file_bin.dir/main.cpp.o -c /Users/evgenstf/external_sorter/temporary_file/main.cpp

CMakeFiles/temporary_file_bin.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/temporary_file_bin.dir/main.cpp.i"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/evgenstf/external_sorter/temporary_file/main.cpp > CMakeFiles/temporary_file_bin.dir/main.cpp.i

CMakeFiles/temporary_file_bin.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/temporary_file_bin.dir/main.cpp.s"
	/Library/Developer/CommandLineTools/usr/bin/g++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/evgenstf/external_sorter/temporary_file/main.cpp -o CMakeFiles/temporary_file_bin.dir/main.cpp.s

# Object files for target temporary_file_bin
temporary_file_bin_OBJECTS = \
"CMakeFiles/temporary_file_bin.dir/main.cpp.o"

# External object files for target temporary_file_bin
temporary_file_bin_EXTERNAL_OBJECTS =

temporary_file_bin: CMakeFiles/temporary_file_bin.dir/main.cpp.o
temporary_file_bin: CMakeFiles/temporary_file_bin.dir/build.make
temporary_file_bin: libtemporary_file.a
temporary_file_bin: CMakeFiles/temporary_file_bin.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/Users/evgenstf/external_sorter/temporary_file/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking CXX executable temporary_file_bin"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/temporary_file_bin.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/temporary_file_bin.dir/build: temporary_file_bin

.PHONY : CMakeFiles/temporary_file_bin.dir/build

CMakeFiles/temporary_file_bin.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/temporary_file_bin.dir/cmake_clean.cmake
.PHONY : CMakeFiles/temporary_file_bin.dir/clean

CMakeFiles/temporary_file_bin.dir/depend:
	cd /Users/evgenstf/external_sorter/temporary_file/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/evgenstf/external_sorter/temporary_file /Users/evgenstf/external_sorter/temporary_file /Users/evgenstf/external_sorter/temporary_file/build /Users/evgenstf/external_sorter/temporary_file/build /Users/evgenstf/external_sorter/temporary_file/build/CMakeFiles/temporary_file_bin.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/temporary_file_bin.dir/depend
