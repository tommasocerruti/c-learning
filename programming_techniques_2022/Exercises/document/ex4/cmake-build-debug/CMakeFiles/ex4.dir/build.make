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
CMAKE_COMMAND = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe"

# The command to remove a file.
RM = "C:\Program Files\JetBrains\CLion 2021.2.1\bin\cmake\win\bin\cmake.exe" -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/ex4.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/ex4.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/ex4.dir/flags.make

CMakeFiles/ex4.dir/main.c.obj: CMakeFiles/ex4.dir/flags.make
CMakeFiles/ex4.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/ex4.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\ex4.dir\main.c.obj -c C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\main.c

CMakeFiles/ex4.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/ex4.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\main.c > CMakeFiles\ex4.dir\main.c.i

CMakeFiles/ex4.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/ex4.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\main.c -o CMakeFiles\ex4.dir\main.c.s

# Object files for target ex4
ex4_OBJECTS = \
"CMakeFiles/ex4.dir/main.c.obj"

# External object files for target ex4
ex4_EXTERNAL_OBJECTS =

ex4.exe: CMakeFiles/ex4.dir/main.c.obj
ex4.exe: CMakeFiles/ex4.dir/build.make
ex4.exe: CMakeFiles/ex4.dir/linklibs.rsp
ex4.exe: CMakeFiles/ex4.dir/objects1.rsp
ex4.exe: CMakeFiles/ex4.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable ex4.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\ex4.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/ex4.dir/build: ex4.exe
.PHONY : CMakeFiles/ex4.dir/build

CMakeFiles/ex4.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\ex4.dir\cmake_clean.cmake
.PHONY : CMakeFiles/ex4.dir/clean

CMakeFiles/ex4.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4 C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4 C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\document\ex4\cmake-build-debug\CMakeFiles\ex4.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/ex4.dir/depend

