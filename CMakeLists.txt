cmake_minimum_required(VERSION 2.8)

#project information
project(a2ece650)

#enable c++11 support
set(CMAKE_CXX_FLAGS "-std=c++11 -Wall ${CMAKE_CXX_FLAGS}")

#create the executable
add_executable(a2ece650 assignment2.cpp Graph.cpp)

