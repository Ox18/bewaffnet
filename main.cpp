#include "raylib.h"
#include "rlgl.h"
#include "Gunbound.h"

int main()
{
    Gunbound gunbound(*new Gunbound());
    InitWindow(gunbound.SCENE_WINDOW_WIDTH, gunbound.SCENE_WINDOW_HEIGHT, gunbound.SCENE_WINDOW_TITLE);

    SetTargetFPS(gunbound.SCENE_FPS);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        gunbound.Draw();
        EndDrawing();
    }

    CloseWindow();

    return 0;
}