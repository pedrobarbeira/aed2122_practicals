cmake_minimum_required(VERSION 3.10)
project(aed2122_p02)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

add_executable(aed2122_p02 main.cpp Tests/tests.cpp Tests/myVector.h)

target_link_libraries(aed2122_p02 gtest gtest_main)
