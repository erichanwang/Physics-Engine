#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>
#include "RigidBody.h"
#include "../math/Vector3D.h"

class PhysicsEngine {
public:
    std::vector<RigidBody*> bodies;
    const double gravity = 9.81; // m/s^2

    void addBody(RigidBody* body) {
        bodies.push_back(body);
    }

    void update(double dt) {
        for (auto body : bodies) {
            // Apply gravity
            body->applyForce(Vector3D(0, -body->mass * gravity, 0));
            body->update(dt);
        }
    }
};

#endif // PHYSICSENGINE_H
