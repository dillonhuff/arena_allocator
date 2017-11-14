cmake_minimum_required(VERSION 2.6)

project(arena_allocator)

SET(EXTRA_CXX_COMPILE_FLAGS "-std=c++11 -I./src -I./test -O2 -Werror -Wall")

SET(CMAKE_CXX_FLAGS  "${CMAKE_CXX_FLAGS} ${EXTRA_CXX_COMPILE_FLAGS}")

INCLUDE_DIRECTORIES(./src/)

SET(TEST_FILES ./test/arena_allocator_tests.cpp)

add_executable(all-tests ${TEST_FILES})
