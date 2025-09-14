# 3D Game Engine

A pure C++ 3D game engine featuring ray tracing rendering and accurate physics simulation.

## Features

- **Ray Tracing Renderer**: High-quality rendering with reflections, shadows, and materials.
- **Physics Simulation**: Accurate physics with real-world data (gravity = 9.81 m/s²).
- **Modular Architecture**: Organized into math, rendering, objects, and physics modules.
- **SDL2 Integration**: Interactive GUI with keyboard and mouse controls.
- **Cross-Platform**: Built with CMake for easy compilation on Windows, Linux, and macOS.

## Requirements

- C++17 compatible compiler (g++, clang++, MSVC)
- CMake 3.10 or higher
- SDL2 library

## Building

1. Clone or download the project.
2. Install SDL2:
   - Windows: Download from https://www.libsdl.org/download-2.0.php
   - Linux: `sudo apt-get install libsdl2-dev`
   - macOS: `brew install sdl2`
3. Create build directory: `mkdir build && cd build`
4. Configure: `cmake ..`
5. Build: `cmake --build .`
6. Run: `./GameEngine` (or `GameEngine.exe` on Windows)

## Usage

- **WASD**: Move camera
- **Mouse**: Look around
- **Space**: Jump (if physics enabled)
- The engine renders a ray-traced scene with a sphere and displays it in an SDL2 window.

## Project Structure

- `src/math/`: Vector and ray math utilities
- `src/rendering/`: Camera, materials, scene, and ray tracer
- `src/objects/`: 3D objects like spheres
- `src/physics/`: Physics engine and rigid bodies
- `src/main.cpp`: Entry point with SDL2 loop

## License

This project is licensed under the MIT License - see the [LICENSE](LICENSE) file for details.

## Contributing

Feel free to submit issues and pull requests.

## Author

Eric Wang
