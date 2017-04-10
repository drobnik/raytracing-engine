#include "LambertBRDF.h"

LambertBRDF::LambertBRDF() : BRDF(), kd(0.0f), diffColor(0.0f) { }

LambertBRDF::LambertBRDF(const LambertBRDF &brdf) : BRDF(brdf),
                                                    kd(brdf.kd),
                                                    diffColor(0.0f){ }

LambertBRDF::~LambertBRDF() { }

LightIntensity LambertBRDF::f(const ShadeInfo &info, const Vector3 &wo,
                              const Vector3 &wi) const {
    LightIntensity k = kd * diffColor;
    return (k * (float)INV_PI);
}

LightIntensity LambertBRDF::rho(const ShadeInfo &info, const Vector3 &wo) const {
    return (kd * diffColor);
}

float LambertBRDF::getKd() const {
    return kd;
}

const LightIntensity &LambertBRDF::getDiffColor() const {
    return diffColor;
}

void LambertBRDF::setKd(float kd) {
    LambertBRDF::kd = kd; //FIXME using this in other files!
}

void LambertBRDF::setDiffColor(const LightIntensity &diffColor) {
    LambertBRDF::diffColor = diffColor;
}