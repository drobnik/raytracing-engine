#include <iostream>
#include "src/Geometry/Vector3.h"
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"

int main(int argc, char* argv[]) {
    /*Scene sampleScene = Scene();
    sampleScene.initialize();
    sampleScene.run();*/

    Scene renderScene = Scene();
    FileManager man = FileManager("/img");
    renderScene.init(); //FIXME
    Renderer renderer = Renderer(renderScene, man);

    //renderer.renderScene();

    return 0;
}