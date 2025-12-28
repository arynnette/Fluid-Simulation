#include "collision.h"
#include "constants.h"
#include "integrator.h"
#include "particle.h"
#include "raylib.h"
#include <vector>


using namespace std;

static void InitSim(void);       // initialize the simulation
static void UpdateSim(void);     // update a single frame of simulation
static void DrawSim(void);       // draw the visuals on the frame
static void UnloadSim(void);     // honestly might not need this
static void UpdateDrawSim(void); // update & draw

const float acceleration = GRAVITY;

Integrator integrator(1.0f / TIME_SCALE);
CollisionHandler collisionHandler(10.0f, 0.6f);
vector<Particle> particles;

int main() {
  InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "arsenii likes balls");
  InitSim();

  SetTargetFPS(TARGET_FPS);

  while (!WindowShouldClose()) {
    UpdateDrawSim();
  }

  UnloadSim();
  CloseWindow(); // esc or cross button trigger
  return 0;
}

void InitSim(void) {
  for (int i = 0; i < 20; i++) {
    particles.emplace_back(
        Vector2{(SCREEN_WIDTH / 2.0f) - i, (SCREEN_HEIGHT / 2.0f) + i * 15}, i);
  }
}

void UpdateSim() {
  collisionHandler.clearContacts(); // reset the contacts that happened

  float dt = 1.0f / TIME_SCALE;

  for (auto &p : particles) {
    p.resetAcceleration();
    p.applyForce({0, GRAVITY * p.mass}); // graviviy
  }

  for (auto &p : particles)
    integrator.integrate(p);

  collisionHandler.handleBoundaryCollisions(particles);
}

void DrawSim() {
  BeginDrawing();

  ClearBackground(RAYWHITE);
  DrawText("stephon also likes balls", 10, 10, 20, GRAY);

  for (const auto &particle : particles) {
    DrawCircleV(particle.position, PARTICLE_RADIUS, BLACK);
  }

  EndDrawing();
}

void UnloadSim() { particles.clear(); }

void UpdateDrawSim() {
  UpdateSim();
  DrawSim();
}