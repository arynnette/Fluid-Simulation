#pragma once

#include "raylib.h"

class Particle {
public:
    Vector2 position;
    Vector2 velocity;
    Vector2 acceleration;
    float mass;

    Particle(Vector2 pos = {0, 0}, float m = 1.0f)
        : position(pos), velocity({0, 0}), acceleration({0, 0}), mass(m) {}

    void resetAcceleration() {
        acceleration = {0, 0};
    }

    void applyForce(Vector2 force) {
        acceleration.x += force.x / mass;
        acceleration.y += force.y / mass;
    }
};
