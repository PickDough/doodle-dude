//
// Created by Misha Muravynets on 27.01.2024.
//

#include "OMonsterSpawner.h"

#include <iostream>

#include "../../../Framework/Scene/FScene.h"
#include "../../Common/GameState/FGameState.h"

void OMonsterSpawner::Init() {
    auto green = createSprite("./bnuy-green.png");
    auto pink = createSprite("./bnuy-pink.png");

    monsterSprites.push_back(green);
    monsterSprites.push_back(pink);

    if (auto gameState = static_cast<FGameState*>(scene->GetGameState())) {
        auto guy = gameState->GetPlayer();
        targetTotalMovedDistance = guy->position.y;
    }
}

void OMonsterSpawner::SpawnMonsters() {
    if (auto gameState = static_cast<FGameState*>(scene->GetGameState())) {
        auto enemiesToSpawn = rd.FRange(1, gameState->DifficultyMultiplier()+1);
        for (int i = 0; i < enemiesToSpawn; i++) {
            glm::vec2 pos = {rd.FRange(100, scene->viewportWidth - 25), rd.FRange(0, distanceBetweenRedraws)};
            pos.y += targetTotalMovedDistance + scene->viewportHeight;

            unsigned long n = static_cast<unsigned long>(rd.FRange(0, 1000)) % monsterSprites.size();
            auto monster = make_unique<OMonster>(monsterSprites[n]);
            monster->position = pos;
            scene->RegisterChild(monster.get());

            monsterSegments.push_back(std::move(monster));
        }
    }
}

void OMonsterSpawner::Tick(float deltaTime) {
    for (const auto &monster: monsterSegments) {
        if (targetTotalMovedDistance - monster->position.y  > scene->viewportHeight) {
            monster->MarkSelfForDeletion();
        }
    }
    monsterSegments.remove_if([] (unique_ptr<OMonster>& m) {
        if (m->isMarkedForDeletion) {
            m.release();
            return true;
        }
       return false;
    });

    if (auto gameState = static_cast<FGameState*>(scene->GetGameState())) {
        auto guy = gameState->GetPlayer();
        auto delta = max(0.0f, guy->position.y - targetTotalMovedDistance);
        targetTotalMovedDistance += delta;
        targetMovedDistance += delta;
        if (targetMovedDistance > distanceBetweenRedraws) {
            targetMovedDistance -= distanceBetweenRedraws;
            SpawnMonsters();
        }
    }
}

void OMonsterSpawner::DeleteSelf() {
    for (auto sprite: monsterSprites) {
        destroySprite(sprite);
    }

    for (auto &monster: monsterSegments) {
        monster.release()->MarkSelfForDeletion();
    }
}
