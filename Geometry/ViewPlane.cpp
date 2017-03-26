#include "ViewPlane.h"

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

float ViewPlane::getGamma() const {
    return gamma;
}
