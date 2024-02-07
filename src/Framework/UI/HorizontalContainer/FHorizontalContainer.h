//
// Created by Misha Muravynets on 22.01.2024.
//

#ifndef FUISPRITE_H
#define FUISPRITE_H
#include <deque>
#include <glm/vec2.hpp>

#include "../../Object/FObject.h"


class Sprite;

class FHorizontalContainer: public FObject {
    std::deque<Sprite*> sprites = {};
public:
    void Init() override;
    void Tick(float deltaTime) override;

    void PushBackSprite(Sprite* sprite);
    void PushFrontSprite(Sprite* sprite);
    void Clear();
};



#endif //FUISPRITE_H
