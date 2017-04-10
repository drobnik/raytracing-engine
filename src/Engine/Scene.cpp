#include "Scene.h"
#include "../Geometry/Objects/Triangle.h"
#include "../Lights/PointLight.h"

//NOTE: cam is initialized in init() method.
Scene::Scene() {
    sceneBackground = LightIntensity(0.0f, 0.0f, 0.0f); //black background
    sceneName = "sample";
    viewPlane = ViewPlane();
    viewPlane.setGamma(1.0f);
    sampleMesh = Mesh();
}

Scene::Scene(int w, int h, float p, const std::string &n) {
    sceneBackground = LightIntensity(0.0f, 0.0f, 0.0f);
    this->viewPlane = ViewPlane(w, h, p);
    sceneName = n;
    sampleMesh = Mesh();
}
//NOTE: objects are empty here. Probably it is a useless constructor
Scene::Scene(const Scene &sc) {
    spheres = sc.spheres;
    samplePlane = sc.samplePlane;
    rays = sc.rays;

    objs.clear();

    camera = sc.camera;
    viewPlane = sc.viewPlane;
    sceneBackground = sc.sceneBackground;
}

Scene::~Scene() {
    delete camera;
    camera = nullptr;
   // delete ambientLight;
   // ambientLight = nullptr;
}

EngineImage Scene::renderScene(Tracer *tracer) {
    return camera->renderScene(viewPlane, sceneBackground, tracer);
}
void Scene::init(){
    Vector3 zero2 = Vector3(0.0f, 10.0f, 100.0f);
    Sphere s2 = Sphere(zero2, 6.0f);
    //PointLight* pointless = new PointLight();

//    s2.setMaterial(Material(LightIntensity(1.0f, 0.5f, 1.0f)));
    s2.setMaterial(LightIntensity(1.0f, 0.5f, 1.0f));
    objs.push_back(std::make_unique<Sphere>(s2));
    camera = new OrthoCamera(Vector3(0.0f, 0.0f, -500.0f),
                             Vector3(0.0f, 0.0f, 1.0f), -20.0f, -20.0f);
    sceneName = sceneName + camera->toString();
}

void Scene::initPers() {
    Vector3 zero2 = Vector3(0.0f, 10.0f, 100.0f);
    Sphere s2 = Sphere(zero2, 6.0f);
//    s2.setMaterial(Material(LightIntensity(1.0f, 0.5f, 1.0f)));
    s2.setMaterial(LightIntensity(1.0f, 0.5f, 1.0f));
    objs.push_back(std::make_unique<Sphere>(s2));
    camera = new PerspectiveCamera(Vector3(0.0f, 0.0f, -20.0f),
                             Vector3(0.0f, 0.0f, 1.0f), 200.0f, 2000);
    sceneName = sceneName + camera->toString();
}

// TODO: Geometry module
Vector3 Scene::calcPoint(Ray &r, float &t, rayState &state){
    Vector3 point = r.getOrigin() + r.getDirection() * t;
    t = 0;
    return point;
}

ShadeInfo Scene::raytraceObjects(const Ray &ray){
    ShadeInfo info = ShadeInfo(*this);
    rayState state;
    Ray ta = ray; //FIXME const getOrigin and direction
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

LightIntensity Scene::Background() {
    return sceneBackground;
}

const ViewPlane &Scene::getViewPlane() const {
    return viewPlane;
}

void Scene::addMesh(Mesh &m) {
    sampleMesh = m;
}

void Scene::addAmbientLight(Light *l) {
    ambientLight = l;
}

const std::vector<Light *> &Scene::getLights() const {
    return lights;
}

Light *Scene::getAmbientLight() const {
    return ambientLight;
}


