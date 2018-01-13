#ifndef RAYTRACING_ENGINE_SCENE_H
#define RAYTRACING_ENGINE_SCENE_H
#include <vector>
#include <iostream>
#include <string>
#include <memory>
#include "../Geometry/Objects/Primitive.h"
#include "../Geometry/Ray.h"
#include "../Geometry/Objects/Sphere.h"
#include "../Geometry/Objects/Plane.h"
#include "../Geometry/Vector3.h"
#include "../Utilities/Utility.h"
#include "../Geometry/ViewPlane.h"
#include "../Lights/PointLight.h"
#include "../Cameras/OrthoCamera.h"
#include "../Utilities/Configuration.h"
#include "../Geometry/Objects/Mesh.h"
#include "../Lights/Light.h"
#include "EngineImage.h"
#include "../Cameras/Camera.h"

class Tracer;
class Camera;
class ShadeInfo;

class Scene {
private:
    ViewPlane viewPlane;
    std::vector<std::unique_ptr<Primitive>> objs;
    std::unique_ptr<Camera> camera;

    LightIntensity sceneBackground;
    std::string sceneName;
    Mesh sampleMesh; // FIXME add to the new collection of meshes
    std::shared_ptr<AmbientLight> ambientLight;
    std::vector<std::shared_ptr<Light>> lights;

public:
    Scene();
    Scene(int w, int h, float p, const std::string &n);

    void init(const std::unique_ptr<Configuration>& conf);
    void ChangeCamera(std::unique_ptr<Camera> cam);
    void ChangeSceneName(std::string s);
    ShadeInfo raytraceObjects(const Ray &ray);
    EngineImage renderScene(std::unique_ptr<Tracer> const &tracer);
    LightIntensity Background();
    const ViewPlane &getViewPlane() const;
    const std::string SceneName() { return sceneName; };
    void addMesh(Mesh& m);
};


#endif //RAYTRACING_ENGINE_SCENE_H
