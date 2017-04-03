#include "FileManager.h"

EngineImage *FileManager::loadImage(const std::string path) {
    //FIXME
    return nullptr;
}

FileManager::FileManager(std::string path, std::string assets) {
    this->path = path;
    assetPath = assets;
    parser = ObjParser();
}

void FileManager::saveImage(EngineImage &img) {
    img.getImg().save_image(path + img.Name() +"."+ BITMAP_FORMAT);

}

Mesh FileManager::loadModel(const std::string name) {
    std::cout<<assetPath + name + "." + MESH_FORMAT<<"\n";
    std::ifstream infile(assetPath + name + "." + MESH_FORMAT);
    Mesh m = parser.loadMesh(infile);
    return m;
}
