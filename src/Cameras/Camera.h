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
    virtual EngineImage
    renderScene(LightIntensity &light, std::unique_ptr<Tracer> const &tracer)=0;
    virtual ~Camera();

protected:
    Vector3 u, v, w; //local coordinates

    Vector3 eye;
    Vector3 lookAt;
    Vector3 up; // shows the viewDistance of the top of camera
    float viewDistance; //for perspective + zoom

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
    void calculateDirection(Vector3& ray); // for rays

};


#endif //RAYTRACING_ENGINE_CAMERA_H
