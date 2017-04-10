#ifndef RAYTRACING_ENGINE_PLANE_H
#define RAYTRACING_ENGINE_PLANE_H
#include "Primitive.h"

class Plane : public Primitive {
private:
    Vector3 normal;
    float offset;
    LightIntensity material;
public:
    Plane();
    ~Plane();
    Plane(const Plane& p);
    Plane(const Vector3& nor, const float& offset);
    virtual rayState intersects(Ray& r, float& t);
    virtual LightIntensity getMaterial();
};


#endif //RAYTRACING_ENGINE_PLANE_H
