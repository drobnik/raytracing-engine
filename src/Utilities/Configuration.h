#ifndef RAYTRACING_ENGINE_CONFIGURATION_H
#define RAYTRACING_ENGINE_CONFIGURATION_H
#include <utility>
#include <memory>
#include "../Geometry/Vector3.h"

class Configuration {
public:
    Configuration(); //default configuration
    Configuration(unsigned int width, unsigned int height, float pixelSize, std::string sceneName);

    unsigned int ViewplaneWidth();
    unsigned int ViewplaneHeight();

    const std::string &getImgPath() const;
    void setImgPath(const std::string &imgPath);

    const std::string &getMeshesPath() const;
    void setMeshesPath(const std::string &meshesPath);

    float getNearplaneDistance() const;
    void setNearplaneDistance(float nearplaneDistance);

    const Vector3 &getCameraPosition() const;
    void setCameraPosition(const Vector3 &cameraPosition);

    const Vector3 &getLookAtPosition() const;
    void setLookAtPosition(const Vector3 &lookAtPosition);

    float PixelSize() const;
    const std::string &SceneName() const;

private:
    std::pair<unsigned int, unsigned int> viewplaneSize;
    std::string imgPath;
    std::string meshesPath;
    float pixelSize;
    float nearPlaneDistance;

    std::string sceneName;
    Vector3 cameraPosition;
    Vector3 lookAtPosition;

    // default values
    static const std::string IMG_PATH;
    static const std::string MESHES_PATH;

    static const std::pair<unsigned int, unsigned int> VIEWPLANE_SIZE;
    static const float PIXEL_SIZE;
    static const std::string SCENE_NAME;

    static const Vector3 EYE_POSITION;
    static const Vector3 LOOK_AT_DIRECTION;
    static const float NEAR_PLANE_DIST;
};


#endif //RAYTRACING_ENGINE_CONFIGURATION_H
