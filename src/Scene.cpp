#include "../include/Scene.h"

Scene::Scene() {

}

// 1 == 2 points
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

//TEMP
void Scene::calcPoint(Ray &r, float& t, rayState& state){
    if(state > 0){
        Vector3 point = r.getOrigin() + r.getDirection() * t;
        std::cout << "The point of intersection: " << point <<"\n";
    }
    t = 0;
}

void Scene::run() {
    Ray r1 = rays.at(0);
    Ray r2 = rays.at(1);
    Ray r3 = rays.at(2);
    float t = 0.0f;

    rayState t1 = spheres.at(0).intersects(r1, t);
    std::cout << "Sphere intersects r1: " << t1 <<"\n";
    calcPoint(r1, t, t1);

    rayState t2 = spheres.at(0).intersects(r2, t);
    std::cout << "Sphere intersects r2: " << t2 <<"\n";
    calcPoint(r2, t, t2);

    rayState t3 = spheres.at(0).intersects(r3, t);
    std::cout << "Sphere intersects r3: " << t3 <<"\n";
    calcPoint(r3, t, t3);

    rayState t4 = samplePlane.intersects(r2, t);
    std::cout << "R2 intersects plane: " << t4 <<"\n";
    calcPoint(r2, t, t4);
}
