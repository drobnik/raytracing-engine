#include "../include/Plane.h"

Plane::Plane() {
    normal = Vector3(1.0f, 1.0f, 1.0f);
    this->offset = Vector3(0.0f, 0.0f, 0.0f);
}

Plane::Plane(Vector3 &nor, Vector3 offset) {
    normal = nor.normalize();
    this->offset = offset;
}

// on the ray - X = Xorigin + t * Vdirection
rayState Plane::intersects(Ray &r, float &a_dist) {

}
