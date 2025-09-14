#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "rendering/RayTracer.h"
#include "physics/Player.h"
#include "objects/Sphere.h"
#include "objects/Plane.h"

int main() {
    // Set up scene
    Scene scene;
    Material sphereMat(Vector3D(0.8, 0.3, 0.3));
    scene.addObject(new Sphere(Vector3D(0, 2, -5), 1.0, sphereMat));
    Material groundMat;
    groundMat.isGrid = true;
    groundMat.gridColor1 = Vector3D(0.8, 0.8, 0.8);
    groundMat.gridColor2 = Vector3D(0.2, 0.2, 0.2);
    groundMat.gridSize = 1.0;
    scene.addObject(new Plane(Vector3D(0, 0, 0), Vector3D(0, 1, 0), groundMat));

    // Set up player and camera
    Player player;
    Camera camera(player.position + Vector3D(0, 1.8, 0), 0, 0, 90, 16.0 / 9.0);

    // Set up ray tracer
    RayTracer tracer(&scene, &camera);

    int width = 800;
    int height = 600;
    std::vector<Vector3D> image(width * height);

    // Render
    tracer.render(scene, camera, width, height, image);

    // Save to PPM
    std::ofstream file("output_interactive.ppm");
    file << "P3\n" << width << " " << height << "\n255\n";
    for (int j = height - 1; j >= 0; --j) {
        for (int i = 0; i < width; ++i) {
            Vector3D color = image[j * width + i];
            int r = std::min(255, (int)(color.x * 255));
            int g = std::min(255, (int)(color.y * 255));
            int b = std::min(255, (int)(color.z * 255));
            file << r << " " << g << " " << b << "\n";
        }
    }
    file.close();

    std::cout << "Rendered output_interactive.ppm" << std::endl;

    return 0;
}
