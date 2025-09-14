#include <iostream>
#include <fstream>
#include "rendering/Scene.h"
#include "rendering/RayTracer.h"
#include "objects/Sphere.h"
#include "rendering/Camera.h"
#include "math/Vector3D.h"

int main() {
    Scene scene;

    // Add a sphere to the scene
    Sphere* sphere = new Sphere(Vector3D(0, 0, -5), 1.0, Material(Vector3D(1, 0, 0)));
    scene.addObject(sphere);

    Camera camera(Vector3D(0, 0, 0), 0.0, 0.0, 90.0, 800.0/600.0);
    RayTracer rayTracer(scene, camera, 800, 600);

    // Render loop placeholder
    std::cout << "Starting render..." << std::endl;

    std::vector<Vector3D> image;
    rayTracer.render(800, 600, image);

    // Output to PPM file
    std::ofstream file("output.ppm");
    file << "P3\n" << 800 << " " << 600 << "\n255\n";
    for (int j = 600 - 1; j >= 0; --j) {
        for (int i = 0; i < 800; ++i) {
            Vector3D color = image[j * 800 + i];
            int ir = int(255.99 * color.x);
            int ig = int(255.99 * color.y);
            int ib = int(255.99 * color.z);
            file << ir << " " << ig << " " << ib << "\n";
        }
    }
    file.close();

    std::cout << "Render complete. Output saved to output.ppm" << std::endl;

    return 0;
}
