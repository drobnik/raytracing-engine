#include "Renderer.h"

// something went wrong -- delete later
Renderer::Renderer() {
    assert(false);
}

Renderer::Renderer(std::shared_ptr<FileManager> man) : manager(std::move(man)) {
    sampler = std::make_shared<AdaptiveSampler>(AdaptiveSampler());
}

void Renderer::renderScene() {
    img = scene->renderScene(tracer);
    saveImage();
}

std::shared_ptr<AdaptiveSampler> Renderer::GetSampler(){
    return sampler;
}

void Renderer::AddScene(const std::shared_ptr<Scene>& s, const std::unique_ptr<Configuration>& conf) {
    std::string name = s->SceneName();
    scene = s;
    img = EngineImage(s->getViewPlane().getWRes(), s->getViewPlane().getHRes(),
                      s->Background(), name);

    scene->InitializeScene(conf, sampler);

    tracer = std::make_unique<Tracer>(Tracer(scene));
}

void Renderer::saveImage() {
    manager->saveImage(img);
    std::cout<<"Finished rendering image.\n";
}


