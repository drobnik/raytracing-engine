#include <iostream>
#include <utility>
#include "src/Engine/Scene.h"
#include "src/Engine/Renderer.h"

// TODO: Move it somewherelse -- maybe some configuration class?
// File Manager setup
const std::string IMG_PATH = "../img/";
const std::string MESHES_PATH = "../assets/";

// Scene setup
const std::pair<int, int> VIEWPLANE_SIZE = std::make_pair(900, 700);
const float PIXEL_SIZE = 0.05f; //FIXME 0.5f pix size
const std::string SCENE_NAME = "scene_1";

// Default perspective camera
const Vector3 EYE_POSITION = Vector3(0.0f, 0.0f, -20.0f);
const Vector3 LOOK_AT_DIRECTION = Vector3(0.0f, 0.0f, 1.0f);
const float NEAR_PLANE_DIST = 200.0f;
const float FAR_PLANE_DIST = 2000.0f;

int main() {
    std::shared_ptr<FileManager> man = std::make_unique<FileManager>(IMG_PATH, MESHES_PATH); // shared resource by multiple renderers
    Mesh k = man->loadModel("cube");    // Sample mesh

    std::shared_ptr<Scene> renderScene = std::make_shared<Scene>(Scene(VIEWPLANE_SIZE.first, VIEWPLANE_SIZE.second,
                                                                PIXEL_SIZE, SCENE_NAME));

    renderScene->init();
    renderScene->addMesh(k);

    Renderer renderer(renderScene, man);
    renderer.renderScene();

    //now reuse the scene with sample perspective cam
//    renderScene->ChangeCamera(std::make_unique<PerspectiveCamera>(PerspectiveCamera(EYE_POSITION,
//                                                   LOOK_AT_DIRECTION, NEAR_PLANE_DIST, FAR_PLANE_DIST)));
//    renderScene->ChangeSceneName("pers");

    //Renderer rendererPers(renderScene, man);
    //rendererPers.renderScene();

    return 0;
}