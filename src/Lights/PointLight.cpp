#include "PointLight.h"

PointLight::PointLight() : Light(), color(LightIntensity(1.0f, 1.0f, 1.0f)),
                           positionL(Vector3(10.0f, 10.0f, 5.0f)),
                           linearCoef(0.3f){ }

PointLight::~PointLight() { }

PointLight::PointLight(const PointLight &light)
            : Light(light),
            color(light.color),
            positionL(light.positionL),
            linearCoef(light.linearCoef){ }

PointLight::PointLight(Vector3 &pos, LightIntensity &col, float linearCoe)
            : Light(),
            color(col),
            positionL(pos),
            linearCoef(linearCoe){ }

Vector3 PointLight::getDirection(ShadeInfo &info) {
    Vector3 posahit = positionL - info.getHit();
    return posahit.normalize();
}

LightIntensity PointLight::L(ShadeInfo &info) {
    return (color * linearCoef);
}