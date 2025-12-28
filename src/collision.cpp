#include "collision.h"
#include "constants.h"
#include <cmath>
#include <vector>

using namespace std;

void CollisionHandler::handleBoundaryCollisions(vector<Particle>& particles) {
    for (auto& p : particles) {
        if (p.position.x - PARTICLE_RADIUS < 0) {
            p.position.x = PARTICLE_RADIUS;
            p.velocity.x *= -restitution;
        }
        if (p.position.x + PARTICLE_RADIUS > SCREEN_WIDTH) {
            p.position.x = SCREEN_WIDTH - PARTICLE_RADIUS;
            p.velocity.x *= -restitution;
        }
        if (p.position.y - PARTICLE_RADIUS < 0) {
            p.position.y = PARTICLE_RADIUS;
            p.velocity.y *= -restitution;
        }
        if (p.position.y + PARTICLE_RADIUS > SCREEN_HEIGHT) {
            p.position.y = SCREEN_HEIGHT - PARTICLE_RADIUS;
            p.velocity.y *= -restitution;
        }
    }
}