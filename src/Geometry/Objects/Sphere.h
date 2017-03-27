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
    Sphere(Sphere* s);
    Sphere(Vector3& center, float rad);
    rayState intersects(Ray& r, float& t) override;
    Vector3 getCenter();
    float getRadius();
};


#endif //RAYTRACING_ENGINE_SPHERE_H
