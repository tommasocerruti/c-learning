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
CMAKE_SOURCE_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/name_conversion.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/name_conversion.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/name_conversion.dir/flags.make

CMakeFiles/name_conversion.dir/main.c.obj: CMakeFiles/name_conversion.dir/flags.make
CMakeFiles/name_conversion.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/name_conversion.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\name_conversion.dir\main.c.obj -c C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\main.c

CMakeFiles/name_conversion.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/name_conversion.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\main.c > CMakeFiles\name_conversion.dir\main.c.i

CMakeFiles/name_conversion.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/name_conversion.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\main.c -o CMakeFiles\name_conversion.dir\main.c.s

# Object files for target name_conversion
name_conversion_OBJECTS = \
"CMakeFiles/name_conversion.dir/main.c.obj"

# External object files for target name_conversion
name_conversion_EXTERNAL_OBJECTS =

name_conversion.exe: CMakeFiles/name_conversion.dir/main.c.obj
name_conversion.exe: CMakeFiles/name_conversion.dir/build.make
name_conversion.exe: CMakeFiles/name_conversion.dir/linklibs.rsp
name_conversion.exe: CMakeFiles/name_conversion.dir/objects1.rsp
name_conversion.exe: CMakeFiles/name_conversion.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable name_conversion.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\name_conversion.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/name_conversion.dir/build: name_conversion.exe
.PHONY : CMakeFiles/name_conversion.dir/build

CMakeFiles/name_conversion.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\name_conversion.dir\cmake_clean.cmake
.PHONY : CMakeFiles/name_conversion.dir/clean

CMakeFiles/name_conversion.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\arrays\name_conversion\cmake-build-debug\CMakeFiles\name_conversion.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/name_conversion.dir/depend
