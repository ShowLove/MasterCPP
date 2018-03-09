# CMAKE generated file: DO NOT EDIT!
# Generated by "Unix Makefiles" Generator, CMake Version 3.9

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
CMAKE_COMMAND = /usr/local/mac-dev-env/cmake-3.9.3/bin/cmake

# The command to remove a file.
RM = /usr/local/mac-dev-env/cmake-3.9.3/bin/cmake -E remove -f

# Escaping for special characters.
EQUALS = =

# The top-level source directory on which CMake was run.
CMAKE_SOURCE_DIR = "/Users/carlosgarzon/Desktop/test folder/MasterCPP"

# The top-level build directory on which CMake was run.
CMAKE_BINARY_DIR = "/Users/carlosgarzon/Desktop/test folder/MasterCPP"

#=============================================================================
# Targets provided globally by CMake.

# Special rule for the target rebuild_cache
rebuild_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake to regenerate build system..."
	/usr/local/mac-dev-env/cmake-3.9.3/bin/cmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : rebuild_cache

# Special rule for the target rebuild_cache
rebuild_cache/fast: rebuild_cache

.PHONY : rebuild_cache/fast

# Special rule for the target edit_cache
edit_cache:
	@$(CMAKE_COMMAND) -E cmake_echo_color --switch=$(COLOR) --cyan "Running CMake cache editor..."
	/usr/local/mac-dev-env/cmake-3.9.3/bin/ccmake -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR)
.PHONY : edit_cache

# Special rule for the target edit_cache
edit_cache/fast: edit_cache

.PHONY : edit_cache/fast

# The main all target
all: cmake_check_build_system
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/carlosgarzon/Desktop/test folder/MasterCPP/CMakeFiles" "/Users/carlosgarzon/Desktop/test folder/MasterCPP/CMakeFiles/progress.marks"
	$(MAKE) -f CMakeFiles/Makefile2 all
	$(CMAKE_COMMAND) -E cmake_progress_start "/Users/carlosgarzon/Desktop/test folder/MasterCPP/CMakeFiles" 0
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
# Target rules for targets named print_from_xml_exe

# Build rule for target.
print_from_xml_exe: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 print_from_xml_exe
.PHONY : print_from_xml_exe

# fast build rule for target.
print_from_xml_exe/fast:
	$(MAKE) -f CMakeFiles/print_from_xml_exe.dir/build.make CMakeFiles/print_from_xml_exe.dir/build
.PHONY : print_from_xml_exe/fast

#=============================================================================
# Target rules for targets named threads_exe

# Build rule for target.
threads_exe: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 threads_exe
.PHONY : threads_exe

# fast build rule for target.
threads_exe/fast:
	$(MAKE) -f CMakeFiles/threads_exe.dir/build.make CMakeFiles/threads_exe.dir/build
.PHONY : threads_exe/fast

#=============================================================================
# Target rules for targets named cpp_practice_exe

# Build rule for target.
cpp_practice_exe: cmake_check_build_system
	$(MAKE) -f CMakeFiles/Makefile2 cpp_practice_exe
.PHONY : cpp_practice_exe

# fast build rule for target.
cpp_practice_exe/fast:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/build
.PHONY : cpp_practice_exe/fast

CppPractice/src/StudyConst.o: CppPractice/src/StudyConst.cpp.o

.PHONY : CppPractice/src/StudyConst.o

# target to build an object file
CppPractice/src/StudyConst.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/StudyConst.cpp.o
.PHONY : CppPractice/src/StudyConst.cpp.o

CppPractice/src/StudyConst.i: CppPractice/src/StudyConst.cpp.i

.PHONY : CppPractice/src/StudyConst.i

# target to preprocess a source file
CppPractice/src/StudyConst.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/StudyConst.cpp.i
.PHONY : CppPractice/src/StudyConst.cpp.i

CppPractice/src/StudyConst.s: CppPractice/src/StudyConst.cpp.s

.PHONY : CppPractice/src/StudyConst.s

# target to generate assembly for a file
CppPractice/src/StudyConst.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/StudyConst.cpp.s
.PHONY : CppPractice/src/StudyConst.cpp.s

CppPractice/src/StudyPointers.o: CppPractice/src/StudyPointers.cpp.o

.PHONY : CppPractice/src/StudyPointers.o

