#include "BRDF.h"

BRDF::BRDF() { }

BRDF::BRDF(const BRDF &brdf) { }

BRDF &BRDF::operator=(const BRDF &rhs) {
    return (*this);
}

BRDF::~BRDF() { }

LightIntensity
BRDF::f(const ShadeInfo &sr, const Vector3 &wo, const Vector3 &wi) const {
    return LightIntensity(0.0f, 0.0f, 0.0f);
}

LightIntensity BRDF::rho(const ShadeInfo &sr, const Vector3 &wo) const {
    return LightIntensity(0.0f, 0.0f, 0.0f);
}
