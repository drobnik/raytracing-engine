#ifndef RAYTRACING_ENGINE_CAMERA_H
#define RAYTRACING_ENGINE_CAMERA_H
#include "../Geometry/Ray.h"
#include "../Geometry/Objects/Primitive.h"
#include "../EngineImage.h"
#include <vector>

class Camera {
public:
    virtual EngineImage renderScene()=0;
    virtual Ray spawnRay(const Vector3& point)=0;

protected:
    Vector3 position;
    Vector3 lookAt;
    Vector3 up;
    Vector3 horizontal;

    float nearPlane;
    float farPlane;
    float fieldOfView;
};


#endif //RAYTRACING_ENGINE_CAMERA_H
