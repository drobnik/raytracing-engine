#ifndef RAYTRACING_ENGINE_PRIMITIVE_H
#define RAYTRACING_ENGINE_PRIMITIVE_H

#include <memory>
#include "../Ray.h"
#include "../../Materials/Material.h"

enum rayState{
    inner = -1,
    miss = 0,
    hit = 1,
    tangent = 2,
    backward = 3
};

class Primitive {
protected:
    std::shared_ptr<Material> material;
public:
    Primitive();
    virtual rayState Intersects(const Ray &r, float &a_dist)=0;
    std::shared_ptr<Material> getMaterial();
    void setMaterial(const std::shared_ptr<Material>& material);
};


#endif //RAYTRACING_ENGINE_PRIMITIVE_H
