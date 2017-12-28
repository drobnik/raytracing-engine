#ifndef RAYTRACING_ENGINE_PERSPCTIVECAMERA_H
#define RAYTRACING_ENGINE_PERSPCTIVECAMERA_H
#include <string>
#include "Camera.h"
#include "../Geometry/ViewPlane.h"
#include "../Engine/Tracer.h"
#define ANTI_MAX 3

class PerspectiveCamera : public Camera {
public:
    std::string toString(){return "_pers_cam";};
    PerspectiveCamera();
    PerspectiveCamera(Vector3 e, Vector3 look, float near, float far);
    virtual EngineImage
    renderScene(ViewPlane &plane, LightIntensity &light, std::shared_ptr<Tracer> tracer) override;
};


#endif //RAYTRACING_ENGINE_PERSPCTIVECAMERA_H
