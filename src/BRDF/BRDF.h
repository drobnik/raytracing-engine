#ifndef RAYTRACING_ENGINE_BRDF_H
#define RAYTRACING_ENGINE_BRDF_H
#include "../Lights/LightIntensity.h"
#include "../Engine/ShadeInfo.h"

class BRDF {
public:
    BRDF();
    BRDF(const BRDF& brdf);
    BRDF& operator= (const BRDF& rhs);
    virtual ~BRDF();
    virtual LightIntensity
    f(const ShadeInfo& sr, const Vector3& wo, const Vector3& wi) const;
    virtual LightIntensity
    rho(const ShadeInfo& sr, const Vector3& wo) const;
};


#endif //RAYTRACING_ENGINE_BRDF_H
