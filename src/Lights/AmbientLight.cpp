#include "AmbientLight.h"

AmbientLight::AmbientLight() : Light(),
                               ls(1.0f),
                               color(LightIntensity(0.5f, 1.0f, 0.5f)){ }

AmbientLight::~AmbientLight() { }

AmbientLight::AmbientLight(const AmbientLight &l) : Light(l),
                                                    ls(l.ls), color(l.color) { }

Vector3 AmbientLight::getDirection(ShadeInfo &info) {
    return (Vector3(0.0f, 0.0f, 0.0f));
}

LightIntensity AmbientLight::L(ShadeInfo &info) {
    return (ls * color);
}
