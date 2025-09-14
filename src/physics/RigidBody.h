#ifndef RIGIDBODY_H
#define RIGIDBODY_H

#include "../math/Vector3D.h"

class RigidBody {
public:
    Vector3D position;
    Vector3D velocity;
    Vector3D acceleration;
    double mass;
    double dragCoeff; // Drag coefficient for air resistance

    RigidBody(const Vector3D& pos, double m, double drag = 0.0) : position(pos), velocity(0,0,0), acceleration(0,0,0), mass(m), dragCoeff(drag) {}

    void applyForce(const Vector3D& force) {
        acceleration = acceleration + force / mass;
    }

    void update(double dt) {
        // Apply drag force: F_drag = -dragCoeff * velocity
        Vector3D dragForce = velocity * (-dragCoeff);
        applyForce(dragForce);

        velocity = velocity + acceleration * dt;
        position = position + velocity * dt;
        acceleration = Vector3D(0,0,0); // Reset acceleration
    }
};

#endif // RIGIDBODY_H
