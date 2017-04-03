#ifndef RAYTRACING_ENGINE_MESH_H
#define RAYTRACING_ENGINE_MESH_H
#include <vector>
#include "Triangle.h"

class Mesh {
private:
    std::vector<Triangle> triangles;
public:
    Mesh();
    ~Mesh();
    Mesh(const Mesh& m);
    Mesh(std::vector<Triangle> tris);
    rayState intersects(Ray& ray); //TODO: one list for all of them
    void show();
};


#endif //RAYTRACING_ENGINE_MESH_H
