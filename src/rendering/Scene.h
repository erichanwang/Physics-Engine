#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../objects/Object.h"
#include "../physics/PhysicsEngine.h"
#include "../math/Vector3D.h"

class Scene {
public:
    std::vector<Object*> objects;
    PhysicsEngine physics;
    Vector3D lightPosition;

    Scene() : lightPosition(0, 10, 0) {}

    void addObject(Object* obj) {
        objects.push_back(obj);
    }

    ~Scene() {
        for (auto obj : objects) {
            delete obj;
        }
    }
};

#endif // SCENE_H
