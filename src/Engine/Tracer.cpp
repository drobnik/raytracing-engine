#include "Tracer.h"

// maybe discard it?
Tracer::Tracer() : scene(nullptr){

}

Tracer::Tracer(const std::shared_ptr<Scene> s) : scene(s) { }

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
