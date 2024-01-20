//
// Created by koler on 19.01.2024.
//

#include "FCamera.h"

FCamera::FCamera(FCamera *camera, float width, float height): width(width),
                                                              height(height) {
    attcahedTo = camera->attcahedTo;
    offset = camera->offset;
}

FCamera::FCamera(FObject *attcahedTo, glm::vec2 offset): attcahedTo(attcahedTo),
                                                         offset(offset) {
}

bool FCamera::Intersact(FObject *obj) {
    return (topLeft.x < obj->Position.x < topLeft.x + width) &
           (topLeft.y > obj->Position.y > topLeft.y - height);
}

glm::vec2 FCamera::CalculateTopLeft() {
    topLeft = glm::vec2(0, attcahedTo->Position.y) + offset;
    topLeft.x -= width / 2.;
    topLeft.y += height / 2.;

    return topLeft;
}

glm::vec2 FCamera::CalculateBottomLeft() {
    CalculateTopLeft();
    auto bottomLeft = topLeft;
    bottomLeft.y -= height;

    return bottomLeft;
}

glm::vec2 FCamera::Project(FObject *obj) {
    auto bottomLeft = topLeft;
    bottomLeft.y -= height;

    return obj->Position - bottomLeft;
}
