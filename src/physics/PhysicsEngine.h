#ifndef PHYSICSENGINE_H
#define PHYSICSENGINE_H

#include <vector>
#include "RigidBody.h"

class PhysicsEngine {
public:
    std::vector<RigidBody*> bodies;
    Vector3D gravity;

    PhysicsEngine() : gravity(0, -9.81, 0) {}

    void addBody(RigidBody* body) {
        bodies.push_back(body);
    }

    void simulate(double dt) {
        for (auto body : bodies) {
            if (!body->isStatic) {
                body->applyForce(gravity * body->mass);
                body->update(dt);
            }
        }
    }

    void update(double dt) {
        simulate(dt);
    }
};

#endif // PHYSICSENGINE_H
