#include "Vector3.h"

Vector3::Vector3(const Vector3 &v1) {
    this->x = v1.x;
    this->y = v1.y;
    this->z = v1.z;
}

Vector3::Vector3(){
    this->x = 0.0f;
    this->y = 0.0f;
    this->z = 0.0f;
}

Vector3::Vector3(float x, float y, float z){
    this->x = x;
    this->y = y;
    this->z = z;
}

float Vector3::length(){
    return sqrtf((this->x * this->x) + (this->y * this->y) + (this->z * this->z));
}

std::ostream& operator<<(std::ostream& out, const Vector3& v){
    out << "[Vector] x: "<< v.getX() <<", y: "<< v.getY() << ", z: "<< v.getZ() <<"\n";
    return out;
}

Vector3 Vector3::normalize(){
    float n = this->length();
    assert(n);
    return *this / n;
}

const Vector3 Vector3::operator/(float k) {

    assert(k);
    float inv = 1.0f / k;
    float x = this->x * inv;
    float y = this->y * inv;
    float z = this->z * inv;

    return Vector3(x, y, z);
}

Vector3 Vector3::neg(Vector3 v) {
    return Vector3(-v.x, -v.y, -v.z);
}

Vector3 Vector3::operator*(const float& k) {
    return Vector3(this->x*k, this->y*k, this->z*k);
}

const Vector3 Vector3::operator+(const Vector3 &v2) {
    return Vector3(this->x + v2.x, this->y + v2.y, this->z + v2.z);
}

const Vector3 Vector3::operator-(const Vector3 &v2) {
    return Vector3(this->x - v2.x, this->y - v2.y, this->z - v2.z);
}

bool Vector3::operator==(const Vector3 &v2) {
    return (this->x == v2.x) && (this->y == v2.y) && (this->z == v2.z);
}

float Vector3::dot(Vector3 v2) {
    return (this->x * v2.x) + (this->y * v2.y) + (this->z * v2.z);
}

float Vector3::absDot(Vector3 v2) {
    return fabsf((this->x * v2.x) + (this->y * v2.y) + (this->z * v2.z));
}

Vector3 Vector3::crossProd(Vector3 v2) {
    return Vector3((this->y * v2.z - this->z * v2.y), (this->z * v2.x - this->x * v2.z),
                   (this->x * v2.y - this -> y * v2.x) );
}

Vector3 Vector3::reflect(Vector3 normal) {
    return *this - (normal * (2 * this->dot(normal)));
}

Vector3 Vector3::lerp(Vector3 v, float t) {
    float x = this->x + t * (v.x - this->x);
    float y = this->y + t * (v.y - this->y);
    float z = this->z + t * (v.z - this->z);
    return Vector3();
}

bool Vector3::operator!=(const Vector3 &v2) {
    return !((*this) == v2);
}



