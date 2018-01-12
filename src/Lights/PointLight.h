#ifndef RAYTRACING_ENGINE_POINTLIGHT_H
#define RAYTRACING_ENGINE_POINTLIGHT_H
#include "../Geometry/Vector3.h"
#include "../Engine/ShadeInfo.h"
#include "../Geometry/Ray.h"
#include "Light.h"

class PointLight : public Light{
private:
    Vector3 positionL;
    LightIntensity color;
    float linearCoefficient;
public:
    PointLight();
    ~PointLight();
    PointLight(const PointLight& light);
    PointLight(Vector3& pos, LightIntensity& col, float linearCoe);
    virtual Vector3 getDirection(ShadeInfo& info);
    virtual LightIntensity L(ShadeInfo& info);
};


#endif //RAYTRACING_ENGINE_POINTLIGHT_H
