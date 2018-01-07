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
    EngineImage img;
    std::unique_ptr<Tracer> tracer;
    //ArgsParser parser;
    //EngineConfig config;
    void saveImage();

    Renderer(Renderer const &) = delete;
    Renderer &operator=(Renderer const &) = delete;

public:
    Renderer();
    Renderer(std::shared_ptr<Scene> s, std::shared_ptr<FileManager> man);
    void renderScene();
};


#endif //RAYTRACING_ENGINE_RENDERER_H
