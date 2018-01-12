#ifndef RAYTRACING_ENGINE_MATERIAL_H
#define RAYTRACING_ENGINE_MATERIAL_H
#include "../Lights/LightIntensity.h"

class ShadeInfo;

class Material {
public:
    Material();
    Material(std::string name, const LightIntensity& ambient, const LightIntensity& diffuse, const LightIntensity& specular);
    Material(const LightIntensity &ambient);
    Material(const Material& mat);
    ~Material();

    virtual LightIntensity shade(ShadeInfo& info)=0;
    Material& operator= (const Material& rhs);

private:
    std::string name;
    LightIntensity ambient;
    LightIntensity diffuse;
    LightIntensity specular;

    float specularAmount;
    float specularCoefficient;
    float reflectFraction;

    //Texture texture;
    float alpha;
};


#endif //RAYTRACING_ENGINE_MATERIAL_H
