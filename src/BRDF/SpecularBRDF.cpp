#include "SpecularBRDF.h"

SpecularBRDF::SpecularBRDF() : BRDF() {
    ks = 0.6f;
    exp = 20.0f;
}

SpecularBRDF::SpecularBRDF(float k, float ex) : ks(k), exp(ex) {}

SpecularBRDF::SpecularBRDF(const SpecularBRDF &spec) : BRDF(spec),
                                                       ks(spec.ks),
                                                       exp(spec.exp){ }

SpecularBRDF::~SpecularBRDF() {}

LightIntensity SpecularBRDF::f(const ShadeInfo &info, const Vector3 &wo, const Vector3 &wi) const {

    LightIntensity L;
    Vector3 normal = info.getNormal();
    float ndotwi = normal.dot(wi);
    Vector3 r(-wi + normal * ndotwi * 2.0f);
    float rdotwo = r.dot(wo);

    if(rdotwo > 0.0f){
        L = ks * powf(rdotwo, exp);
    }

    return L;
}

LightIntensity SpecularBRDF::rho(const ShadeInfo &info, const Vector3 &wo) const {
    return BRDF::rho(info, wo); //just black
}
