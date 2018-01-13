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
    img.set_all_channels((const unsigned char &) (background.Red() * 255),
                         (const unsigned char &) (background.Green() * 255),
                         (const unsigned char &) (background.Blue() * 255));
}
EngineImage::EngineImage(const EngineImage &e) {
    width = e.width;
    height = e.height;
    background = e.background;
    name = e.name;
}

void EngineImage::setPixel(int x, int y, LightIntensity &c) {
    assert((x >= 0 && x < width) && (y >= 0 && y < height));

    rgb_t color = make_colour((const unsigned int &) (c.Red() * 255),
                              (const unsigned int &) (c.Green() * 255),
                              (const unsigned int &) (c.Blue() * 255));
    img.set_pixel(x, y, color);
}

void EngineImage::resetPixels(LightIntensity &c) {
    img.set_all_channels((const unsigned char &) (c.Red() * 255),
                         (const unsigned char &) (c.Green() * 255),
                         (const unsigned char &) (c.Blue() * 255));
}

const LightIntensity &EngineImage::getBackground() const {
    return background;
}

bitmap_image & EngineImage::getImg() {
    return img;
}

