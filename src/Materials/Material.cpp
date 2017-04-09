#include "Material.h"

Material::Material() { }

Material::Material(LightIntensity diff) : Material(){
    kAmbient = diff;
}

LightIntensity Material::getAmbient()const {
    return kAmbient;
}

Material::Material(LightIntensity amb, LightIntensity diff,
                   LightIntensity spec)
        : kAmbient(amb),
          kDiffuse(diff),
          kSpecular(spec){}

const LightIntensity &Material::getKDiffuse() const {
    return kDiffuse;
}

const LightIntensity &Material::getKSpecular() const {
    return kSpecular;
}

bool Material::isTextureOn() const {
    return textureOn;
}

