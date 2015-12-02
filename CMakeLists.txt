cmake_minimum_required(VERSION 2.8)
project(randomNumbers)

set(CMAKE_CXX_FLAGS "${CMAKE_CXX_FLAGS} -std=c++11")

set(SOURCE_FILES main.cpp stats.cpp stats.h)
add_executable(randomNumbers ${SOURCE_FILES})
