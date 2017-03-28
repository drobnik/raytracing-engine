#ifndef RAYTRACING_ENGINE_IMAGE_H
#define RAYTRACING_ENGINE_IMAGE_H
#include <vector>
#include <cassert>
#include <string>
#include "../Geometry/Vector3.h"
#include "../Lights/LightIntensity.h"
#include "../../lib/bitmap/bitmap_image.hpp"

class EngineImage {
private:
    std::string name;
    int width;
    int height;
    bitmap_image img;
    LightIntensity background;

public:
    EngineImage();
    EngineImage(int w, int h, std::string &imgName);
    EngineImage(int w, int h, LightIntensity light, std::string &imgName);
    ~EngineImage() {};
    EngineImage(const EngineImage& e);
    bitmap_image & getImg();
    const LightIntensity &getBackground() const;
    void setPixel(int x, int y, LightIntensity &c);
    void resetPixels(LightIntensity &c);
    inline std::string Name(){ return name;};
};


#endif //RAYTRACING_ENGINE_IMAGE_H
