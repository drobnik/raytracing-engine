#include "Light.h"

Light::Light()
        : shadows(false),
          lightColor(LightIntensity::White),
          intensity(1.0f) { }

Light::~Light() {}
Light::Light(const Light &l)
        : shadows(l.shadows),
          lightColor(l.lightColor),
          intensity(l.intensity) { }

Light::Light(const LightIntensity& color, float intensity, bool shadows)
        : shadows(shadows),
          lightColor(color),
          intensity(intensity) {}

Light &Light::operator=(const Light &lr) {
    shadows = lr.shadows;
    lightColor = lr.lightColor;
    intensity = lr.intensity;
    return (*this);
}
