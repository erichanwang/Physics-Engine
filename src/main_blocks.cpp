#include <iostream>
#include <vector>
#include <fstream>
#include <string>
#include "rendering/Scene.h"
#include "rendering/RayTracer.h"
#include "rendering/Camera.h"
#include "objects/Sphere.h"
#include "objects/Block.h"
#include "physics/PhysicsEngine.h"
// #include "rendering/UI.h"  // Commented out to avoid raylib dependency for testing

int main() {
    // Create scene
    Scene scene;

    // Add ground
    scene.addObject(new Sphere(Vector3D(0, -1001, 0), 1000, Material(Vector3D(0.5, 0.5, 0.5))));

    // Add blocks
    for (int i = 0; i < 5; ++i) {
        Block* block = new Block(Vector3D(i*2 - 4, 5 + i, 0), Vector3D(1,1,1), Material(Vector3D(1,0,0)));
        scene.addObject(block);
        // Add physics
        RigidBody* rb = new RigidBody(block->position, 1.0);
        scene.physics.addBody(rb);
    }

    // Camera
    Camera camera(Vector3D(0, 2, 10), 0, 0, 90, 16.0/9.0);

    // Simulate physics and render
    int width = 800, height = 600;
    std::vector<Vector3D> image(width * height);

    for (int frame = 0; frame < 100; ++frame) {
        // Update physics
        scene.physics.update(0.1);

        // Update object positions
        for (size_t i = 0; i < scene.objects.size(); ++i) {
            if (i >= 1 && i <= 5) { // blocks
                Block* block = dynamic_cast<Block*>(scene.objects[i]);
                if (block) {
                    block->position = scene.physics.bodies[i-1]->position;
                }
            }
        }

        // RayTracer
        RayTracer rayTracer(scene, camera, width, height);

        // Render
        rayTracer.render(width, height, image);

        // Save or display
        std::string filename = "output_blocks_" + std::to_string(frame) + ".ppm";
        std::ofstream file(filename);
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

        std::cout << "Frame " << frame << " rendered." << std::endl;
    }

    // Display last frame
    // DisplayImage("output_blocks_99.ppm");  // Commented out to avoid raylib dependency for testing

    return 0;
}
