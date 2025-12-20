#include "raylib.h"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Fluid Simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        DrawText("HI", 190, 200, 40, BLACK);
        DrawFPS(10, 10);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}