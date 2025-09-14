#ifndef CAMERA_H
#define CAMERA_H

#define _USE_MATH_DEFINES
#include <cmath>

#include "../math/Vector3D.h"
#include "../math/Ray.h"

class Camera {
public:
    Vector3D position;
    Vector3D lookAt;
    double fov; // field of view in degrees
    double aspectRatio;

    Camera(const Vector3D& pos, double yaw, double pitch, double fov, double aspect)
        : position(pos), fov(fov), aspectRatio(aspect) {
        // Compute lookAt from yaw and pitch
        const double PI = acos(-1.0);
        double radYaw = yaw * PI / 180.0;
        double radPitch = pitch * PI / 180.0;
        lookAt = Vector3D(sin(radYaw) * cos(radPitch), sin(radPitch), cos(radYaw) * cos(radPitch)) + position;
    }

    Ray getRay(double u, double v) const;
};

#endif // CAMERA_H
