#include "EngineImage.h"

EngineImage::EngineImage()
    : width(600),
      height(400),
      img(bitmap_image()),
      background(LightIntensity(0.0f, 0.0f, 0.0f)),
      name("dummy") { }

EngineImage::EngineImage(int w, int h, std::string &imgName) {
    width = w;
    height = h;
    name = imgName;
    img = bitmap_image((const unsigned int) w, (const unsigned int) h);
    background = LightIntensity(0.0f, 0.0f, 0.0f);
}

EngineImage::EngineImage(int w, int h, LightIntensity light, std::string &imgName) {
    width = w;
    height = h;
    name = imgName;
    img = bitmap_image((const unsigned int) w, (const unsigned int) h);
    background = light;
    img.set_all_channels((const unsigned char &) (background.red() * 255),
                         (const unsigned char &) (background.green() * 255),
                         (const unsigned char &) (background.blue() * 255));
}
EngineImage::EngineImage(const EngineImage &e) {
    width = e.width;
    height = e.height;
    background = e.background;
    name = e.name;
}

/*Vector3 EngineImage::getPixel(int x, int y) {
    assert((x >= 0 && x < width) && (y >= 0 && y < height));
    return imgData.at((unsigned long long int) (x + y * width));
}*/

// c == 0
void EngineImage::setPixel(int x, int y, LightIntensity &c) {
    assert((x >= 0 && x < width) && (y >= 0 && y < height));

    rgb_t color = make_colour((const unsigned int &) (c.red() * 255),
                              (const unsigned int &) (c.green() * 255),
                              (const unsigned int &) (c.blue() * 255));
    img.set_pixel(x, y, color);
}

void EngineImage::resetPixels(LightIntensity &c) {
    img.set_all_channels((const unsigned char &) (c.red() * 255),
                         (const unsigned char &) (c.green() * 255),
                         (const unsigned char &) (c.blue() * 255));
}

const LightIntensity &EngineImage::getBackground() const {
    return background;
}

bitmap_image & EngineImage::getImg() {
    return img;
}

