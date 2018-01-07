#ifndef RAYTRACING_ENGINE_TRACER_H
#define RAYTRACING_ENGINE_TRACER_H
#include <string>
#include "../Lights/LightIntensity.h"
#include "../Geometry/Ray.h"
#include "../Engine/ShadeInfo.h"
#include "Scene.h"

class Tracer {
private:
    std::shared_ptr<Scene> scene;
public:
    Tracer();
    Tracer(std::shared_ptr<Scene> s);
    LightIntensity rayTrace(const Ray& ray) const;
    std::string sceneName(); //FIXME
};


#endif //RAYTRACING_ENGINE_TRACER_H
