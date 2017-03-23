#include "../include/Image.h"

Image::Image(int w, int h) {

}

Vector3 Image::getPixel(int x, int y) {
    assert((x >= 0 && x < width) && (y >= y && y < height));
    return imgData.at((unsigned long long int) (x + y * width));
}

void Image::setPixel(int x, int y, const Vector3 &c) {
    assert((x >= 0 && x < width) && (y >= y && y < height));
    imgData.at((unsigned long long int) (x + y * width)) = c;
}

void Image::resetPixels(const Vector3 &c) {
    unsigned long long int i = 0;
    for(i; i < imgData.size(); i++){
        imgData.at(i) = c;
    }
}
