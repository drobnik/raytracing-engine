#include "LightIntensity.h"

LightIntensity LightIntensity::operator+(LightIntensity &l) {
    return LightIntensity(r + l.red(), g + l.green(), b + l.blue());
}

LightIntensity LightIntensity::operator-(LightIntensity &l) {
    return LightIntensity(r - l.red(), g - l.green(), b - l.blue());
}

//do i need this?! vvvv
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
/*
std::ostream operator<<(std::ostream &str, LightIntensity &l) {
    return str << "Light Intensity [R: " << l.red()<<", G: "<< l.green() << ", B: "<<l.blue();
}*/

// przekazac liste rzeczy na scenie, puscic promien z kazdego piksela. jak jestesmy
// przy jednym promieniu, to sprawdz przeciecia z kazda rzecza na scenie