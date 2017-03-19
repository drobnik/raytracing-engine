#ifndef RAYTRACING_ENGINE_SPHERE_H
#define RAYTRACING_ENGINE_SPHERE_H
#include <cmath>
#include "Primitive.h"
#include "Vector3.h"

class Sphere : Primitive{
private:
    Vector3 center;
    float radius;
public:
    Sphere();
    Sphere(Vector3& center, float rad);
    virtual inline rayState intersects(Ray& r, float& a_dist);
};


#endif //RAYTRACING_ENGINE_SPHERE_H
