# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.27

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
CMAKE_COMMAND = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake

# The command to remove a file.
RM = /opt/homebrew/Cellar/cmake/3.27.7/bin/cmake -E rm -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build

# Include any dependencies generated for this target.
include CMakeFiles/FiniteStateMachinesApp.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/FiniteStateMachinesApp.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/FiniteStateMachinesApp.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/FiniteStateMachinesApp.dir/flags.make

CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/flags.make
CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o: FiniteStateMachinesApp_autogen/mocs_compilation.cpp
CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o -MF CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o.d -o CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o -c /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/FiniteStateMachinesApp_autogen/mocs_compilation.cpp

CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/FiniteStateMachinesApp_autogen/mocs_compilation.cpp > CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.i

CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/FiniteStateMachinesApp_autogen/mocs_compilation.cpp -o CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.s

CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/flags.make
CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o: /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/main.cpp
CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o -MF CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o.d -o CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o -c /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/main.cpp

CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/main.cpp > CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.i

CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/main.cpp -o CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.s

CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/flags.make
CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o: /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/mainwindow.cpp
CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o -MF CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o.d -o CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o -c /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/mainwindow.cpp

CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/mainwindow.cpp > CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.i

CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/mainwindow.cpp -o CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.s

CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/flags.make
CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o: /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/dfadialog.cpp
CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o -MF CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o.d -o CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o -c /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/dfadialog.cpp

CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/dfadialog.cpp > CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.i

CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/dfadialog.cpp -o CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.s

CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/flags.make
CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o: /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/machine.cpp
CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o: CMakeFiles/FiniteStateMachinesApp.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o -MF CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o.d -o CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o -c /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/machine.cpp

CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.i"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/machine.cpp > CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.i

CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.s"
	/usr/bin/clang++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp/machine.cpp -o CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.s

# Object files for target FiniteStateMachinesApp
FiniteStateMachinesApp_OBJECTS = \
"CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o" \
"CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o" \
"CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o" \
"CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o" \
"CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o"

# External object files for target FiniteStateMachinesApp
FiniteStateMachinesApp_EXTERNAL_OBJECTS =

FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: CMakeFiles/FiniteStateMachinesApp.dir/FiniteStateMachinesApp_autogen/mocs_compilation.cpp.o
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: CMakeFiles/FiniteStateMachinesApp.dir/main.cpp.o
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: CMakeFiles/FiniteStateMachinesApp.dir/mainwindow.cpp.o
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: CMakeFiles/FiniteStateMachinesApp.dir/dfadialog.cpp.o
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: CMakeFiles/FiniteStateMachinesApp.dir/machine.cpp.o
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: CMakeFiles/FiniteStateMachinesApp.dir/build.make
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: /Users/noahmcclelland/Qt/6.6.0/macos/lib/QtWidgets.framework/Versions/A/QtWidgets
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: /Users/noahmcclelland/Qt/6.6.0/macos/lib/QtGui.framework/Versions/A/QtGui
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: /Users/noahmcclelland/Qt/6.6.0/macos/lib/QtCore.framework/Versions/A/QtCore
FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp: CMakeFiles/FiniteStateMachinesApp.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/FiniteStateMachinesApp.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/FiniteStateMachinesApp.dir/build: FiniteStateMachinesApp.app/Contents/MacOS/FiniteStateMachinesApp
.PHONY : CMakeFiles/FiniteStateMachinesApp.dir/build

CMakeFiles/FiniteStateMachinesApp.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/FiniteStateMachinesApp.dir/cmake_clean.cmake
.PHONY : CMakeFiles/FiniteStateMachinesApp.dir/clean

CMakeFiles/FiniteStateMachinesApp.dir/depend:
	cd /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/FiniteStateMachinesApp /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build /Users/noahmcclelland/Projects/GitHub/FiniteStateMachines/build/CMakeFiles/FiniteStateMachinesApp.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/FiniteStateMachinesApp.dir/depend

