//
// Created by koler on 19.01.2024.
//

#include "FScene.h"
#include "Framework.h"

void FScene::PreInit(int &width, int &height, bool &fullscreen) {
    width = viewportWidth;
    height = viewportHeight;
    fullscreen = false;

    Camera = new FCamera(Camera, width, height);
    GameState = new FGameState(Camera);
}

void FScene::InitChildren() {
    for (FObject *obj: WaitingForInitObjects) {
        obj->GameState = GameState;
        obj->Init();
        Objects.push_back(obj);
    }

    WaitingForInitObjects.clear();
}

bool FScene::Tick() {
    InitChildren();
    Camera->CalculateTopLeft();

    for (FObject *obj: Objects) {
        obj->Tick();
        if (obj->Image) {
            if (Camera->Intersact(obj)) {
                auto projection = Camera->Project(obj);

                drawSprite(obj->Image, projection.x, projection.y);
            }
        }
    }

    return false;
}

void FScene::onMouseMove(int x, int y, int xrelative, int yrelative) {
}

void FScene::onMouseButtonClick(FRMouseButton button, bool isReleased) {
}

void FScene::onKeyPressed(FRKey k) {
}

void FScene::onKeyReleased(FRKey k) {
}

void FScene::RegisterChild(FObject *child) {
    WaitingForInitObjects.push_back(child);
}

void FScene::SetCameraTarget(FObject *target, glm::vec2 offset) {
    Camera = new FCamera(target, offset);
}
