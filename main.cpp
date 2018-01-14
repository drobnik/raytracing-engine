#include <iostream>
#include <utility>
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"
#include "src/Cameras/PerspectiveCamera.h"

int main() {
    std::unique_ptr<Configuration> conf = std::make_unique<Configuration>();
    std::shared_ptr<FileManager> man = std::make_shared<FileManager>(conf->getImgPath(), conf->getMeshesPath());

    Mesh k = man->loadModel("cube"); // Sample mesh

    std::shared_ptr<Scene> renderScene = std::make_shared<Scene>(Scene(conf->ViewplaneWidth(), conf->ViewplaneHeight(),
                                                                conf->PixelSize(), conf->SceneName()));

    renderScene->InitializeScene(conf);
    renderScene->addMesh(k);

    Renderer renderer(renderScene, man);
    renderer.renderScene();

    //now reuse the scene with sample perspective cam
    renderScene->ChangeCamera(std::make_unique<PerspectiveCamera>(PerspectiveCamera(conf->getCameraPosition(),
                                                                                    conf->getLookAtPosition(), Vector3::Up,
                                                                                    conf->ViewplaneWidth(),
                                                                                    conf->ViewplaneHeight(),
                                                                                    conf->PixelSize())));
    renderScene->ChangeSceneName("pers");

    Renderer rendererPers(renderScene, man);
    rendererPers.renderScene();

    return 0;
}