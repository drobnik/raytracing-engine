#ifndef RAYTRACING_ENGINE_TRIANGLE_H
#define RAYTRACING_ENGINE_TRIANGLE_H
#include "Primitive.h"

class Triangle : public Primitive{
private:
    Vector3 a, b, c; //TODO create Point3 and Point2 classes
    Vector3 normal;
    LightIntensity material;

public:
    Triangle();
    ~Triangle();
    Triangle(const Triangle& t);
    Triangle(Vector3& a, Vector3& b, Vector3& c);
    rayState intersects(Ray& ray, float& t) override;
    LightIntensity getMaterial();
    Vector3 & getNormal();
    void setNormal(const Vector3 &normal);
    void flipNormal(Triangle& t);
};


#endif //RAYTRACING_ENGINE_TRIANGLE_H
