#include <iostream>
#include "include/Vector3.h"
#include "include/Scene.h"

int main(int argc, char* argv[]) {
    Scene sampleScene = Scene();
    sampleScene.initialize();
    sampleScene.run();

    return 0;
}