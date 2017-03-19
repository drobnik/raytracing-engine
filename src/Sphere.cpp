#include "../include/Sphere.h"

Sphere::Sphere() {

}

Sphere::Sphere(Vector3 &center, float rad) {
    this->center = center;
    radius = rad;
}

rayState Sphere::intersects(Ray& r, float& a_dist){
    Vector3 originCenter = r.getOrigin() - center;
    float b = -originCenter.dot(r.getDirection());
    float delta = (b * b) - originCenter.dot(originCenter) + radius;

    rayState state = miss;

    if(delta > 0){
        float det = sqrtf(delta);
        float p1 = b - det;
        float p2 = b + det;

        if(p2 > 0){
            if(p1 < 0){
                if(p2 < a_dist){
                    a_dist = p2;
                    state = tangent;
                }
            }
            else{
                if(p1 < a_dist){
                    a_dist = p1;
                    state = hit;
                }
            }
        }
    }
    return state;
}
