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

float Vector3::length(Vector3 v){
    return sqrt((v.x * v.x) + (v.y * v.y) + (v.z * v.z));
}

std::ostream& operator<<(std::ostream& out, const Vector3& v){
    return out << "[Vector] x: "<< v.getX() <<", y: "<< v.getY() << ", z: "<< v.getZ() <<"\n";
}

Vector3 Vector3::normalize(Vector3 v){

}

/*Vector3 &Vector3::operator*(const Vector3 &v2) {
    return <#initializer#>;
}*/

Vector3 &Vector3::operator/(float k) {

    assert(k);
    float inv = 1.0f / k;
    float x = this->x * inv;
    float y = this->y * inv;
    float z = this->z * inv;

    return *(new Vector3(x, y, z));
    //return
}
/*
Vector3 operator*(const Vector3& v1, const Vector3& v2){

}*/