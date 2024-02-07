//
// Created by Misha Muravynets on 24.01.2024.
//

#ifndef NUMBERSPRITES_H
#define NUMBERSPRITES_H
#include <map>
#include "Framework.h"

using namespace std;
class NumberSprites {
public:
    void ReleaseSprites() const {
        for (auto pair: digits) {
            destroySprite(pair.second);
        }
    }

    NumberSprites() {
        digits.insert({0, createSprite("./0.png")});
        digits.insert({1, createSprite("./1.png")});
        digits.insert({2, createSprite("./2.png")});
        digits.insert({3, createSprite("./3.png")});
        digits.insert({4, createSprite("./4.png")});
        digits.insert({5, createSprite("./5.png")});
        digits.insert({6, createSprite("./6.png")});
        digits.insert({7, createSprite("./7.png")});
        digits.insert({8, createSprite("./8.png")});
        digits.insert({9, createSprite("./9.png")});
    }

    map<int, Sprite*> digits = {};
};



#endif //NUMBERSPRITES_H
