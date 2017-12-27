#ifndef RAYTRACING_ENGINE_MESH_H
#define RAYTRACING_ENGINE_MESH_H
#include <vector>
#include <memory>
#include <fstream>
#include <iostream>
#include <string>
#include "Triangle.h"
#include "../../Engine/ShadeInfo.h"
#include "Sphere.h"

class Mesh {
private:
    std::vector<std::shared_ptr<Triangle>> triangles;
    Sphere simpleBounding; //hey, hey, throw a pointer here
public:
    Mesh();
    Mesh(const Mesh& m);
    Mesh(const std::vector<std::shared_ptr<Triangle>> tris);
    ShadeInfo intersects(const Ray &ray, Scene &scene); //TODO: one list for all of them
};


#endif //RAYTRACING_ENGINE_MESH_H
