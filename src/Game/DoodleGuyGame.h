//
// Created by Misha Muravynets on 24.01.2024.
//

#ifndef DOODLEGUYGAME_H
#define DOODLEGUYGAME_H
#include "../Framework/Scene/FScene.h"
#include "Common/GameState/FGameState.h"
#include "Objects/DoodleGuy/ODoodleGuy.h"
#include "Objects/Jetpack/OJetpackSpawner.h"
#include "Objects/MonsterSpawner/OMonsterSpawner.h"
#include "Objects/UI/GameOver/OGameOver.h"
#include "Objects/PlatformSpawner/OPlatformSpawner.h"
#include "Objects/UI/Score/OScore.h"
#include "Objects/UI/SpeedBoost/OSpeedBoost.h"

class DoodleGuyGame {
    FScene* scene;
    unique_ptr<FCamera> camera;
    unique_ptr<FGameState> state;

    unique_ptr<ODoodleGuy> guy;
    unique_ptr<OPlatformSpawner> tileSpawner;
    unique_ptr<OMonsterSpawner> monsterSpawner;
    unique_ptr<OJetpackSpawner> jetpackSpawner;

    unique_ptr<OScore> score;
    unique_ptr<OSpeedBoost> speedBoost;
    unique_ptr<OGameOver> gameOver;

    void SetUp();
public:
    int width;
    int heigth;
    void Start();

    void Restart();

    void Exit();
};



#endif //DOODLEGUYGAME_H
