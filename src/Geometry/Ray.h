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
    Vector3 getOrigin() const;
    Vector3 getDirection() const;
    float getDistance() const;
    void setOrigin(const Vector3 &origin);
    void setDirection(const Vector3 &direction);
    void setDepth(int depth);
};


#endif //RAYTRACING_ENGINE_RAY_H
