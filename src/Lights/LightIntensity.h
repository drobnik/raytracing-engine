#ifndef RAYTRACING_ENGINE_LIGHTINTENSITY_H
#define RAYTRACING_ENGINE_LIGHTINTENSITY_H
#include <iostream>
#include <cassert>

class LightIntensity {
protected:
    float r;
    float g;
    float b;
public:
    LightIntensity();
    LightIntensity(float r1, float g1, float b1);
    LightIntensity(float r1, float g1);
    LightIntensity(float r1);
    LightIntensity(const LightIntensity& l);

    float red();
    float green();
    float blue();

    LightIntensity operator+(LightIntensity& l);
    LightIntensity add(float r1, float g1, float b1);
    LightIntensity operator-(LightIntensity& l);
    LightIntensity operator/(LightIntensity& l);
    LightIntensity operator/(float value);
    bool operator<(LightIntensity& l);
    bool operator==(LightIntensity& l);
    bool operator!=(LightIntensity& l);
    friend LightIntensity operator*(float scale, LightIntensity& l);
    friend LightIntensity operator*(LightIntensity& l, float scale);
    friend LightIntensity operator+(LightIntensity& l1, LightIntensity& l2);
    friend std::ostream& operator<<(std::ostream &str, LightIntensity &l);
    friend float clampColor(float base);
};


#endif //RAYTRACING_ENGINE_LIGHTINTENSITY_H
