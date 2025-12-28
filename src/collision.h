#ifndef COLLISION_H
#define COLLISION_H

#include "constants.h"
#include "particle.h"
#include <vector>
#include <set>

class CollisionHandler {
private:
    float restitution;
    float minDistance;
    std::set<std::pair<size_t, size_t>> contactsThisFrame;

public:
    CollisionHandler(float minDist = MINIMUM_PARTICLE_DISTANCE, float rest = PARTICLE_RESTITUTION)
        : minDistance(minDist), restitution(rest) {}

    void handleBoundaryCollisions(std::vector<Particle>& particles);
    void clearContacts() { contactsThisFrame.clear(); }
};

#endif
