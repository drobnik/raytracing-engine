#include "Configuration.h"

Configuration::Configuration()
        : viewplaneSize(VIEWPLANE_SIZE),
          pixelSize(PIXEL_SIZE),
          sceneName(SCENE_NAME),
          imgPath(IMG_PATH),
          meshesPath(MESHES_PATH),
          cameraPosition(EYE_POSITION),
          lookAtPosition(LOOK_AT_DIRECTION),
          nearPlaneDistance(NEAR_PLANE_DIST) { }

Configuration::Configuration(unsigned int width, unsigned int height, float pixelSize, std::string sceneName)
        : imgPath(IMG_PATH),
          meshesPath(MESHES_PATH),
          cameraPosition(EYE_POSITION),
          lookAtPosition(LOOK_AT_DIRECTION),
          nearPlaneDistance(NEAR_PLANE_DIST) {
    viewplaneSize = std::pair<unsigned int, unsigned int>(width, height);
    this->pixelSize = pixelSize;
    this->sceneName = sceneName;
}


const std::string &Configuration::getImgPath() const {
    return imgPath;
}

void Configuration::setImgPath(const std::string &imgPath) {
    Configuration::imgPath = imgPath;
}

const std::string &Configuration::getMeshesPath() const {
    return meshesPath;
}

void Configuration::setMeshesPath(const std::string &meshesPath) {
    Configuration::meshesPath = meshesPath;
}

float Configuration::getNearplaneDistance() const {
    return nearPlaneDistance;
}

void Configuration::setNearplaneDistance(float nearplaneDistance) {
    Configuration::nearPlaneDistance = nearplaneDistance;
}

const Vector3 &Configuration::getCameraPosition() const {
    return cameraPosition;
}

void Configuration::setCameraPosition(const Vector3 &cameraPosition) {
    Configuration::cameraPosition = cameraPosition;
}

const Vector3 &Configuration::getLookAtPosition() const {
    return lookAtPosition;
}

void Configuration::setLookAtPosition(const Vector3 &lookAtPosition) {
    Configuration::lookAtPosition = lookAtPosition;
}

unsigned int Configuration::ViewplaneWidth(){ return viewplaneSize.first; }

unsigned int Configuration::ViewplaneHeight(){ return viewplaneSize.second; }

float Configuration::PixelSize() const {
    return pixelSize;
}

const std::string &Configuration::SceneName() const {
    return sceneName;
}

// Consts
const std::string Configuration::IMG_PATH = "../img/";
const std::string Configuration::MESHES_PATH = "../assets/";

const std::pair<unsigned int, unsigned int> Configuration::VIEWPLANE_SIZE = std::make_pair(800, 600);
const float Configuration::PIXEL_SIZE = 0.5f;
const std::string Configuration::SCENE_NAME = "scene_1";

const Vector3 Configuration::EYE_POSITION = Vector3(0.0f, 0.0f, 50.0f);
const Vector3 Configuration::LOOK_AT_DIRECTION = Vector3(0.0f, 0.0f, -50.0f);
const float Configuration::NEAR_PLANE_DIST = 200.0f;




