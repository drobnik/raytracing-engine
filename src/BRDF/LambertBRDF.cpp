#include "LambertBRDF.h"

LambertBRDF::LambertBRDF() : BRDF(), kd(0.0f), diffColor(LightIntensity(0.0f, 0.0f, 0.5f)) { }

LambertBRDF::LambertBRDF(const LambertBRDF &brdf) : BRDF(brdf),
                                                    kd(brdf.kd),
                                                    diffColor(brdf.diffColor){ }

LambertBRDF::~LambertBRDF() { }

LightIntensity LambertBRDF::f(const ShadeInfo &info, const Vector3 &wo,
                              const Vector3 &wi) const {
    LightIntensity k = kd * diffColor;
    return ((float)INV_PI * k);
}

LightIntensity LambertBRDF::rho(const ShadeInfo &info, const Vector3 &wo) const {
    return (diffColor * kd);
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