//
// Created by Misha Muravynets on 27.01.2024.
//

#ifndef OSPEEDBOOST_H
#define OSPEEDBOOST_H
#include "../../../../Framework/Object/FObject.h"
#include "../../../../Framework/Scene/FScene.h"
#include "../../../../Framework/UI/HorizontalContainer/FHorizontalContainer.h"
#include "../../../Common/NumberSprites/NumberSprites.h"

class OSpeedBoost: public FObject {
private:
    unique_ptr<FHorizontalContainer> container;
    unique_ptr<NumberSprites> sprites;
    Sprite* arrowUp;
    Sprite* arrowDown;
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void DeleteSelf() override;
};



#endif //OSPEEDBOOST_H
