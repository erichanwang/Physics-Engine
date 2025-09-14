#ifndef OBJECT_H
#define OBJECT_H

#include "../math/Ray.h"
#include "../math/Vector3D.h"
#include "../rendering/Material.h"
#include "../rendering/HitRecord.h"

class Object {
public:
    Material material;

    Object(const Material& mat = Material()) : material(mat) {}
    virtual ~Object() = default;

    // Virtual function to check intersection with a ray
    // Returns true if intersects, fills HitRecord
    virtual bool intersect(const Ray& ray, double tMin, double tMax, HitRecord& rec) const = 0;

    // Virtual function to get the normal at a point on the object
    virtual Vector3D getNormal(const Vector3D& point) const = 0;
};

#endif // OBJECT_H
