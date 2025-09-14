#ifndef SCENE_H
#define SCENE_H

#include <vector>
#include "../objects/Object.h"
#include "../physics/PhysicsEngine.h"
#include "HitRecord.h"

class Scene {
public:
    std::vector<Object*> objects;
    PhysicsEngine physics;

    void addObject(Object* obj) {
        objects.push_back(obj);
    }

    bool intersect(const Ray& ray, double tMin, double tMax, HitRecord& rec) const {
        HitRecord tempRec;
        bool hitAnything = false;
        double closestSoFar = tMax;

        for (const auto& object : objects) {
            if (object->intersect(ray, tMin, closestSoFar, tempRec)) {
                hitAnything = true;
                closestSoFar = tempRec.t;
                rec = tempRec;
            }
        }
        return hitAnything;
    }
};

#endif // SCENE_H
