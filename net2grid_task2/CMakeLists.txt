cmake_minimum_required(VERSION 3.10)

# Project name
project(NET2GRID-TASK C)

# Set the C standard
set(CMAKE_C_STANDARD 99)

# Include directories for headers
include_directories(inc)

# Source files for the main project
file(GLOB_RECURSE SOURCES "src/*.c")

# Test source files
file(GLOB_RECURSE TEST_SOURCES "test/*.c")

# Add the main project executable
add_executable(NET2GRID-TASK ${SOURCES})

# Add the test executable
if(TEST_SOURCES)
    list(APPEND TEST_SOURCES src/x_to_y_int.c)

    add_executable(task2_tests ${TEST_SOURCES})
    target_link_libraries(task2_tests cmocka)
else()
    message(WARNING "No test source files found in 'test' directory.")
endif()
