//
// Created by Misha Muravynets on 29.01.2024.
//

#include "OJetpack.h"

#include <iostream>

#include "../../../Framework/Scene/FScene.h"
#include "../DoodleGuy/ODoodleGuy.h"

void OJetpack::Init() {
    idleSprite = createSprite("./tile009.png");
    animation.push_back(new Frame{createSprite("./tile000.png"), 1});
    animation.push_back(new Frame{createSprite("./tile001.png"), 2});
    animation.push_back(new Frame{createSprite("./tile002.png"), 3});

    animation.push_back(new Frame{createSprite("./tile003.png"), 4});
    animation.push_back(new Frame{createSprite("./tile004.png"), 5});
    animation.push_back(new Frame{createSprite("./tile005.png"), 3});

    int w, h;
    getSpriteSize(idleSprite, w, h);
    size = {w, h};
    collider = make_unique<FCollider>(w, h, this, true);
    collider->RegisterOnCollision([this](FObject *attachedTo, FObject *other, glm::vec2 normal) {
            OnCollision(attachedTo, other, normal);
        }
    );
}

void OJetpack::Tick(float deltaTime) {
    collider->position = position;
    if (isActive) {
        doodleGuy->velocity.y = 900.0f;
        doodleGuy->speedBoost = 1.0f;
        position = doodleGuy->position + glm::vec2(0, doodleGuy->size.y / 3);
        if (doodleGuy->IsLeft()) {
            position.x += doodleGuy->size.x;
        } else {
            position.x -= doodleGuy->size.x / 2;
        }

        if (!currFrame)
            currFrame = animation[0];
        if (passedTime > frameTime) {
            currFrame = animation[currFrame->goTo];
            passedTime = 0.0;
        }
        scene->GetViewport().Draw(currFrame->sprite, position);
        passedTime += deltaTime;
    } else {
        scene->GetViewport().Draw(idleSprite, position);
    }
}

void OJetpack::OnCollision(FObject *attachedTo, FObject *other, glm::vec2 normal) {
    if (isActive)
        return;

    if (auto guy = dynamic_cast<ODoodleGuy *>(other)) {
        doodleGuy = guy;
        doodleGuy->collider->isEnabled = false;
        isActive = true;
        scene->CreateTimer(chrono::seconds(8), [this]() {
            isActive = false;
            collider->isEnabled = false;
            scene->CreateTimer(chrono::seconds(2), [this] {
                doodleGuy->collider->isEnabled = true;
            });
        });
    }
}


void OJetpack::DeleteSelf() {
    FObject::DeleteSelf();

    destroySprite(idleSprite);
    for (auto anim: animation) {
        destroySprite(anim->sprite);
        delete anim;
    }
}
