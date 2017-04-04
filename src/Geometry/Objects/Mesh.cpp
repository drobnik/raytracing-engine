#include "Mesh.h"


Mesh::Mesh() { }

Mesh::~Mesh() { }

Mesh::Mesh(const Mesh &m) {
    triangles = m.triangles;
}

Mesh::Mesh(std::vector<Triangle> tris) {
    triangles = tris;
}

//FIXME
rayState Mesh::intersects(Ray &ray) {
    float t = 0.0f;
    rayState triangleS = miss;
    int iu = 0;
    for(std::vector<Triangle>::iterator i = triangles.begin();
        i != triangles.end(); i++){
        iu++;
        triangleS = i->intersects(ray, t);
        //std::cout<<iu<<"\n";
        //i->show();
    }

    return triangleS;
}

void Mesh::show() {
    std::vector<Triangle>::iterator kek;

    for(kek = triangles.begin(); kek != triangles.end(); kek++){
        kek->show();
    }
}
