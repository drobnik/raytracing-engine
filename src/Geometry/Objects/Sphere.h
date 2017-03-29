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
    Material material;
public:
    Sphere();
    ~Sphere();
    Sphere(const Sphere& s);
    Sphere(Sphere* s);
    Sphere(Vector3& center, float rad);
    rayState intersects(Ray& r, float& t) override;
    Vector3 getCenter();
    float getRadius();
    virtual Material getMaterial();

    void setMaterial(const Material &material);
};


#endif //RAYTRACING_ENGINE_SPHERE_H
