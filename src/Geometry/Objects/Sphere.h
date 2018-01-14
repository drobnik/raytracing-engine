#ifndef RAYTRACING_ENGINE_SPHERE_H
#define RAYTRACING_ENGINE_SPHERE_H
#include <cmath>
#include <algorithm>
#include "Primitive.h"
#include "../Vector3.h"

class Sphere : public Primitive{
private:
    Vector3 center;
    float radius;

public:
    Sphere();
    Sphere(const Sphere& s);
    Sphere(Vector3& center, float rad);
    rayState Intersects(const Ray &r, float &t) override;
};


#endif //RAYTRACING_ENGINE_SPHERE_H
