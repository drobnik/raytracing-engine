#include "Material.h"

Material::Material() : alpha(1.0f), textureOn(false) { }

Material::~Material() {}

Material&
Material::operator= (const Material& rhs){
    return (*this);
}

bool Material::isTextureOn() const {
    return textureOn;
}

Material::Material(const Material &mat) : alpha(mat.alpha),
                                          textureOn(mat.textureOn){ }

// default shade
LightIntensity Material::shade(ShadeInfo& info){
    return LightIntensity(0.0f, 0.0f, 0.0f);
}