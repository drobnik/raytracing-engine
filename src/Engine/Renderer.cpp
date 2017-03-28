#include "Renderer.h"

Renderer::Renderer() {
    img = EngineImage(500,500);
    assert(false);
}

Renderer::~Renderer() { //?!
    delete tracer;
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
    img = EngineImage(s.getViewPlane().getWRes(),
                      s.getViewPlane().getHRes(), s.Background());
    tracer = new Tracer(scenePtr);
}

void Renderer::renderScene() {
    img = scene->renderScene(tracer);
    saveImage();
}

void Renderer::saveImage() {
    manager->saveImage(img,"test.bmp");
    std::cout<<"\nDone\n";
}


