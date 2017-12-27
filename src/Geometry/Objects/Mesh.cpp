#include "Mesh.h"


Mesh::Mesh() {
    Vector3 ce = Vector3(0.0f, 0.0f, 0.0f);
    simpleBounding = Sphere(ce, 5);
}

Mesh::Mesh(const Mesh &m) {
    triangles = m.triangles;
    simpleBounding = m.simpleBounding;
}

Mesh::Mesh(const std::vector<std::shared_ptr<Triangle>> tris) {
    triangles = tris;
    Vector3 ce = Vector3(0.0f, 0.0f, 0.0f);
    simpleBounding = Sphere(ce, 5);
}

ShadeInfo Mesh::intersects(const Ray &ray, Scene &scene) {
    float t = 0.0f, tmin = INFINITY;
    Ray r = ray; //FIXME
    rayState triangleS = miss;

    ShadeInfo info = ShadeInfo(scene);
        for(auto&& item: triangles){
            triangleS = item -> intersects(r, t);
            if((triangleS == tangent || triangleS == hit) && (t < tmin)) {
                info.setState(triangleS);
                tmin = t;
                info.setMaterial(item -> getMaterial());
                info.setNormal(item -> getNormal());
                info.setHit(r.getOrigin() + r.getDirection() * t);
            }
        }

    return info;
}

