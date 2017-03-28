#ifndef RAYTRACING_ENGINE_PERSPCTIVECAMERA_H
#define RAYTRACING_ENGINE_PERSPCTIVECAMERA_H
#include <string>
#include "Camera.h"
#include "../Geometry/ViewPlane.h"
#include "../Engine/Tracer.h"

class PerspectiveCamera : public Camera {
public:
    PerspectiveCamera();
    PerspectiveCamera(Vector3 e, Vector3 look, float near, float far);
    virtual EngineImage
    renderScene(ViewPlane &plane, LightIntensity &light, Tracer *tracer) override;
    std::string toString(){return "_pers_cam";};
};


#endif //RAYTRACING_ENGINE_PERSPCTIVECAMERA_H
