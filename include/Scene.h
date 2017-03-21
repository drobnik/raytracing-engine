#ifndef RAYTRACING_ENGINE_SCENE_H
#define RAYTRACING_ENGINE_SCENE_H
#include <vector>
#include <iostream>
#include "Ray.h"
#include "Primitive.h"
#include "Sphere.h"
#include "Plane.h"
#include "Vector3.h"

class Scene {
    //TODO: one lis for all
private:
    std::vector<Sphere> spheres;
    std::vector<Ray> rays;
    Plane samplePlane;
public:
    Scene();
    void initialize();
    void run();
    void calcPoint(Ray &r, float& t, rayState& state);//, rayState& m);
};


#endif //RAYTRACING_ENGINE_SCENE_H
