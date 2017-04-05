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

//FIXME
rayState Mesh::intersects(Ray &ray) {
    float t = 0.0f;
    rayState triangleS = miss;
    int distInVec;
    Vector3 normalS;

        for(std::vector<Triangle>::iterator i = triangles.begin();
            i != triangles.end(); i++){
            distInVec = std::distance(triangles.begin(), i);
            normalS = i->getNormal();
            //std::cout<<std::distance(triangles.begin(), i)<<"\n";
            triangleS = i->intersects(ray, t);
            //i->show();
        }

    return triangleS;
}

void Mesh::show() {
    std::cout<<"Mesh: triangles num:"<<triangles.size()<<"\n";
    std::vector<Triangle>::iterator kek;

    std::cout<<"Triangles: "<<"\n";
    for(kek = triangles.begin(); kek != triangles.end(); kek++){
        kek->show();
    }
}

