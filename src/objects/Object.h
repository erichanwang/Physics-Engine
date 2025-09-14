#ifndef OBJECT_H
#define OBJECT_H

#include "../math/Ray.h"
#include "../rendering/HitRecord.h"

class Object {
public:
    virtual ~Object() {}
    virtual bool intersect(const Ray& ray, double tMin, double tMax, HitRecord& rec) const = 0;
};

#endif // OBJECT_H
