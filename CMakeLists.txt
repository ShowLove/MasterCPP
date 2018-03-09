# Specify the minimum version for CMake
cmake_minimum_required(VERSION 2.8)

# Project's name
project(CPP)

# The following folder will be included
include_directories("${PROJECT_SOURCE_DIR}")

##########################
# practice cpp 
#########################
# add all the source files
file(GLOB CPP_PRACTICE_SOURCES CppPractice/src/*.cpp)

# add all the header files
file(GLOB CPP_PRACTICE_HEADERS CppPractice/headers/*.h)

#where your executable is, also files you want to include and link
add_executable(cpp_practice_exe ${CPP_PRACTICE_SOURCES} ${CPP_PRACTICE_HEADERS})

############################
# practice threads with gdb 
###########################
# add all the source files
file(GLOB THREADS_SOURCES Threads/src/*.cpp)

#where your executable is, also files you want to include and link
add_executable(threads_exe ${THREADS_SOURCES})



#####################################################################
# cmake .
# make -j5
# ./cpp_practice or ./ 
#####################################################################


