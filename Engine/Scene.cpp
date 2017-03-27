#include "Scene.h"



Scene::Scene() {
    sceneBackground = LightIntensity(0.0f, 0.0f, 0.0f); //black background
} // add flag for a camera

Scene::Scene(Camera *cam) {
    sceneBackground = LightIntensity(0.0f, 0.0f, 0.0f); //black background
}

//FIXME whats goin on -- better follow `the rule of three`
/*Scene::~Scene() {
 * //take care of our dear objs
    delete camera;
    camera = nullptr;
}*/

void Scene::initialize() {
    Vector3 zero = Vector3();
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

    viewPlane.WRes(500); //from the configuration file!!
    viewPlane.HRes(500);
    viewPlane.setPixSize(1.0f);
    viewPlane.setGamma(1.0f);
}

void Scene::init(){
    Vector3 zero = Vector3();
   // std::unique_ptr<Primitive> sphere(new Sphere(zero, 10));
    objs.push_back(std::make_unique<Sphere>(new Sphere(zero, 10)));
    camera = new OrthoCamera();
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

//FIXME
EngineImage Scene::renderScene() {
//    return camera->renderScene(objs, <#initializer#>, <#initializer#>);
}

//FIXME
ShadeInfo Scene::raytraceObjects(const Ray &ray) const {
    ShadeInfo info = ShadeInfo();
    //ShadeInfo info(*this);
    /*float t = 0.0f, tmin = INFINITY;

    for(unsigned int i = 0; i < objs.size(); i++){
        rayState state = objs.at(i)->intersects((Ray &) ray, t);
        if( (state == hit || state == tangent) && (t < tmin)){
            //info.intersection = state;
            tmin = t;
            //FIXME add a material parameter to every primitive called `diffuse color` known from the very beginning
            //info.color = objs.at(i)->getColor();
        }
    }*/

    return info;
}


