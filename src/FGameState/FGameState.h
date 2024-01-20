//
// Created by koler on 19.01.2024.
//

#ifndef FGAMESTATE_H
#define FGAMESTATE_H
#include <glm/vec2.hpp>

class FCamera;
class FGameState {
private:
    int Score = 0;
    FCamera* Camera = nullptr;

public:
    explicit FGameState(FCamera* camera);

    [[nodiscard]] int GetScore() const;

    [[nodiscard]] int DifficultyMultiplier() const;

    [[nodiscard]] glm::vec2 CameraBottomLeft() const;
};


#endif //FGAMESTATE_H
