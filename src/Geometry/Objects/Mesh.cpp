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
   // return backward;
}

void Mesh::show() {
    std::vector<Triangle>::iterator kek;

    for(kek = triangles.begin(); kek != triangles.end(); kek++){
        kek->show();
    }
}
