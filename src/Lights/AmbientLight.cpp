#include "AmbientLight.h"

AmbientLight::AmbientLight() : Light(LightIntensity(0.5f, 1.0f, 0.5f), 1.0f){ }

AmbientLight::AmbientLight(const AmbientLight &l){
    lightColor = l.lightColor;
    intensity = l.intensity;
}

Vector3 AmbientLight::getDirection(ShadeInfo &info) {
    return (Vector3(0.0f, 0.0f, 0.0f)); // maybe define zero vector?
}

LightIntensity AmbientLight::L(ShadeInfo &info) {
    //LightIntensity color = info.intersectedMaterial->Ambient() * (lightColor * intensity);
}
