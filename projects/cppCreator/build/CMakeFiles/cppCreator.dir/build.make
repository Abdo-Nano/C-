# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.28

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

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /mnt/sdb1/programming/C++/projects/cppCreator

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /mnt/sdb1/programming/C++/projects/cppCreator/build

# Include any dependencies generated for this target.
include CMakeFiles/cppCreator.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/cppCreator.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/cppCreator.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/cppCreator.dir/flags.make

CMakeFiles/cppCreator.dir/main.cpp.o: CMakeFiles/cppCreator.dir/flags.make
CMakeFiles/cppCreator.dir/main.cpp.o: /mnt/sdb1/programming/C++/projects/cppCreator/main.cpp
CMakeFiles/cppCreator.dir/main.cpp.o: CMakeFiles/cppCreator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/sdb1/programming/C++/projects/cppCreator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/cppCreator.dir/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cppCreator.dir/main.cpp.o -MF CMakeFiles/cppCreator.dir/main.cpp.o.d -o CMakeFiles/cppCreator.dir/main.cpp.o -c /mnt/sdb1/programming/C++/projects/cppCreator/main.cpp

CMakeFiles/cppCreator.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cppCreator.dir/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/sdb1/programming/C++/projects/cppCreator/main.cpp > CMakeFiles/cppCreator.dir/main.cpp.i

CMakeFiles/cppCreator.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cppCreator.dir/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/sdb1/programming/C++/projects/cppCreator/main.cpp -o CMakeFiles/cppCreator.dir/main.cpp.s

CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o: CMakeFiles/cppCreator.dir/flags.make
CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o: /mnt/sdb1/programming/C++/projects/cppCreator/CMakeFiles.cpp
CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o: CMakeFiles/cppCreator.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/mnt/sdb1/programming/C++/projects/cppCreator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o -MF CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o.d -o CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o -c /mnt/sdb1/programming/C++/projects/cppCreator/CMakeFiles.cpp

CMakeFiles/cppCreator.dir/CMakeFiles.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/cppCreator.dir/CMakeFiles.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /mnt/sdb1/programming/C++/projects/cppCreator/CMakeFiles.cpp > CMakeFiles/cppCreator.dir/CMakeFiles.cpp.i

CMakeFiles/cppCreator.dir/CMakeFiles.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/cppCreator.dir/CMakeFiles.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /mnt/sdb1/programming/C++/projects/cppCreator/CMakeFiles.cpp -o CMakeFiles/cppCreator.dir/CMakeFiles.cpp.s

# Object files for target cppCreator
cppCreator_OBJECTS = \
"CMakeFiles/cppCreator.dir/main.cpp.o" \
"CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o"

# External object files for target cppCreator
cppCreator_EXTERNAL_OBJECTS =

cppCreator: CMakeFiles/cppCreator.dir/main.cpp.o
cppCreator: CMakeFiles/cppCreator.dir/CMakeFiles.cpp.o
cppCreator: CMakeFiles/cppCreator.dir/build.make
cppCreator: CMakeFiles/cppCreator.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/mnt/sdb1/programming/C++/projects/cppCreator/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Linking CXX executable cppCreator"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/cppCreator.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/cppCreator.dir/build: cppCreator
.PHONY : CMakeFiles/cppCreator.dir/build

CMakeFiles/cppCreator.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/cppCreator.dir/cmake_clean.cmake
.PHONY : CMakeFiles/cppCreator.dir/clean

CMakeFiles/cppCreator.dir/depend:
	cd /mnt/sdb1/programming/C++/projects/cppCreator/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /mnt/sdb1/programming/C++/projects/cppCreator /mnt/sdb1/programming/C++/projects/cppCreator /mnt/sdb1/programming/C++/projects/cppCreator/build /mnt/sdb1/programming/C++/projects/cppCreator/build /mnt/sdb1/programming/C++/projects/cppCreator/build/CMakeFiles/cppCreator.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/cppCreator.dir/depend

