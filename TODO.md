# TODO List for 3D Game Engine Project

## Project Setup
- [x] Create project directory structure
- [x] Create CMakeLists.txt for build system
- [x] Create .vscode/tasks.json and launch.json for g++ auto run fix

## Core Engine Components
- [x] Implement Vector3D class (src/math/Vector3D.h, Vector3D.cpp)
- [x] Implement Ray class (src/math/Ray.h, Ray.cpp)
- [x] Implement Camera class (src/rendering/Camera.h, Camera.cpp)
- [x] Implement Material class (src/rendering/Material.h, Material.cpp)
- [x] Implement Sphere class (src/objects/Sphere.h, Sphere.cpp)
- [x] Implement Scene class (src/rendering/Scene.h, Scene.cpp)
- [x] Implement RayTracer class (src/rendering/RayTracer.h, RayTracer.cpp)
- [x] Implement PhysicsEngine class (src/physics/PhysicsEngine.h, PhysicsEngine.cpp)
- [x] Implement RigidBody class (src/physics/RigidBody.h, RigidBody.cpp)
- [x] Create main.cpp with game loop

## Documentation and Licensing
- [x] Create README.md
- [x] Create LICENSE (MIT)

## Interactivity Features
- [x] Implement Player class (src/physics/Player.h, Player.cpp)
- [x] Update Camera for interactive control (mouse look, movement)
- [x] Modify UI for real-time rendering and input handling
- [x] Add gravity to player
- [x] Implement WASD/arrow keys movement, space jump, mouse angle change
- [x] Add grid support to Material and RayTracer

## Testing and Finalization
- [x] Build and test the project
- [x] Verify g++ auto run configuration
- [x] Test interactivity and grid
