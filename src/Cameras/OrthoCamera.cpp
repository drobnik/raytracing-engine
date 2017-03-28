#include "OrthoCamera.h"

OrthoCamera::OrthoCamera() : Camera() { }

OrthoCamera::OrthoCamera(Vector3 e, Vector3 look, float near, float far)
        : Camera(e, look, near, far){ }

EngineImage
OrthoCamera::renderScene(ViewPlane &plane, LightIntensity &light, Tracer *tracer) {
    LightIntensity color;
    EngineImage image = EngineImage(plane.getWRes(), plane.getHRes(), light);
    image.resetPixels(light);
    float x, y;
    Ray ray;// zw == nearPlane
    ray.setDirection(Vector3(0.0f, 0.0f, -1.0f));

    for(unsigned int r = 0; r < plane.getWRes(); r++){ //up
        for(unsigned int c = 0; c < plane.getHRes(); c++){ //horizontal
            x = plane.getPixSize() * (c - 0.5f *(plane.getHRes() - 1.0f));
            y = plane.getPixSize() * (r - 0.5f * (plane.getWRes() - 1.0f));
            ray.setOrigin(Vector3(x, y, nearPlane));
            color = tracer->rayTrace(ray);
            image.setPixel((int)r, (int)c, color);
        }
    }
    return image;
}

//FIXME why do i need this?
Ray OrthoCamera::spawnRay(const Vector3 &point) {
    return Ray();
}

