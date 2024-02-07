//
// Created by Misha Muravynets on 29.01.2024.
//

#include "OBrokenTile.h"
#include "../../DoodleGuy/ODoodleGuy.h"
#include "../../../../Framework/Scene/FScene.h"

void OBrokenTile::Init() {
    idleSprite = createSprite("./broken-tile-1.png");
    animation.push_back(createSprite("./broken-tile-2.png"));
    animation.push_back(createSprite("./broken-tile-3.png"));
    animation.push_back(createSprite("./broken-tile-4.png"));

    int w, h;
    getSpriteSize(idleSprite, w, h);
    size = {w, h};
    collider = make_unique<FCollider>(w, h, this, true);
    collider->RegisterOnCollision([this](FObject *attachedTo, FObject *other, glm::vec2 normal) {
            OnCollision(attachedTo, other, normal);
        }
    );
    collider->position = position + glm::vec2(0, 40);;
}

void OBrokenTile::Tick(float deltaTime) {
    if (isBroken) {
        if (currFrame >= animation.size())
            return;
        position.y -= 300 * deltaTime;
        scene->GetViewport().Draw(animation[currFrame], position);
        passedTime += deltaTime;

        if (passedTime > frameTime) {
            currFrame++;
            passedTime = 0.0;
        }
    } else {
        scene->GetViewport().Draw(idleSprite, position);
    }
}

void OBrokenTile::OnCollision(FObject *attachedTo, FObject *other, glm::vec2 normal) {
    if (isBroken)
        return;

    if (auto guy = dynamic_cast<ODoodleGuy *>(other)) {
        if (guy->velocity.y < 0) {
            isBroken = true;
        }
    }
}
