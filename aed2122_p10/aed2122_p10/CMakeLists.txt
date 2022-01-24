# AED 2021/2022 - Aula Pratica 10
# Pedro Ribeiro (DCC/FCUP) [09/01/2022]

cmake_minimum_required(VERSION 3.10)
project(aed2122_p10)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Tests")

add_executable(aed2122_p10 main.cpp Tests/tests.cpp Tests/funWithGraphs.cpp Tests/graph.cpp Tests/minHeap.h Tests/disjointSets.h)

target_link_libraries(aed2122_p10 gtest gtest_main)
