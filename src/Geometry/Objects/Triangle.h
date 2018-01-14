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
    rayState Intersects(const Ray &ray, float &t) override;
    Vector3 & GetNormal();
    void SetNormal(const Vector3 &normal);
    void FlipNormal(Triangle &t);
    void Move(const Vector3 &offset);
};


#endif //RAYTRACING_ENGINE_TRIANGLE_H
