#include <iostream>
#include "src/Geometry/Vector3.h"
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"

int main(int argc, char* argv[]) {
    /*Scene sampleScene = Scene();
    sampleScene.initialize();
    sampleScene.run();*/

    FileManager man = FileManager("/img");
    Scene renderScene = Scene();
    renderScene.init();
    ViewPlane plane = renderScene.getViewPlane();
    Renderer renderer = Renderer(renderScene, man);
    //FIXME
    //EngineImage img = renderer.renderScene();

    return 0;
}