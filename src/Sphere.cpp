#include "../include/Sphere.h"

Sphere::Sphere() {

}

Sphere::Sphere(Vector3 &center, float rad) {
    this->center = center;
    radius = rad;
}

rayState Sphere::intersects(Ray& r, float& t){
    rayState state = miss;
    float p1 =0.0f, p2 = 0.0f;

    Vector3 originCenter = r.getOrigin() - center;
    float a = r.getDirection().dot(r.getDirection());
    float b = 2 * r.getDirection().dot(originCenter);
    float c = originCenter.dot(originCenter) - radius * radius;

    float delta = b*b - 4*a*c;

    if(delta > 0){
        float q;
        if(b > 0) q = -0.5f * (b + sqrtf(delta));
        else q = -0.5f * (b - sqrtf(delta));

        p1 = q / a;
        p2 = c / q;
        state = hit;
    }
    else if(delta == 0){ // intersects in one place
        p1 = p2 = -0.5f * b / a;
        state = tangent;
    }

    if(p1 > p2) std::swap(p1, p2);

    if(p1 < 0){
        p1 = p2;
        if(p1 < 0) return miss; //both negative values
    }

    t = p1;
    return state;

}

Vector3 Sphere::getCenter() {
    return center;
}
