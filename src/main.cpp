#define TIME_SCALE 60.0

#include "raylib.h"
#include "constants.h"

static void InitSim(void); // initialize the simulation
static void UpdateSim(void); // update a single frame of simulation
static void DrawSim(void); // draw the visuals on the frame
static void UnloadSim(void); // honestly might not need this
static void UpdateDrawSim(void); // update & draw

const float acceleration = GRAVITY;

int main() {
    InitWindow(SCREEN_WIDTH, SCREEN_HEIGHT, "arsenii likes balls");
    InitSim();

    SetTargetFPS(60);
    

    while (!WindowShouldClose()) {
        UpdateDrawSim();
    }
    
    UnloadSim();
    CloseWindow(); //esc or cross button trigger
    return 0;
}

void InitSim(void) {

}

void UpdateSim() {
    //lol
}

void DrawSim() {
    BeginDrawing();

    ClearBackground(PINK);    
    DrawText("Use arrows to move the ball", 10, 10, 30, BLACK);
    
    EndDrawing();
}

void UnloadSim() {

}

void UpdateDrawSim() {
    UpdateSim();
    DrawSim();
}