#ifndef RAYTRACING_ENGINE_RAY_H
#define RAYTRACING_ENGINE_RAY_H
#include "Vector3.h"
#include <climits>

class Ray {
private:
    Vector3 origin;
    Vector3 direction;
    float distance;
    int depth;

public:
    Ray();
    ~Ray() {};
    Ray(const Vector3& origin, const Vector3& direct);
    Ray(const Ray& parent);
    void pointAt(const Vector3 &dest);
    Vector3 getOrigin();
    Vector3 getDirection();
    float getDistance();
    void setOrigin(const Vector3 &origin);
    void setDirection(const Vector3 &direction);
    void setDepth(int depth);
};


#endif //RAYTRACING_ENGINE_RAY_H
