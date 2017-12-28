#ifndef RAYTRACING_ENGINE_ORTHOCAMERA_H
#define RAYTRACING_ENGINE_ORTHOCAMERA_H
#define MAX_DEPTH 3
#define SPATIAL 0.05f
#include <string>
#include <algorithm>
#include "Camera.h"
#include "../Geometry/ViewPlane.h"
#include "../Engine/Tracer.h"

class OrthoCamera : public Camera {
public:
    OrthoCamera();
    OrthoCamera(Vector3 e, Vector3 look, float near, float far);
    virtual EngineImage
    renderScene(ViewPlane &plane, LightIntensity &light, std::shared_ptr<Tracer> tracer) override;
    std::string toString(){return "_ortho_cam";};
};

#endif //RAYTRACING_ENGINE_ORTHOCAMERA_H
