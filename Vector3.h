#ifndef RAYTRACING_ENGINE_VECTOR_H
#define RAYTRACING_ENGINE_VECTOR_H
#include <cmath>
#include <iostream>
#include <assert.h>

class Vector3 {
private:
    float x;
    float y;
    float z;
public: //operatory
    Vector3();
    Vector3(const Vector3& v1);
    Vector3(float x, float y, float z);
    void neg(Vector3 v);

    Vector3& operator*(const Vector3& v2);
    Vector3& operator*(float k);
    Vector3& operator+(const Vector3& v2);
    Vector3& operator+(float k);
    Vector3& operator-(const Vector3& v2);
    Vector3& operator-(float k);
    Vector3& operator/(float k);
    bool operator==(const Vector3& v2);
    bool operator!=(const Vector3& v2);

    float dot(Vector3 v1, Vector3 v2);
    Vector3 crossProd(Vector3 v1, Vector3 v2);
    float length(Vector3 v);
    Vector3 normalize(Vector3 v);
    Vector3 reflect(Vector3 normal);
    Vector3 lerp(Vector3 v, float t);

    float getX() const {return x;};
    float getY() const {return y;};
    float getZ() const {return z;};
};

#endif //RAYTRACING_ENGINE_VECTOR_H
