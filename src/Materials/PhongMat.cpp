
#include "PhongMat.h"

PhongMat::PhongMat() : Material() {
    ambientBrdf = std::make_unique<LambertBRDF>(LambertBRDF());
    diffuseBrdf = std::make_unique<LambertBRDF>(LambertBRDF());
    glossySpec = std::make_unique<SpecularBRDF>(SpecularBRDF());
}


PhongMat::PhongMat(LambertBRDF ambient, LambertBRDF diff,
                   SpecularBRDF gloss) : Material() {
    ambientBrdf = std::make_unique<LambertBRDF>(ambient);
    diffuseBrdf = std::make_unique<LambertBRDF>(diff);
    glossySpec = std::make_unique<SpecularBRDF>(gloss);
}

LightIntensity PhongMat::shade(ShadeInfo &info) {
    Ray r = info.getRay();
    Vector3 wo = r.getDirection().normalize(), norm;
    LightIntensity L = ambientBrdf->rho(info, -wo)
                       * info.getAmbientLight()->L(info);
    LightIntensity diffus, gloss, diffGloss; //diffuse light missing?

    const std::vector<std::shared_ptr<Light>> &lights = info.getLights();

    for(auto&& light: lights){
        Vector3 wi = light->getDirection(info);
        norm = info.getNormal();
        float ndotwi = norm.dot(wi);

        if(ndotwi > 0.0f) {
            diffus = diffuseBrdf->f(info, wo, wi);
            gloss = glossySpec->f(info, wo, wi);
            diffGloss = diffus + gloss;
            L = (L + diffGloss) * (ndotwi * light->L(info));
        }
     }
     return L;
}
