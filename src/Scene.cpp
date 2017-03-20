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

void Scene::run() {
    // R1 test
    Ray r1 = rays.at(0);
    Ray r2 = rays.at(1);
    float dis = r1.getDistance();
    std::cout << "speher" << r1.getDirection() << "\n";
    std::cout << "Sphere intersects r1: " << spheres.at(0).intersects(r1, dis) << "\n";
    std::cout << "Sphere intersects r2: " << spheres.at(0).intersects(r2, dis) << "\n";
}
