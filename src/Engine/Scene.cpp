#include "Scene.h"


Scene::Scene() {
    sceneBackground = LightIntensity(0.0f, 0.0f, 0.0f); //black background
    sceneName = "sample";
    viewPlane = ViewPlane();
    viewPlane.setGamma(1.0f);
    sampleMesh = Mesh();
    // Default camera -- can be changed later
}

Scene::Scene(int w, int h, float p, const std::string &n) {
    sceneBackground = LightIntensity(0.5f, 0.5f, 0.5f);
    this->viewPlane = ViewPlane(w, h, p);
    sceneName = n;
    sampleMesh = Mesh();
}

EngineImage Scene::renderScene(std::unique_ptr<Tracer> const &tracer) {
    return EngineImage();// camera->renderScene(viewPlane, sceneBackground, tracer);
}

void Scene::init(){
    Vector3 zero2 = Vector3(0.0f, 10.0f, 100.0f);
    Sphere s2 = Sphere(zero2, 6.0f);
    ambientLight = AmbientLight();
    lights.push_back(std::make_unique<PointLight>(PointLight()));


    s2.setMaterial(LightIntensity(1.0f, 0.5f, 1.0f));
    objs.push_back(std::make_unique<Sphere>(s2));

//    camera = std::make_unique<OrthoCamera>(OrthoCamera(Vector3(0.0f, 0.0f, -500.0f),
//                                                       Vector3(0.0f, 0.0f, 1.0f), -20.0f, -20.0f));
    sceneName = this->sceneName; //+ camera->toString();
}

// TODO: REVIEW it -- unused state
Vector3 Scene::calcPoint(Ray &r, float &t, rayState &state){
    Vector3 point = r.getOrigin() + r.getDirection() * t;
    t = 0;
    return point;
}

ShadeInfo Scene::raytraceObjects(const Ray &ray){
    ShadeInfo info = ShadeInfo(*this);
    info.setAmbientLight(ambientLight);
    rayState state;
    Ray ta = ray; //FIXME const getOrigin and viewDistance
    float t = 0.0f, tmin = INFINITY;

    for(unsigned int i = 0; i < objs.size(); i++){
        state = objs.at(i)->intersects((Ray &) ray, t);
        if( (state == tangent || state == hit) && (t < tmin)){
            info.setState(state);
            tmin = t;
            info.setMaterial(objs.at(0)->getMaterial()); //FIXME add true material!
            info.setHit(ta.getOrigin() + ta.getDirection() * t);
        }
    }

    ShadeInfo meshInfo = ShadeInfo(sampleMesh.intersects(ray, *this));
    if(meshInfo.State() == hit){
        if(info.getHit().length() < meshInfo.getHit().length()) {
            return meshInfo;
        }
    }

    return info;
}

LightIntensity Scene::Background() { return sceneBackground; }

const ViewPlane &Scene::getViewPlane() const { return viewPlane; }

void Scene::addMesh(Mesh &m) { sampleMesh = m; }

void Scene::addAmbientLight(AmbientLight l) { ambientLight = l; }

const std::vector<std::unique_ptr<Light>> &Scene::getLights() const { return lights; }

void Scene::ChangeCamera(std::unique_ptr<Camera> cam){ camera.swap(cam); }

void Scene::ChangeSceneName(std::string s) { sceneName = s; }

AmbientLight Scene::getAmbientLight() const { return ambientLight; }


