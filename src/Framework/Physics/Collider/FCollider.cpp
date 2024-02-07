//
// Created by Misha Muravynets on 22.01.2024.
//

#include "FCollider.h"

void FCollider::TriggerCollision(FObject* collider, const glm::vec2 normal) const {
    for (const auto& callback: onCollisionCallbacks) {
        callback(attachedTo, collider, normal);
    }
}

void FCollider::RegisterOnCollision(
    const std::function<void(FObject* attachedTo, FObject* colldier, glm::vec2 normal)> &func) {
    onCollisionCallbacks.push_back(func);
}
