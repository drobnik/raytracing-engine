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

    float Red() const;
    float Green() const;
    float Blue() const;

    LightIntensity operator+(const LightIntensity& l);
    LightIntensity add(float r1, float g1, float b1);
    LightIntensity operator*(const LightIntensity l);
    LightIntensity operator-(const LightIntensity& l);
    LightIntensity operator/(const LightIntensity& l);
    LightIntensity operator/(float value);
    bool operator<(const LightIntensity& l);
    bool operator==(const LightIntensity& l);
    bool operator!=(const LightIntensity& l);
    friend std::ostream& operator<<(std::ostream &str, LightIntensity &l);

    friend float clampColor(float base);

    static LightIntensity Black;
    static LightIntensity White;
    static LightIntensity Grey;
};

LightIntensity operator*(const float scale, const LightIntensity &l);
LightIntensity operator*(const LightIntensity& l, const float scale);


#endif //RAYTRACING_ENGINE_LIGHTINTENSITY_H
