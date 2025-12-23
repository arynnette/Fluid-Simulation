#include "raylib.h"

int main() {
    const int screenWidth = 1280;
    const int screenHeight = 720;

    InitWindow(screenWidth, screenHeight, "Fluid Simulation");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        
        const char* text = "Hi again.";
        int textWidth = MeasureText(text, 40);
        DrawText(text, screenWidth / 2 - textWidth / 2, screenHeight / 2 - 20, 40, BLACK);
        
        EndDrawing();
    }

    CloseWindow();
    return 0;
}