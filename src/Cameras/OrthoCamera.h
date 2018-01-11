#ifndef RAYTRACING_ENGINE_ORTHOCAMERA_H
#define RAYTRACING_ENGINE_ORTHOCAMERA_H

#include "Camera.h"

class OrthoCamera : Camera {
public:
    EngineImage
    renderScene(LightIntensity &light, std::unique_ptr<Tracer> const &tracer) override;
    OrthoCamera(const Vector3& e, const Vector3& look, const Vector3& up = Vector3(0.0f, 1.0f, 0.0f));
};


#endif //RAYTRACING_ENGINE_ORTHOCAMERA_H
