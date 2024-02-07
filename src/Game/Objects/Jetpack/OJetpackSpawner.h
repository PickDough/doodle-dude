//
// Created by Misha Muravynets on 29.01.2024.
//

#ifndef OJETPACKSPAWNER_H
#define OJETPACKSPAWNER_H
#include <list>

#include "OJetpack.h"
#include "../../Common/Random.h"

class OJetpackSpawner: public FObject {
    float targetMovedDistance;
    float targetTotalMovedDistance;
    float distanceBetweenRedraws = 5000;

    unique_ptr<OJetpack> jetpack = {};

    bool isRedrawRequired;
    Random rd;

public:
    void Init() override;

    void SpawnJetpack();

    void Tick(float deltaTime) override;
    void DeleteSelf() override;
};



#endif //OJETPACKSPAWNER_H
