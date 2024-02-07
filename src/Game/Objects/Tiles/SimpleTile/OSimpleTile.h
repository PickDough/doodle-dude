//
// Created by Misha Muravynets on 25.01.2024.
//

#ifndef SIMPLETILE_H
#define SIMPLETILE_H
#include "../OTile.h"
#include "../../../../Framework/Object/FObject.h"


class OSimpleTile : public OTile {
    int w, h;
    Sprite *sprite;

public:
    OSimpleTile(int w, int h, Sprite *sprite)
        : w(w),
          h(h),
          sprite(sprite) {
    }

private:
    void Init() override;

    void Tick(float deltaTime) override;
};


#endif //SIMPLETILE_H
