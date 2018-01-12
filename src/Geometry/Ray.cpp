#include "Ray.h"

Ray::Ray() {
    origin = Vector3();
    direction = Vector3(1,0,0);
    Vector3();
    distance = INFINITY;
    depth = 0;
}

Ray::Ray(const Vector3& origin, const Vector3& direct){
    this->origin = origin;
    direction = direct;
    Vector3();
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
}
Vector3 Ray::getOrigin() const{ return origin; }

Vector3 Ray::getDirection() const { return direction; }

float Ray::getDistance() {
    return distance;
}

void Ray::setOrigin(const Vector3 &origin) {
    Ray::origin = origin;
}

void Ray::setDirection(const Vector3 &direction) {
    Ray::direction = direction;
}

void Ray::setDepth(int depth) {
    Ray::depth = depth;
}
