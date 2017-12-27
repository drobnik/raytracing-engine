#include <iostream>
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"

int main(int argc, char* argv[]) {
    //add a name of produced image
    FileManager man = FileManager("../img/", "../assets/");
    Mesh k = man.loadModel("cube"); //FIMXE move somewherelse
    Scene renderScene = Scene(900, 700, 0.05f, "scene_1"); //FIXME 0.5f pix size
    Scene renderScenePers = Scene(900, 700, 0.05f, "scene_2");
    renderScene.init();
    renderScenePers.initPers();

    renderScene.addMesh(k);
    renderScenePers.addMesh(k);

    Renderer renderer = Renderer(renderScene, man);
    Renderer rendererPers = Renderer(renderScenePers, man);

    renderer.renderScene();
    rendererPers.renderScene();

    return 0;
}