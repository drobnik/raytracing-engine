#include "Renderer.h"

Renderer::Renderer() {
    this->img = EngineImage(0,0);
    assert(false);
}

//FIXME
Renderer::Renderer(Scene &s, FileManager& man) {
    scene = &s;
    manager = &man;
    img = EngineImage(0, 0);
}

EngineImage Renderer::renderScene(Tracer *tracer) {
    EngineImage img = scene->renderScene(tracer);
    return img;
}

void Renderer::saveImage() {
    manager->saveImage(img,"test.bmp"); //TODO config.sceneName
}
