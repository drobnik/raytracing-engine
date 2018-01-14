#ifndef RAYTRACING_ENGINE_RENDERER_H
#define RAYTRACING_ENGINE_RENDERER_H
#include <cassert>
#include <memory>
#include "Scene.h"
#include "../Utilities/FileManager.h"
#include "Tracer.h"

class Renderer {
private:
    std::shared_ptr<FileManager> manager;
    std::shared_ptr<Scene> scene;
    std::shared_ptr<AdaptiveSampler> sampler;
    EngineImage img;
    // TODO move configuration here

    std::unique_ptr<Tracer> tracer;
    //ArgsParser parser;
    //EngineConfig config;
    void saveImage();

    Renderer(Renderer const &) = delete;
    Renderer &operator=(Renderer const &) = delete;

public:
    Renderer();
    Renderer(std::shared_ptr<FileManager> man);
    void renderScene();
    std::shared_ptr<AdaptiveSampler> GetSampler();
    void AddScene(const std::shared_ptr<Scene>& s, const std::unique_ptr<Configuration>& conf);
};


#endif //RAYTRACING_ENGINE_RENDERER_H
