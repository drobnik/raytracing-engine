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
    //Material material; //color info
    LightIntensity material;
    Scene& scene; // for shading

public:
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
};


#endif //RAYTRACING_ENGINE_SHADEINFO_H
