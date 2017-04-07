#include "Mesh.h"


Mesh::Mesh() {
    Vector3 ce = Vector3(0.0f, 0.0f, 0.0f);
    simpleBounding = Sphere(ce, 5);
}

Mesh::~Mesh() { }

Mesh::Mesh(const Mesh &m) {
    triangles = m.triangles;
    simpleBounding = m.simpleBounding;
}

Mesh::Mesh(std::vector<Triangle> tris) {
    triangles = tris;
    Vector3 ce = Vector3(0.0f, 0.0f, 0.0f);
    simpleBounding = Sphere(ce, 5);
}

ShadeInfo Mesh::intersects(const Ray &ray, Scene &scene) {
    float t = 0.0f, tmin = INFINITY;
    Ray r = ray; //FIXME
    rayState triangleS = miss;

    ShadeInfo info = ShadeInfo(scene);
        for(std::vector<Triangle>::iterator i = triangles.begin();
            i != triangles.end(); i++){
            triangleS = i->intersects(r, t);
            if( (triangleS == tangent || triangleS == hit) && (t < tmin)){
                info.setState(triangleS);
                tmin = t;
                info.setMaterial(i->getMaterial());
                info.setNormal(i->getNormal());
                info.setHit(r.getOrigin() + r.getDirection() * t);
            }
        }

    return info;
}

