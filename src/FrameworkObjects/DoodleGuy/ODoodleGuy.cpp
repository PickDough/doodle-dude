//
// Created by koler on 19.01.2024.
//

#include "ODoodleGuy.h"

#include <iostream>

#include <filesystem>
namespace fs = std::filesystem;

void ODoodleGuy::Init() {
    Image = createSprite("./data/bunny-left.png");
}

void ODoodleGuy::Tick() {
    Position.y -= FlightSpeed;
}
