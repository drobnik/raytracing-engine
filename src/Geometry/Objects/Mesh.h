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
    std::shared_ptr<Sphere> simpleBounding;
public:
    Mesh();
    Mesh(const std::vector<std::shared_ptr<Triangle>> tris);
    ShadeInfo intersects(const Ray &ray, std::vector<std::shared_ptr<Light>> lights, std::shared_ptr<AmbientLight> ambient);
};


#endif //RAYTRACING_ENGINE_MESH_H
