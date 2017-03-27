#include <iostream>
#include "Geometry/Vector3.h"
#include "Engine/Scene.h"
#include "Engine/Renderer.h"

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