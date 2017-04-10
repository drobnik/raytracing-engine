#include "LightIntensity.h"

float clampColor(float base) {
    if(base >= 0.0f || base <= 1.0f){
        return base;
    } else if(base > 1.0f){
        return 1.0f;
    } else if(base < 0.0f){
        return 0.0f;
    } else{
        return base; // to turn off silly warnings
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

LightIntensity LightIntensity::operator+(LightIntensity &l) {
    return LightIntensity(clampColor(r + l.r),
                          clampColor(g + l.g),
                          clampColor(b + l.b));
}

LightIntensity LightIntensity::operator-(LightIntensity &l) {
    return LightIntensity(clampColor(r - l.red()),
                          clampColor(g - l.green()),
                          clampColor(b - l.blue()));
}

LightIntensity LightIntensity::operator/(LightIntensity &l) {
    assert(l.r != 0.0f && l.g != 0.0f && l.b != 0.0f);
    return LightIntensity(r/l.red(), g/l.green(), b/l.blue());
}

LightIntensity LightIntensity::operator/(float value) {
    if(value != 0.0f){
        return LightIntensity(r/value, g/value, b/value);
    } else{
        return LightIntensity(0.0f, 0.0f, 0.0f);
    }
}

bool LightIntensity::operator==(LightIntensity &l) {
    return (r == l.red() && g == l.green() && b == l.blue());
}

LightIntensity operator*(float scale, const LightIntensity &l) {
    LightIntensity lu = l; //FIXME
    return LightIntensity(clampColor(lu.red() * scale),
                          clampColor(lu.green() * scale),
                          clampColor(lu.blue() * scale));
}

LightIntensity operator*(LightIntensity &l, float scale) {
    return LightIntensity(clampColor(l.red() * scale),
                          clampColor(l.green() * scale),
                          clampColor(l.blue() * scale));
}

std::ostream& operator<<(std::ostream &str, LightIntensity &l) {
    str << "Light Intensity [R: " << l.red()<<", G: "<< l.green() << ", B: "<<l.blue()<<" ]\n";
    return str;
}

LightIntensity::LightIntensity(const LightIntensity &l) {
    r = l.r;
    g = l.g;
    b = l.b;
}

bool LightIntensity::operator<(LightIntensity &l) {
    return (r < l.r) && (g < l.g) && (b < l.b);
}

LightIntensity operator+(LightIntensity &l1, LightIntensity &l2) {
    return LightIntensity(clampColor(l1.r + l2.r),
                          clampColor(l1.g + l2.g),
                          clampColor(l1.b + l2.b));
}

LightIntensity LightIntensity::add(float r1, float g1, float b1) {
    return LightIntensity(clampColor(r + r1),
                          clampColor(g + g1),
                          clampColor(b + b1));
};

bool LightIntensity::operator!=(LightIntensity &l) {
    return !(r == l.red() && g == l.green() && b == l.blue());
}

float LightIntensity::red() {return clampColor(r);};
float LightIntensity::green() {return clampColor(g);};
float LightIntensity::blue() {return clampColor(b);}


