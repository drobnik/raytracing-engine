#include "LambertBRDF.h"

LambertBRDF::LambertBRDF() : BRDF(), kd(0.0f), diffColor(LightIntensity(0.0f, 0.0f, 0.0f)) { }

LambertBRDF::LambertBRDF(const LambertBRDF &brdf) : BRDF(brdf),
                                                    kd(brdf.kd),
                                                    diffColor(brdf.diffColor){ }

LambertBRDF::~LambertBRDF() { }

LightIntensity LambertBRDF::f(const ShadeInfo &info, const Vector3 &wo, const Vector3 &wi) const {
    LightIntensity k = kd * diffColor;
    return ((float)INV_PI * k);
}

LightIntensity LambertBRDF::rho(const ShadeInfo &info, const Vector3 &wo) const {
    return (diffColor * kd);
}

LambertBRDF::LambertBRDF(const LightIntensity& light, const float k) : kd(k), diffColor(light){ }