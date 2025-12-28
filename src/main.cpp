#include "raylib.h"
#include "constants.h"
#include "particle.h"
#include "integrator.h"
#include "collision.h"
#include <vector>

static void InitSim(void); // initialize the simulation
static void UpdateSim(void); // update a single frame of simulation
static void DrawSim(void); // draw the visuals on the frame
static void UnloadSim(void); // honestly might not need this
static void UpdateDrawSim(void); // update & draw

const float acceleration = GRAVITY;

EulerIntegrator integrator(1.0f / 120.0f);
CollisionHandler collisionHandler(10.0f, 0.8f);
std::vector<Particle> particles;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "arsenii likes balls");
    InitSim();

    SetTargetFPS(TARGET_FPS);
    

    while (!WindowShouldClose()) {
        UpdateDrawSim();
    }
    
    UnloadSim();
    CloseWindow(); //esc or cross button trigger
    return 0;
}

void InitSim(void) {
    particles.emplace_back(Vector2{SCREEN_WIDTH / 2.0f, SCREEN_HEIGHT / 2.0f}, 1.0f);
}

void UpdateSim() {
    const int substeps = 4;  // subdivide time step
    float dt = 1.0f / TIME_SCALE / substeps;
    
    for (int i = 0; i < substeps; i++) {
        for (auto& p : particles) {
            p.resetAcceleration();
            p.applyForce({0, GRAVITY * p.mass}); // graviviy
        }
        
        for (auto& p : particles)
            integrator.integrate(p);
    
        collisionHandler.handleCollisions(particles);
        collisionHandler.handleBoundaryCollisions(particles);
    }
}

void DrawSim() {
    BeginDrawing();

    ClearBackground(RAYWHITE);    
    DrawText("stephon also likes balls", 10, 10, 20, GRAY);

    for (const auto& particle : particles) {
        DrawCircleV(particle.position, PARTICLE_RADIUS, BLACK);
    }

    EndDrawing();
}

void UnloadSim() {
    particles.clear();
}

void UpdateDrawSim() {
    UpdateSim();
    DrawSim();
}