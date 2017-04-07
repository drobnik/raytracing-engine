#include "ShadeInfo.h"

ShadeInfo::ShadeInfo(Scene &scene) : scene(scene), state(miss) {}

ShadeInfo::~ShadeInfo() {
    //delete scene ?!?!
}

ShadeInfo::ShadeInfo(const ShadeInfo &info)
        : scene(info.scene),
          state(info.state),
          material(info.material),
          intersection(info.intersection),
          normal(info.normal) {}

rayState ShadeInfo::State() const {
    return state;
}

const Material &ShadeInfo::getMaterial(){
    return material;
}

void ShadeInfo::setHit(const Vector3 &intersection) {
    ShadeInfo::intersection = intersection;
}

void ShadeInfo::setMaterial(const Material &material) {
    ShadeInfo::material = material;
}

void ShadeInfo::setState(rayState state) {
    ShadeInfo::state = state;
}

void ShadeInfo::setNormal(const Vector3 &normal) {
    ShadeInfo::normal = normal;
}

const Vector3 &ShadeInfo::getNormal() const {
    return normal;
}

const Vector3 &ShadeInfo::getHit() const {
    return intersection;
}

void ShadeInfo::setIntersection(const Vector3 &intersection) {
    ShadeInfo::intersection = intersection;
}
