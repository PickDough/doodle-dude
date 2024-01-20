//
// Created by koler on 19.01.2024.
//

#ifndef FOBJECT_H
#define FOBJECT_H
#include <Framework.h>
#include <glm/vec2.hpp>

class FGameState;
class FObject {
public:
    FObject() = default;

    virtual ~FObject() = default;

    Sprite*Image = nullptr;
    glm::vec2 Position = {};

    void virtual Init() = 0;

    void virtual Tick() = 0;

    FGameState* GameState;
};



#endif //FOBJECT_H
