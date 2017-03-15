cmake_minimum_required(VERSION 3.6)
project(raytracing_engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Vector3.cpp Vector3.h)
add_executable(raytracing_engine ${SOURCE_FILES})