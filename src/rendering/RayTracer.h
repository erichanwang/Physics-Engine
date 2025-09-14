#ifndef RAYTRACER_H
#define RAYTRACER_H

#include "Scene.h"
#include "Camera.h"
#include "../math/Vector3D.h"

class RayTracer {
public:
    const Scene* scene;
    const Camera* camera;

    RayTracer() : scene(nullptr), camera(nullptr) {}
    RayTracer(const Scene* s, const Camera* c) : scene(s), camera(c) {}

    Vector3D trace(const Ray& ray, int depth) const {
        (void)depth; // Suppress unused parameter warning
        HitRecord rec;
        if (scene->intersect(ray, 0.001, 1e9, rec)) {
            if (rec.material.isGrid) {
                int ix = floor(rec.point.x / rec.material.gridSize);
                int iz = floor(rec.point.z / rec.material.gridSize);
                if ((ix + iz) % 2 == 0) {
                    return rec.material.gridColor1;
                } else {
                    return rec.material.gridColor2;
                }
            } else {
                return rec.material.color;
            }
        } else {
            // Sky color
            Vector3D unitDir = ray.direction.normalize();
            double t = 0.5 * (unitDir.y + 1.0);
            return Vector3D(1.0, 1.0, 1.0) * (1.0 - t) + Vector3D(0.5, 0.7, 1.0) * t;
        }
    }

    Vector3D renderPixel(int x, int y, int width, int height) const {
        double u = double(x) / double(width);
        double v = double(y) / double(height);
        Ray ray = camera->getRay(u, v);
        return trace(ray, 0);
    }

    void render(const Scene& s, const Camera& c, int width, int height, std::vector<Vector3D>& image) const {
        image.resize(width * height);
        for (int j = height - 1; j >= 0; --j) {
            for (int i = 0; i < width; ++i) {
                image[j * width + i] = renderPixel(i, j, width, height);
            }
        }
    }
};

#endif // RAYTRACER_H
