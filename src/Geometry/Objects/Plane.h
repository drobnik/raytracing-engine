#ifndef RAYTRACING_ENGINE_PLANE_H
#define RAYTRACING_ENGINE_PLANE_H
#include "Primitive.h"
#include "../../Materials/PhongMat.h"

class Plane : public Primitive {
private:
    Vector3 normal;
    float offset;

public:
    Plane();
    Plane(const Plane& p);
    Plane(const Vector3& nor, const float& offset);
    rayState Intersects(const Ray &r, float &t) override; //was virtual
};


#endif //RAYTRACING_ENGINE_PLANE_H
