#ifndef RAYTRACING_ENGINE_POINTLIGHT_H
#define RAYTRACING_ENGINE_POINTLIGHT_H
#include "../Geometry/Vector3.h"
#include "../Engine/ShadeInfo.h"
#include "../Geometry/Ray.h"

class PointLight {
private:
    Vector3 positionL;
    float constAttr;
    float linearAttr;
public:
    bool isInShadow(Ray& ray, ShadeInfo& info);
    LightIntensity getDiffuse(Vector3 camPos, ShadeInfo& info);
    LightIntensity getSpecular(Vector3 camPos, ShadeInfo& info);


};


#endif //RAYTRACING_ENGINE_POINTLIGHT_H
