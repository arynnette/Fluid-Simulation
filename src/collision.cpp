#include "collision.h"
#include "constants.h"
#include <cmath>
#include <vector>

using namespace std;

void CollisionHandler::handleCollisions(vector<Particle>& particles) {
    for (size_t i = 0; i < particles.size(); i++) {
        for (size_t j = i + 1; j < particles.size(); j++) {
            // check collisions because substeps are being used lol
            auto contact = std::make_pair(i, j);
            if (contactsThisFrame.count(contact)) {
                continue;
            }

            Vector2 delta = {
                particles[j].position.x - particles[i].position.x,
                particles[j].position.y - particles[i].position.y
            };
            float dist = sqrt(delta.x * delta.x + delta.y * delta.y);

            if (dist < minDistance && dist > 0) {
                contactsThisFrame.insert(contact); // it collided!

                float overlap = minDistance - dist;
                float nx = delta.x / dist;
                float ny = delta.y / dist;

                particles[i].position.x -= nx * overlap * 0.5f;
                particles[i].position.y -= ny * overlap * 0.5f;
                particles[j].position.x += nx * overlap * 0.5f;
                particles[j].position.y += ny * overlap * 0.5f;

                float dvx = particles[j].velocity.x - particles[i].velocity.x;
                float dvy = particles[j].velocity.y - particles[i].velocity.y;
                float dvn = dvx * nx + dvy * ny;

                if (dvn < 0) {
                    particles[i].velocity.x -= 0.025 * dvn * nx;
                    particles[i].velocity.y -= 0.025 * dvn * ny;
                    particles[j].velocity.x += 0.025 * dvn * nx;
                    particles[j].velocity.y += 0.025 * dvn * ny;
                }
            }
        }
    }
}

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