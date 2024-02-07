//
// Created by Misha Muravynets on 23.01.2024.
//

#ifndef OSCORE_H
#define OSCORE_H
#include <map>

#include "../../../../Framework/UI/HorizontalContainer/FHorizontalContainer.h"
#include "../../../Common/NumberSprites/NumberSprites.h"
constexpr float DIST_TO_SCORE = 1.0 / 100.0;
using namespace std;
class OScore: public FObject {
private:
    unique_ptr<FHorizontalContainer> container;
    int score = 0;
    unique_ptr<NumberSprites> sprites;
public:
    void Init() override;
    void Tick(float deltaTime) override;
    void DeleteSelf() override;
};


#endif //OSCORE_H
