#include "raylib.h"

int main() {

    const int screenWidth = 1280;
    const int screenHeight = 720;
    const float acceleration = 9.8; 

    Vector2 pos = {screenWidth/2.0, 25}; 
    Vector2 vel = {0.0, 0.0};
    Color pink = {255, 144, 202, 255};
    Color teal = {40, 225, 237, 255};

    InitWindow(screenWidth, screenHeight, "Move-a-ball");
    SetTargetFPS(60);

    while (!WindowShouldClose()) {

        //unforced movement (velocity and acceleration)
        pos.x += vel.x;
        pos.y += vel.y;
        vel.y += acceleration/60.0; //per frame
        vel.x += 5.0f/60.0f; //artificial sideways movement

        //forced movement
        if(IsKeyDown(KEY_RIGHT)){
            pos.x += 2.0f;
        };
        if(IsKeyDown(KEY_LEFT)){
            pos.x -= 2.0f;
        };
        if(IsKeyDown(KEY_UP)){
            pos.y -= 2.0f;
        };
        if(IsKeyDown(KEY_DOWN)){
            pos.y += 2.0f;
        };

        //boundary collision
        if(pos.y >= screenHeight - 20 || pos.y <= 20){
            vel.y *= -0.95;
        };
        if(pos.x <= 20 || pos.x >= screenWidth -20){
            vel.x *= -0.95;
        };

        //things appearing on the screen
        BeginDrawing();

        ClearBackground(pink);
        
        DrawText("Use arrows to move the ball", 10, 10, 30, BLACK);

        DrawCircleV(pos, 20, teal);
        
        EndDrawing();
    }

    CloseWindow(); //esc or cross button trigger
    return 0;
}