#include "PhongMat.h"

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
    Vector3 wo = r.getDirection();
    LightIntensity L = ambientBrdf->rho(info, wo.neg(wo));// * info.getScene().ambient->L(info); //beware
    /*
     * typedef std::vector<Light*>::iterator iter;
     * for(iter i = info.getScene().lights.begin(); i != info.getScene().lights.end(); i++){
     *  Vector3 wi = i->getDirection(info);
     *  float ndotwi = info.getNormal() * wi;
     *
     *  if(ndotwi > 0.0f){
     *  L = L + (diffuseBrdf->f(info, wo, wi) + glossySpec->f(info, wo, wi)) * i->L(info) * ndotwi;
     * }
     *
     * return L;
     * */
    return Material::shade(info);
}
