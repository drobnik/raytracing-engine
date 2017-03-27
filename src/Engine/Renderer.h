#ifndef RAYTRACING_ENGINE_RENDERER_H
#define RAYTRACING_ENGINE_RENDERER_H
#include <cassert>
#include "Scene.h"
#include "../Utilities/FileManager.h"
#include "Tracer.h"

class Renderer {
private:
    FileManager* manager;
    Scene* scene;
    EngineImage img;
    Tracer* tracer;
    //ArgsParser parser;
    //EngineConfig config;
    void saveImage();
public:
    Renderer();
    Renderer(Scene& s, FileManager& man);
    EngineImage renderScene(Tracer *tracer);
};


#endif //RAYTRACING_ENGINE_RENDERER_H
