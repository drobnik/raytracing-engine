#include "Tracer.h"

Tracer::Tracer() : scene(nullptr){

}

Tracer::Tracer(Scene *scene) {
    this->scene = scene;
}

//FIXME
LightIntensity Tracer::rayTrace(const Ray &ray) const {
/*    ShadeInfo info(scene->raytraceObjects(ray));
     if(info.State() == hit)
          return info.getMaterial().getColor();
     else
          return scene->Background();*/
}
