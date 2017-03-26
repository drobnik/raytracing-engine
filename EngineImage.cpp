#include "EngineImage.h"

EngineImage::EngineImage() {
    assert(false);
}

EngineImage::EngineImage(int w, int h) {
    width = w;
    height = h;
    imgData.reserve((unsigned long long int) (width * height));
    background = LightIntensity(0.0f, 0.0f, 0.0f);
}

EngineImage::EngineImage(int w, int h, LightIntensity light) {
    width = w;
    height = h;
    imgData.reserve((unsigned long long int) (width * height));
    background = light;
}
Vector3 EngineImage::getPixel(int x, int y) {
    assert((x >= 0 && x < width) && (y >= y && y < height));
    return imgData.at((unsigned long long int) (x + y * width));
}

void EngineImage::setPixel(int x, int y, const Vector3 &c) {
    assert((x >= 0 && x < width) && (y >= y && y < height));
    imgData.at((unsigned long long int) (x + y * width)) = c;
}

void EngineImage::resetPixels(const Vector3 &c) {
    unsigned long long int i = 0;
    for(i; i < imgData.size(); i++){
        imgData.at(i) = c;
    }
}

int EngineImage::getWidth() const {
    return width;
}

int EngineImage::getHeight() const {
    return height;
}

const std::vector<Vector3> &EngineImage::getImgData() const {
    return imgData;
}

const LightIntensity &EngineImage::getBackground() const {
    return background;
}


