# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.22

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
CMAKE_SOURCE_DIR = /home/richie/Compiler

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /home/richie/Compiler/build

# Include any dependencies generated for this target.
include CMakeFiles/Compiler.dir/depend.make
# Include any dependencies generated by the compiler for this target.
include CMakeFiles/Compiler.dir/compiler_depend.make

# Include the progress variables for this target.
include CMakeFiles/Compiler.dir/progress.make

# Include the compile flags for this target's objects.
include CMakeFiles/Compiler.dir/flags.make

CMakeFiles/Compiler.dir/src/main.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/src/main.cpp.o: ../src/main.cpp
CMakeFiles/Compiler.dir/src/main.cpp.o: CMakeFiles/Compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richie/Compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_1) "Building CXX object CMakeFiles/Compiler.dir/src/main.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Compiler.dir/src/main.cpp.o -MF CMakeFiles/Compiler.dir/src/main.cpp.o.d -o CMakeFiles/Compiler.dir/src/main.cpp.o -c /home/richie/Compiler/src/main.cpp

CMakeFiles/Compiler.dir/src/main.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/src/main.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/richie/Compiler/src/main.cpp > CMakeFiles/Compiler.dir/src/main.cpp.i

CMakeFiles/Compiler.dir/src/main.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/src/main.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/richie/Compiler/src/main.cpp -o CMakeFiles/Compiler.dir/src/main.cpp.s

CMakeFiles/Compiler.dir/src/Keywords.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/src/Keywords.cpp.o: ../src/Keywords.cpp
CMakeFiles/Compiler.dir/src/Keywords.cpp.o: CMakeFiles/Compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richie/Compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_2) "Building CXX object CMakeFiles/Compiler.dir/src/Keywords.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Compiler.dir/src/Keywords.cpp.o -MF CMakeFiles/Compiler.dir/src/Keywords.cpp.o.d -o CMakeFiles/Compiler.dir/src/Keywords.cpp.o -c /home/richie/Compiler/src/Keywords.cpp

CMakeFiles/Compiler.dir/src/Keywords.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/src/Keywords.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/richie/Compiler/src/Keywords.cpp > CMakeFiles/Compiler.dir/src/Keywords.cpp.i

CMakeFiles/Compiler.dir/src/Keywords.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/src/Keywords.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/richie/Compiler/src/Keywords.cpp -o CMakeFiles/Compiler.dir/src/Keywords.cpp.s

CMakeFiles/Compiler.dir/src/Lexer.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/src/Lexer.cpp.o: ../src/Lexer.cpp
CMakeFiles/Compiler.dir/src/Lexer.cpp.o: CMakeFiles/Compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richie/Compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_3) "Building CXX object CMakeFiles/Compiler.dir/src/Lexer.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Compiler.dir/src/Lexer.cpp.o -MF CMakeFiles/Compiler.dir/src/Lexer.cpp.o.d -o CMakeFiles/Compiler.dir/src/Lexer.cpp.o -c /home/richie/Compiler/src/Lexer.cpp

CMakeFiles/Compiler.dir/src/Lexer.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/src/Lexer.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/richie/Compiler/src/Lexer.cpp > CMakeFiles/Compiler.dir/src/Lexer.cpp.i

CMakeFiles/Compiler.dir/src/Lexer.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/src/Lexer.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/richie/Compiler/src/Lexer.cpp -o CMakeFiles/Compiler.dir/src/Lexer.cpp.s

CMakeFiles/Compiler.dir/src/Parser.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/src/Parser.cpp.o: ../src/Parser.cpp
CMakeFiles/Compiler.dir/src/Parser.cpp.o: CMakeFiles/Compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richie/Compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_4) "Building CXX object CMakeFiles/Compiler.dir/src/Parser.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Compiler.dir/src/Parser.cpp.o -MF CMakeFiles/Compiler.dir/src/Parser.cpp.o.d -o CMakeFiles/Compiler.dir/src/Parser.cpp.o -c /home/richie/Compiler/src/Parser.cpp

CMakeFiles/Compiler.dir/src/Parser.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/src/Parser.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/richie/Compiler/src/Parser.cpp > CMakeFiles/Compiler.dir/src/Parser.cpp.i

CMakeFiles/Compiler.dir/src/Parser.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/src/Parser.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/richie/Compiler/src/Parser.cpp -o CMakeFiles/Compiler.dir/src/Parser.cpp.s

