//
// Created by Misha Muravynets on 27.01.2024.
//
#pragma once
#ifndef RANDOM_H
#define RANDOM_H

#endif //RANDOM_H
#include <random>
class Random {
public:
    Random() {
        std::random_device rd;
        mt = std::mt19937(rd());
    }

    float FRange(const float min, const float max) {
        std::uniform_real_distribution dist(min, max);

        return dist(mt);
    }

private:
    std::mt19937 mt;
};