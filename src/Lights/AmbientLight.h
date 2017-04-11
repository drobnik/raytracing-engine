#ifndef RAYTRACING_ENGINE_AMBIENTLIFGHT_H
#define RAYTRACING_ENGINE_AMBIENTLIFGHT_H
#include "Light.h"

class AmbientLight : public Light {
private:
    float ls;
    LightIntensity color;
public:
    AmbientLight();
    ~AmbientLight();
    AmbientLight(const AmbientLight& l);
    virtual Vector3 getDirection(ShadeInfo& info);
    virtual LightIntensity L(ShadeInfo& info);
};


#endif //RAYTRACING_ENGINE_AMBIENTLIFGHT_H
