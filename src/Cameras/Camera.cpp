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
          w(Vector3(0.0f, 0.0f, 1.0f)){

}

Camera::~Camera() {

}

void Camera::calcUVW() {
    w = eye - lookAt;
    w.normalize();
    u = up.crossProd(w);
    v = w.crossProd(u);
}
