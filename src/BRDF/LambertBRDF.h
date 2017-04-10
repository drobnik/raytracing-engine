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
    LambertBRDF(const LambertBRDF& brdf);
    virtual ~LambertBRDF();
    virtual LightIntensity
    f(const ShadeInfo& info, const Vector3& wo, const Vector3& wi) const;
    virtual LightIntensity
    rho(const ShadeInfo& info, const Vector3& wo) const;
    void setKd(float kd);
    void setDiffColor(const LightIntensity &diffColor);
    float getKd() const;
    const LightIntensity &getDiffColor() const;
};


#endif //RAYTRACING_ENGINE_LAMBERTBRDF_H
