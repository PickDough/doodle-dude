//
// Created by Misha Muravynets on 29.01.2024.
//

#include "OJetpackSpawner.h"
#include "../../../Framework/Scene/FScene.h"
#include "../../Common/GameState/FGameState.h"

void OJetpackSpawner::Init() {
    if (auto gameState = static_cast<FGameState *>(scene->GetGameState())) {
        auto guy = gameState->GetPlayer();
        targetTotalMovedDistance = guy->position.y;
    }

    SpawnJetpack();
}

void OJetpackSpawner::SpawnJetpack() {
    auto pos = glm::vec2{rd.FRange(100, scene->viewportWidth - 25), rd.FRange(0, distanceBetweenRedraws)};
    pos.y += targetTotalMovedDistance + scene->viewportHeight;

    jetpack = make_unique<OJetpack>();
    jetpack->position = pos;
    scene->RegisterChild(jetpack.get());
}

void OJetpackSpawner::Tick(float deltaTime) {
    if (auto gameState = static_cast<FGameState *>(scene->GetGameState())) {
        auto guy = gameState->GetPlayer();
        auto delta = max(0.0f, guy->position.y - targetTotalMovedDistance);
        targetTotalMovedDistance += delta;
        targetMovedDistance += delta;
        if (targetMovedDistance > distanceBetweenRedraws) {
            targetMovedDistance -= distanceBetweenRedraws;
            if (!jetpack->isActive) {

                jetpack.release()->MarkSelfForDeletion();
                SpawnJetpack();
            }
        }
    }
}

void OJetpackSpawner::DeleteSelf() {
    FObject::DeleteSelf();

    jetpack.release()->MarkSelfForDeletion();
}
