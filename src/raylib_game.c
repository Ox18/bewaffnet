#include "raylib.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Bewaffnet");

    // intro screen
    Texture2D mainScreenTexture = LoadTexture("resources/img/screens/intro-a.png");



    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        // DrawTexture(mainScreenTexture, 0, 0, WHITE);
        EndDrawing();
    }

    CloseWindow();

    return 0;
}