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
CMAKE_SOURCE_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/alphabetical_order.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/alphabetical_order.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/alphabetical_order.dir/flags.make

CMakeFiles/alphabetical_order.dir/main.c.obj: CMakeFiles/alphabetical_order.dir/flags.make
CMakeFiles/alphabetical_order.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/alphabetical_order.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\alphabetical_order.dir\main.c.obj -c C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\main.c

CMakeFiles/alphabetical_order.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/alphabetical_order.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\main.c > CMakeFiles\alphabetical_order.dir\main.c.i

CMakeFiles/alphabetical_order.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/alphabetical_order.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\main.c -o CMakeFiles\alphabetical_order.dir\main.c.s

# Object files for target alphabetical_order
alphabetical_order_OBJECTS = \
"CMakeFiles/alphabetical_order.dir/main.c.obj"

# External object files for target alphabetical_order
alphabetical_order_EXTERNAL_OBJECTS =

alphabetical_order.exe: CMakeFiles/alphabetical_order.dir/main.c.obj
alphabetical_order.exe: CMakeFiles/alphabetical_order.dir/build.make
alphabetical_order.exe: CMakeFiles/alphabetical_order.dir/linklibs.rsp
alphabetical_order.exe: CMakeFiles/alphabetical_order.dir/objects1.rsp
alphabetical_order.exe: CMakeFiles/alphabetical_order.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable alphabetical_order.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\alphabetical_order.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/alphabetical_order.dir/build: alphabetical_order.exe
.PHONY : CMakeFiles/alphabetical_order.dir/build

CMakeFiles/alphabetical_order.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\alphabetical_order.dir\cmake_clean.cmake
.PHONY : CMakeFiles/alphabetical_order.dir/clean

CMakeFiles/alphabetical_order.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\alphabetical_order\cmake-build-debug\CMakeFiles\alphabetical_order.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/alphabetical_order.dir/depend

