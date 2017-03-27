cmake_minimum_required(VERSION 3.6)
project(raytracing_engine)

set(CMAKE_CXX_STANDARD 14)

set(SOURCE_FILES main.cpp src/Geometry/Vector3.cpp src/Geometry/Vector3.h src/Geometry/Ray.cpp
        src/Geometry/Ray.h src/Geometry/Objects/Sphere.cpp src/Geometry/Objects/Sphere.h src/Geometry/Objects/Primitive.cpp
        src/Geometry/Objects/Primitive.h src/Geometry/Objects/Plane.cpp src/Geometry/Objects/Plane.h src/Engine/Scene.cpp
        src/Engine/Scene.h src/Utilities/Utility.cpp src/Utilities/Utility.h lib/bitmap/bitmap_image.hpp
        src/Cameras/Camera.h src/Engine/EngineImage.cpp src/Engine/EngineImage.h src/Utilities/FileManager.cpp
        src/Utilities/FileManager.h src/Lights/LightIntensity.cpp src/Lights/LightIntensity.h
        src/Cameras/OrthoCamera.cpp src/Cameras/OrthoCamera.h src/Engine/Renderer.cpp src/Engine/Renderer.h
        src/Cameras/Camera.cpp src/Geometry/ViewPlane.cpp src/Geometry/ViewPlane.h src/Engine/Tracer.cpp
        src/Engine/Tracer.h src/Engine/ShadeInfo.cpp src/Engine/ShadeInfo.h src/Materials/Material.cpp src/Materials/Material.h)
add_executable(raytracing_engine ${SOURCE_FILES})