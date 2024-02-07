//
// Created by Misha Muravynets on 29.01.2024.
//

#ifndef OPROJECTILE_H
#define OPROJECTILE_H
#include "../../../Framework/Object/FObject.h"


class OProjectile: public FObject {
    glm::vec2 direction;
    float velocity = 1200;
    Sprite* sprite;
    FObject* instigator;

public:
    explicit OProjectile(const glm::vec2 &direction, FObject* instigator)
        : direction(direction), instigator(instigator) {
    }

private:
    void Init() override;
    void Tick(float deltaTime) override;
    void OnCollision(FObject* attachedTo, FObject* colldier, glm::vec2 normal);
    void DeleteSelf() override;
};



#endif //OPROJECTILE_H
