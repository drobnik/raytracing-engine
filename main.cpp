#include <iostream>
#include "src/Geometry/Vector3.h"
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"

int main(int argc, char* argv[]) {
   /* Scene sampleScene = Scene();
    sampleScene.initialize();
    sampleScene.run();*/

    //add a name of produced image
    FileManager man = FileManager("../img/");
    Scene renderScene = Scene(600, 400, 1.0f, "scene_1");
    renderScene.init();
    Renderer renderer = Renderer(renderScene, man);

    renderer.renderScene();

    return 0;
}