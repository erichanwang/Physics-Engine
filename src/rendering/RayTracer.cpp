#include "RayTracer.h"
#include "../math/Ray.h"
#include <algorithm>

void RayTracer::render(int w, int h, std::vector<Vector3D>& image) {
    width = w;
    height = h;
    image.resize(width * height);
    for (int j = height - 1; j >= 0; --j) {
        for (int i = 0; i < width; ++i) {
            double u = double(i) / double(width);
            double v = double(j) / double(height);
            Ray ray = camera.getRay(u, v);
            Vector3D color = traceRay(ray);
            image[(height - 1 - j) * width + i] = color;
        }
    }
}

Vector3D RayTracer::traceRay(const Ray& ray, int depth) {
    // Simple ray tracing: find closest intersection
    HitRecord rec;
    double closestSoFar = 1e9;
    bool hitAnything = false;
    for (const auto& obj : scene.objects) {
        if (obj->intersect(ray, 0.001, closestSoFar, rec)) {
            hitAnything = true;
            closestSoFar = rec.t;
        }
    }
    if (!hitAnything) return Vector3D(0.2, 0.2, 0.2); // background

    Vector3D hitPoint = rec.point;
    Vector3D normal = rec.normal;
    Vector3D lightDir = (scene.lightPosition - hitPoint).normalize();
    double diffuse = std::max(0.0, normal.dot(lightDir));
    Vector3D color = rec.material.color * diffuse;
    return color;
}
