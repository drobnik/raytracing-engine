#include "Scene.h"
#include "../Geometry/Objects/Triangle.h"

//NOTE: cam is initialized in init() method.
Scene::Scene() {
    sceneBackground = LightIntensity(0.0f, 0.0f, 0.0f); //black background
    sceneName = "sample";
    //viewPlane = ViewPlane();
    viewPlane.setGamma(1.0f);
}

Scene::Scene(int w, int h, float p, const std::string &n) {
    sceneBackground = LightIntensity(0.0f, 0.0f, 0.0f); //black background
    this->viewPlane = ViewPlane(w, h, p);
    sceneName = n;
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
}

EngineImage Scene::renderScene(Tracer *tracer) {
    return camera->renderScene(viewPlane, sceneBackground, tracer);
}

void Scene::initialize() {
    Vector3 zero = Vector3();
    //Vector3 zero = Vector3(10.0f, 10.0f, 0.0f);
    Vector3 rayOrigin = Vector3(0.0f, 0.0f, -20.0f);

    Sphere s = Sphere(zero, 10);
    spheres.push_back(s);
    samplePlane = Plane(Vector3(0.0f, 1.0f, 1.0f), 0.0f);

    Ray r1 = Ray(rayOrigin, Vector3(0.0f, 0.0f, 1.0f));
    Ray r2 = Ray(rayOrigin, Vector3(0.0f, 1.0f, 0.0f));
    Ray r3 = Ray(Vector3(0.0f, -10.0f, -10.0f), Vector3(0.0f, 0.0f, 1.0f));

    r1.pointAt(zero);
    r2.pointAt(Vector3(0.0f, 10.0f, 0.0f));
    r3.pointAt(Vector3(0.0f, 10.0f, 0.0f));

    rays.push_back(r1);
    rays.push_back(r2);
    rays.push_back(r3);
}

void Scene::init(){
    Vector3 zero1 = Vector3(0.0f, 0.0f, 50.0f);
    Vector3 zero2 = Vector3(0.0f, 10.0f, 10.0f);
    Vector3 a, b, c;
    a = Vector3(30.0f, 10.0f, 0.0f), b = Vector3(10.0f, 2.0f, 0.0f),
        c = Vector3(-10.0f, 20.0f, 0.0f);
    Triangle t = Triangle(a, b, c);
    Sphere s2 = Sphere(zero2, 10.0f);
    s2.setMaterial(Material(LightIntensity(1.0f, 0.5f, 1.0f)));
    objs.push_back(std::make_unique<Sphere>(Sphere(zero1, 30.0f)));
    objs.push_back(std::make_unique<Sphere>(s2));
    objs.push_back(std::make_unique<Triangle>(t));
    camera = new OrthoCamera(Vector3(0.0f, 0.0f, -20.0f),
                             Vector3(0.0f, 0.0f, 1.0f), -20.0f, -20.0f);
    sceneName = sceneName + camera->toString();
}

void Scene::initPers() {
    Vector3 zero1 = Vector3(0.0f, 0.0f, 50.0f);
    Vector3 zero2 = Vector3(0.0f, 10.0f, 10.0f);
    Sphere s2 = Sphere(zero2, 10.0f);
    s2.setMaterial(Material(LightIntensity(1.0f, 0.5f, 1.0f)));
    Vector3 a, b, c;
    a = Vector3(30.0f, 10.0f, 0.0f), b = Vector3(10.0f, 2.0f, 0.0f),
    c = Vector3(-10.0f, 20.0f, 0.0f);
    Triangle t = Triangle(a, b, c);
    objs.push_back(std::make_unique<Sphere>(Sphere(zero1, 10.0f)));
    objs.push_back(std::make_unique<Sphere>(s2));
    objs.push_back(std::make_unique<Triangle>(t));
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

void Scene::run() {
    Vector3 p1, p2, p3, p4;
    Ray r1 = rays.at(0);
    Ray r2 = rays.at(1);
    Ray r3 = rays.at(2);
    float t = 0.0f;

    rayState t1 = spheres.at(0).intersects(r1, t);
    Utility::logResults(t1, "R1", "sphere"); //typeof?
    p1 = calcPoint(r1, t, t1);
    Utility::logPoint(p1, t1);

    rayState t2 = spheres.at(0).intersects(r2, t);
    Utility::logResults(t2, "R2", "sphere");
    p2 = calcPoint(r2, t, t2);
    Utility::logPoint(p2, t2);

    rayState t3 = spheres.at(0).intersects(r3, t);
    Utility::logResults(t3, "R3", "sphere");
    p3 = calcPoint(r3, t, t3);
    Utility::logPoint(p3, t3);

    rayState t4 = samplePlane.intersects(r2, t);
    Utility::logResults(t4, "R2", "plane");
    p4 = calcPoint(r2, t, t4);
    Utility::logPoint(p4, t4);
}

ShadeInfo Scene::raytraceObjects(const Ray &ray){
    ShadeInfo info = ShadeInfo(*this);
    float t = 0.0f, tmin = INFINITY;

    for(unsigned int i = 0; i < objs.size(); i++){
        rayState state = objs.at(i)->intersects((Ray &) ray, t);
        if( (state == 2 || state == 1) && (t < tmin)){
            info.setState(state);
            tmin = t;
            info.setMaterial(objs.at(i)->getMaterial());
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


