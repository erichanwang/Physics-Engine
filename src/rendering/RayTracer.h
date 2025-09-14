#ifndef RAYTRACER_H
#define RAYTRACER_H

#include <vector>
#include "Scene.h"
#include "Camera.h"
#include "../math/Vector3D.h"

class RayTracer {
public:
    Scene& scene;
    Camera& camera;
    int width, height;

    RayTracer(Scene& s, Camera& c, int w, int h) : scene(s), camera(c), width(w), height(h) {}

    void render(int width, int height, std::vector<Vector3D>& image);
    Vector3D traceRay(const Ray& ray, int depth = 0);
};

#endif // RAYTRACER_H
