#include "Renderer.h"

// something went wrong -- delete later
Renderer::Renderer() {
    assert(false);
}

Renderer::Renderer(std::shared_ptr<Scene> s, std::shared_ptr<FileManager> man) : manager(std::move(man)) {
    std::string name = s->SceneName();
    scene = s;
    img = EngineImage(s->getViewPlane().getWRes(), s->getViewPlane().getHRes(),
                      s->Background(), name);
    tracer = std::make_unique<Tracer>(Tracer(scene));
}

void Renderer::renderScene() {
    img = scene->renderScene(tracer);
    saveImage();
}

void Renderer::saveImage() {
    manager->saveImage(img);
    std::cout<<"Finished rendering image.\n";
}


