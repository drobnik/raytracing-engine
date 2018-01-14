#include "Scene.h"



Scene::Scene() {
    sceneBackground = LightIntensity(0.0f, 0.0f, 0.0f); //black background
    sceneName = "sample";
    viewPlane = ViewPlane();
    viewPlane.setGamma(1.0f);
}

Scene::Scene(int w, int h, float p, const std::string &n) {
    sceneBackground = LightIntensity(0.5f, 0.5f, 0.5f);
    this->viewPlane = ViewPlane(w, h, p);
    sceneName = n;
}

EngineImage Scene::renderScene(std::unique_ptr<Tracer> const &tracer) {
    return camera->RenderScene(sceneBackground, tracer);
}

void Scene::InitializeScene(const std::unique_ptr<Configuration> &conf, const std::shared_ptr<AdaptiveSampler>& sampler){
    Vector3 zero2 = Vector3(0.0f, 10.0f, 100.0f);
    float radius = 6.0f;

    Sphere s2 = Sphere(zero2, radius);
    ambientLight = std::make_shared<AmbientLight>(AmbientLight());
    lights.push_back(std::make_shared<PointLight>(PointLight()));

    objs.push_back(std::make_unique<Sphere>(s2));
    camera = std::move(std::make_unique<OrthoCamera>(OrthoCamera(conf->getCameraPosition(), conf->getLookAtPosition(),
                                                                 conf->ViewplaneHeight(), conf->ViewplaneWidth(),
                                                                 conf->PixelSize(), sampler)));
}

ShadeInfo Scene::raytraceObjects(const Ray &ray){
    ShadeInfo info = ShadeInfo(lights, ambientLight);

    rayState state;
    float t = 0.0f, tmin = INFINITY;

    for(auto&& obj: objs) {
        state = obj->Intersects((Ray &) ray, t);
        if( (state == tangent || state == hit) && (t < tmin)){
            info.setState(state);
            tmin = t;
            info.setMaterial(obj->getMaterial());
            info.setHit(ray.getOrigin() + ray.getDirection() * t);
        }
    }

    ShadeInfo meshInfo(lights, ambientLight);
    for(auto&& mesh: meshes) {
        meshInfo = mesh->Intersects(ray, meshInfo);

        if(meshInfo.State() == hit){
            if(info.getHit().length() < meshInfo.getHit().length()) {
                return meshInfo;
            }
        }
    }

    return info;
}

LightIntensity Scene::Background() { return sceneBackground; }

const ViewPlane &Scene::getViewPlane() const { return viewPlane; }

void Scene::addMesh(Mesh &m) {
    meshes.push_back(std::make_unique<Mesh>(m));
}

void Scene::ChangeCamera(std::unique_ptr<Camera> cam){ camera.swap(cam); }

void Scene::ChangeSceneName(std::string s) { sceneName = s; }


