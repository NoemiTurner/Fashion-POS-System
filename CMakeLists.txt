
project(FASHION_PROJECT)

cmake_minimum_required(VERSION 3.0)

set(CMAKE_CXX_STANDARD 11)
set(CMAKE_CXX_FLAGS "-O0")
set(CMAKE_BUILD_TYPE Debug)

# locate gtest
find_package(GTest REQUIRED)
include_directories(${GTEST_INCLUDE_DIRS})

# create unit test executable
add_executable(fashion_project_tests
               fashion_project.cpp
               fashion_project_tests.cpp)
target_link_libraries(fashion_project_tests ${GTEST_LIBRARIES} pthread)

