#include "OrthoCamera.h"
#include "../Geometry/ViewPlane.h"

//FIXME
OrthoCamera::OrthoCamera() {

}

OrthoCamera::OrthoCamera(Vector3 eye, Vector3 lookAt, float nearPlane, float farPlane) {

}
EngineImage
OrthoCamera::renderScene(std::vector<std::unique_ptr<Primitive>> &objs,
                         ViewPlane &plane, LightIntensity &light/*Tracer* tracer*/) {
    LightIntensity color;
    EngineImage image = EngineImage(plane.getWRes(), plane.getHRes(), light);
    float x, y;
    Ray ray;
    ray.setDirection(Vector3(0.0f, 0.0f, -1.0f));
    // zw == nearPlane
    //setDirection();

    for(unsigned int r = 0; r < plane.getWRes(); r++){ //u
        for(unsigned int c = 0; c < plane.getHRes(); c++){
            x = plane.getPixSize() * (c - 0.5f *(plane.getHRes() - 1.0f));
            y = plane.getPixSize() * (r - 0.5f * (plane.getWRes() - 1.0f));
            ray.setOrigin(Vector3(x, y, nearPlane));
            //color = tracer->traceRay(ray); //FIXME
            image.getImg().set_pixel((const unsigned int) x,
                                     (const unsigned int) y,
                                     (const unsigned char) color.red(),
                                     (const unsigned char) color.green(),
                                     (const unsigned char) color.blue());
        }
    }
    return EngineImage();
}

Ray OrthoCamera::spawnRay(const Vector3 &point) {
    return Ray();
}

