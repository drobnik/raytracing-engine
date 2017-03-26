#ifndef RAYTRACING_ENGINE_FILEMANAGER_H
#define RAYTRACING_ENGINE_FILEMANAGER_H
#include <string>
#include "../lib/bitmap/bitmap_image.hpp"
#include "../EngineImage.h"

// this class is used for load/save operations; now it is only dedicated
// to BMP images. OBJs to be introduced.

class FileManager {
//private: some configuration file here
private:
    std::string path; //FIXME only for the renders; ie "\users\winds\"
public:
    FileManager(std::string path);
    EngineImage* loadImage(const std::string path);
    void saveImage(EngineImage img, const std::string name); //later: return a status and handle it somehow?
};


#endif //RAYTRACING_ENGINE_FILEMANAGER_H