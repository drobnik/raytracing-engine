#ifndef RAYTRACING_ENGINE_PHONGMAT_H
#define RAYTRACING_ENGINE_PHONGMAT_H
#include <vector>
#include "../BRDF/SpecularBRDF.h"
#include "../BRDF/LambertBRDF.h"


class PhongMat : public Material {
private:
    std::unique_ptr<LambertBRDF> ambientBrdf;
    std::unique_ptr<LambertBRDF> diffuseBrdf;
    std::unique_ptr<SpecularBRDF> glossySpec;
public:
    PhongMat();
    PhongMat(LambertBRDF ambient, LambertBRDF diff, SpecularBRDF gloss);
    LightIntensity shade(ShadeInfo& info);
};


#endif //RAYTRACING_ENGINE_PHONGMAT_H
