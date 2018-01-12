#include "Material.h"

Material::Material(){}
Material::Material(std::string name, const LightIntensity& ambient,
                   const LightIntensity& diffuse, const LightIntensity& specular)
        : ambient(ambient),
          diffuse(diffuse),
          specular(specular),
          name(name),
          alpha(1.0f),
          specularAmount(0.5f),
          specularCoefficient(10.0f),
          reflectFraction(0.0f) { }

Material::~Material(){}

Material::Material(const LightIntensity &ambient)
        : ambient(ambient),
          diffuse(LightIntensity::Grey),
          specular(LightIntensity::White),
          name("null"),
          alpha(1.0f),
          specularAmount(0.5f),
          specularCoefficient(10.0f),
          reflectFraction(0.0f) { }

Material::Material(const Material& mat)
        : ambient(mat.ambient),
          diffuse(mat.diffuse),
          specular(mat.specular),
          name(mat.name),
          alpha(mat.alpha),
          specularAmount(mat.specularAmount),
          specularCoefficient(mat.specularCoefficient),
          reflectFraction(mat.reflectFraction) { }

Material&
Material::operator= (const Material& rhs){
    name = rhs.name;
    ambient = rhs.ambient;
    diffuse = rhs.diffuse;
    specular = rhs.specular;
    specularAmount = rhs.specularAmount;
    specularCoefficient = rhs.specularCoefficient;
    reflectFraction = rhs.reflectFraction;

    return (*this);
}

