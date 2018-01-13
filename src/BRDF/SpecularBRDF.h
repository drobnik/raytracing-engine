#ifndef RAYTRACING_ENGINE_SPECULARBRDF_H
#define RAYTRACING_ENGINE_SPECULARBRDF_H
#include "BRDF.h"

class SpecularBRDF : public BRDF{
private:
    float ks;
    float exp;

public:
    SpecularBRDF();
    SpecularBRDF(const SpecularBRDF& spec);
    SpecularBRDF(float k, float exp);
    ~SpecularBRDF();

    LightIntensity
    f(const ShadeInfo& info, const Vector3& wo, const Vector3& wi) const override;

    LightIntensity
    rho(const ShadeInfo& info, const Vector3& wo) const override;

};


#endif //RAYTRACING_ENGINE_SPECULARBRDF_H
