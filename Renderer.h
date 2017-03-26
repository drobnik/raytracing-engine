#ifndef RAYTRACING_ENGINE_RENDERER_H
#define RAYTRACING_ENGINE_RENDERER_H
#include "Scene.h"
#include "Utilities/FileManager.h"
#include <cassert>

class Renderer {
private:
    FileManager* manager;
    Scene* scene;
    EngineImage img;
    // Tracer* tracer;
    //ArgsParser parser;
    //EngineConfig config;
public:
    Renderer();
    Renderer(Scene& s, FileManager& man);
    EngineImage renderScene();
    void saveImage();
};


#endif //RAYTRACING_ENGINE_RENDERER_H
