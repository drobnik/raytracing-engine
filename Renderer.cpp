#include "Renderer.h"

Renderer::Renderer(Scene &s) {
    img = EngineImage(0, 0);
}

EngineImage Renderer::renderScene() {
    EngineImage img = scene->renderScene();
    return img;
}

void Renderer::saveImage() {

}

Renderer::Renderer() {
    assert(false);
}
