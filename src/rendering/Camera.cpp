#include "Camera.h"
#include <cmath>

Ray Camera::getRay(double u, double v) const {
    // Calculate camera basis vectors
    Vector3D forward = (lookAt - position).normalize();
    Vector3D right = forward.cross(Vector3D(0, 1, 0)).normalize();
    Vector3D up = right.cross(forward);

    const double PI = acos(-1.0);
    double tanFov = tan((fov * PI / 180.0) / 2.0);
    double aspectRatioInv = 1.0 / aspectRatio;

    Vector3D rayDir = forward + right * ((2 * u - 1) * tanFov) + up * ((2 * v - 1) * tanFov * aspectRatioInv);
    rayDir = rayDir.normalize();

    return Ray(position, rayDir);
}
