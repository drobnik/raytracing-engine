#ifndef RAYTRACING_ENGINE_LAMBERTBRDF_H
#define RAYTRACING_ENGINE_LAMBERTBRDF_H
#include "../Lights/LightIntensity.h"
#include "BRDF.h"
#define INV_PI (1 / M_PI)

class LambertBRDF : public BRDF{
private:
    float kd; // diff reflection coe
    LightIntensity diffColor;

public:
    LambertBRDF();
    LambertBRDF(const LightIntensity& light, const float k);
    LambertBRDF(const LambertBRDF& brdf);
    ~LambertBRDF();

    LightIntensity
    f(const ShadeInfo& info, const Vector3& wo, const Vector3& wi) const override;

    LightIntensity
    rho(const ShadeInfo& info, const Vector3& wo) const override;
};


#endif //RAYTRACING_ENGINE_LAMBERTBRDF_H
