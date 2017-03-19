#include "Ray.h"

Ray::Ray() {
    origin = Vector3();
    direction = Vector3();
    distance = 0.0f;
    depth = 1;
}

Ray::Ray(Vector3& origin, Vector3& direct){
    this->origin = origin;
    direction = direct;
    depth = 1;
}

Ray::Ray(const Ray &parent) {
    this->origin = parent.origin;
    this->direction = parent.direction;
    this->distance = parent.distance;
    this->depth = parent.depth + 1;
}

Vector3 Ray::getOrigin() {
    return origin;
}

Vector3 Ray::getDirection() {
    return direction;
}

float Ray::getDistance() {
    return distance;
}