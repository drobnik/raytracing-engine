#ifndef RAYTRACING_ENGINE_ORTHOCAMERA_H
#define RAYTRACING_ENGINE_ORTHOCAMERA_H

#include "../Engine/Tracer.h"
#include "Camera.h"
#include "../Utilities/AdaptiveSampler.h"

class OrthoCamera : public Camera {
public:
    EngineImage
    RenderScene(LightIntensity &background, std::unique_ptr<Tracer> const &tracer) override;

    OrthoCamera();
    //switch the order
    OrthoCamera(const Vector3 &e, const Vector3 &look, unsigned int height, unsigned int width,
                float pixSize, const std::shared_ptr<AdaptiveSampler>& sampler, const Vector3 &u = Vector3(0.0f, 1.0f, 0.0f));
    OrthoCamera(const OrthoCamera& cam);
};


#endif //RAYTRACING_ENGINE_ORTHOCAMERA_H
