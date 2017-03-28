#include "Plane.h"

Plane::Plane() : Primitive() {
    normal = Vector3(0.0f, 1.0f, 0.0f);
    offset = 0.0f;
    material = Material();
}

rayState Plane::intersects(Ray &r, float &t) {
    rayState state = miss;
    float denom = normal.dot(r.getDirection());
    float q = 0.0f;

    if(fabs(denom) < 1e-6) return state; //parallel to the plane
    q = r.getOrigin().dot(normal);
    t = (offset - q) / denom;
    return t >= 0 ? (state=backward) : (state=tangent); //dodatni tyl

}

Plane::Plane(const Vector3 &nor, const float &off)
        : normal(nor),
          Primitive(){
    normal.normalize();
    offset = off;
}

//FIXME no copy constructor
Plane::Plane(const Plane &p)
        : normal(p.normal),
          offset(p.offset)
          { }
Plane::~Plane() { }
