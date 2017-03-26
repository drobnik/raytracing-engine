#include "FileManager.h"

//FIXME
EngineImage *FileManager::loadImage(const std::string path) {
    return nullptr;
}

FileManager::FileManager(std::string path) {

}

void FileManager::saveImage(EngineImage img, const std::string name) {
    std::vector<Vector3> imgData = img.getImgData();
    bitmap_image image((const unsigned int)img.getWidth(),
                       (const unsigned int) img.getHeight());

    image.set_all_channels((const unsigned char &) (img.getBackground().red() * 255),
                           (const unsigned char &) (img.getBackground().green() * 255),
                           (const unsigned char &) (img.getBackground().blue() * 255));

    for(unsigned int i = 0; i < imgData.size(); i++){
        //image.set_pixel();
    }

    image.save_image(path + name);
}
