#ifndef RAYTRACING_ENGINE_TRIANGLE_H
#define RAYTRACING_ENGINE_TRIANGLE_H
#include "../../Materials/PhongMat.h"
#include "Primitive.h"

class Triangle : public Primitive{
private:
    Vector3 a, b, c;
    Vector3 normal;

public:
    Triangle();
    ~Triangle();
    Triangle(const Triangle& t);
    Triangle(Vector3& a, Vector3& b, Vector3& c);
    rayState intersects(const Ray& ray, float& t) override;
    Vector3 & getNormal();
    void setNormal(const Vector3 &normal);
    void flipNormal(Triangle& t);
};


#endif //RAYTRACING_ENGINE_TRIANGLE_H
