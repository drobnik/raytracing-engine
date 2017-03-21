#ifndef RAYTRACING_ENGINE_PLANE_H
#define RAYTRACING_ENGINE_PLANE_H
#include "Primitive.h"

class Plane : Primitive {
private:
    Vector3 normal; // no crossproduct, or adding a point
    Vector3 offset; //D?
public:
    virtual rayState intersects(Ray& r, float& t);
    Plane();
    Plane(Vector3& nor, Vector3& offset);
};


#endif //RAYTRACING_ENGINE_PLANE_H
