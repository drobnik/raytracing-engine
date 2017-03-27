#ifndef RAYTRACING_ENGINE_PLANE_H
#define RAYTRACING_ENGINE_PLANE_H
#include "Primitive.h"

class Plane : Primitive {
private:
    Vector3 normal;
    float offset;
public:
    Plane();
    ~Plane();
    Plane(const Plane& p);
    Plane(const Vector3& nor, const float& offset);
    virtual rayState intersects(Ray& r, float& t);
};


#endif //RAYTRACING_ENGINE_PLANE_H
