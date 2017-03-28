#include "Tracer.h"

Tracer::Tracer() : scene(nullptr){

}

Tracer::Tracer(Scene *scene) {
    this->scene = scene;
}

LightIntensity Tracer::rayTrace(const Ray &ray) const {
    ShadeInfo info(scene->raytraceObjects(ray)); //FIXME scene
   // std::cout<<"state: "<<std::to_string(info.State())<<"\n";
   // std::cout<<info.getMaterial().getColor().red()<<"\n"; //FIXME 0.5f!!!
     if(info.State() == hit)
          return info.getMaterial().getColor();
     else
          return scene->Background();
}

std::string Tracer::sceneName() {
    assert(scene != nullptr);
    return scene->SceneName();
}
