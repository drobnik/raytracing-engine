#include "Camera.h"

void Camera::calcUVW() {
    w = eye - lookAt;
    w.normalize();
    u = up.crossProd(w);
    v = w.crossProd(u);
}