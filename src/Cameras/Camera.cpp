#include "Camera.h"

Camera::Camera(): eye(Vector3(0.0f, 0.0f, 400.0f)),
                  lookAt(Vector3()),
                  up(Vector3(0.0f, 1.0f, 0.0f)){}

Camera::Camera(const Vector3& e, const Vector3& look, const Vector3& u,
               unsigned int height, unsigned int width, float pixSize,
               const std::shared_ptr<AdaptiveSampler>& sampler)
        : eye(e),
          lookAt(look),
          up(u),
          viewHeight(height),
          viewWidth(width),
          pixelSize(pixSize),
          sampler(sampler) {
    calculateUVW();
}

Camera::Camera(const Camera& cam)
        : eye(cam.eye),
          lookAt(cam.lookAt),
          up(cam.up),
          viewDistance(cam.viewDistance),
          viewHeight(cam.viewHeight),
          viewWidth(cam.viewWidth),
          pixelSize(cam.pixelSize),
          zoom(cam.zoom),
          u(cam.u),
          v(cam.v),
          w(cam.w),
          sampler(cam.sampler){ }

Camera::~Camera() { }

Vector3 Camera::CalculateDirection(Vector3&& point) {
    Vector3 direct = u * point.getX() + v * point.getY() - w * viewDistance;
    direct = direct.normalize();
    return direct;

}
void Camera::calculateUVW() {
    w = eye - lookAt;
    w.normalize();
    u = up.crossProd(w);
    v = w.crossProd(u);

    // special cases of looking vertically -- Suffern's hint
    bool camDir = eye.getX() == lookAt.getX()
                  && eye.getZ() == lookAt.getZ();

    // down
    if ( camDir && (eye.getY() > lookAt.getY())) {
        u = Vector3(0, 0, 1);
        v = Vector3(1, 0, 0);
        w = Vector3(0, 1, 0);
    }

    // up
    if (camDir && (eye.getY() < lookAt.getY())) {
        u = Vector3(1, 0, 0);
        v = Vector3(0, 0, 1);
        w = Vector3(0, -1, 0);
    }
}

