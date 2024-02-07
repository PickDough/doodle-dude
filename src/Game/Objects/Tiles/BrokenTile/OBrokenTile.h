//
// Created by Misha Muravynets on 29.01.2024.
//

#ifndef OBROKENTILE_H
#define OBROKENTILE_H
#include <deque>

#include "../OTile.h"
#include "../../../../Framework/Object/FObject.h"


class OBrokenTile: public OTile {
public:
    void OnCollision(FObject* attachedTo, FObject* other, glm::vec2 normal);
private:
    bool isBroken;
    Sprite* idleSprite;
    deque<Sprite*> animation = {};
    int currFrame;

    float frameTime = 0.3;
    float passedTime;


    void Init() override;
    void Tick(float deltaTime) override;
};



#endif //OBROKENTILE_H
