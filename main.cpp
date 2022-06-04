#include "raylib.h"
#include "rlgl.h"
#include "src/App.h"

int main()
{
    App app(*new App());
    InitWindow(app.SCENE_WINDOW_WIDTH, app.SCENE_WINDOW_HEIGHT, app.SCENE_WINDOW_TITLE);

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