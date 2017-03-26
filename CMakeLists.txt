cmake_minimum_required(VERSION 3.6)
project(raytracing_engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp Geometry/Vector3.cpp Geometry/Vector3.h Geometry/Ray.cpp
        Geometry/Ray.h Geometry/Objects/Sphere.cpp Geometry/Objects/Sphere.h Geometry/Objects/Primitive.cpp
        Geometry/Objects/Primitive.h Geometry/Objects/Plane.cpp Geometry/Objects/Plane.h Scene.cpp
        Scene.h Utilities/Utility.cpp Utilities/Utility.h lib/bitmap/bitmap_image.hpp
        Cameras/Camera.h EngineImage.cpp EngineImage.h Utilities/FileManager.cpp
        Utilities/FileManager.h Lights/LightIntensity.cpp Lights/LightIntensity.h
        Cameras/OrthoCamera.cpp Cameras/OrthoCamera.h Renderer.cpp Renderer.h Cameras/Camera.cpp)
add_executable(raytracing_engine ${SOURCE_FILES})