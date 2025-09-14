#ifndef RAY_H
#define RAY_H

#include "Vector3D.h"

class Ray {
public:
    Vector3D origin;
    Vector3D direction;

    Ray() : origin(), direction() {}
    Ray(const Vector3D& origin, const Vector3D& direction) : origin(origin), direction(direction.normalize()) {}

    Vector3D at(double t) const {
        return origin + direction * t;
    }
};

#endif // RAY_H
