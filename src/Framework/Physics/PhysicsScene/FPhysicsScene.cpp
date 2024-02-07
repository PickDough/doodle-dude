//
// Created by Misha Muravynets on 22.01.2024.
//

#include "FPhysicsScene.h"

#include "../../Object/FObject.h"
#include <complex>

void FPhysicsScene::PhysicsTick() {
    for (auto obj: seekingObjects) {
        if (!obj->isEnabled)
            continue;
        for (auto staticObj: staticObjects) {
            if (!staticObj->isEnabled || obj == staticObj)
                continue;
            if (CheckCollision(obj, staticObj)) {
                auto normal = obj->attachedTo->Center() - staticObj->attachedTo->Center();
                if (normal.x > normal.y)
                    normal.y = 0;
                else
                    normal.x = 0;
                obj->TriggerCollision(staticObj->attachedTo, normal);
                staticObj->TriggerCollision(obj->attachedTo, normal);
            }
        }
    }
}

void FPhysicsScene::RegisterCollider(FCollider* collider) {
    if (collider->IsSeeking()) {
        seekingObjects.push_back(collider);
    }

    staticObjects.push_back(collider);
}

void FPhysicsScene::UnregisterCollider(FCollider *collider) {
    staticObjects.remove(collider);
    seekingObjects.remove(collider);
}

auto FPhysicsScene::CheckCollision(FCollider* one, FCollider* two) -> bool {
    auto obj1 = one->attachedTo;
    auto obj2 = two->attachedTo;

    bool collisionX = one->position.x + obj1->size.x >= two->position.x &&
        two->position.x + obj2->size.x >= one->position.x;

    bool collisionY = one->position.y + obj1->size.y >= two->position.y &&
        two->position.y + obj2->size.y >= one->position.y;

    return collisionX && collisionY;
}
