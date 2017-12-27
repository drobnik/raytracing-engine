#include "Renderer.h"

Renderer::Renderer() {
    std::string name = "dummy_ren";
    img = EngineImage(500, 500, name);
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

Renderer::Renderer(Scene* s, FileManager& man) {
    std::string name = s->SceneName();
    scene = s;
    manager = &man;
    img = EngineImage(s->getViewPlane().getWRes(), s->getViewPlane().getHRes(),
                      s->Background(), name);
    tracer = new Tracer(s);
}

void Renderer::renderScene() {
    img = scene->renderScene(tracer);
    saveImage();
}

void Renderer::saveImage() {
    manager->saveImage(img);
    std::cout<<"Finished rendering image.\n";
}


