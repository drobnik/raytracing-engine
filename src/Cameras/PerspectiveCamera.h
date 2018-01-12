#ifndef RAYTRACING_ENGINE_PERSPECTIVECAMERA_H
#define RAYTRACING_ENGINE_PERSPECTIVECAMERA_H
#include "../Utilities/Utility.h"
#include "../Engine/Tracer.h"
#include "Camera.h"

class PerspectiveCamera : public Camera {
public:
    virtual EngineImage
    RenderScene(LightIntensity &background, std::unique_ptr<Tracer> const &tracer) override;
    PerspectiveCamera(const Vector3& e, const Vector3& look, const Vector3& u,
                      unsigned int height, unsigned int width, float pixSize, float field = 45.0f);
    PerspectiveCamera(const PerspectiveCamera& cam);

private:
    float fieldOfView;
    void calculateViewDistance();
};


#endif //RAYTRACING_ENGINE_PERSPECTIVECAMERA_H
