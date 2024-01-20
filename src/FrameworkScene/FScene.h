//
// Created by koler on 19.01.2024.
//

#ifndef FSCENE_H
#define FSCENE_H
#include <Framework.h>
#include <vector>

#include "../FrameworkCamera/FCamera.h"
#include "../FrameworkObjects/FObject.h"
#include "../FGameState/FGameState.h"


class FScene: public Framework {
public:
    explicit FScene(){}

    void PreInit(int& width, int& height, bool& fullscreen) override;

    bool Init() override {
        return true;
    }

    void Close() override {

    }

    const char* GetTitle() override
    {
        return "DoodleGuy";
    }

public:
    int viewportHeight = 800;
    int viewportWidth = 600;

    void InitChildren();

    void RegisterChild(FObject* child);

    void SetCameraTarget(FObject* target, glm::vec2 offset);

    bool Tick() override;

    void onMouseMove(int x, int y, int xrelative, int yrelative) override;

    void onMouseButtonClick(FRMouseButton button, bool isReleased) override;

    void onKeyPressed(FRKey k) override;

    void onKeyReleased(FRKey k) override;

private:
    FGameState* GameState = nullptr;
    FCamera* Camera = nullptr;
    std::vector<FObject*> Objects = std::vector<FObject*>{};
    std::vector<FObject*> WaitingForInitObjects = std::vector<FObject*>{};
};



#endif //FSCENE_H
