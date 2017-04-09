#include "Light.h"

Light::Light() : shadows(false){ }

Light::Light(const Light &l) : shadows(l.shadows){ }

Light::~Light() { }

Light &Light::operator=(const Light &lr) {
    return (*this);
}

// radiance
LightIntensity Light::L(ShadeInfo &info) {
    return LightIntensity(0.0f, 0.0f, 0.0f);
}
