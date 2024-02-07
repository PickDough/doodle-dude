//
// Created by Misha Muravynets on 27.01.2024.
//

#ifndef OMONSTERSPAWNER_H
#define OMONSTERSPAWNER_H
#include <deque>
#include <list>

#include "../../../Framework/Object/FObject.h"
#include "../../Common/Random.h"
#include "../../Common/SpawnerStruct/SegmentSpawningConfiguration.h"
#include "../Monsters/OMonster.h"


class OMonsterSpawner: public FObject {
    float targetMovedDistance;
    float targetTotalMovedDistance;
    float distanceBetweenRedraws;

    list<unique_ptr<OMonster>> monsterSegments = {};
    vector<Sprite*> monsterSprites = {};

    bool isRedrawRequired;
    Random rd;

public:
    OMonsterSpawner(float distanceBetweenRedraws=1800): distanceBetweenRedraws(distanceBetweenRedraws) {

    }

    void Init() override;

    void SpawnMonsters();

    void Tick(float deltaTime) override;
    void DeleteSelf() override;
};



#endif //OMONSTERSPAWNER_H
