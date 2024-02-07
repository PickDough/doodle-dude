//
// Created by Misha Muravynets on 29.01.2024.
//

#ifndef OJETPACK_H
#define OJETPACK_H
#include <deque>

#include "../../../Framework/Object/FObject.h"
#include "../DoodleGuy/ODoodleGuy.h"

struct Frame {
    Sprite* sprite;
    int goTo;
};
class OJetpack: public FObject {
    ODoodleGuy* doodleGuy;

    Sprite* idleSprite;
    deque<Frame*> animation = {};
    Frame* currFrame;

    float frameTime = 0.2;
    float passedTime;

public:
    bool isActive;
    void OnCollision(FObject* attachedTo, FObject* other, glm::vec2 normal);

    void Init() override;
    void Tick(float deltaTime) override;
    void DeleteSelf() override;
};



#endif //OJETPACK_H
