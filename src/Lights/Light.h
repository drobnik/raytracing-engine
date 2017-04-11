#ifndef RAYTRACING_ENGINE_LIGHT_H
#define RAYTRACING_ENGINE_LIGHT_H
#include "../Geometry/Vector3.h"
#include "LightIntensity.h"

class ShadeInfo;

class Light {
protected:
    bool shadows;
public:
    Light();
    Light(const Light& l);
    virtual ~Light();
    Light& operator=(const Light& lr);
    virtual Vector3 getDirection(ShadeInfo& info) = 0;
    virtual LightIntensity L(ShadeInfo& info);
};


#endif //RAYTRACING_ENGINE_LIGHT_H
