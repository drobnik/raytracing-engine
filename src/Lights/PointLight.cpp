#include "PointLight.h"

//FIXME
bool PointLight::isInShadow(Ray &ray, ShadeInfo &info) {
    return false;
}

LightIntensity PointLight::getDiffuse(Vector3 camPos, ShadeInfo &info) {
    return LightIntensity();
}

LightIntensity PointLight::getSpecular(Vector3 camPos, ShadeInfo &info) {
    return LightIntensity();
}
