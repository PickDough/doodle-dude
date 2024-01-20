//
// Created by koler on 19.01.2024.
//

#include "OPlatformSpawner.h"

#include <ctime>
#include <iostream>

#include "Framework.h"
#include "../../FGameState/FGameState.h"

void OPlatformSpawner::Init() {
    TileSprite = createSprite("./data/tile.png");

    isRedrawRequired = true;
}

void OPlatformSpawner::Tick() {
    if (isRedrawRequired) {
        DrawTiles();
        isRedrawRequired = false;
    }

    for (auto segment: tileSegments) {
        for (auto tile: segment) {
            drawSprite(TileSprite, tile.x, tile.y);
        }
    }
}

void OPlatformSpawner::DrawTiles() {
    std::cout << "spawning" << std::endl;
    auto cameraPos = GameState->CameraBottomLeft();
    for (int i = -cutoff / 2; i < segments + cutoff / 2; i++) {
        auto segmentLeft = cameraPos - glm::vec2(0, i * heightBetweenSegments);
        vector<glm::vec2> segmentVec;
        segmentVec.clear();

        int totalPlatformsOnSegment =std::max(1, maxPlatformsPerSegment / GameState->DifficultyMultiplier());
        for (int j = 1; j < totalPlatformsOnSegment + 1; j ++ ) {
            float x = Random(0,  width / totalPlatformsOnSegment);
            float y = Random(0, heightBetweenSegments);

            segmentVec.push_back(glm::vec2(j * x, segmentLeft.y + y));
        }


        tileSegments[i + cutoff / 2] = segmentVec;
    }
}

int OPlatformSpawner::Random(int min, int max) //range : [min, max]
{
    static bool first = true;
    if (first)
    {
        std::srand( time(NULL) ); //seeding for the first time only!
        first = false;
    }
    return min + std::rand() % (( max + 1 ) - min);
}


