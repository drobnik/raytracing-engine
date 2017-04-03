#ifndef RAYTRACING_ENGINE_TRIANGLE_H
#define RAYTRACING_ENGINE_TRIANGLE_H
#include "Primitive.h"

class Triangle : public Primitive{
private:
    Vector3 a, b, c; //TODO create Point3 and Point2 classes
    Vector3 normal;
    Material material;
public:
    Triangle();
    ~Triangle();
    Triangle(const Triangle& t);
    Triangle(Vector3& a, Vector3& b, Vector3& c);
    rayState intersects(Ray& ray, float& t) override;
    Material getMaterial();
    void show();
};


#endif //RAYTRACING_ENGINE_TRIANGLE_H
