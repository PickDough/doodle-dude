//
// Created by koler on 19.01.2024.
//

#ifndef UPLATFORMSPAWNER_H
#define UPLATFORMSPAWNER_H

#include "../FObject.h"
#include <Framework.h>
#include <vector>

using namespace std;

class OPlatformSpawner : public FObject {
    float heightBetweenSegments;
    float height;
    float width;

    bool isRedrawRequired;
    vector<vector<glm::vec2>> tileSegments;
    int cutoff = 2;
    int segments;
    int maxPlatformsPerSegment;
    Sprite* TileSprite;

    int Random(int min, int max);
    void DrawTiles();
public:
    OPlatformSpawner(float height, float width, int segments = 4, int maxPlatforms = 32)
        : height(height),
          width(width),
          segments(segments + cutoff) {
        maxPlatformsPerSegment = maxPlatforms / segments;
        tileSegments = vector<vector<glm::vec2>>(segments + cutoff);
        heightBetweenSegments = height / segments;
    }

    void Init() override;

    void Tick() override;
};


#endif //UPLATFORMSPAWNER_H
