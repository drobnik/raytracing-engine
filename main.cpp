#include <iostream>
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"
#include "src/Cameras/Camera.h"

int main() {
    FileManager man = FileManager("../img/", "../assets/");

    // Sample mesh
    Mesh k = man.loadModel("cube"); //FIMXE move somewherelse
    std::shared_ptr<Scene> renderScene = std::make_shared<Scene>(Scene(900, 700, 0.05f, "scene_1")); //FIXME 0.5f pix size

    renderScene->init();
    renderScene->addMesh(k);

    Renderer renderer = Renderer(renderScene, man);
    renderer.renderScene();

    //now reuse the scene with sample perspective cam
    renderScene->ChangeCamera(std::make_shared<PerspectiveCamera>(PerspectiveCamera(Vector3(0.0f, 0.0f, -20.0f),
                                                   Vector3(0.0f, 0.0f, 1.0f), 200.0f, 2000)));
    renderScene->ChangeSceneName("pers");

    Renderer rendererPers = Renderer(renderScene, man);
    rendererPers.renderScene();

    return 0;
}