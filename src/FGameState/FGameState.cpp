//
// Created by koler on 19.01.2024.
//

#include "FGameState.h"
#include "../FrameworkCamera/FCamera.h"

FGameState::FGameState(FCamera *camera): Camera(camera) {
}

int FGameState::GetScore() const {
    return Score;
}

int FGameState::DifficultyMultiplier() const {
    return 1 + Score / 1000;
}

glm::vec2 FGameState::CameraBottomLeft() const {
    return Camera->CalculateBottomLeft();
}
