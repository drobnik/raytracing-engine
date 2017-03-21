cmake_minimum_required(VERSION 3.6)
project(raytracing_engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/Vector3.cpp include/Vector3.h src/Ray.cpp include/Ray.h src/Sphere.cpp include/Sphere.h src/Primitive.cpp include/Primitive.h src/Plane.cpp include/Plane.h src/Scene.cpp include/Scene.h src/Utility.cpp include/Utility.h)
add_executable(raytracing_engine ${SOURCE_FILES})