# target to build an object file
CppPractice/src/StudyPointers.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/StudyPointers.cpp.o
.PHONY : CppPractice/src/StudyPointers.cpp.o

CppPractice/src/StudyPointers.i: CppPractice/src/StudyPointers.cpp.i

.PHONY : CppPractice/src/StudyPointers.i

# target to preprocess a source file
CppPractice/src/StudyPointers.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/StudyPointers.cpp.i
.PHONY : CppPractice/src/StudyPointers.cpp.i

CppPractice/src/StudyPointers.s: CppPractice/src/StudyPointers.cpp.s

.PHONY : CppPractice/src/StudyPointers.s

# target to generate assembly for a file
CppPractice/src/StudyPointers.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/StudyPointers.cpp.s
.PHONY : CppPractice/src/StudyPointers.cpp.s

CppPractice/src/Topics.o: CppPractice/src/Topics.cpp.o

.PHONY : CppPractice/src/Topics.o

# target to build an object file
CppPractice/src/Topics.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/Topics.cpp.o
.PHONY : CppPractice/src/Topics.cpp.o

CppPractice/src/Topics.i: CppPractice/src/Topics.cpp.i

.PHONY : CppPractice/src/Topics.i

# target to preprocess a source file
CppPractice/src/Topics.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/Topics.cpp.i
.PHONY : CppPractice/src/Topics.cpp.i

CppPractice/src/Topics.s: CppPractice/src/Topics.cpp.s

.PHONY : CppPractice/src/Topics.s

# target to generate assembly for a file
CppPractice/src/Topics.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/Topics.cpp.s
.PHONY : CppPractice/src/Topics.cpp.s

CppPractice/src/main.o: CppPractice/src/main.cpp.o

.PHONY : CppPractice/src/main.o

# target to build an object file
CppPractice/src/main.cpp.o:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/main.cpp.o
.PHONY : CppPractice/src/main.cpp.o

CppPractice/src/main.i: CppPractice/src/main.cpp.i

.PHONY : CppPractice/src/main.i

# target to preprocess a source file
CppPractice/src/main.cpp.i:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/main.cpp.i
.PHONY : CppPractice/src/main.cpp.i

CppPractice/src/main.s: CppPractice/src/main.cpp.s

.PHONY : CppPractice/src/main.s

# target to generate assembly for a file
CppPractice/src/main.cpp.s:
	$(MAKE) -f CMakeFiles/cpp_practice_exe.dir/build.make CMakeFiles/cpp_practice_exe.dir/CppPractice/src/main.cpp.s
.PHONY : CppPractice/src/main.cpp.s

PrintFromXml/src/XmlParser.o: PrintFromXml/src/XmlParser.cpp.o

.PHONY : PrintFromXml/src/XmlParser.o

# target to build an object file
PrintFromXml/src/XmlParser.cpp.o:
	$(MAKE) -f CMakeFiles/print_from_xml_exe.dir/build.make CMakeFiles/print_from_xml_exe.dir/PrintFromXml/src/XmlParser.cpp.o
.PHONY : PrintFromXml/src/XmlParser.cpp.o

PrintFromXml/src/XmlParser.i: PrintFromXml/src/XmlParser.cpp.i

.PHONY : PrintFromXml/src/XmlParser.i

# target to preprocess a source file
PrintFromXml/src/XmlParser.cpp.i:
	$(MAKE) -f CMakeFiles/print_from_xml_exe.dir/build.make CMakeFiles/print_from_xml_exe.dir/PrintFromXml/src/XmlParser.cpp.i
.PHONY : PrintFromXml/src/XmlParser.cpp.i

PrintFromXml/src/XmlParser.s: PrintFromXml/src/XmlParser.cpp.s

.PHONY : PrintFromXml/src/XmlParser.s

# target to generate assembly for a file
PrintFromXml/src/XmlParser.cpp.s:
	$(MAKE) -f CMakeFiles/print_from_xml_exe.dir/build.make CMakeFiles/print_from_xml_exe.dir/PrintFromXml/src/XmlParser.cpp.s
.PHONY : PrintFromXml/src/XmlParser.cpp.s

PrintFromXml/src/xmltest.o: PrintFromXml/src/xmltest.cpp.o

.PHONY : PrintFromXml/src/xmltest.o

# target to build an object file
PrintFromXml/src/xmltest.cpp.o:
	$(MAKE) -f CMakeFiles/print_from_xml_exe.dir/build.make CMakeFiles/print_from_xml_exe.dir/PrintFromXml/src/xmltest.cpp.o
