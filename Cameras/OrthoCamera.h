#ifndef RAYTRACING_ENGINE_ORTHOCAMERA_H
#define RAYTRACING_ENGINE_ORTHOCAMERA_H
#include "Camera.h"

class OrthoCamera : public Camera {
public:
    virtual EngineImage renderScene(std::vector<std::unique_ptr<Primitive>>& objs) override;
    virtual Ray spawnRay(const Vector3& point) override;
};

#endif //RAYTRACING_ENGINE_ORTHOCAMERA_H
