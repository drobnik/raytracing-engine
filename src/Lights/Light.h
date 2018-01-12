#ifndef RAYTRACING_ENGINE_LIGHT_H
#define RAYTRACING_ENGINE_LIGHT_H
#include "../Geometry/Vector3.h"
#include "LightIntensity.h"

class ShadeInfo;

class Light {
protected:
    bool shadows;
    LightIntensity lightColor;
    float intensity;

public:
    Light();
    virtual ~Light();
    Light(const LightIntensity& color, float intensity, bool shadows=false);
    Light(const Light& l);
    Light& operator=(const Light& lr);
    virtual LightIntensity L(ShadeInfo& info)=0;
    virtual Vector3 getDirection(ShadeInfo& info) = 0;
};


#endif //RAYTRACING_ENGINE_LIGHT_H
