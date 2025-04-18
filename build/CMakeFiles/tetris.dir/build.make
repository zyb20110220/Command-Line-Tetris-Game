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
CMAKE_SOURCE_DIR = /workspaces/Command-Line-Tetris-Game

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /workspaces/Command-Line-Tetris-Game/build

# Include any dependencies generated for this target.
include CMakeFiles/tetris.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/tetris.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/tetris.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/tetris.dir/flags.make

CMakeFiles/tetris.dir/src/game_logic.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/game_logic.cpp.o: /workspaces/Command-Line-Tetris-Game/src/game_logic.cpp
CMakeFiles/tetris.dir/src/game_logic.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Command-Line-Tetris-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/tetris.dir/src/game_logic.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/game_logic.cpp.o -MF CMakeFiles/tetris.dir/src/game_logic.cpp.o.d -o CMakeFiles/tetris.dir/src/game_logic.cpp.o -c /workspaces/Command-Line-Tetris-Game/src/game_logic.cpp

CMakeFiles/tetris.dir/src/game_logic.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/game_logic.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Command-Line-Tetris-Game/src/game_logic.cpp > CMakeFiles/tetris.dir/src/game_logic.cpp.i

CMakeFiles/tetris.dir/src/game_logic.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/game_logic.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Command-Line-Tetris-Game/src/game_logic.cpp -o CMakeFiles/tetris.dir/src/game_logic.cpp.s

CMakeFiles/tetris.dir/src/game_state.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/game_state.cpp.o: /workspaces/Command-Line-Tetris-Game/src/game_state.cpp
CMakeFiles/tetris.dir/src/game_state.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Command-Line-Tetris-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/tetris.dir/src/game_state.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/game_state.cpp.o -MF CMakeFiles/tetris.dir/src/game_state.cpp.o.d -o CMakeFiles/tetris.dir/src/game_state.cpp.o -c /workspaces/Command-Line-Tetris-Game/src/game_state.cpp

CMakeFiles/tetris.dir/src/game_state.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/game_state.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Command-Line-Tetris-Game/src/game_state.cpp > CMakeFiles/tetris.dir/src/game_state.cpp.i

CMakeFiles/tetris.dir/src/game_state.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/game_state.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Command-Line-Tetris-Game/src/game_state.cpp -o CMakeFiles/tetris.dir/src/game_state.cpp.s

CMakeFiles/tetris.dir/src/renderer.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/renderer.cpp.o: /workspaces/Command-Line-Tetris-Game/src/renderer.cpp
CMakeFiles/tetris.dir/src/renderer.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Command-Line-Tetris-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/tetris.dir/src/renderer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/renderer.cpp.o -MF CMakeFiles/tetris.dir/src/renderer.cpp.o.d -o CMakeFiles/tetris.dir/src/renderer.cpp.o -c /workspaces/Command-Line-Tetris-Game/src/renderer.cpp

CMakeFiles/tetris.dir/src/renderer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/renderer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Command-Line-Tetris-Game/src/renderer.cpp > CMakeFiles/tetris.dir/src/renderer.cpp.i

CMakeFiles/tetris.dir/src/renderer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/renderer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Command-Line-Tetris-Game/src/renderer.cpp -o CMakeFiles/tetris.dir/src/renderer.cpp.s

CMakeFiles/tetris.dir/src/terminal.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/terminal.cpp.o: /workspaces/Command-Line-Tetris-Game/src/terminal.cpp
CMakeFiles/tetris.dir/src/terminal.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Command-Line-Tetris-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/tetris.dir/src/terminal.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/terminal.cpp.o -MF CMakeFiles/tetris.dir/src/terminal.cpp.o.d -o CMakeFiles/tetris.dir/src/terminal.cpp.o -c /workspaces/Command-Line-Tetris-Game/src/terminal.cpp

CMakeFiles/tetris.dir/src/terminal.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/terminal.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Command-Line-Tetris-Game/src/terminal.cpp > CMakeFiles/tetris.dir/src/terminal.cpp.i

CMakeFiles/tetris.dir/src/terminal.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/terminal.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Command-Line-Tetris-Game/src/terminal.cpp -o CMakeFiles/tetris.dir/src/terminal.cpp.s

CMakeFiles/tetris.dir/src/tetris.cpp.o: CMakeFiles/tetris.dir/flags.make
CMakeFiles/tetris.dir/src/tetris.cpp.o: /workspaces/Command-Line-Tetris-Game/src/tetris.cpp
CMakeFiles/tetris.dir/src/tetris.cpp.o: CMakeFiles/tetris.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --progress-dir=/workspaces/Command-Line-Tetris-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/tetris.dir/src/tetris.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/tetris.dir/src/tetris.cpp.o -MF CMakeFiles/tetris.dir/src/tetris.cpp.o.d -o CMakeFiles/tetris.dir/src/tetris.cpp.o -c /workspaces/Command-Line-Tetris-Game/src/tetris.cpp

CMakeFiles/tetris.dir/src/tetris.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Preprocessing CXX source to CMakeFiles/tetris.dir/src/tetris.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /workspaces/Command-Line-Tetris-Game/src/tetris.cpp > CMakeFiles/tetris.dir/src/tetris.cpp.i

CMakeFiles/tetris.dir/src/tetris.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green "Compiling CXX source to assembly CMakeFiles/tetris.dir/src/tetris.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /workspaces/Command-Line-Tetris-Game/src/tetris.cpp -o CMakeFiles/tetris.dir/src/tetris.cpp.s

# Object files for target tetris
tetris_OBJECTS = \
"CMakeFiles/tetris.dir/src/game_logic.cpp.o" \
"CMakeFiles/tetris.dir/src/game_state.cpp.o" \
"CMakeFiles/tetris.dir/src/renderer.cpp.o" \
"CMakeFiles/tetris.dir/src/terminal.cpp.o" \
"CMakeFiles/tetris.dir/src/tetris.cpp.o"

# External object files for target tetris
tetris_EXTERNAL_OBJECTS =

tetris: CMakeFiles/tetris.dir/src/game_logic.cpp.o
tetris: CMakeFiles/tetris.dir/src/game_state.cpp.o
tetris: CMakeFiles/tetris.dir/src/renderer.cpp.o
tetris: CMakeFiles/tetris.dir/src/terminal.cpp.o
tetris: CMakeFiles/tetris.dir/src/tetris.cpp.o
tetris: CMakeFiles/tetris.dir/build.make
tetris: CMakeFiles/tetris.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color "--switch=$(COLOR)" --green --bold --progress-dir=/workspaces/Command-Line-Tetris-Game/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Linking CXX executable tetris"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/tetris.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/tetris.dir/build: tetris
.PHONY : CMakeFiles/tetris.dir/build

CMakeFiles/tetris.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/tetris.dir/cmake_clean.cmake
.PHONY : CMakeFiles/tetris.dir/clean

CMakeFiles/tetris.dir/depend:
	cd /workspaces/Command-Line-Tetris-Game/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /workspaces/Command-Line-Tetris-Game /workspaces/Command-Line-Tetris-Game /workspaces/Command-Line-Tetris-Game/build /workspaces/Command-Line-Tetris-Game/build /workspaces/Command-Line-Tetris-Game/build/CMakeFiles/tetris.dir/DependInfo.cmake "--color=$(COLOR)"
.PHONY : CMakeFiles/tetris.dir/depend

