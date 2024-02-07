//
// Created by Misha Muravynets on 22.01.2024.
//

#ifndef FPHYSICSSCENE_H
#define FPHYSICSSCENE_H
#include <list>
#include <vector>

#include "../Collider/FCollider.h"

class FPhysicsScene {
    list<FCollider*> staticObjects = {};
    list<FCollider*> seekingObjects = {};
public:
    void PhysicsTick();

    void RegisterCollider(FCollider* collider);
    void UnregisterCollider(FCollider* collider);

    static bool CheckCollision(FCollider* one, FCollider* two);
};



#endif //FPHYSICSSCENE_H
