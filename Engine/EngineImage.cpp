#include "EngineImage.h"

EngineImage::EngineImage() {
    std::cout<<"engineimage() used!";
}

EngineImage::EngineImage(int w, int h) {
    width = w;
    height = h;
    img = bitmap_image((const unsigned int) w, (const unsigned int) h);
    background = LightIntensity(0.0f, 0.0f, 0.0f);
}

EngineImage::EngineImage(int w, int h, LightIntensity light) {
    width = w;
    height = h;
    img = bitmap_image((const unsigned int) w, (const unsigned int) h);
    background = light;
    img.set_all_channels((const unsigned char &) (background.red() * 255),
                         (const unsigned char &) (background.green() * 255),
                         (const unsigned char &) (background.blue() * 255));
}

/*Vector3 EngineImage::getPixel(int x, int y) {
    assert((x >= 0 && x < width) && (y >= y && y < height));
    return imgData.at((unsigned long long int) (x + y * width));
}*/

void EngineImage::setPixel(int x, int y, const LightIntensity &c) {
    assert((x >= 0 && x < width) && (y >= y && y < height));
    img.set_pixel(x, y, background.red() * 255, background.green() * 255, background.blue() * 255);
    //imgData.at((unsigned long long int) (x + y * width)) = c;
}

void EngineImage::resetPixels(const LightIntensity &c) {
    img.set_all_channels((const unsigned char &) (c.red() * 255),
                         (const unsigned char &) (c.green() * 255),
                         (const unsigned char &) (c.blue() * 255));
}

int EngineImage::getWidth() const {
    return width;
}

int EngineImage::getHeight() const {
    return height;
}

const LightIntensity &EngineImage::getBackground() const {
    return background;
}

bitmap_image & EngineImage::getImg() {
    return img;
}


