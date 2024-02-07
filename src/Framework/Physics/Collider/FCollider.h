//
// Created by Misha Muravynets on 22.01.2024.
//

#ifndef FCOLLIDER_H
#define FCOLLIDER_H
#include <functional>
#include <glm/vec2.hpp>

class FObject;
using namespace std;
class FCollider {
    friend class FPhysicsScene;

    int w;
    int h;
    FObject* attachedTo;

    std::vector<const std::function<void (FObject* attachedTo, FObject* colldier,
                                          glm::vec2 normal)>> onCollisionCallbacks{};
    bool seeking;

    void TriggerCollision(FObject* collider, glm::vec2 normal) const;

public:
    glm::vec2 position;
    bool isEnabled = true;

    [[nodiscard]] bool IsSeeking() const {
        return seeking;
    }

    explicit FCollider(int w, int h, FObject* attached_to, const bool seeking = false)
        : w(w),
          h(h),
          attachedTo(attached_to), seeking(seeking) {
    }

    void RegisterOnCollision(
        const std::function<void (FObject* attachedTo, FObject* colldier, glm::vec2 normal)> &
        func);
};


#endif //FCOLLIDER_H
