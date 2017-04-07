#ifndef RAYTRACING_ENGINE_SHADEINFO_H
#define RAYTRACING_ENGINE_SHADEINFO_H
#include "../Geometry/Objects/Primitive.h"
class Scene;

class ShadeInfo {
private:
    rayState state;
    Vector3 intersection;
    Vector3 normal;
    Material material; //color info
    Scene& scene; // for shading

public:
    ShadeInfo(Scene &scene);
    ShadeInfo(const ShadeInfo& info);
    ~ShadeInfo();
    const Material &getMaterial();
    void setHit(const Vector3 &intersection);
    void setMaterial(const Material &material);
    rayState State() const;
    void setState(rayState state);
    const Vector3 &getNormal() const;
    void setNormal(const Vector3 &normal);
    const Vector3 &getHit() const;
    void setIntersection(const Vector3 &intersection);
};


#endif //RAYTRACING_ENGINE_SHADEINFO_H
