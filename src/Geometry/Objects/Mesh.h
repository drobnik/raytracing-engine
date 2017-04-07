#ifndef RAYTRACING_ENGINE_MESH_H
#define RAYTRACING_ENGINE_MESH_H
#include <vector>
#include <fstream>
#include <iostream>
#include <string>
#include "Triangle.h"
#include "../../Engine/ShadeInfo.h"
#include "Sphere.h"

class Mesh {
private:
    std::vector<Triangle> triangles;
    Sphere simpleBounding;
public:
    Mesh();
    ~Mesh();
    Mesh(const Mesh& m);
    Mesh(std::vector<Triangle> tris);
    ShadeInfo intersects(const Ray &ray, Scene &scene); //TODO: one list for all of them
    void show();
};


#endif //RAYTRACING_ENGINE_MESH_H
