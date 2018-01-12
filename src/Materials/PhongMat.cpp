#include <vector>
#include "PhongMat.h"
#include "../Lights/Light.h"

PhongMat::PhongMat() : Material(){ }

PhongMat::PhongMat(const PhongMat &phongy) : Material(phongy),
                                             ambientBrdf(phongy.ambientBrdf),
                                             diffuseBrdf(phongy.diffuseBrdf),
                                             glossySpec(phongy.glossySpec) {}

PhongMat::PhongMat(LambertBRDF *ambient, LambertBRDF *diff,
                   SpecularBRDF *gloss) : ambientBrdf(ambient), diffuseBrdf(diff), glossySpec(gloss){}

LightIntensity PhongMat::shade(ShadeInfo &info) {
    Ray r = info.getRay();
    Vector3 wo = r.getDirection().normalize(), norm;
    LightIntensity L = ambientBrdf->rho(info, -wo)//wo.neg(wo))
                       * info.getScene().getAmbientLight().L(info);
    LightIntensity diffus, gloss, diffGloss; //diffuse light missing?

    std::vector<std::unique_ptr<Light>> const &lights = info.getScene().getLights(); //beware

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
