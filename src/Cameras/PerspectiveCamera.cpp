#include "PerspectiveCamera.h"

PerspectiveCamera::PerspectiveCamera() : Camera(){ }

PerspectiveCamera::PerspectiveCamera(Vector3 e, Vector3 look, float near,
                                     float far) : Camera(e, look, near, far){
    Camera::fieldOfView = 45;
}

EngineImage
PerspectiveCamera::renderScene(ViewPlane &plane, LightIntensity &light,
                               Tracer *tracer) {
    LightIntensity color;
    std::string name = tracer->sceneName();
    EngineImage image = EngineImage(plane.getWRes(), plane.getHRes(), light,
                                    name);
    image.resetPixels(light);
    float x, y;
    float d, near;
    Ray ray;
    Vector3 vc, vo;

    ray.setOrigin(eye);
    for(unsigned int r = 0; r < plane.getWRes(); r++){ //up
        for(unsigned int c = 0; c < plane.getHRes(); c++){ //horizontal
            x = plane.getPixSize() * (c - 0.5f *(plane.getHRes() - 1.0f));
            y = plane.getPixSize() * (r - 0.5f *(plane.getWRes() - 1.0f));
            vo = Vector3(x, y, nearPlane) - eye;
            d = vo.length();
            ray.setDirection(Vector3(x, y, d));//+100));
            vo = ray.getDirection().normalize();
            ray.setDirection(vo);
            color = tracer->rayTrace(ray);
            image.setPixel((int)r, (int)c, color);
        }
    }
    return image;
}
/*
 *
            d = vo.length();
            vc = Vector3(x, y, d+1000); // -d
            ray.setDirection(vc);*/