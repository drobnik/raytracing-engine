#ifndef RAYTRACING_ENGINE_FILEMANAGER_H
#define RAYTRACING_ENGINE_FILEMANAGER_H
#include <string>
#include <fstream>
#include "../../lib/bitmap/bitmap_image.hpp"
#include "../Engine/EngineImage.h"
#include "../Geometry/Objects/Mesh.h"
#include "../Utilities/ObjParser.h"
#define BITMAP_FORMAT "bmp"
#define MESH_FORMAT "obj"

class FileManager {
//private: some configuration file here
private:
    std::string path; //FIXME directory for renders only
    std::string assetPath;
    ObjParser parser;
public:
    FileManager(std::string path, std::string assets);
    EngineImage* loadImage(const std::string path);
    Mesh loadModel(const std::string name);
    void saveImage(EngineImage &img);
};


#endif //RAYTRACING_ENGINE_FILEMANAGER_H
