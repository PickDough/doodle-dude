//
// Created by Misha Muravynets on 24.01.2024.
//

#include "FObject.h"
#include "../Scene/FScene.h"

glm::vec2 FObject::Center() const {
    return position + size / 2.0f;
}

void FObject::MarkSelfForDeletion() {
    scene->MarkForDeletion(this);
    isMarkedForDeletion = true;
}