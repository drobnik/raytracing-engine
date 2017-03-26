#ifndef RAYTRACING_ENGINE_CAMERA_H
#define RAYTRACING_ENGINE_CAMERA_H
#include "../Geometry/Ray.h"
#include "../Geometry/Objects/Primitive.h"
#include "../EngineImage.h"
#include "../Geometry/ViewPlane.h"
#include <vector>
#include <memory>

class Camera {
public:
    virtual EngineImage
    renderScene(std::vector<std::unique_ptr<Primitive>> &objs,
                ViewPlane &plane, LightIntensity &light)=0;
    virtual Ray spawnRay(const Vector3& point)=0;
    void calcUVW();

protected:
    Vector3 eye;
    Vector3 lookAt;
    Vector3 up;
    Vector3 horizontal;

    float nearPlane;
    float farPlane;
    float fieldOfView;

    Vector3 u, v, w; //local coordinates
};


#endif //RAYTRACING_ENGINE_CAMERA_H
