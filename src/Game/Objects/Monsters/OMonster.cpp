//
// Created by Misha Muravynets on 27.01.2024.
//

#include "OMonster.h"

#include "../../../Framework/Scene/FScene.h"
#include "../../Common/Random.h"

void OMonster::Init() {
    int w, h;
    getSpriteSize(sprite, w, h);
    size = {w, h};
    collider = make_unique<FCollider>(w, h, this, false);
    totalTime = Random().FRange(M_PI, 2.0f * M_PI);
}

void OMonster::Tick(float deltaTime) {
    if (isAggressive) {
        totalTime += 2.0f*deltaTime;
        auto radialMovemnet = 20.0f*glm::vec2{sin(M_PI * totalTime), cos(M_PI * totalTime)};
        scene->GetViewport().Draw(sprite, position + radialMovemnet);
        collider->position = position + radialMovemnet;
    } else {
        collider->isEnabled = false;
    }
}
