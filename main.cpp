#include <iostream>
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"

int main() {
    FileManager man = FileManager("../img/", "../assets/");

    // Sample mesh
    Mesh k = man.loadModel("cube"); //FIMXE move somewherelse
    Scene* renderScene = new Scene(900, 700, 0.05f, "scene_1"); //FIXME 0.5f pix size

    renderScene->init();
    renderScene->addMesh(k);

    Renderer renderer = Renderer(renderScene, man);
    renderer.renderScene();

    //now reuse the scene with sample perspective cam
    renderScene->ChangeCamera(new PerspectiveCamera(Vector3(0.0f, 0.0f, -20.0f),
                                                   Vector3(0.0f, 0.0f, 1.0f), 200.0f, 2000));
    renderScene->ChangeSceneName("pers");

    Renderer rendererPers = Renderer(renderScene, man);
    rendererPers.renderScene();

    return 0;
}