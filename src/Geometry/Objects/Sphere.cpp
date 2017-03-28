#include "Sphere.h"

Sphere::Sphere()
        : //Primitive(),
          radius(10),
          center(Vector3(0.0f, 0.0f, 0.0f)) {
    LightIntensity l = LightIntensity(0.8f, 0.8f, 0.8f);
    material = Material(l);
}

Sphere::~Sphere() { }

Sphere::Sphere(const Sphere &s){
    radius = s.radius;
    center = s.center;
    material = s.material;
}

Sphere::Sphere(Vector3 &center, float rad) : Primitive(){
    LightIntensity l = LightIntensity(1.0f, 0.0f, 0.0f);
    this->center = center;
    radius = rad;
    material = Material(l);
}

Sphere::Sphere(Sphere *s) : Primitive() {
    center = s->getCenter();
    radius = s ->getRadius();
}

rayState Sphere::intersects(Ray& r, float& t) {
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
            if (i1 < 0)
            { 
                if (i2 < t){
                    t = i2;
                    state = inner;
                }
                
            }
            else
            {
                if (i1 < t) {
                    t = i1;
                    state = hit;
                }
            }
        }
    }
    else if (det == 0){
        float t_temp = b;
        t = t_temp;
        state = tangent;
    }

    return state;
}

Vector3 Sphere::getCenter() {
    return center;
}

float Sphere::getRadius() {
    return radius;
}

Material Sphere::getMaterial() {
    return material;
}
