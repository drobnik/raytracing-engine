#include <iostream>
#include "src/Geometry/Vector3.h"
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"

int main(int argc, char* argv[]) {
    //add a name of produced image
    FileManager man = FileManager("../img/", "../assets/");
    //Mesh k = man.loadModel("cube"); //FIMXE move somewherelse
    Scene renderScene = Scene(900, 700, 0.05f, "scene_1"); //FIXME 0.5f pix size
    //Scene renderScenePers = Scene(500, 500, 1.0f, "scene_2");
    renderScene.init();
    //renderScenePers.initPers();

    //k.show();
    //renderScene.addMesh(k);
    //renderScenePers.addMesh(k);

    Renderer renderer = Renderer(renderScene, man);
    //Renderer rendererPers = Renderer(renderScenePers, man);

    renderer.renderScene();
    //rendererPers.renderScene();

    return 0;
}