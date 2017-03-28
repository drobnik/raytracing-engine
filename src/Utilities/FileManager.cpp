#include "FileManager.h"

EngineImage *FileManager::loadImage(const std::string path) {
    //FIXME
    return nullptr;
}

FileManager::FileManager(std::string path) {
    this->path = path;
}

void FileManager::saveImage(EngineImage &img) {
    img.getImg().save_image(path + img.Name() +"."+ BITMAP_FORMAT);

}
