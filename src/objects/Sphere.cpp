#include "Sphere.h"
#include <cmath>

Sphere::Sphere(const Vector3D& pos, double r, const Material& m)
    : Object(m), position(pos), radius(r) {}

bool Sphere::intersect(const Ray& ray, double tMin, double tMax, HitRecord& rec) const {
    Vector3D oc = ray.origin - position;
    double a = ray.direction.dot(ray.direction);
    double b = 2.0 * oc.dot(ray.direction);
    double c = oc.dot(oc) - radius * radius;
    double discriminant = b * b - 4 * a * c;
    if (discriminant < 0) return false;
    double sqrtD = std::sqrt(discriminant);
    double root = (-b - sqrtD) / (2 * a);
    if (root < tMin || root > tMax) {
        root = (-b + sqrtD) / (2 * a);
        if (root < tMin || root > tMax) return false;
    }
    rec.t = root;
    rec.point = ray.at(rec.t);
    rec.normal = getNormal(rec.point);
    rec.material = material;
    rec.object = (Object*)this;
    return true;
}

Vector3D Sphere::getNormal(const Vector3D& point) const {
    return (point - position).normalize();
}
