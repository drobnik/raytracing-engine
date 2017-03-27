#ifndef RAYTRACING_ENGINE_SCENE_H
#define RAYTRACING_ENGINE_SCENE_H
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "../Geometry/Objects/Primitive.h"
#include "../Geometry/Ray.h"
#include "../Cameras/OrthoCamera.h"
#include "../Geometry/Objects/Sphere.h"
#include "../Geometry/Objects/Plane.h"
#include "../Geometry/Vector3.h"
#include "../Utilities/Utility.h"
#include "../Cameras/Camera.h"
#include "../Utilities/Utility.h"
#include "../Geometry/ViewPlane.h"
#include "ShadeInfo.h"

class Scene {
private:
    std::vector<Sphere> spheres;
    std::vector<Ray> rays;
    Plane samplePlane;
    std::vector<std::unique_ptr<Primitive>> objs;// headaches guaranteed
    Camera* camera;
    ViewPlane viewPlane;
    LightIntensity sceneBackground;

public:
    Scene();
    Scene(Camera* cam);
    Scene(const Scene& sc);
    ~Scene();
    void initialize();
    void init();
    void run();
    Vector3 calcPoint(Ray &r, float &t, rayState &state); //move to math
    ShadeInfo raytraceObjects(const Ray& ray);
    EngineImage renderScene(Tracer *tracer);
    LightIntensity Background();
};


#endif //RAYTRACING_ENGINE_SCENE_H