.PHONY : PrintFromXml/src/xmltest.cpp.o

PrintFromXml/src/xmltest.i: PrintFromXml/src/xmltest.cpp.i

.PHONY : PrintFromXml/src/xmltest.i

# target to preprocess a source file
PrintFromXml/src/xmltest.cpp.i:
	$(MAKE) -f CMakeFiles/print_from_xml_exe.dir/build.make CMakeFiles/print_from_xml_exe.dir/PrintFromXml/src/xmltest.cpp.i
.PHONY : PrintFromXml/src/xmltest.cpp.i

PrintFromXml/src/xmltest.s: PrintFromXml/src/xmltest.cpp.s

.PHONY : PrintFromXml/src/xmltest.s

# target to generate assembly for a file
PrintFromXml/src/xmltest.cpp.s:
	$(MAKE) -f CMakeFiles/print_from_xml_exe.dir/build.make CMakeFiles/print_from_xml_exe.dir/PrintFromXml/src/xmltest.cpp.s
.PHONY : PrintFromXml/src/xmltest.cpp.s

Threads/src/Thread.o: Threads/src/Thread.cpp.o

.PHONY : Threads/src/Thread.o

# target to build an object file
Threads/src/Thread.cpp.o:
	$(MAKE) -f CMakeFiles/threads_exe.dir/build.make CMakeFiles/threads_exe.dir/Threads/src/Thread.cpp.o
.PHONY : Threads/src/Thread.cpp.o

Threads/src/Thread.i: Threads/src/Thread.cpp.i

.PHONY : Threads/src/Thread.i

# target to preprocess a source file
Threads/src/Thread.cpp.i:
	$(MAKE) -f CMakeFiles/threads_exe.dir/build.make CMakeFiles/threads_exe.dir/Threads/src/Thread.cpp.i
.PHONY : Threads/src/Thread.cpp.i

Threads/src/Thread.s: Threads/src/Thread.cpp.s

.PHONY : Threads/src/Thread.s

# target to generate assembly for a file
Threads/src/Thread.cpp.s:
	$(MAKE) -f CMakeFiles/threads_exe.dir/build.make CMakeFiles/threads_exe.dir/Threads/src/Thread.cpp.s
.PHONY : Threads/src/Thread.cpp.s

# Help Target
help:
	@echo "The following are some of the valid targets for this Makefile:"
	@echo "... all (the default if no target is provided)"
	@echo "... clean"
	@echo "... depend"
	@echo "... rebuild_cache"
	@echo "... edit_cache"
	@echo "... print_from_xml_exe"
	@echo "... threads_exe"
	@echo "... cpp_practice_exe"
	@echo "... CppPractice/src/StudyConst.o"
	@echo "... CppPractice/src/StudyConst.i"
	@echo "... CppPractice/src/StudyConst.s"
	@echo "... CppPractice/src/StudyPointers.o"
	@echo "... CppPractice/src/StudyPointers.i"
	@echo "... CppPractice/src/StudyPointers.s"
	@echo "... CppPractice/src/Topics.o"
	@echo "... CppPractice/src/Topics.i"
	@echo "... CppPractice/src/Topics.s"
	@echo "... CppPractice/src/main.o"
	@echo "... CppPractice/src/main.i"
	@echo "... CppPractice/src/main.s"
	@echo "... PrintFromXml/src/XmlParser.o"
	@echo "... PrintFromXml/src/XmlParser.i"
	@echo "... PrintFromXml/src/XmlParser.s"
	@echo "... PrintFromXml/src/xmltest.o"
	@echo "... PrintFromXml/src/xmltest.i"
	@echo "... PrintFromXml/src/xmltest.s"
	@echo "... Threads/src/Thread.o"
	@echo "... Threads/src/Thread.i"
	@echo "... Threads/src/Thread.s"
.PHONY : help



#=============================================================================
# Special targets to cleanup operation of make.

# Special rule to run CMake to check the build system integrity.
# No rule that depends on this can have commands that come from listfiles
# because they might be regenerated.
cmake_check_build_system:
	$(CMAKE_COMMAND) -H$(CMAKE_SOURCE_DIR) -B$(CMAKE_BINARY_DIR) --check-build-system CMakeFiles/Makefile.cmake 0
.PHONY : cmake_check_build_system

