#include "LightIntensity.h"

LightIntensity LightIntensity::operator+(LightIntensity &l) {
    return LightIntensity(r + l.red(), g + l.green(), b + l.blue());
}

LightIntensity LightIntensity::operator-(LightIntensity &l) {
    return LightIntensity(r - l.red(), g - l.green(), b - l.blue());
}

LightIntensity LightIntensity::operator/(LightIntensity &l) {
    return LightIntensity(r/l.red(), g/l.green(), b/l.blue());
}

bool LightIntensity::operator==(LightIntensity &l) {
    return (r == l.red() && g == l.green() && b == l.blue());
}

LightIntensity operator*(float scale, LightIntensity &l) {
    return LightIntensity(l.red() * scale, l.green() * scale, l.blue() * scale);
}

LightIntensity operator*(LightIntensity &l, float scale) {
    return LightIntensity(l.red() * scale, l.green() * scale, l.blue() * scale);
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
