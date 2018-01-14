#ifndef RAYTRACING_ENGINE_ADAPTIVESAMPLER_H
#define RAYTRACING_ENGINE_ADAPTIVESAMPLER_H
#include "../Lights/LightIntensity.h"
#include "../Geometry/Ray.h"
#include "../Engine/Tracer.h"

class AdaptiveSampler {
private:
    Ray ra, rb, rc, rd;
    Vector3 direction;

    void orthoSetup(const Ray& ray, float offset);
    void perspectiveSetup(const Ray& ray, float offset);
    void resetRays();

    static const int MAX_DEPTH;
public:
    AdaptiveSampler();
    LightIntensity AdaptiveSampling(Ray &ray, std::unique_ptr<Tracer> const &tracer, float pixSize,
                                   int depth, bool isOrtho);
};


#endif //RAYTRACING_ENGINE_ADAPTIVESAMPLER_H
