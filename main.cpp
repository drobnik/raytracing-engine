#include <iostream>
#include "src/Geometry/Vector3.h"
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"

int main(int argc, char* argv[]) {
   /* Scene sampleScene = Scene();
    sampleScene.initialize();
    sampleScene.run();*/

    //add a name of produced image
    FileManager man = FileManager("../img/", "../assets/");
    man.loadModel("cube");
    Scene renderScene = Scene(500, 500, 1.0f, "scene_1");
    Scene renderScenePers = Scene(500, 500, 1.0f, "scene_2");
    renderScene.init();
    renderScenePers.initPers();

    Renderer renderer = Renderer(renderScene, man);
    Renderer rendererPers = Renderer(renderScenePers, man);

    renderer.renderScene();
    rendererPers.renderScene();

    return 0;
}