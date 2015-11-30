cmake_minimum_required(VERSION 3.3)
project(geekssol)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp queue_with_stacks.cpp queue_with_stacks.h reverse_linked.cpp reverse_linked.h list_mid_ele.cpp list_mid_ele.h equilibrium_index.cpp equilibrium_index.h)
add_executable(geekssol ${SOURCE_FILES})