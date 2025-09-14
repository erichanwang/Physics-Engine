#ifndef BLOCK_H
#define BLOCK_H

#include "../math/Vector3D.h"
#include "../math/Ray.h"
#include "../rendering/Material.h"
#include "../rendering/HitRecord.h"
#include "Object.h"

class Block : public Object {
public:
    Vector3D position;
    Vector3D size; // width, height, depth

    Block(const Vector3D& pos, const Vector3D& sz, const Material& mat) : Object(mat), position(pos), size(sz) {}

    // Ray intersection with block (axis-aligned bounding box)
    bool intersect(const Ray& ray, double tMin, double tMax, HitRecord& rec) const override {
        Vector3D min = position - size * 0.5;
        Vector3D max = position + size * 0.5;

        double tmin = (min.x - ray.origin.x) / ray.direction.x;
        double tmax = (max.x - ray.origin.x) / ray.direction.x;

        if (tmin > tmax) std::swap(tmin, tmax);

        double tymin = (min.y - ray.origin.y) / ray.direction.y;
        double tymax = (max.y - ray.origin.y) / ray.direction.y;

        if (tymin > tymax) std::swap(tymin, tymax);

        if ((tmin > tymax) || (tymin > tmax))
            return false;

        if (tymin > tmin)
            tmin = tymin;

        if (tymax < tmax)
            tmax = tymax;

        double tzmin = (min.z - ray.origin.z) / ray.direction.z;
        double tzmax = (max.z - ray.origin.z) / ray.direction.z;

        if (tzmin > tzmax) std::swap(tzmin, tzmax);

        if ((tmin > tzmax) || (tzmin > tmax))
            return false;

        if (tzmin > tmin)
            tmin = tzmin;

        if (tzmax < tmax)
            tmax = tzmax;

        double t = tmin;
        if (t < tMin || t > tMax) return false;

        rec.t = t;
        rec.point = ray.at(t);
        rec.normal = getNormal(rec.point);
        rec.material = material;
        return true;
    }

    Vector3D getNormal(const Vector3D& point) const override {
        Vector3D min = position - size * 0.5;
        Vector3D max = position + size * 0.5;
        double epsilon = 1e-6;
        if (std::abs(point.x - min.x) < epsilon) return Vector3D(-1, 0, 0);
        if (std::abs(point.x - max.x) < epsilon) return Vector3D(1, 0, 0);
        if (std::abs(point.y - min.y) < epsilon) return Vector3D(0, -1, 0);
        if (std::abs(point.y - max.y) < epsilon) return Vector3D(0, 1, 0);
        if (std::abs(point.z - min.z) < epsilon) return Vector3D(0, 0, -1);
        if (std::abs(point.z - max.z) < epsilon) return Vector3D(0, 0, 1);
        return Vector3D(0, 1, 0); // default
    }
};

#endif // BLOCK_H
