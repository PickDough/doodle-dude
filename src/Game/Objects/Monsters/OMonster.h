//
// Created by Misha Muravynets on 27.01.2024.
//

#ifndef OMONSTER_H
#define OMONSTER_H
#include "../../../Framework/Object/FObject.h"


class OMonster: public FObject {
    Sprite* sprite;
    float totalTime;
public:
    bool isAggressive = true;

    explicit OMonster(Sprite *sprite)
        : sprite(sprite) {
    }

    void Init() override;
    void Tick(float deltaTime) override;
};



#endif //OMONSTER_H
