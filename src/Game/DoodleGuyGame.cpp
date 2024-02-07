//
// Created by Misha Muravynets on 24.01.2024.
//

#include "DoodleGuyGame.h"

#include <iostream>


using namespace std;

void DoodleGuyGame::SetUp() {
    guy = make_unique<ODoodleGuy>();
    guy->position = glm::vec2(300, 0);
    guy->RegisterOnDeath([this]() { Restart(); });

    tileSpawner = make_unique<OPlatformSpawner>();
    monsterSpawner = make_unique<OMonsterSpawner>();
    jetpackSpawner = make_unique<OJetpackSpawner>();

    score = make_unique<OScore>();
    score->position = {25, 25};

    speedBoost = make_unique<OSpeedBoost>();
    speedBoost->position = {25, 75};

    camera = make_unique<FCamera>(guy.get(), glm::vec2(0, 100));
    state = make_unique<FGameState>(guy.get());
}

void DoodleGuyGame::Start() {
    scene = new FScene();
    scene->viewportHeight = heigth;
    scene->viewportWidth = width;

    SetUp();

    scene->RegisterChild(tileSpawner.get());
    scene->RegisterChild(monsterSpawner.get());
    scene->RegisterChild(jetpackSpawner.get());
    scene->RegisterChild(score.get());
    scene->RegisterChild(speedBoost.get());
    scene->RegisterChild(guy.get());

    scene->SetCamera(camera.get());
    scene->SetGameState(state.get());

    run(scene);
}

void DoodleGuyGame::Restart() {
    if (!scene)
        return;
    guy.release()->MarkSelfForDeletion();
    tileSpawner.release()->MarkSelfForDeletion();
    monsterSpawner.release()->MarkSelfForDeletion();
    jetpackSpawner.release()->MarkSelfForDeletion();
    score.release()->MarkSelfForDeletion();
    speedBoost.release()->MarkSelfForDeletion();

    gameOver = make_unique<OGameOver>();
    gameOver->position = glm::vec2(scene->viewportWidth / 2, scene->viewportHeight / 2);
    scene->RegisterChild(gameOver.get());

    scene->CreateTimer(chrono::seconds(3), [this]() {
        scene->MarkForDeletion(gameOver.release());
        scene->MarkForDeletion(camera.release());
        SetUp();

        scene->RegisterChild(tileSpawner.get());
        scene->RegisterChild(monsterSpawner.get());
        scene->RegisterChild(jetpackSpawner.get());
        scene->RegisterChild(score.get());
        scene->RegisterChild(speedBoost.get());
        scene->RegisterChild(guy.get());

        scene->SetCamera(camera.get());
        scene->SetGameState(state.get());

        scene->gameSpeed = 0.5f;
    });
}
