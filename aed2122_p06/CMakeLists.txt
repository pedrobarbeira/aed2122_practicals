cmake_minimum_required(VERSION 3.10)
project(aed2122_p06)

set(CMAKE_CXX_STANDARD 11)

add_subdirectory(lib/googletest-master)
include_directories(lib/googletest-master/googletest/include)
include_directories(lib/googletest-master/googlemock/include)

set(CMAKE_RUNTIME_OUTPUT_DIRECTORY "${CMAKE_CURRENT_SOURCE_DIR}/Tests")

add_executable(aed2122_p06 main.cpp Tests/tests.cpp Tests/dictionary.cpp Tests/game.cpp Tests/bst.h Tests/binaryTree.h)

target_link_libraries(aed2122_p06 gtest gtest_main)
