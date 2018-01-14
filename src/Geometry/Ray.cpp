#include "Ray.h"

Ray::Ray() {
    origin = Vector3();
    direction = Vector3(1.0f, 0.0f, 0.0f);
    distance = INFINITY;
    depth = 0;
}

Ray::Ray(const Vector3& origin, const Vector3& direct){
    this->origin = origin;
    direction = direct;
    distance = INFINITY;
    depth = 0;
}

Ray::Ray(const Ray &parent) {
    this->origin = parent.origin;
    this->direction = parent.direction;
    this->distance = parent.distance;
    this->depth = parent.depth + 1;
}

Vector3 Ray::getOrigin() const{ return origin; }

Vector3 Ray::getDirection() const { return direction; }

float Ray::getDistance() const{
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

void Ray::resetRay() {
    origin = Vector3::Zero;
    direction = Vector3::Forward;
    depth = 0;
}
