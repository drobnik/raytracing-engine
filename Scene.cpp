#include "Scene.h"


Scene::Scene() {} // add flag for a camera

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
}

void Scene::init(){
    Vector3 zero = Vector3();
   // std::unique_ptr<Primitive> sphere(new Sphere(zero, 10));
    objs.push_back(std::make_unique<Sphere>(new Sphere(zero, 10)));
    //camera = new OrthoCamera();
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
    return camera->renderScene(objs);
}


