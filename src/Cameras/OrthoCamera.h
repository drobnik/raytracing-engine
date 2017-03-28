#ifndef RAYTRACING_ENGINE_ORTHOCAMERA_H
#define RAYTRACING_ENGINE_ORTHOCAMERA_H
#include <string>
#include "Camera.h"
#include "../Geometry/ViewPlane.h"
#include "../Engine/Tracer.h"

class OrthoCamera : public Camera {
public:
    OrthoCamera();
    OrthoCamera(Vector3 e, Vector3 look, float near, float far);
    virtual EngineImage
    renderScene(ViewPlane &plane, LightIntensity &light, Tracer *tracer) override;
    virtual Ray
    spawnRay(const Vector3& point) override;
    std::string toString(){return "_ortho_cam";};
};

#endif //RAYTRACING_ENGINE_ORTHOCAMERA_H
