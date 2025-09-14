#ifndef SPHERE_H
#define SPHERE_H

#include "Object.h"
#include "../rendering/Material.h"

class Sphere : public Object {
public:
    Vector3D position;
    double radius;

    Sphere(const Vector3D& pos = Vector3D(), double r = 1.0, const Material& m = Material());

    bool intersect(const Ray& ray, double tMin, double tMax, HitRecord& rec) const override;
    Vector3D getNormal(const Vector3D& point) const override;
};

#endif // SPHERE_H
