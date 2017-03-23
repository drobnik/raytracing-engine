#ifndef RAYTRACING_ENGINE_FILEMANAGER_H
#define RAYTRACING_ENGINE_FILEMANAGER_H
#include <string>
#include "Image.h"

// this class is used for load/save operations; now it is only dedicated
// to BMP images. OBJs to be introduced.

class FileManager {
//private: some configuration file here
public:
    Image* loadImage(const std::string path);
    void saveImage(); //later: return a status and handle it somehow?
};


#endif //RAYTRACING_ENGINE_FILEMANAGER_H
