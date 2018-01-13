#ifndef RAYTRACING_ENGINE_FILEMANAGER_H
#define RAYTRACING_ENGINE_FILEMANAGER_H
#include <string>
#include <fstream>
#include "../../lib/bitmap/bitmap_image.hpp"
#include "../Engine/EngineImage.h"
#include "../Geometry/Objects/Mesh.h"
#include "../Utilities/ObjParser.h"

class FileManager {
private:
    std::string path;
    std::string assetPath;
    ObjParser parser;

    static const std::string BITMAP_FORMAT;
    static const std::string MESH_FORMAT;
public:
    FileManager(std::string path, std::string assets);
    Mesh loadModel(const std::string name);
    void saveImage(EngineImage &img);
};


#endif //RAYTRACING_ENGINE_FILEMANAGER_H
