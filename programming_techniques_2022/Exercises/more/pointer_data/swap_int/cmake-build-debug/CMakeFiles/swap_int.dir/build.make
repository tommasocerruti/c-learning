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
CMAKE_SOURCE_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/swap_int.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/swap_int.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/swap_int.dir/flags.make

CMakeFiles/swap_int.dir/main.c.obj: CMakeFiles/swap_int.dir/flags.make
CMakeFiles/swap_int.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/swap_int.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\swap_int.dir\main.c.obj -c C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\main.c

CMakeFiles/swap_int.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/swap_int.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\main.c > CMakeFiles\swap_int.dir\main.c.i

CMakeFiles/swap_int.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/swap_int.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\main.c -o CMakeFiles\swap_int.dir\main.c.s

# Object files for target swap_int
swap_int_OBJECTS = \
"CMakeFiles/swap_int.dir/main.c.obj"

# External object files for target swap_int
swap_int_EXTERNAL_OBJECTS =

swap_int.exe: CMakeFiles/swap_int.dir/main.c.obj
swap_int.exe: CMakeFiles/swap_int.dir/build.make
swap_int.exe: CMakeFiles/swap_int.dir/linklibs.rsp
swap_int.exe: CMakeFiles/swap_int.dir/objects1.rsp
swap_int.exe: CMakeFiles/swap_int.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable swap_int.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\swap_int.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/swap_int.dir/build: swap_int.exe
.PHONY : CMakeFiles/swap_int.dir/build

CMakeFiles/swap_int.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\swap_int.dir\cmake_clean.cmake
.PHONY : CMakeFiles/swap_int.dir/clean

CMakeFiles/swap_int.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\more\pointer_data\swap_int\cmake-build-debug\CMakeFiles\swap_int.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/swap_int.dir/depend

