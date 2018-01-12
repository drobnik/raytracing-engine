#include "Mesh.h"

Mesh::Mesh() {
    Vector3 ce = Vector3(0.0f, 0.0f, 0.0f);
    simpleBounding = std::make_shared<Sphere>(Sphere(ce, 5));
}

Mesh::Mesh(const std::vector<std::shared_ptr<Triangle>> tris) {
    triangles = tris;
    Vector3 ce = Vector3(0.0f, 0.0f, 0.0f);
    simpleBounding = std::make_shared<Sphere>(Sphere(ce, 5));
}

ShadeInfo Mesh::intersects(const Ray &ray, std::vector<std::shared_ptr<Light>> lights, std::shared_ptr<AmbientLight> ambient) {
    float t = 0.0f, tmin = INFINITY;
    Ray r = ray; //FIXME
    rayState triangleS = miss;

    ShadeInfo info = ShadeInfo(lights, ambient);
        for(auto&& item: triangles){
            triangleS = item -> intersects(ray, t);
            if((triangleS == tangent || triangleS == hit) && (t < tmin)) {
                info.setState(triangleS);
                tmin = t;
                info.setMaterial(item -> getMaterial());
                info.setNormal(item -> getNormal());
                info.setHit(ray.getOrigin() + ray.getDirection() * t);
            }
        }

    return info;
}

