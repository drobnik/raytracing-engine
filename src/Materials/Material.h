#ifndef RAYTRACING_ENGINE_MATERIAL_H
#define RAYTRACING_ENGINE_MATERIAL_H

#include "../Lights/LightIntensity.h"

class Material {
private:
    LightIntensity ambientColor; //TEMP
public:
    Material(); //TEMP
    Material(LightIntensity diff);
    LightIntensity getColor()const;
};


#endif //RAYTRACING_ENGINE_MATERIAL_H
