#ifndef RAYTRACING_ENGINE_PHONGMAT_H
#define RAYTRACING_ENGINE_PHONGMAT_H
#include "../BRDF/SpecularBRDF.h"
#include "../BRDF/LambertBRDF.h"
#include "../Engine/Scene.h"

class PhongMat : public Material {
private:
    LambertBRDF* ambientBrdf;
    LambertBRDF* diffuseBrdf;
    SpecularBRDF* glossySpec;
public:
    PhongMat();
    PhongMat(const PhongMat& phongy);
    PhongMat(LambertBRDF* ambient, LambertBRDF* diff, SpecularBRDF* gloss);
    LightIntensity shade(ShadeInfo& info);
};


#endif //RAYTRACING_ENGINE_PHONGMAT_H
