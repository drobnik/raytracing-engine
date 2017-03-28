#ifndef RAYTRACING_ENGINE_LIGHTINTENSITY_H
#define RAYTRACING_ENGINE_LIGHTINTENSITY_H
#include <iostream>

class LightIntensity {
protected:
    float r;
    float g;
    float b;
public:
    inline LightIntensity() {r=0.0f, g=0.0f, b=0.0f;};
    inline LightIntensity(float r1, float g1, float b1) {r=r1, g=g1, b=b1;};
    inline LightIntensity(float r1, float g1) {r=r1, g=g1, b=0.0f;};
    inline LightIntensity(float r1) {r=r1, g=0.0f, b=0.0f;};
    LightIntensity(const LightIntensity& l);

    float red() {return r;};
    float green() {return g;};
    float blue() {return b;};

    LightIntensity operator+(LightIntensity& l);
    LightIntensity operator-(LightIntensity& l);
    LightIntensity operator/(LightIntensity& l);
    bool operator==(LightIntensity& l);
    friend LightIntensity operator*(float scale, LightIntensity& l);
    friend LightIntensity operator*(LightIntensity& l, float scale);
    friend std::ostream& operator<<(std::ostream &str, LightIntensity &l);
};


#endif //RAYTRACING_ENGINE_LIGHTINTENSITY_H
