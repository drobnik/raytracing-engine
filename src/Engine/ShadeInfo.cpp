#include "ShadeInfo.h"

ShadeInfo::ShadeInfo(Scene &scene) : scene(scene) {}

ShadeInfo::~ShadeInfo() {

}

ShadeInfo::ShadeInfo(const ShadeInfo &info) : scene(info.scene) {

}

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
