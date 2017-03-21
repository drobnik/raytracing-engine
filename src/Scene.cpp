#include "../include/Scene.h"

Scene::Scene() {

}

void Scene::initialize() {
    Vector3 zero = Vector3();
    Vector3 rayOrigin = Vector3(0.0f, 0.0f, -20.0f);
    Vector3 direction = Vector3(0.0f, 1.0f, 0.0f); //hard coded?

    Sphere s = Sphere(zero, 10);
    spheres.push_back(s);
    Ray r1 = Ray(rayOrigin, zero);
    Ray r2 = Ray(rayOrigin, direction);
    rays.push_back(r1);
    rays.push_back(r2);
}

//TEMP
void Scene::calcPoint(Ray &r, float t){
    if(t > 0){
        Vector3 point = r.getOrigin() + r.getDirection() * t;
        std::cout << "The point of intersection: " << point <<"\n";
    }
}

void Scene::run() {
    Ray r1 = rays.at(0);
    Ray r2 = rays.at(1);
    float t = 0.0f;

    std::cout << "Sphere intersects r1: " << spheres.at(0).intersects(r1, t) << " t: "<< t <<"\n";
    calcPoint(r1, t);
    t = 0.0f;
    std::cout << "Sphere intersects r2: " << spheres.at(0).intersects(r2, t) << " t: "<< t <<"\n";
    calcPoint(r1, t);
}