CMakeFiles/Compiler.dir/src/Testing.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/src/Testing.cpp.o: ../src/Testing.cpp
CMakeFiles/Compiler.dir/src/Testing.cpp.o: CMakeFiles/Compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richie/Compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_5) "Building CXX object CMakeFiles/Compiler.dir/src/Testing.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Compiler.dir/src/Testing.cpp.o -MF CMakeFiles/Compiler.dir/src/Testing.cpp.o.d -o CMakeFiles/Compiler.dir/src/Testing.cpp.o -c /home/richie/Compiler/src/Testing.cpp

CMakeFiles/Compiler.dir/src/Testing.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/src/Testing.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/richie/Compiler/src/Testing.cpp > CMakeFiles/Compiler.dir/src/Testing.cpp.i

CMakeFiles/Compiler.dir/src/Testing.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/src/Testing.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/richie/Compiler/src/Testing.cpp -o CMakeFiles/Compiler.dir/src/Testing.cpp.s

CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o: ../src/Utils/TokenUtils.cpp
CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o: CMakeFiles/Compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richie/Compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_6) "Building CXX object CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o -MF CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o.d -o CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o -c /home/richie/Compiler/src/Utils/TokenUtils.cpp

CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/richie/Compiler/src/Utils/TokenUtils.cpp > CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.i

CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/richie/Compiler/src/Utils/TokenUtils.cpp -o CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.s

CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o: CMakeFiles/Compiler.dir/flags.make
CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o: ../src/AstNodes/Program.cpp
CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o: CMakeFiles/Compiler.dir/compiler_depend.ts
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --progress-dir=/home/richie/Compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_7) "Building CXX object CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -MD -MT CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o -MF CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o.d -o CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o -c /home/richie/Compiler/src/AstNodes/Program.cpp

CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.i: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Preprocessing CXX source to CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.i"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -E /home/richie/Compiler/src/AstNodes/Program.cpp > CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.i

CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.s: cmake_force
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green "Compiling CXX source to assembly CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.s"
	/usr/bin/c++ $(CXX_DEFINES) $(CXX_INCLUDES) $(CXX_FLAGS) -S /home/richie/Compiler/src/AstNodes/Program.cpp -o CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.s

# Object files for target Compiler
Compiler_OBJECTS = \
"CMakeFiles/Compiler.dir/src/main.cpp.o" \
"CMakeFiles/Compiler.dir/src/Keywords.cpp.o" \
"CMakeFiles/Compiler.dir/src/Lexer.cpp.o" \
"CMakeFiles/Compiler.dir/src/Parser.cpp.o" \
"CMakeFiles/Compiler.dir/src/Testing.cpp.o" \
"CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o" \
"CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o"

# External object files for target Compiler
Compiler_EXTERNAL_OBJECTS =

Compiler: CMakeFiles/Compiler.dir/src/main.cpp.o
Compiler: CMakeFiles/Compiler.dir/src/Keywords.cpp.o
Compiler: CMakeFiles/Compiler.dir/src/Lexer.cpp.o
Compiler: CMakeFiles/Compiler.dir/src/Parser.cpp.o
Compiler: CMakeFiles/Compiler.dir/src/Testing.cpp.o
Compiler: CMakeFiles/Compiler.dir/src/Utils/TokenUtils.cpp.o
Compiler: CMakeFiles/Compiler.dir/src/AstNodes/Program.cpp.o
Compiler: CMakeFiles/Compiler.dir/build.make
Compiler: CMakeFiles/Compiler.dir/link.txt
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --green --bold --progress-dir=/home/richie/Compiler/build/CMakeFiles --progress-num=$(CMAKE_PROGRESS_8) "Linking CXX executable Compiler"
	$(CMAKE_COMMAND) -E cmake_link_script CMakeFiles/Compiler.dir/link.txt --verbose=$(VERBOSE)

# Rule to build all files generated by this target.
CMakeFiles/Compiler.dir/build: Compiler
.PHONY : CMakeFiles/Compiler.dir/build

CMakeFiles/Compiler.dir/clean:
	$(CMAKE_COMMAND) -P CMakeFiles/Compiler.dir/cmake_clean.cmake
.PHONY : CMakeFiles/Compiler.dir/clean

CMakeFiles/Compiler.dir/depend:
	cd /home/richie/Compiler/build && $(CMAKE_COMMAND) -E cmake_depends "Unix Makefiles" /home/richie/Compiler /home/richie/Compiler /home/richie/Compiler/build /home/richie/Compiler/build /home/richie/Compiler/build/CMakeFiles/Compiler.dir/DependInfo.cmake --color=$(COLOR)
.PHONY : CMakeFiles/Compiler.dir/depend

