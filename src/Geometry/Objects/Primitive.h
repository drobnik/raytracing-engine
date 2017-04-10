#ifndef RAYTRACING_ENGINE_PRIMITIVE_H
#define RAYTRACING_ENGINE_PRIMITIVE_H
#include "../Ray.h"
#include "../../Materials/Material.h"

enum rayState{
    inner = -1,
    miss = 0,
    hit = 1,
    tangent = 2,
    backward = 3
};

class Primitive {
public:
    Primitive();
    ~Primitive() = default;
    Primitive(const Primitive& p) = delete;
    virtual rayState intersects(Ray& r, float& a_dist)=0;
    virtual LightIntensity getMaterial()=0;
};


#endif //RAYTRACING_ENGINE_PRIMITIVE_H
