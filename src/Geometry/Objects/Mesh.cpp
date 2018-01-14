#include "Mesh.h"

Mesh::Mesh() {
    Vector3 ce = Vector3::Zero;
    simpleBounding = std::make_shared<Sphere>(Sphere(ce, 5));
    position = Vector3::Zero;
}

Mesh::Mesh(const std::vector<std::shared_ptr<Triangle>> tris) {
    triangles = tris;

    Vector3 ce = Vector3::Zero;
    simpleBounding = std::make_shared<Sphere>(Sphere(ce, 5));
    position = Vector3::Zero;
}

void Mesh::ChangePosition(const Vector3& position) {
    for(auto&& item : triangles){
        item->Move(position);
    }
}

ShadeInfo Mesh::Intersects(const Ray &ray, ShadeInfo &info) {
    float t = 0.0f, tmin = INFINITY;
    rayState triangleS = miss;

        for(auto&& item : triangles){
            triangleS = item->Intersects(ray, t);
            if((triangleS == tangent || triangleS == hit) && (t < tmin)) {
                info.setState(triangleS);
                tmin = t;
                info.setMaterial(item -> getMaterial());
                info.setNormal(item->GetNormal());
                info.setHit(ray.getOrigin() + ray.getDirection() * t);
            }
        }

    return info;
}

