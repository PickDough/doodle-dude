//
// Created by Misha Muravynets on 25.01.2024.
//

#include "OSimpleTile.h"
#include "../../../../Framework/Scene/FScene.h"

void OSimpleTile::Init() {
    size = {w, h};
    collider = make_unique<FCollider>(w, h, this);
    collider->position = position + glm::vec2(0, 40);
}

void OSimpleTile::Tick(float deltaTime) {
    scene->GetViewport().Draw(sprite, position);
}
