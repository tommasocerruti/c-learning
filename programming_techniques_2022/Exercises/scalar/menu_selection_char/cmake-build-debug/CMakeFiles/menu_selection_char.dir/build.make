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
CMAKE_SOURCE_DIR = C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\cmake-build-debug

# Include any dependencies generated for this target.
include CMakeFiles/menu_selection_char.dir/depend.make
# Include the progress variables for this target.
include CMakeFiles/menu_selection_char.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/menu_selection_char.dir/flags.make

CMakeFiles/menu_selection_char.dir/main.c.obj: CMakeFiles/menu_selection_char.dir/flags.make
CMakeFiles/menu_selection_char.dir/main.c.obj: ../main.c
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building C object CMakeFiles/menu_selection_char.dir/main.c.obj"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -o CMakeFiles\menu_selection_char.dir\main.c.obj -c C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\main.c

CMakeFiles/menu_selection_char.dir/main.c.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing C source to CMakeFiles/menu_selection_char.dir/main.c.i"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -E C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\main.c > CMakeFiles\menu_selection_char.dir\main.c.i

CMakeFiles/menu_selection_char.dir/main.c.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling C source to assembly CMakeFiles/menu_selection_char.dir/main.c.s"
	C:\PROGRA~1\MINGW-~1\X86_64~1.0-P\mingw64\bin\gcc.exe $(C_DEFINES) $(C_INCLUDES) $(C_FLAGS) -S C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\main.c -o CMakeFiles\menu_selection_char.dir\main.c.s

# Object files for target menu_selection_char
menu_selection_char_OBJECTS = \
"CMakeFiles/menu_selection_char.dir/main.c.obj"

# External object files for target menu_selection_char
menu_selection_char_EXTERNAL_OBJECTS =

menu_selection_char.exe: CMakeFiles/menu_selection_char.dir/main.c.obj
menu_selection_char.exe: CMakeFiles/menu_selection_char.dir/build.make
menu_selection_char.exe: CMakeFiles/menu_selection_char.dir/linklibs.rsp
menu_selection_char.exe: CMakeFiles/menu_selection_char.dir/objects1.rsp
menu_selection_char.exe: CMakeFiles/menu_selection_char.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\cmake-build-debug\CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Linking C executable menu_selection_char.exe"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles\menu_selection_char.dir\link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/menu_selection_char.dir/build: menu_selection_char.exe
.PHONY : CMakeFiles/menu_selection_char.dir/build

CMakeFiles/menu_selection_char.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles\menu_selection_char.dir\cmake_clean.cmake
.PHONY : CMakeFiles/menu_selection_char.dir/clean

CMakeFiles/menu_selection_char.dir/depend:
	$(CMAKE_COMMAND) -E cmake_depends "MinGW Makefiles" C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\cmake-build-debug C:\Users\tomma\OneDrive\Desktop\reading_material\course_PROGRAMMING.TECHNIQUES\Exercises\scalar_data\menu_selection_char\cmake-build-debug\CMakeFiles\menu_selection_char.dir\DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/menu_selection_char.dir/depend
