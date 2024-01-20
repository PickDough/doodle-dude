#include <Framework.h>
#include <iostream>

#include "src/FrameworkObjects/DoodleGuy/ODoodleGuy.h"
#include "src/FrameworkObjects/PlatformSpawner/OPlatformSpawner.h"
#include "src/FrameworkScene/FScene.h"


int main(int argc, char *argv[])
{
    const auto scene = new FScene();
    auto guy = new ODoodleGuy();
    guy->Position = glm::vec2(-100, 0);

    auto spawner = new OPlatformSpawner(scene->viewportHeight, scene->viewportWidth);
    scene->RegisterChild(guy);
    scene->RegisterChild(spawner);

    scene->SetCameraTarget(guy, glm::vec2(0, -200));

    return run(scene);
}
