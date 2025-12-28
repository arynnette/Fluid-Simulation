#ifndef COLLISION_H
#define COLLISION_H

#include "particle.h"
#include <vector>

class CollisionHandler {
private:
    float restitution;
    float minDistance;

public:
    CollisionHandler(float minDist = 10.0f, float rest = 0.8f)
        : minDistance(minDist), restitution(rest) {}

    void handleCollisions(std::vector<Particle>& particles);
    void handleBoundaryCollisions(std::vector<Particle>& particles);
};

#endif
