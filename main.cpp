#include <iostream>
#include "Geometry/Vector3.h"
#include "Scene.h"
#include "Renderer.h"

int main(int argc, char* argv[]) {
    Scene sampleScene = Scene();
    sampleScene.initialize();
    sampleScene.run();

    /*Scene renderScene = Scene();
    renderScene.init(); //FIXME
    Renderer renderer = Renderer(renderScene);
    renderer.renderScene();*/

    return 0;
}