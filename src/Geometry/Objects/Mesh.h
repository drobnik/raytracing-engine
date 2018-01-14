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
    Vector3 position;
    std::vector<std::shared_ptr<Triangle>> triangles;
    std::shared_ptr<Sphere> simpleBounding;
public:
    Mesh();
    Mesh(const std::vector<std::shared_ptr<Triangle>> tris);
    ShadeInfo Intersects(const Ray& ray, ShadeInfo& info);
    void ChangePosition(const Vector3& position);
};


#endif //RAYTRACING_ENGINE_MESH_H
