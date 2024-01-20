//
// Created by koler on 19.01.2024.
//

#ifndef FCAMERA_H
#define FCAMERA_H
#include "../FrameworkObjects/FObject.h"


class FCamera {
    float width;
    float height;
    glm::vec2 topLeft;

public:
    FObject *attcahedTo;
    glm::vec2 offset;

    FCamera(FCamera *camera, float width, float height);

    FCamera(FObject *attcahedTo, glm::vec2 offset);

    bool Intersact(FObject *obj);

    glm::vec2 CalculateTopLeft();
    glm::vec2 FCamera::CalculateBottomLeft();

    glm::vec2 Project(FObject *obj);
};


#endif //FCAMERA_H
