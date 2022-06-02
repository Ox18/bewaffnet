#include "raylib.h"
#include "rlgl.h"
#include "TransitionScreen.h"

int main()
{
    TransitionScreen transitionScreen;

    const int screenWidth = 800;
    const int screenHeight = 600;
    InitWindow(screenWidth, screenHeight, "Gunbound");
    
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