#ifndef RAYTRACING_ENGINE_IMAGE_H
#define RAYTRACING_ENGINE_IMAGE_H
#include <vector>
#include <cassert>
#include "Vector3.h"

class Image {
private:
    int width;
    int height;
    std::vector<Vector3> imgData; // size = width * height;; think about using pointers!!

public:
    Image(int w, int h);
    Vector3 getPixel(int x, int y);
    void setPixel(int x, int y, const Vector3& c);
    void resetPixels(const Vector3& c);
};


#endif //RAYTRACING_ENGINE_IMAGE_H
