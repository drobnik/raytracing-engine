#ifndef RAYTRACING_ENGINE_TRACER_H
#define RAYTRACING_ENGINE_TRACER_H
#include "../Lights/LightIntensity.h"
#include "../Geometry/Ray.h"
#include "../Engine/ShadeInfo.h"
#include "Scene.h"

class Tracer {
private:
    Scene* scene;
public:
    Tracer();
    Tracer(Scene* scene);
    LightIntensity rayTrace(const Ray& ray) const;
};


#endif //RAYTRACING_ENGINE_TRACER_H
