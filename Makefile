# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.14

# Default target executed when no arguments are given to make.
default_target: all

.PHONY : default_target

# Allow only one "make -f Makefile2" at a time, but pass parallelism.
.NOTPARALLEL:


#=============================================================================
# Special targets provided by cmake.

# Disable implicit rules so canonical targets will work.
.SUFFIXES:


# Remove some rules from gmake that .SUFFIXES does not remove.
SUFFIXES =

.SUFFIXES: .hpux_make_needs_suffix_list


# Suppress display of executed commands.
$(VERBOSE).SILENT:


# A target that is always out of date.
cmake_force:

.PHONY : cmake_force

#=============================================================================
# Set environment variables for the build.

# The shell in which to execute make rules.
SHELL = /bin/sh

# The CMake executable.
CMAKE_COMMAND = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake

# The command to remove a file.
RM = /Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /Users/grady/CLionProjects/c

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /Users/grady/CLionProjects/c

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/Applications/CLion.app/Contents/bin/cmake/mac/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/grady/CLionProjects/c/CMakeFiles /Users/grady/CLionProjects/c/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /Users/grady/CLionProjects/c/CMakeFiles 0
.PHONY : all

# The main clean target
clean:
	$(MAKE) -f CMakeFiles/Makefile2 clean
.PHONY : clean

# The main clean target
clean/fast: clean

.PHONY : clean/fast

# Prepare targets for installation.
preinstall: all
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall

# Prepare targets for installation.
preinstall/fast:
	$(MAKE) -f CMakeFiles/Makefile2 preinstall
.PHONY : preinstall/fast

# clear depends
depend:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named c

# Build rule for target.
c : cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 c
.PHONY : c

# fast build rule for target.
c/fast:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/build
.PHONY : c/fast

pex/pex1/pex1.o: pex/pex1/pex1.c.o

.PHONY : pex/pex1/pex1.o

# target to build an object file
pex/pex1/pex1.c.o:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/pex/pex1/pex1.c.o
.PHONY : pex/pex1/pex1.c.o

pex/pex1/pex1.i: pex/pex1/pex1.c.i

.PHONY : pex/pex1/pex1.i

# target to preprocess a source file
pex/pex1/pex1.c.i:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/pex/pex1/pex1.c.i
.PHONY : pex/pex1/pex1.c.i

pex/pex1/pex1.s: pex/pex1/pex1.c.s

.PHONY : pex/pex1/pex1.s

# target to generate assembly for a file
pex/pex1/pex1.c.s:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/pex/pex1/pex1.c.s
.PHONY : pex/pex1/pex1.c.s

proj/lws-protocol.o: proj/lws-protocol.c.o

.PHONY : proj/lws-protocol.o

# target to build an object file
proj/lws-protocol.c.o:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/proj/lws-protocol.c.o
.PHONY : proj/lws-protocol.c.o

proj/lws-protocol.i: proj/lws-protocol.c.i

.PHONY : proj/lws-protocol.i

# target to preprocess a source file
proj/lws-protocol.c.i:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/proj/lws-protocol.c.i
.PHONY : proj/lws-protocol.c.i

proj/lws-protocol.s: proj/lws-protocol.c.s

.PHONY : proj/lws-protocol.s

# target to generate assembly for a file
proj/lws-protocol.c.s:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/proj/lws-protocol.c.s
.PHONY : proj/lws-protocol.c.s

proj/lws-server.o: proj/lws-server.c.o

.PHONY : proj/lws-server.o

# target to build an object file
proj/lws-server.c.o:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/proj/lws-server.c.o
.PHONY : proj/lws-server.c.o

proj/lws-server.i: proj/lws-server.c.i

.PHONY : proj/lws-server.i

# target to preprocess a source file
proj/lws-server.c.i:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/proj/lws-server.c.i
.PHONY : proj/lws-server.c.i

proj/lws-server.s: proj/lws-server.c.s

.PHONY : proj/lws-server.s

# target to generate assembly for a file
proj/lws-server.c.s:
	$(MAKE) -f CMakeFiles/c.dir/build.make CMakeFiles/c.dir/proj/lws-server.c.s
.PHONY : proj/lws-server.c.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... c"
	@echo "... pex/pex1/pex1.o"
	@echo "... pex/pex1/pex1.i"
	@echo "... pex/pex1/pex1.s"
	@echo "... proj/lws-protocol.o"
	@echo "... proj/lws-protocol.i"
	@echo "... proj/lws-protocol.s"
	@echo "... proj/lws-server.o"
	@echo "... proj/lws-server.i"
	@echo "... proj/lws-server.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -S$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system
