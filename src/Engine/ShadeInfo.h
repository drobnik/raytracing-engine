#ifndef RAYTRACING_ENGINE_SHADEINFO_H
#define RAYTRACING_ENGINE_SHADEINFO_H

#include <vector>
#include <memory>
#include <bits/shared_ptr.h>
#include "../Geometry/Objects/Primitive.h"
#include "../Materials/Material.h"
#include "../Lights/AmbientLight.h"
#include "../Lights/Light.h"

class Scene;

class ShadeInfo {
private:
    rayState state;
    Vector3 intersection;
    Vector3 normal;
    std::shared_ptr<Material> material; //nearest material
    Ray ray; //for specular

    Vector3 lightDirection;
    std::shared_ptr<AmbientLight> ambientLight;
    std::vector<std::shared_ptr<Light>> lights;

public: //FIXME add set for the ray
    ShadeInfo(std::vector<std::shared_ptr<Light>> lights, std::shared_ptr<AmbientLight> ambient);
    ShadeInfo(const ShadeInfo& info);
    ~ShadeInfo();
    const std::shared_ptr<Material>& getMaterial();
    void setHit(const Vector3 &intersection);
    void setMaterial(const std::shared_ptr<Material>& material);
    const Vector3 & getNormal() const;
    rayState State() const;
    void setState(rayState state);
    void setNormal(const Vector3 &normal);
    const Vector3 &getHit() const;
    const Ray &getRay() const;
    const Vector3 &getLightDir() const;
    std::shared_ptr<AmbientLight> &getAmbientLight();
    const std::vector<std::shared_ptr<Light>> &getLights() const;
    void setAmbientLight(AmbientLight& ambientLight);
};


#endif //RAYTRACING_ENGINE_SHADEINFO_H
