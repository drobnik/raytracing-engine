#include "Material.h"

Material::Material() {
    //diffuseColor = LightIntensity(0.5f, 0.5f, 0.5f);
}

Material::Material(LightIntensity diff) : Material(){
    diffuseColor = diff;
}

LightIntensity Material::getColor()const {
    return diffuseColor;
}

