#include "Scene.h"
#include "../Geometry/Objects/Triangle.h"

//NOTE: cam is initialized in init() method.
Scene::Scene() {
    sceneBackground = LightIntensity(1.0f, 1.0f, 1.0f); //black background
    sceneName = "sample";
    viewPlane = ViewPlane();
    viewPlane.setGamma(1.0f);
    sampleMesh = Mesh();
}

Scene::Scene(int w, int h, float p, const std::string &n) {
    sceneBackground = LightIntensity(1.0f, 1.0f, 1.0f);
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
}

EngineImage Scene::renderScene(Tracer *tracer) {
    return camera->renderScene(viewPlane, sceneBackground, tracer);
}
void Scene::init(){
    Vector3 zero2 = Vector3(0.0f, 10.0f, 100.0f);
    Sphere s2 = Sphere(zero2, 6.0f);

    s2.setMaterial(Material(LightIntensity(1.0f, 0.5f, 1.0f)));
    objs.push_back(std::make_unique<Sphere>(s2));
    camera = new OrthoCamera(Vector3(0.0f, 0.0f, -500.0f),
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
    //objs.push_back(std::make_unique<Sphere>(s2));
    //objs.push_back(std::make_unique<Triangle>(t));
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
            info.setMaterial(objs.at(0)->getMaterial());
            info.setHit(ta.getOrigin() + ta.getDirection() * t);
        }
    }

    ShadeInfo meshInfo = ShadeInfo(sampleMesh.intersects(ray, *this));
    if(meshInfo.State() == hit){
        /*std::cout<<"\n";
        std::cout<<"R: "<<meshInfo.getMaterial().getColor().red()<<"\n";
        std::cout<<"G: "<<meshInfo.getMaterial().getColor().green()<<"\n";
        std::cout<<"B: "<<meshInfo.getMaterial().getColor().blue()<<"\n";*/
        return meshInfo;
    }
    /*if(meshInfo.getState() == tangent || meshInfo.getState() == hit) {
        float distMesh = meshInfo.getHit().length();
        float distPri =;
        if ()
            return meshInfo;
    }*/

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


