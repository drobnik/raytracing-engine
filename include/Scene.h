#ifndef RAYTRACING_ENGINE_SCENE_H
#define RAYTRACING_ENGINE_SCENE_H
#include <vector>
#include <iostream>
#include <string>
#include "Ray.h"
#include "Primitive.h"
#include "Sphere.h"
#include "Plane.h"
#include "Vector3.h"
#include "Utility.h"

class Scene {
private:
    std::vector<Sphere> spheres;
    std::vector<Ray> rays;
    Plane samplePlane;
public:
    Scene();
    void initialize();
    void run();
    Vector3 calcPoint(Ray &r, float &t, rayState &state);

};


#endif //RAYTRACING_ENGINE_SCENE_H
