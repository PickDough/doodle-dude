//
// Created by Misha Muravynets on 22.01.2024.
//

#include "FHorizontalContainer.h"

#include "../../Scene/FScene.h"

void FHorizontalContainer::Init() {
}

void FHorizontalContainer::Tick(float deltaTime) {
    auto pos = position;
    int w,h;
    for (auto sprite: sprites) {
        scene->GetViewport().DrawOverViewport(sprite, pos);
        getSpriteSize(sprite, w, h);
        pos.x += w;
    }
}

void FHorizontalContainer::PushBackSprite(Sprite *sprite) {
    sprites.push_back(sprite);
}

void FHorizontalContainer::PushFrontSprite(Sprite *sprite) {
    sprites.push_front(sprite);
}

void FHorizontalContainer::Clear() {
    sprites.clear();
}
