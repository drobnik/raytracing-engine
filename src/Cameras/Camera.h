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
    static const unsigned int ANTI_MAX = 10;

    virtual EngineImage
    RenderScene(LightIntensity &light, std::unique_ptr<Tracer> const &tracer)=0;
    Vector3 CalculateDirection(Vector3&& point); // for rays
    virtual ~Camera();

protected:
    Vector3 u, v, w; //local coordinates

    Vector3 eye;
    Vector3 lookAt;
    Vector3 up; // shows the viewDistance of the top of camera

    //for perspective
    float viewDistance;
    float zoom;

    unsigned int viewWidth;
    unsigned int viewHeight;
    float pixelSize;

    Camera();
    Camera(const Camera& cam);
    Camera(const Vector3& e, const Vector3& look, const Vector3& u,
           unsigned int height, unsigned int width, float pixSize);

    //float clamp(float c, float down, float upper);
private:
    void calculateUVW();

};


#endif //RAYTRACING_ENGINE_CAMERA_H
