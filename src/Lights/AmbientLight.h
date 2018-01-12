#ifndef RAYTRACING_ENGINE_AMBIENTLIFGHT_H
#define RAYTRACING_ENGINE_AMBIENTLIFGHT_H
#include "Light.h"

class AmbientLight : public Light {
public:
    AmbientLight();
    ~AmbientLight() {};
    AmbientLight(const LightIntensity& color, float intensity);
    AmbientLight(const AmbientLight& l);
    virtual Vector3 getDirection(ShadeInfo& info);
    virtual LightIntensity L(ShadeInfo& info);
};


#endif //RAYTRACING_ENGINE_AMBIENTLIFGHT_H
