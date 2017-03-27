#include "ViewPlane.h"

ViewPlane::ViewPlane()
    : wResolution(600),
      hResolution(400),
      pixSize(1.0f),
      gamma(1.0f){ }

ViewPlane::ViewPlane(int h, int w, float siz) : gamma(1.0f) {
    hResolution = h;
    wResolution = w;
    pixSize = siz;
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
