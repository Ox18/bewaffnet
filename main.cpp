#include "raylib.h"
#include "rlgl.h"
#include "TransitionScreen.h"

const float screenWidth = 800.0f;
const float screenHeight = 600.0f;

int main()
{
    TransitionScreen transitionScreen(screenWidth, screenHeight);

    InitWindow(screenWidth, screenHeight, "Gunbound2");
    
    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        transitionScreen.execute();
        EndDrawing();
    }

    CloseWindow();
    
    return 0;
}