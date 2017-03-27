#include "Renderer.h"

Renderer::Renderer() {
    img = EngineImage(0,0);
    assert(false);
}

Renderer::~Renderer() { //?!
    tracer = nullptr;
    manager = nullptr;
    scene = nullptr;
}

Renderer::Renderer(const Renderer &r) {
    tracer = r.tracer;
    manager = r.manager;
    scene = r.scene;
    img = r.img;
}

Renderer::Renderer(Scene &s, FileManager& man) {
    Scene* scenePtr = &s;
    scene = &s;
    manager = &man;
    img = EngineImage(0, 0);
    tracer = new Tracer(scenePtr); //ticking bomb..
}

void Renderer::renderScene(Tracer *tracer) {
    EngineImage image = scene->renderScene(tracer);
    img = image;
    saveImage();
}

void Renderer::saveImage() {
    manager->saveImage(img,"test.bmp"); //TODO config.sceneName
}


