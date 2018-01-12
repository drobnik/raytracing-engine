#include "ShadeInfo.h"

ShadeInfo::ShadeInfo(std::vector<std::shared_ptr<Light>> lights, std::shared_ptr<AmbientLight> ambient) : state(miss) {
    lights.swap(lights);
    ambientLight.swap(ambient);
}

ShadeInfo::~ShadeInfo() { }

ShadeInfo::ShadeInfo(const ShadeInfo &info)
        : state(info.state),
          material(info.material),
          intersection(info.intersection),
          normal(info.normal), lightDirection(info.lightDirection),
          lights(info.lights), ambientLight(info.ambientLight){}

rayState ShadeInfo::State() const { return state; }

const std::shared_ptr<Material>& ShadeInfo::getMaterial() { return material; }

void ShadeInfo::setHit(const Vector3 &intersection) { ShadeInfo::intersection = intersection; }

void ShadeInfo::setMaterial(const std::shared_ptr<Material>& material) { ShadeInfo::material = material; }

void ShadeInfo::setState(rayState state) { ShadeInfo::state = state; }

void ShadeInfo::setNormal(const Vector3 &normal) { ShadeInfo::normal = normal; }

const Vector3 &ShadeInfo::getHit() const { return intersection; }

const Vector3 &ShadeInfo::getNormal() const{ return ShadeInfo::normal; }

const Ray &ShadeInfo::getRay() const { return ray; }

const Vector3 &ShadeInfo::getLightDir() const { return lightDirection; }

std::shared_ptr<AmbientLight> &ShadeInfo::getAmbientLight() { return ambientLight; }

const std::vector<std::shared_ptr<Light>>  &ShadeInfo::getLights() const { return lights; }

