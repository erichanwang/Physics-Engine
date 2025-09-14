#ifndef MATERIAL_H
#define MATERIAL_H

#include "../math/Vector3D.h"

class Material {
public:
    Vector3D color;
    double diffuse;
    double specular;
    double shininess;

    Material(const Vector3D& c = Vector3D(1,1,1), double d = 0.8, double s = 0.2, double sh = 10.0)
        : color(c), diffuse(d), specular(s), shininess(sh) {}
};

#endif // MATERIAL_H
