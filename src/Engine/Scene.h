#ifndef RAYTRACING_ENGINE_SCENE_H
#define RAYTRACING_ENGINE_SCENE_H
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "../Geometry/Objects/Primitive.h"
#include "../Geometry/Ray.h"
#include "../Cameras/OrthoCamera.h"
#include "../Cameras/PerspectiveCamera.h"
#include "../Geometry/Objects/Sphere.h"
#include "../Geometry/Objects/Plane.h"
#include "../Geometry/Vector3.h"
#include "../Utilities/Utility.h"
#include "../Utilities/Utility.h"
#include "../Geometry/ViewPlane.h"
#include "ShadeInfo.h"
#include "../Geometry/Objects/Mesh.h"
#include "../Lights/Light.h"

class Tracer;
class Camera;

class Scene {
private:
    std::vector<Sphere> spheres;
    std::vector<Ray> rays;
    Plane samplePlane;
    std::vector<std::unique_ptr<Primitive>> objs;// headaches guaranteed
    Camera* camera;
    ViewPlane viewPlane;
    LightIntensity sceneBackground;
    std::string sceneName;
    Mesh sampleMesh;
    AmbientLight ambientLight;
    std::vector<Light*> lights;//beware

public:
    Scene();
    Scene(int w, int h, float p, const std::string &n);
    Scene(const Scene& sc);
    ~Scene();
    void init();
    void initPers();
    Vector3 calcPoint(Ray &r, float &t, rayState &state); //move to math
    ShadeInfo raytraceObjects(const Ray &ray);
    EngineImage renderScene(Tracer *tracer);
    LightIntensity Background();
    const ViewPlane &getViewPlane() const;
    const std::string SceneName() { return sceneName; };
    void addMesh(Mesh& m);
    void addAmbientLight(AmbientLight l);
    AmbientLight getAmbientLight() const;
    const std::vector<Light *> &getLights() const;
};


#endif //RAYTRACING_ENGINE_SCENE_H
