#include "LightIntensity.h"

LightIntensity LightIntensity::Black = LightIntensity(0.0f, 0.0f, 0.0f);

LightIntensity LightIntensity::White = LightIntensity(1.0f, 1.0f, 1.0f);

LightIntensity LightIntensity::Grey = LightIntensity(0.7f, 0.7f, 0.7f);

float clampColor(float base) {
    if(base >= 0.0f || base <= 1.0f){
        return base;
    } else if(base > 1.0f){
        return 1.0f;
    } else if(base < 0.0f){
        return 0.0f;
    } else{
        return base;
    }
}

LightIntensity::LightIntensity() {r=0.0f, g=0.0f, b=0.0f;}

LightIntensity::LightIntensity(float r1, float g1, float b1) {
    r = clampColor(r1), g = clampColor(g1), b = clampColor(b1);
}

LightIntensity::LightIntensity(float r1, float g1){
    r = clampColor(r1), g = clampColor(g1), b = 0.0f;
}

LightIntensity::LightIntensity(float r1) {
    r = r1, g = 0.0f, b = 0.0f;
}

LightIntensity LightIntensity::operator+(const LightIntensity &l) {
    return LightIntensity(clampColor(r + l.r),
                          clampColor(g + l.g),
                          clampColor(b + l.b));
}

LightIntensity LightIntensity::operator-(const LightIntensity &l) {
    return LightIntensity(clampColor(r - l.r),
                          clampColor(g - l.g),
                          clampColor(b - l.b));
}

LightIntensity LightIntensity::operator/(const LightIntensity &l) {
    assert(l.r != 0.0f && l.g != 0.0f && l.b != 0.0f);
    return LightIntensity(r/l.r, g/l.g, b/l.b);
}

LightIntensity LightIntensity::operator/(float value) {
    if(value != 0.0f){
        return LightIntensity(r/value, g/value, b/value);
    } else{
        return LightIntensity(0.0f, 0.0f, 0.0f);
    }
}

bool LightIntensity::operator==(const LightIntensity &l) {
    return (r == l.r && g == l.g && b == l.b);
}

LightIntensity operator*(float scale, const LightIntensity &l) {
    return LightIntensity(clampColor(l.Red() * scale),
                          clampColor(l.Green() * scale),
                          clampColor(l.Blue() * scale));
}

LightIntensity operator*(const LightIntensity &l, float scale) {
    return LightIntensity(clampColor(l.Red() * scale),
                          clampColor(l.Green() * scale),
                          clampColor(l.Blue() * scale));
}

std::ostream& operator<<(std::ostream &str, LightIntensity &l) {
    str << "Light Intensity [R: " << l.Red()<<", G: "<< l.Green() << ", B: "<<l.Blue()<<" ]\n";
    return str;
}

LightIntensity::LightIntensity(const LightIntensity &l) {
    r = l.r;
    g = l.g;
    b = l.b;
}

bool LightIntensity::operator<(const LightIntensity &l) {
    return (r < l.r) && (g < l.g) && (b < l.b);
}

LightIntensity LightIntensity::add(float r1, float g1, float b1) {
    return LightIntensity(clampColor(r + r1),
                          clampColor(g + g1),
                          clampColor(b + b1));
}

bool LightIntensity::operator!=(const LightIntensity &l) {
    return !(*this == l);
}

float LightIntensity::Red() const {return clampColor(r);}
float LightIntensity::Green() const {return clampColor(g);}
float LightIntensity::Blue() const {return clampColor(b);}

LightIntensity LightIntensity::operator*(const LightIntensity l) {
    return LightIntensity(r*l.r, g*l.g, b*l.b);
}


