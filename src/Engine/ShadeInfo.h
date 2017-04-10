#ifndef RAYTRACING_ENGINE_SHADEINFO_H
#define RAYTRACING_ENGINE_SHADEINFO_H
#include "../Geometry/Objects/Primitive.h"
#include "../Materials/Material.h"
class Scene;

class ShadeInfo {
private:
    rayState state;
    Vector3 intersection;
    Vector3 normal;
    //Material* material; //nearest material
    LightIntensity material;
    Ray ray; //for specular
    Scene& scene; // for shading
    Vector3 lightDir;

public: //FIXME add set for the ray
    ShadeInfo(Scene &scene);
    ShadeInfo(const ShadeInfo& info);
    ~ShadeInfo();
    //const Material &getMaterial();
    const LightIntensity &getMaterial();
    void setHit(const Vector3 &intersection);
    //void setMaterial(const Material &material);
    void setMaterial(const LightIntensity &material);
    const Vector3 & getNormal() const;
    rayState State() const;
    void setState(rayState state);
    void setNormal(const Vector3 &normal);
    const Vector3 &getHit() const;
    const Ray &getRay() const;
    Scene &getScene() const;
    void setLightDir(const Vector3 &lightDir);
    const Vector3 &getLightDir() const;
};


#endif //RAYTRACING_ENGINE_SHADEINFO_H
