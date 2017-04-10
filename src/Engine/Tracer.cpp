#include "Tracer.h"

Tracer::Tracer() : scene(nullptr){

}

Tracer::Tracer(Scene *scene) {
    this->scene = scene;
}

//FIXME
LightIntensity Tracer::rayTrace(const Ray &ray) const {
    ShadeInfo info(scene->raytraceObjects(ray));

     if(info.State() == tangent || info.State() == hit)
          return info.getMaterial();
     else
          return scene->Background();
}

std::string Tracer::sceneName() {
    assert(scene != nullptr);
    return scene->SceneName();
}
