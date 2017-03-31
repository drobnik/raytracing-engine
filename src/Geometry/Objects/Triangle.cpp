#include "Triangle.h"

Triangle::Triangle() : Primitive(){
    a = Vector3(0.0f, 0.0f, 0.0f);
    b = Vector3(0.0f, 0.0f, 1.0f);
    c = Vector3(1.0f, 0.0f, 0.0f);
    normal = Vector3(0.0f, 1.0f, 0.0f);
}

Triangle::~Triangle(){ }

Triangle::Triangle(const Triangle &t) : Primitive() {
    a = t.a;
    b = t.b;
    c = t.c;
    normal = t.normal;
}

Triangle::Triangle(Vector3 &a, Vector3 &b, Vector3 &c)
        : Primitive(), a(a), b(b), c(c) {
    Vector3 v1 = b - a;
    Vector3 v2 = c - a;
    normal = v1.crossProd(v2);
    normal.normalize();
}

// FIXME add hit info!
rayState Triangle::intersects(Ray &ray, float &t) {
    float a, b, c, d, e, f, g, h, i, j, k, l;
    float m, n, p, q, s, r, d1, d2, d3, invDem;
    float beta, gamma, tet; // for t
    Vector3 ori = ray.getOrigin();
    Vector3 dir = ray.getDirection();

    a = this->a.getX() - this->b.getX(), b = this->a.getX() - this->c.getX();
    c = ray.getDirection().getX(), d = this->a.getX() - ori.getX();
    e = this->a.getY() - this->b.getY(), f = this->a.getY() - this->c.getY();
    g = dir.getY(), h = this->a.getY() - ori.getY(), i = this->a.getZ();
    j = this->a.getZ() - this->c.getZ(), k = dir.getY();
    l = this->a.getZ() - ori.getZ();

    m = f * k - g * j, n = h * k - g * l, p = f * l - h * j, q = g * i - e * k;
    s = e * j - f * i;
    d1 = a * m, d2 = b * q, d3 = c * s;
    invDem = 1.0f / (d1 + d2 + d3);
    beta = (d * m - b * n - c * p) * invDem;
    if(beta < 0.0f) return miss;

    r = e * l - h * i;
    gamma = (a * n + d * q + c * r) *invDem;
    if(gamma < 0.0f || gamma + beta > 1.0f) return miss;

    tet = (a * p - b * r + d * s) * invDem;
    if(tet < e-6) return miss;

    t = tet;
    //info.normal = normal;
    //info.point = ray.getOrigin() + t * ray.getDirection()
    return tangent;
}
