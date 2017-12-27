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
    LightIntensity material;
   // Material* material;
public:
    Sphere();
    Sphere(const Sphere& s);
    Sphere(Sphere* s); //what? Need to define rule of three (5?)
    Sphere(Vector3& center, float rad);
    rayState intersects(Ray& r, float& t) override;
    Vector3 getCenter();
    float getRadius();
    virtual LightIntensity getMaterial();

    void setMaterial(const LightIntensity &material);
};


#endif //RAYTRACING_ENGINE_SPHERE_H
