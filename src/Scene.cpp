#include "../include/Scene.h"

Scene::Scene() {

}

void Scene::initialize() {
    Vector3 zero = Vector3();
    Vector3 rayOrigin = Vector3(0.0f, 0.0f, -20.0f);
    Vector3 direction = Vector3(0.0f, 1.0f, 0.0f); //hard coded?

    Sphere s = Sphere(zero, 10);
   // objects.push_back(&s); //slicing hard
    Ray r1 = Ray(rayOrigin, zero);
    Ray r2 = Ray(rayOrigin, direction);
    rays.push_back(r1);
    rays.push_back(r2);
}

void Scene::run() {

}
