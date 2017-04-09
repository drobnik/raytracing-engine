#ifndef RAYTRACING_ENGINE_MATERIAL_H
#define RAYTRACING_ENGINE_MATERIAL_H

#include "../Lights/LightIntensity.h"

class Material {
private:
    LightIntensity kAmbient; //TEMP
    LightIntensity kDiffuse;
    LightIntensity kSpecular;
    // Texture texture;
    float alpha;
    bool textureOn;
public:
    Material(); //TEMP
    Material(LightIntensity amb, LightIntensity diff, LightIntensity spec);
    Material(LightIntensity ambient);
    LightIntensity getAmbient()const;
    const LightIntensity &getKDiffuse() const;
    const LightIntensity &getKSpecular() const;
    bool isTextureOn() const;
};


#endif //RAYTRACING_ENGINE_MATERIAL_H
