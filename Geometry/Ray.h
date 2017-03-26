#ifndef RAYTRACING_ENGINE_RAY_H
#define RAYTRACING_ENGINE_RAY_H
#include "Vector3.h"
#include <climits>

class Ray {
private:
    Vector3 origin;
    Vector3 direction;
    Vector3 destination;
    float distance;
    int depth;

public:
    Ray();
    Ray(const Vector3& origin, const Vector3& direct);
    Ray(const Ray& parent);
    void pointAt(const Vector3 &dest);
    Vector3 getOrigin();
    Vector3 getDirection();
    float getDistance();
};


#endif //RAYTRACING_ENGINE_RAY_H
