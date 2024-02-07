//
// Created by Misha Muravynets on 29.01.2024.
//

#pragma once
#ifndef OTILE_H
#define OTILE_H
#include "../../../Framework/Object/FObject.h"

#endif //OTILE_H
class OTile: public FObject {
    void Init() override = 0;
    void Tick(float deltaTime) override = 0;
};