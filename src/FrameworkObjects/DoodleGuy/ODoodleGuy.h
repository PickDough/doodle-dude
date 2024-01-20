//
// Created by koler on 19.01.2024.
//

#ifndef ODOODLEGUY_H
#define ODOODLEGUY_H
#include "../FObject.h"


class ODoodleGuy: public FObject {
    void Init() override;

    void Tick() override;
public:
    float FlightSpeed = 0.2;
};



#endif //ODOODLEGUY_H
