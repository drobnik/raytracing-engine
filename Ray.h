#ifndef RAYTRACING_ENGINE_RAY_H
#define RAYTRACING_ENGINE_RAY_H
#include "Vector3.h"

class Ray {
private:
    Vector3 origin;
    Vector3 direction;
    float distance;
    int depth;
    // float time; <- for motion blur
public:
    Ray();
    Ray(Vector3& origin, Vector3& direct);
    Ray(const Ray& parent);
    Vector3 getOrigin();
    Vector3 getDirection();
    float getDistance();
};


#endif //RAYTRACING_ENGINE_RAY_H
