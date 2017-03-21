#include "../include/Plane.h"

Plane::Plane() {
    normal = Vector3(1.0f, 1.0f, 1.0f);
    offset = Vector3(0.0f, 0.0f, 0.0f);
}

// on the ray - X = Xorigin + t * Vdirection
rayState Plane::intersects(Ray &r, float &t) {

}

Plane::Plane(Vector3 &nor, Vector3 &offset) {
    normal = nor.normalize();
    this->offset = offset;
}
