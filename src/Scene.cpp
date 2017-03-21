#include "../include/Scene.h"

Scene::Scene() {}

void Scene::initialize() {
    Vector3 zero = Vector3();
    Vector3 rayOrigin = Vector3(0.0f, 0.0f, -20.0f);

    Sphere s = Sphere(zero, 10);
    spheres.push_back(s);
    samplePlane = Plane(Vector3(0.0f, 1.0f, 1.0f), 0.0f);

    Ray r1 = Ray(rayOrigin, Vector3(0.0f, 0.0f, 1.0f));
    Ray r2 = Ray(rayOrigin, Vector3(0.0f, 1.0f, 0.0f));
    Ray r3 = Ray(Vector3(0.0f, -10.0f, -10.0f), Vector3(0.0f, 0.0f, 1.0f));

    r1.setDestination(zero);
    r2.setDestination(Vector3(0.0f, 10.0f, 0.0f));
    r3.setDestination(Vector3(0.0f, 10.0f, 0.0f));

    rays.push_back(r1);
    rays.push_back(r2);
    rays.push_back(r3);
}

void Scene::logPoint(Vector3 point, rayState &state) {
    if(state > 0) {
        std::cout << "The nearest point of intersection: " << point <<"\n";
    }
}

// ideas - utilities module with logging possibility, linear/geometry for basic calculations
// add ID or name for every ray!!
void Scene::logResults(const rayState &state, const std::string &rayName, const std::string &primitive) {
    std::cout << "Ray " << rayName << " ";
    if(state > 0){
        std::cout << "intersects a " << primitive << " in ";
        if(state == 1) std::cout << "2 points.\n";
        else std::cout << "1 point.\n";
    }
    if(state == 0) std::cout <<"misses the primitive.\n\n";
}

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
    logResults(t1, "R1", "sphere"); //typeof?
    p1 = calcPoint(r1, t, t1);
    logPoint(p1, t1);

    rayState t2 = spheres.at(0).intersects(r2, t);
    logResults(t2, "R2", "sphere");
    p2 = calcPoint(r2, t, t2);
    logPoint(p2, t2);

    rayState t3 = spheres.at(0).intersects(r3, t);
    logResults(t3, "R3", "sphere");
    p3 = calcPoint(r3, t, t3);
    logPoint(p3, t3);

    rayState t4 = samplePlane.intersects(r2, t);
    logResults(t4, "R2", "plane");
    p4 = calcPoint(r2, t, t4);
    logPoint(p4, t4);
}


