#ifndef RAYTRACING_ENGINE_IMAGE_H
#define RAYTRACING_ENGINE_IMAGE_H
#include <vector>
#include <cassert>
#include "Geometry/Vector3.h"
#include "Lights/LightIntensity.h"

class EngineImage {
private:
    int width;
    int height;
    std::vector<Vector3> imgData; // size = width * height;; think about using pointers!!
    LightIntensity background;
public:
    EngineImage(int w, int h);
    EngineImage(int w, int h, LightIntensity light);
    EngineImage();
    int getWidth() const;
    int getHeight() const;
    const std::vector<Vector3> &getImgData() const;
    const LightIntensity &getBackground() const;
    Vector3 getPixel(int x, int y);
    void setPixel(int x, int y, const Vector3& c);
    void resetPixels(const Vector3& c);
};


#endif //RAYTRACING_ENGINE_IMAGE_H
