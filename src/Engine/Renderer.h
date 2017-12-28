#ifndef RAYTRACING_ENGINE_RENDERER_H
#define RAYTRACING_ENGINE_RENDERER_H
#include <cassert>
#include "Scene.h"
#include "../Utilities/FileManager.h"
#include "Tracer.h"

class Renderer {
private:
    std::shared_ptr<FileManager> manager;
    std::shared_ptr<Scene> scene;
    EngineImage img;
    std::shared_ptr<Tracer> tracer;
    //ArgsParser parser;
    //EngineConfig config;
    void saveImage();

public:
    Renderer();
    Renderer(const Renderer& r);
    Renderer(std::shared_ptr<Scene> s, FileManager& man);
    void renderScene();
};


#endif //RAYTRACING_ENGINE_RENDERER_H
