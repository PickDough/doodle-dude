//
// Created by Misha Muravynets on 24.01.2024.
//

#ifndef OGAMEOVER_H
#define OGAMEOVER_H
#include "../../../../Framework/Object/FObject.h"
#include "../../../Common/NumberSprites/NumberSprites.h"
#include "../../../../Framework/UI/HorizontalContainer/FHorizontalContainer.h"

class OGameOver: public FObject {
public:
private:
    Sprite* gameOverSprite;
    Sprite* yourScoreSprite;
    Sprite* tileSprite; // Idk, just to identify it so the other score is distance

    unique_ptr<NumberSprites> sprites = {};
    unique_ptr<FHorizontalContainer> scoreContainer;
    unique_ptr<FHorizontalContainer> distContainer;

    void Init() override;
    void Tick(float deltaTime) override;
    void DeleteSelf() override;
};



#endif //OGAMEOVER_H
