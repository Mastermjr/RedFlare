cmake_minimum_required(VERSION 2.6 )
set (CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++17")
project (RedFlare)
add_executable(RedFlare examples.cpp examples.cpp examples.h)
