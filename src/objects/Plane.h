#ifndef PLANE_H
#define PLANE_H

#include "../math/Vector3D.h"
#include "../math/Ray.h"
#include "../rendering/Material.h"
#include "../rendering/HitRecord.h"
#include "Object.h"

class Plane : public Object {
public:
    Vector3D point;
    Vector3D normal;
    Material material;

    Plane(const Vector3D& p, const Vector3D& n, const Material& m) : point(p), normal(n), material(m) {}

    bool intersect(const Ray& ray, double tMin, double tMax, HitRecord& record) const override {
        double denom = normal.dot(ray.direction);
        if (fabs(denom) > 1e-6) {
            Vector3D p0l0 = point - ray.origin;
            double t = p0l0.dot(normal) / denom;
            if (t > tMin && t < tMax) {
                record.t = t;
                record.point = ray.at(t);
                record.normal = normal;
                record.material = material;
                return true;
            }
        }
        return false;
    }
};

#endif // PLANE_H
