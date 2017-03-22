#ifndef RAYTRACING_ENGINE_PRIMITIVE_H
#define RAYTRACING_ENGINE_PRIMITIVE_H
#include "Ray.h"

enum rayState{
    inner = -1,
    miss = 0,
    hit = 1,
    tangent = 2,
    backward = 3
};

class Primitive {
public:
    virtual rayState intersects(Ray& r, float& a_dist)=0;
};


#endif //RAYTRACING_ENGINE_PRIMITIVE_H
