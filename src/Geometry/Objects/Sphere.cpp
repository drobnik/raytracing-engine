#include "Sphere.h"
#include "../../Materials/PhongMat.h"

Sphere::Sphere():
        center(Vector3(0.0f, 0.0f, 0.0f)),
        radius(10) {
    LightIntensity l = LightIntensity(0.8f, 0.8f, 0.8f);
    material = std::make_shared<PhongMat>(PhongMat());
}

Sphere::Sphere(const Sphere &s){
    radius = s.radius;
    center = s.center;
    material = s.material;
}

// TODO add constructor for material definition!
Sphere::Sphere(Vector3 &center, float rad) : Primitive(){
    this->center = center;
    radius = rad;
    material = std::make_shared<PhongMat>(PhongMat());
}

rayState Sphere::intersects(const Ray& r, float& t) {
    rayState state = miss;
    Vector3 v = r.getOrigin() - center;
    float b = -v.dot(r.getDirection());
    float det = (b * b) - v.dot(v) + radius*radius;

    if (det > 0) {
        det = sqrtf(det);

        float i1 = b - det;
        float i2 = b + det;
        t = r.getDistance();

        if (i2 > 0){
            if (i1 < 0) {
                if (i2 < t){
                    t = i2;
                    state = inner;
                }
                
            } else {
                if (i1 < t) {
                    t = i1;
                    state = hit;
                }
            }
        }
    } else if (det == 0){
        float t_temp = b;
        t = t_temp;
        state = tangent;
    }

    return state;
}