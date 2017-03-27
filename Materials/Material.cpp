#include "Material.h"

Material::Material() {
    diffuseColor = LightIntensity(0.5f, 0.5f, 0.5f);
}

Material::Material(LightIntensity diff) {
    diffuseColor = diff;
}

LightIntensity Material::getColor() {
    return diffuseColor;
}

