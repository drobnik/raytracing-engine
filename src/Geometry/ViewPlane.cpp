#include "ViewPlane.h"

ViewPlane::ViewPlane()
    : wResolution(100),
      hResolution(100),
      pixSize(0.05f),
      gamma(1.0f){ }

ViewPlane::ViewPlane(int w, int h, float siz) {
    wResolution = w;
    hResolution = h;
    pixSize = siz;
    gamma = 1.0f;
}
int ViewPlane::getHRes() const {
    return hResolution;
}

int ViewPlane::getWRes() const {
    return wResolution;
}

float ViewPlane::getPixSize() const {
    return pixSize;
}

void ViewPlane::HRes(int hResolution) {
    ViewPlane::hResolution = hResolution;
}

void ViewPlane::WRes(int wResolution) {
    ViewPlane::wResolution = wResolution;
}

void ViewPlane::setPixSize(float pixSize) {
    ViewPlane::pixSize = pixSize;
}

void ViewPlane::setGamma(float gamma) {
    ViewPlane::gamma = gamma;
}
