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
    # Link the linked_list.c file to the test executable
    list(APPEND TEST_SOURCES src/linked_list.c)
    list(APPEND TEST_SOURCES src/change.c)
    list(APPEND TEST_SOURCES src/print.c)

    add_executable(test_linked_list ${TEST_SOURCES})
    target_link_libraries(test_linked_list cmocka)
else()
    message(WARNING "No test source files found in 'tests' directory.")
endif()
