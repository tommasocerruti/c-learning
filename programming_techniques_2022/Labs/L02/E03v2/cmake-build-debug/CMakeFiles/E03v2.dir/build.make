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
CMAKE_SOURCE_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/E03v2.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/E03v2.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/E03v2.dir/flags.make

CMakeFiles/E03v2.dir/library.c.obj: CMakeFiles/E03v2.dir/flags.make
CMakeFiles/E03v2.dir/library.c.obj: ../library.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/E03v2.dir/library.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\E03v2.dir\library.c.obj -c C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\library.c

CMakeFiles/E03v2.dir/library.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/E03v2.dir/library.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\library.c > CMakeFiles\E03v2.dir\library.c.i

CMakeFiles/E03v2.dir/library.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/E03v2.dir/library.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\library.c -o CMakeFiles\E03v2.dir\library.c.s

# Object files for target E03v2
E03v2_OBJECTS = \
"CMakeFiles/E03v2.dir/library.c.obj"

# External object files for target E03v2
E03v2_EXTERNAL_OBJECTS =

libE03v2.a: CMakeFiles/E03v2.dir/library.c.obj
libE03v2.a: CMakeFiles/E03v2.dir/build.make
libE03v2.a: CMakeFiles/E03v2.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C static library libE03v2.a"
	$(CMAKE_COMMAND) -P CMakeFiles\E03v2.dir\cmake_clean_target.cmake
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\E03v2.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/E03v2.dir/build: libE03v2.a
.PHONY : CMakeFiles/E03v2.dir/build

CMakeFiles/E03v2.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\E03v2.dir\cmake_clean.cmake
.PHONY : CMakeFiles/E03v2.dir/clean

CMakeFiles/E03v2.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2 C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2 C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Labs\L02\E03v2\cmake-build-debug\CMakeFiles\E03v2.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/E03v2.dir/depend

