//
// Created by Misha Muravynets on 27.01.2024.
//

#include "OSpeedBoost.h"

#include "../../../Common/GameState/FGameState.h"
#include "../../DoodleGuy/ODoodleGuy.h"

void OSpeedBoost::Init() {
    sprites = make_unique<NumberSprites>();
    container = make_unique<FHorizontalContainer>();
    container->position = position;
    scene->RegisterChild(container.get());
    arrowDown = createSprite("./arrow-down.png");
    arrowUp = createSprite("./arrow-up.png");
}

void OSpeedBoost::Tick(float deltaTime) {
    if (auto gameState = static_cast<FGameState *>(scene->GetGameState())) {
        container->Clear();
        auto guy = dynamic_cast<ODoodleGuy*>(gameState->GetPlayer());
        int num = guy->GetSpeedBoost() * 100.0f;
        while (num > 9) {
            container->PushFrontSprite(sprites->digits[num % 10]);
            num = num / 10;
        }
        container->PushFrontSprite(sprites->digits[num % 10]);

        if (guy->GetVelocity().y > 0.0f) {
            container->PushFrontSprite(arrowUp);
        } else {
            container->PushFrontSprite(arrowDown);
        }
    }
}

void OSpeedBoost::DeleteSelf() {
    scene->MarkForDeletion(container.release());
    sprites->ReleaseSprites();
}
