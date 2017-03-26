#include "Ray.h"

Ray::Ray() {
    origin = Vector3();
    direction = Vector3(1,0,0);
    destination = Vector3();
    distance = INFINITY;
    depth = 0;
}

Ray::Ray(const Vector3& origin, const Vector3& direct){
    this->origin = origin;
    direction = direct;
    destination = Vector3();
    distance = INFINITY;
    depth = 0;
}

Ray::Ray(const Ray &parent) {
    this->origin = parent.origin;
    this->direction = parent.direction;
    this->distance = parent.distance;
    this->depth = parent.depth + 1;
}

void Ray::pointAt(const Vector3 &dest) {
    this->destination = dest;
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