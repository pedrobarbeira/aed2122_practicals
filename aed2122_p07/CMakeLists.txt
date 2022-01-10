# AED 2021/2022 - Aula Pratica 07
# Pedro Ribeiro (DCC/FCUP) [06/12/2012]

cmake_minimum_required(VERSION 3.10)
project(aed2122_p07)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Tests")

add_executable(aed2122_p07 main.cpp Tests/tests.cpp Tests/funWithBSTs.cpp Tests/bst.h)

target_link_libraries(aed2122_p07 gtest gtest_main)
