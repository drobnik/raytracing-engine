#include "Camera.h"

Camera::Camera(): eye(Vector3(0.0f, 0.0f, 400.0f)),
                  lookAt(Vector3()),
                  up(Vector3(0.0f, 1.0f, 0.0f)),
                  nearPlane(100),
                  farPlane(5000),
                  u(Vector3(1.0f, 0.0f, 0.0f)),
                  v(Vector3(0.0f, 1.0f, 0.0f)),
                  w(Vector3(0.0f, 0.0f, 1.0f)) {}

Camera::Camera(Vector3 e, Vector3 look, float near, float far)
        : eye(e),
          lookAt(look),
          up(Vector3(0.0f, 1.0f, 0.0f)),
          nearPlane(near),
          farPlane(far),
          u(Vector3(1.0f, 0.0f, 0.0f)),
          v(Vector3(0.0f, 1.0f, 0.0f)),
          w(Vector3(0.0f, 0.0f, 1.0f)){ }

Camera::Camera(const Camera& cam)
        : eye(cam.eye),
          lookAt(cam.lookAt),
          up(cam.up),
          nearPlane(cam.nearPlane),
          farPlane(cam.farPlane),
          u(cam.u),
          v(cam.v),
          w(cam.w){ }

Camera::~Camera() { }

void Camera::calcUVW() {
    w = eye - lookAt;
    w.normalize();
    u = up.crossProd(w);
    v = w.crossProd(u);

    bool camDir = eye.getX() == lookAt.getX() && eye.getZ() == lookAt.getZ();
    if ( camDir && eye.getY() > lookAt.getY()) { //vertically down
        u = Vector3(0, 0, 1);
        v = Vector3(1, 0, 0);
        w = Vector3(0, 1, 0);
    }

    if (camDir && eye.getY() < lookAt.getY()) { //vertically up
        u = Vector3(1, 0, 0);
        v = Vector3(0, 0, 1);
        w = Vector3(0, -1, 0);
    }
}

