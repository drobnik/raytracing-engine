#include <vector>
#include "PhongMat.h"
#include "../Lights/Light.h"

PhongMat::PhongMat() : Material(){ }

PhongMat::~PhongMat() { }

PhongMat::PhongMat(const PhongMat &phongy) : Material(phongy),
                                             ambientBrdf(phongy.ambientBrdf),
                                             diffuseBrdf(phongy.diffuseBrdf),
                                             glossySpec(phongy.glossySpec) {}

PhongMat::PhongMat(LambertBRDF *ambient, LambertBRDF *diff,
                   SpecularBRDF *gloss) {
    ambientBrdf = ambient;
    diffuseBrdf = diff;
    glossySpec = gloss;
}

LightIntensity PhongMat::shade(ShadeInfo &info) {
    Ray r = info.getRay();
    Vector3 wo = r.getDirection(), norm;
  /*  LightIntensity L = ambientBrdf->rho(info, wo.neg(wo))
                       * info.getScene().getAmbientLight()->L(info); //why*/
    LightIntensity L, diffus, gloss, diffGloss;

    typedef std::vector<Light*>::iterator iter;
    std::vector<Light*> lights = info.getScene().getLights();

    for(iter i = lights.begin(); i != lights.end(); i++){
        Vector3 wi = (*i)->getDirection(info);
        norm = info.getNormal();

        float ndotwi = norm.dot(wi);

        if(ndotwi > 0.0f) {
            diffus = diffuseBrdf->f(info, wo, wi);
            gloss = glossySpec->f(info, wo, wi);
//            diffGloss = diffus + gloss;
            /*L = (L + diffGloss) *
                    (ndotwi * (*i)->L(info));*/
        }
     }

     return L;

}
