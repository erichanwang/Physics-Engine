#ifndef PLAYER_H
#define PLAYER_H

#include "../math/Vector3D.h"
#include <cmath>

class Player {
public:
    Vector3D position;
    Vector3D velocity;
    bool onGround;
    float mass;
    float jumpSpeed;
    float moveSpeed;

    Player() : position(0, 1.8, 0), velocity(0, 0, 0), onGround(false), mass(1.0f), jumpSpeed(5.0f), moveSpeed(5.0f) {}

    void update(float dt, float gravity = -9.81f) {
        velocity.y += gravity * dt;
        position += velocity * dt;
        if (position.y <= 0) {
            position.y = 0;
            velocity.y = 0;
            onGround = true;
        } else {
            onGround = false;
        }
    }

    void jump() {
        if (onGround) {
            velocity.y = jumpSpeed;
            onGround = false;
        }
    }

    void move(const Vector3D& direction, float dt) {
        Vector3D dir = direction;
        dir.y = 0;
        if (dir.length() > 0) dir = dir.normalize();
        position += dir * moveSpeed * dt;
    }
};

#endif // PLAYER_H
