#ifndef HITRECORD_H
#define HITRECORD_H

#include "../math/Vector3D.h"
#include "Material.h"

class Object;

struct HitRecord {
    double t;
    Vector3D point;
    Vector3D normal;
    Material material;
    Object* object = nullptr;
};

#endif // HITRECORD_H
