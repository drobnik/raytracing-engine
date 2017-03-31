#include "Material.h"

Material::Material() {
    //ambientColor = LightIntensity(0.5f, 0.5f, 0.5f);
}

Material::Material(LightIntensity diff) : Material(){
    ambientColor = diff;
}

LightIntensity Material::getColor()const {
    return ambientColor;
}

