#include "ShadeInfo.h"

ShadeInfo::ShadeInfo(Scene &scene) : scene(scene), state(miss) {}

ShadeInfo::~ShadeInfo() { }

ShadeInfo::ShadeInfo(const ShadeInfo &info)
        : scene(info.scene),
          state(info.state),
          material(info.material),
          intersection(info.intersection),
          normal(info.normal), lightDir(info.lightDir){}

rayState ShadeInfo::State() const {
    return state;
}

const LightIntensity &ShadeInfo::getMaterial(){
    return material;
}

void ShadeInfo::setHit(const Vector3 &intersection) {
    ShadeInfo::intersection = intersection;
}

void ShadeInfo::setMaterial(const LightIntensity &material) {
    ShadeInfo::material = material;
}

void ShadeInfo::setState(rayState state) {
    ShadeInfo::state = state;
}

void ShadeInfo::setNormal(const Vector3 &normal) {
    ShadeInfo::normal = normal;
}

const Vector3 &ShadeInfo::getHit() const {
    return intersection;
}

const Vector3 &ShadeInfo::getNormal() const{
    return ShadeInfo::normal;
}

const Ray &ShadeInfo::getRay() const {
    return ray;
}

Scene &ShadeInfo::getScene() const {
    return scene;
}

void ShadeInfo::setLightDir(const Vector3 &lightDir) {
    ShadeInfo::lightDir = lightDir;
}

const Vector3 &ShadeInfo::getLightDir() const {
    return lightDir;
}

const AmbientLight &ShadeInfo::getAmbientLight() const {
    return *ambientLight;
}

const std::vector<Light *> &ShadeInfo::getLights() const {
    return lights;
}

void ShadeInfo::setAmbientLight(AmbientLight &ambientLight) {
    ShadeInfo::ambientLight = &ambientLight;
}

void ShadeInfo::setLights(const std::vector<Light *> &lights) {
    ShadeInfo::lights = lights;
}
