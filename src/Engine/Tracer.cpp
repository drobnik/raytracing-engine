#include "Tracer.h"

Tracer::Tracer() : scene(nullptr){

}

Tracer::Tracer(Scene *scene) {
    this->scene = scene;
}

LightIntensity Tracer::rayTrace(const Ray &ray) const {
   // Ray r = Ray(Vector3(0.0f, -7.0f, -20.0f), Vector3(0.0f, 0.0f, 1.0f) );
    //Ray r0 = ray;
    ShadeInfo info(scene->raytraceObjects(ray)); //FIXME &ray
     if(info.State() == 2 || info.State() == 1)
          return info.getMaterial().getColor();
     else
          return scene->Background();
}

std::string Tracer::sceneName() {
    assert(scene != nullptr);
    return scene->SceneName();
}
