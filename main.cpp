#include "raylib.h"
#include "rlgl.h"
#include "App.h"

int main()
{
    Application app;
    InitWindow(app.SCENE_WIDTH, app.SCENE_HEIGHT, "Gunbound");

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        app.run();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}