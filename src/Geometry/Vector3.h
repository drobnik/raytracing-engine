#ifndef RAYTRACING_ENGINE_VECTOR_H
#define RAYTRACING_ENGINE_VECTOR_H
#include <cmath>
#include <iostream>
#include <assert.h>

class Vector3 {
private:
    float x, y, z;

public:
    Vector3();
    Vector3(const Vector3& v1);
    Vector3(float x, float y, float z);
    Vector3 operator-() const;

    Vector3 operator*(const float& k);
    Vector3 operator/(float k) const;
    Vector3 operator+(const Vector3 &v2) const;
    Vector3 operator-(const Vector3 &v2) const;
    bool operator==(const Vector3& v2);
    bool operator!=(const Vector3& v2);

    float dot(Vector3 v2);
    float absDot(Vector3 v2);
    Vector3 crossProd(Vector3 v2);
    float length()const;
    Vector3 normalize();

    Vector3 reflect(Vector3 normal);
    Vector3 lerp(Vector3 v, float t);

    float getX() const {return x;};
    float getY() const {return y;};
    float getZ() const {return z;};

    friend std::ostream& operator<<(std::ostream&, const Vector3&);

    static const Vector3 Zero;
    static const Vector3 Up;
    static const Vector3 Forward;
};


#endif //RAYTRACING_ENGINE_VECTOR_H
