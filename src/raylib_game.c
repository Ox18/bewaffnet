#include "raylib.h"
#include "rlgl.h"

int main(void)
{
    const int screenWidth = 800;
    const int screenHeight = 600;

    InitWindow(screenWidth, screenHeight, "Bewaffnet");

    // intro screen
    Texture2D mainScreenTexture = LoadTexture("resources/img/screens/intro-a.png");
    Texture2D mainScreenTexture2 = LoadTexture("resources/img/screens/intro-b.png");

    Vector2 center = { 200, 200 };

    SetTargetFPS(60);
    float max_open_left = 600.0f;
    float open_left = .0f;
    float max_open_right = 0.0f;
    float open_right = 600.0f;
    float line_per_change = 0.1f;

    float max_close_left = 0.0f;
    float max_close_right = 600.0f;

    int open = 1;
    int open_time_3000 = 0;

    while (!WindowShouldClose())
    {

        BeginDrawing();
        ClearBackground(RAYWHITE);
        if(open == 1){
            DrawTexture(mainScreenTexture, 0, 0, WHITE);
        }else{
            DrawTexture(mainScreenTexture2, 0, 0, WHITE);
        }
        DrawTriangle((Vector2){0.0f, .0f},
                    (Vector2){0.0f, open_left},
                    (Vector2){800.0f, .0f}, BLACK);

        DrawTriangle((Vector2){800.0f, open_right},
                    (Vector2){0.0f, 600.0f},
                    (Vector2){800.0f, 600.0f}, BLACK);

        if(open == 1){
            if(open_left < max_open_left && open_right > max_open_right){
                open_left += line_per_change;
                open_right -= line_per_change;
                line_per_change += line_per_change * .12f + .2f;
            }else{
                open_left = max_open_left;
                open_right = max_open_right;
                open = 0;
                line_per_change = 0.1f;
            }
        }

        if(open == 0){
            
            if(open_time_3000 == 30){
                if(open_left > max_close_left && open_right < max_close_right){
                    open_left -= line_per_change;
                    open_right += line_per_change;
                    line_per_change += line_per_change * .12f + .2f;
                }else{
                    open_left = max_close_left;
                    open_right = max_close_right;
                    line_per_change = 0.1f;
                }
            }else{
                open_time_3000++;
            }
        
        }
        EndDrawing();
    }

    CloseWindow();

    return 0;
}
