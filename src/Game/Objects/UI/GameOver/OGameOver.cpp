//
// Created by Misha Muravynets on 24.01.2024.
//

#include "OGameOver.h"
#include "../../../../Framework/Scene/FScene.h"
#include "../../../Common/GameState/FGameState.h"
#include "../Score/OScore.h"
#include "../Score/OScore.h"

void OGameOver::Init() {
    sprites = make_unique<NumberSprites>();
    
    gameOverSprite = createSprite("./game-over.png");
    int w,h;
    getSpriteSize(gameOverSprite, w, h);
    position -= glm::vec2(w / 2, h);
    yourScoreSprite = createSprite("./your-score.png");
    tileSprite = createSprite("./tile.png");

    scoreContainer = make_unique<FHorizontalContainer>();
    scoreContainer->position = position + glm::vec2(0, 100);

    distContainer = make_unique<FHorizontalContainer>();
    distContainer->position = position + glm::vec2(0, 200);

    FGameState* gameState = static_cast<FGameState*>(scene->GetGameState());
    int num = gameState->Score;
    while (num > 9) {
        scoreContainer->PushFrontSprite(sprites->digits[num % 10]);
        num = num / 10;
    }
    scoreContainer->PushFrontSprite(sprites->digits[num % 10]);
    num = gameState->PassedPlatforms;
    while (num > 9) {
        distContainer->PushFrontSprite(sprites->digits[num % 10]);
        num = num / 10;
    }
    distContainer->PushFrontSprite(sprites->digits[num % 10]);

    scoreContainer->PushFrontSprite(yourScoreSprite);
    distContainer->PushFrontSprite(tileSprite);
    distContainer->PushFrontSprite(yourScoreSprite);

    scene->RegisterChild(scoreContainer.get());
    scene->RegisterChild(distContainer.get());
}

void OGameOver::Tick(float deltaTime) {
    scene->GetViewport().DrawOverViewport(gameOverSprite, position);
}

void OGameOver::DeleteSelf() {
    scene->MarkForDeletion(scoreContainer.release());
    scene->MarkForDeletion(distContainer.release());
    destroySprite(gameOverSprite);
    destroySprite(yourScoreSprite);
    destroySprite(tileSprite);

    sprites->ReleaseSprites();
}
