#include "Material.h"

Material::Material() { }

Material::Material(LightIntensity diff) : Material(){
    ambientColor = diff;
}

LightIntensity Material::getColor()const {
    return ambientColor;
}

