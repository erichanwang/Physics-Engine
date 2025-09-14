#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "../math/Vector3D.h"

class RigidBody {
public:
    Vector3D position;
    Vector3D velocity;
    Vector3D acceleration;
    double mass; // kg
    double dragCoefficient;
    bool isStatic;

    RigidBody() : position(), velocity(), acceleration(), mass(1.0), dragCoefficient(0.0), isStatic(false) {}
    RigidBody(const Vector3D& pos, double m = 1.0) : position(pos), velocity(), acceleration(), mass(m), dragCoefficient(0.0), isStatic(false) {}
    RigidBody(const Vector3D& pos, double m, double drag) : position(pos), velocity(), acceleration(), mass(m), dragCoefficient(drag), isStatic(false) {}

    void applyForce(const Vector3D& force) {
        if (!isStatic) {
            acceleration = acceleration + force * (1.0 / mass);
        }
    }

    void update(double dt) {
        if (!isStatic) {
            velocity = velocity + acceleration * dt;
            position = position + velocity * dt;
            acceleration = Vector3D(0, 0, 0); // Reset acceleration
            // Apply drag
            if (dragCoefficient > 0) {
                velocity = velocity * (1 - dragCoefficient * dt);
            }
        }
    }
};

#endif // RIGIDBODY_H
