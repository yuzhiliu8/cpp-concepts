cmake_minimum_required(VERSION 3.10)
project(leetcode LANGUAGES CXX)
# set (PROJECT_NAME leetcode)

set(CMAKE_CXX_STANDARD 20)
set(CMAKE_CXX_STANDARD_REQUIRED ON)
set(CMAKE_BUILD_TYPE Debug)

find_package(Catch2 REQUIRED)

include_directories(${PROJECT_SOURCE_DIR}/include)

file(GLOB SRC_FILES ${PROJECT_SOURCE_DIR}/src/*.cpp)
add_library(leetcode_lib ${SRC_FILES})

add_executable(leetcode src/main.cpp)
target_link_libraries(leetcode PRIVATE leetcode_lib)


file(GLOB TEST_FILES ${PROJECT_SOURCE_DIR}/test/*.cpp)
add_executable(tests ${TEST_FILES})
target_link_libraries(tests PRIVATE leetcode_lib)


include(CTest)
include(Catch)
catch_discover_tests(tests)
