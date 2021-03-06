# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.10

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
CMAKE_COMMAND = /usr/bin/cmake

# The command to remove a file.
RM = /usr/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = /root/cairo/webserver

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = /root/cairo/webserver

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "No interactive CMake dialog available..."
	/usr/bin/cmake -E echo No\ interactive\ CMake\ dialog\ available.
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start /root/cairo/webserver/CMakeFiles /root/cairo/webserver/CMakeFiles/progress.marks
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start /root/cairo/webserver/CMakeFiles 0
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
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 1
.PHONY : depend

#=============================================================================
# Target rules for targets named CServer

# Build rule for target.
CServer: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 CServer
.PHONY : CServer

# fast build rule for target.
CServer/fast:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/build
.PHONY : CServer/fast

src/dispatcher.o: src/dispatcher.cpp.o

.PHONY : src/dispatcher.o

# target to build an object file
src/dispatcher.cpp.o:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/dispatcher.cpp.o
.PHONY : src/dispatcher.cpp.o

src/dispatcher.i: src/dispatcher.cpp.i

.PHONY : src/dispatcher.i

# target to preprocess a source file
src/dispatcher.cpp.i:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/dispatcher.cpp.i
.PHONY : src/dispatcher.cpp.i

src/dispatcher.s: src/dispatcher.cpp.s

.PHONY : src/dispatcher.s

# target to generate assembly for a file
src/dispatcher.cpp.s:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/dispatcher.cpp.s
.PHONY : src/dispatcher.cpp.s

src/event_loop.o: src/event_loop.cpp.o

.PHONY : src/event_loop.o

# target to build an object file
src/event_loop.cpp.o:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/event_loop.cpp.o
.PHONY : src/event_loop.cpp.o

src/event_loop.i: src/event_loop.cpp.i

.PHONY : src/event_loop.i

# target to preprocess a source file
src/event_loop.cpp.i:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/event_loop.cpp.i
.PHONY : src/event_loop.cpp.i

src/event_loop.s: src/event_loop.cpp.s

.PHONY : src/event_loop.s

# target to generate assembly for a file
src/event_loop.cpp.s:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/event_loop.cpp.s
.PHONY : src/event_loop.cpp.s

src/main.o: src/main.cpp.o

.PHONY : src/main.o

# target to build an object file
src/main.cpp.o:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/main.cpp.o
.PHONY : src/main.cpp.o

src/main.i: src/main.cpp.i

.PHONY : src/main.i

# target to preprocess a source file
src/main.cpp.i:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/main.cpp.i
.PHONY : src/main.cpp.i

src/main.s: src/main.cpp.s

.PHONY : src/main.s

# target to generate assembly for a file
src/main.cpp.s:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/main.cpp.s
.PHONY : src/main.cpp.s

src/thread_pool.o: src/thread_pool.cpp.o

.PHONY : src/thread_pool.o

# target to build an object file
src/thread_pool.cpp.o:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/thread_pool.cpp.o
.PHONY : src/thread_pool.cpp.o

src/thread_pool.i: src/thread_pool.cpp.i

.PHONY : src/thread_pool.i

# target to preprocess a source file
src/thread_pool.cpp.i:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/thread_pool.cpp.i
.PHONY : src/thread_pool.cpp.i

src/thread_pool.s: src/thread_pool.cpp.s

.PHONY : src/thread_pool.s

# target to generate assembly for a file
src/thread_pool.cpp.s:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/thread_pool.cpp.s
.PHONY : src/thread_pool.cpp.s

src/utils.o: src/utils.cpp.o

.PHONY : src/utils.o

# target to build an object file
src/utils.cpp.o:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/utils.cpp.o
.PHONY : src/utils.cpp.o

src/utils.i: src/utils.cpp.i

.PHONY : src/utils.i

# target to preprocess a source file
src/utils.cpp.i:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/utils.cpp.i
.PHONY : src/utils.cpp.i

src/utils.s: src/utils.cpp.s

.PHONY : src/utils.s

# target to generate assembly for a file
src/utils.cpp.s:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/utils.cpp.s
.PHONY : src/utils.cpp.s

src/vhannel.o: src/vhannel.cpp.o

.PHONY : src/vhannel.o

# target to build an object file
src/vhannel.cpp.o:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/vhannel.cpp.o
.PHONY : src/vhannel.cpp.o

src/vhannel.i: src/vhannel.cpp.i

.PHONY : src/vhannel.i

# target to preprocess a source file
src/vhannel.cpp.i:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/vhannel.cpp.i
.PHONY : src/vhannel.cpp.i

src/vhannel.s: src/vhannel.cpp.s

.PHONY : src/vhannel.s

# target to generate assembly for a file
src/vhannel.cpp.s:
	$(MAKE) -f CMakeFiles/CServer.dir/build.make CMakeFiles/CServer.dir/src/vhannel.cpp.s
.PHONY : src/vhannel.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... CServer"
	@echo "... edit_cache"
	@echo "... src/dispatcher.o"
	@echo "... src/dispatcher.i"
	@echo "... src/dispatcher.s"
	@echo "... src/event_loop.o"
	@echo "... src/event_loop.i"
	@echo "... src/event_loop.s"
	@echo "... src/main.o"
	@echo "... src/main.i"
	@echo "... src/main.s"
	@echo "... src/thread_pool.o"
	@echo "... src/thread_pool.i"
	@echo "... src/thread_pool.s"
	@echo "... src/utils.o"
	@echo "... src/utils.i"
	@echo "... src/utils.s"
	@echo "... src/vhannel.o"
	@echo "... src/vhannel.i"
	@echo "... src/vhannel.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

