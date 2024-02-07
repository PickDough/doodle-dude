//
// Created by Misha Muravynets on 29.01.2024.
//

#include "OProjectile.h"

#include <iostream>

#include "../../../Framework/Scene/FScene.h"
#include "../Monsters/OMonster.h"

void OProjectile::Init() {
    sprite = createSprite("./egg-projectile.png");
    int w, h;
    getSpriteSize(sprite, w, h);
    size = {w, h};
    collider = make_unique<FCollider>(w, h, this, true);
    collider->RegisterOnCollision([this](FObject *attachedTo, FObject *other, glm::vec2 normal) {
            OnCollision(attachedTo, other, normal);
        }
    );

    scene->CreateTimer(chrono::seconds(3), [this] {
        if (!isMarkedForDeletion)
            MarkSelfForDeletion();
    });
}

void OProjectile::Tick(float deltaTime) {
    position += direction * velocity * deltaTime;
    collider->position = position;
    if (collider->isEnabled && instigator && !instigator->isMarkedForDeletion)
        scene->GetViewport().Draw(sprite, position);
}

void OProjectile::OnCollision(FObject *attachedTo, FObject *other, glm::vec2 normal) {
    if (auto monster = dynamic_cast<OMonster *>(other)) {
        monster->isAggressive = false;
        collider->isEnabled = false;
    }
}

void OProjectile::DeleteSelf() {
    destroySprite(sprite);
}
