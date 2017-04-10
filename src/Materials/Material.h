#ifndef RAYTRACING_ENGINE_MATERIAL_H
#define RAYTRACING_ENGINE_MATERIAL_H
#include "../Lights/LightIntensity.h"

class ShadeInfo;

class Material {
private:
    // Texture texture;
    float alpha;
    bool textureOn;
public:
    Material();
    ~Material();
    Material(const Material& mat);
    virtual LightIntensity shade(ShadeInfo& info);
    bool isTextureOn() const;
    Material& operator= (const Material& rhs);
};


#endif //RAYTRACING_ENGINE_MATERIAL_H
