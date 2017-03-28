#include "Tracer.h"

Tracer::Tracer() : scene(nullptr){

}

Tracer::Tracer(Scene *scene) {
    this->scene = scene;
}

LightIntensity Tracer::rayTrace(const Ray &ray) const {
    ShadeInfo info(scene->raytraceObjects(ray)); //FIXME
     if(info.State() == hit)
          return info.getMaterial().getColor();
     else
          return scene->Background();
}

std::string Tracer::sceneName() {
    assert(scene != nullptr);
    return scene->SceneName();
}