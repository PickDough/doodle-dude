//
// Created by Misha Muravynets on 23.01.2024.
//

#include "OScore.h"

#include "../../../../Framework/Scene/FScene.h"
#include "../../../Common/GameState/FGameState.h"

void OScore::DeleteSelf() {
    scene->MarkForDeletion(container.release());
    sprites->ReleaseSprites();
}

void OScore::Init() {
    sprites = make_unique<NumberSprites>();
    container = make_unique<FHorizontalContainer>();
    container->position = position;
    scene->RegisterChild(container.get());
}

void OScore::Tick(float deltaTime) {
    if (auto gameState = static_cast<FGameState*>(scene->GetGameState())) {
        score = max(score, static_cast<int>(gameState->GetPlayer()->position.y * DIST_TO_SCORE));
        gameState->Score = score;
        container->Clear();

        int num = score;
        while (num > 9) {
            container->PushFrontSprite(sprites->digits[num % 10]);
            num = num / 10;
        }
        container->PushFrontSprite(sprites->digits[num % 10]);
    }
}
