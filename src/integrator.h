#ifndef INTEGRATOR_H
#define INTEGRATOR_H

#include "particle.h"

class EulerIntegrator {
private:
    float dt;

public:
    EulerIntegrator(float timeStep = 1.0f / 60.0f) : dt(timeStep) {}

    void integrate(Particle& particle) {
        // Position: x = x + v * dt
        particle.position.x += particle.velocity.x * dt;
        particle.position.y += particle.velocity.y * dt;

        // Velocity: v = v + a * dt
        particle.velocity.x += particle.acceleration.x * dt;
        particle.velocity.y += particle.acceleration.y * dt;
    }

    void setTimeStep(float timeStep) { dt = timeStep; }
    float getTimeStep() const { return dt; }
};

#endif
