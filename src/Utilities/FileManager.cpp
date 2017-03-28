#include "FileManager.h"

//FIXME
EngineImage *FileManager::loadImage(const std::string path) {
    //EngineImage img = new En
    return nullptr;
}

FileManager::FileManager(std::string path) {
    this->path = path;
}

void FileManager::saveImage(EngineImage img, const std::string name) {
    // hey, img inside has no width and height
    img.getImg().save_image(path + name);
}
