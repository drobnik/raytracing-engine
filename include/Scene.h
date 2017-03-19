#ifndef RAYTRACING_ENGINE_SCENE_H
#define RAYTRACING_ENGINE_SCENE_H
#include <vector>
#include <memory>
#include "Ray.h"
#include "Primitive.h"
#include "Sphere.h"
#include "Plane.h"
#include "Vector3.h"

class Scene {
private:
    std::vector<std::unique_ptr<Primitive>> objects;
    std::vector<Ray> rays;
public:
    Scene();
    void initialize();
    void run();
};


#endif //RAYTRACING_ENGINE_SCENE_H
