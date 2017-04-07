#ifndef RAYTRACING_ENGINE_CAMERA_H
#define RAYTRACING_ENGINE_CAMERA_H
#include "../Geometry/Ray.h"
#include "../Geometry/Objects/Primitive.h"
#include "../Engine/EngineImage.h"
#include "../Geometry/ViewPlane.h"
#include <vector>
#include <memory>

class Tracer;
class Camera {
public:
    Camera();
    Camera(const Camera& cam);
    Camera(Vector3 e, Vector3 look, float near, float far);
    virtual ~Camera();
    virtual EngineImage
    renderScene(ViewPlane &plane, LightIntensity &light, Tracer *tracer)=0;
    virtual std::string toString()=0;
    void calcUVW();
protected:
    Vector3 eye;
    Vector3 lookAt;
    Vector3 up;

    float nearPlane;
    float farPlane;
    float fieldOfView;
    float clamp(float c, float down, float upper);

    Vector3 u, v, w; //local coordinates
};


#endif //RAYTRACING_ENGINE_CAMERA_H
