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
    int kek;
    Vector3 hehe;
    triangleS = simpleBounding.intersects(ray, t);
    if(triangleS == hit || triangleS == tangent){
        //std::cout<<"trafia\n";
        for(std::vector<Triangle>::iterator i = triangles.begin();
            i != triangles.end(); i++){
            kek = std::distance(triangles.begin(), i);
            hehe = i->getNormal();
            //std::cout<<std::distance(triangles.begin(), i)<<"\n";
            triangleS = i->intersects(ray, t);
            //i->show();
        }
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

