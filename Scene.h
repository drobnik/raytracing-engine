#ifndef RAYTRACING_ENGINE_SCENE_H
#define RAYTRACING_ENGINE_SCENE_H
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "Geometry/Objects/Primitive.h"
#include "Geometry/Ray.h"
#include "Geometry/Objects/Sphere.h"
#include "Geometry/Objects/Plane.h"
#include "Geometry/Vector3.h"
#include "Utilities/Utility.h"
#include "Cameras/Camera.h"
#include "Utilities/Utility.h"

class Scene {
private:
    std::vector<Sphere> spheres;
    std::vector<Ray> rays;
    std::vector<std::unique_ptr<Primitive>> objs;// headaches guaranteed
    Plane samplePlane; //delete
    Camera* camera;

public:
    Scene();
    void initialize();
    void init();
    void run();
    Vector3 calcPoint(Ray &r, float &t, rayState &state); //move to math
    EngineImage renderScene();
};


#endif //RAYTRACING_ENGINE_SCENE_H
