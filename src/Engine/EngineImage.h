#ifndef RAYTRACING_ENGINE_IMAGE_H
#define RAYTRACING_ENGINE_IMAGE_H
#include <vector>
#include <cassert>
#include "../Geometry/Vector3.h"
#include "../Lights/LightIntensity.h"
#include "../../lib/bitmap/bitmap_image.hpp"

class EngineImage {
private:
    int width;
    int height;
    bitmap_image img;
    LightIntensity background;

public:
    EngineImage(int w, int h);
    EngineImage(int w, int h, LightIntensity light);
    EngineImage();
    int getWidth() const;
    int getHeight() const;
    bitmap_image & getImg();
    const LightIntensity &getBackground() const;
    //Vector3 getPixel(int x, int y);
    void setPixel(int x, int y, const LightIntensity& c);
    void resetPixels(const LightIntensity& c);
};


#endif //RAYTRACING_ENGINE_IMAGE_H
