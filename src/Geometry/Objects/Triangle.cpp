#include "Triangle.h"


Triangle::Triangle() : Primitive(){
    a = Vector3(0.0f, 0.0f, 0.0f);
    b = Vector3(0.0f, 0.0f, 1.0f);
    c = Vector3(1.0f, 0.0f, 0.0f);
    normal = Vector3(0.0f, 1.0f, 0.0f);
    material = std::make_shared<PhongMat>(PhongMat());
}

Triangle::~Triangle(){ }

Triangle::Triangle(const Triangle &t) {
    a = t.a;
    b = t.b;
    c = t.c;
    normal = t.normal;
    material = t.material;
}

Triangle::Triangle(Vector3 &a, Vector3 &b, Vector3 &c) {
    this->a = a;
    this->b = b;
    this->c = c;
    Vector3 v1 = b - a;
    Vector3 v2 = c - a;
    normal = v1.crossProd(v2);
    normal.normalize();
    normal = -normal;
    material = std::make_shared<PhongMat>(PhongMat()); //TODO
}

rayState Triangle::Intersects(const Ray &ray, float &t) {
    float a, b, c, d, e, f, g, h, i, j, k, l;
    float m, n, p, q, s, r, d1, d2, d3, invDem;
    float beta, gamma, tet = 0.0f; // for t
    Vector3 ori = ray.getOrigin();
    Vector3 dir = ray.getDirection();

    a = this->a.getX() - this->b.getX(), b = this->a.getX() - this->c.getX();
    c = ray.getDirection().getX(), d = this->a.getX() - ori.getX();
    e = this->a.getY() - this->b.getY(), f = this->a.getY() - this->c.getY();
    g = dir.getY(), h = this->a.getY() - ori.getY(), i = this->a.getZ() - this->b.getZ();
    j = this->a.getZ() - this->c.getZ(), k = dir.getZ();
    l = this->a.getZ() - ori.getZ();

    m = f * k - g * j, n = h * k - g * l, p = f * l - h * j, q = g * i - e * k;
    s = e * j - f * i;
    d1 = a * m, d2 = b * q, d3 = c * s;
    invDem = 1.0f / (d1 + d2 + d3);

    beta = (d * m - b * n - c * p) * invDem;
    if(beta < 0.0f) {
        return miss;
    }

    r = e * l - h * i;
    gamma = (a * n + d * q + c * r) *invDem;
    if(gamma < 0.0f || gamma + beta > 1.0f){
        return miss;
    }

    tet = (a * p - b * r + d * s) * invDem;

    if(tet < e-6) return miss;
    t = tet;

    return hit;
}

Vector3 & Triangle::GetNormal() {
    return normal;
}

void Triangle::FlipNormal(Triangle &t) {
    Vector3 a, b, c;
    a = t.a, b = t.b, c = t.c;
    Vector3 v1 = b - c;
    Vector3 v2 = a - c;
    t.normal = v1.crossProd(v2);
    normal.normalize();
}

void Triangle::SetNormal(const Vector3 &normal) {
    Triangle::normal = normal;
}

void Triangle::Move(const Vector3 &offset) {
    a = a + offset;
    b = b + offset;
    c = c + offset;
}