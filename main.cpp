#include "raylib.h"
#include "rlgl.h"
#include "TransitionScreen.h"

const float screenWidth = 800.0f;
const float screenHeight = 600.0f;

int main()
{
    TransitionScreen transitionScreen(screenWidth, screenHeight);

    InitWindow(screenWidth, screenHeight, "Gunbound2");
    // intro screen
    Texture2D mainScreenTexture = LoadTexture("res/img/screens/intro-a.png");
    Texture2D mainScreenTexture2 = LoadTexture("res/img/screens/intro-b.png");

    int framesCounter = 0;
    int location = 0;

    SetTargetFPS(60);
    while (!WindowShouldClose())
    {
        BeginDrawing();
        ClearBackground(RAYWHITE);
        switch (location)
        {
        case 0:
            DrawTexture(mainScreenTexture, 0, 0, WHITE);
            if (transitionScreen.isOpened())
            {
                if (transitionScreen.validChangeWindowOnClose())
                {
                    transitionScreen.changeWindows();
                }
                else
                {
                    transitionScreen.toggleReinitialized();
                }
            }
            if(framesCounter > 60){
                location = 1;
                framesCounter = 0;
            }
            break;
        case 1:
            DrawTexture(mainScreenTexture2, 0, 0, WHITE);
            if(!transitionScreen.isOpened()){
                if(transitionScreen.validChangeWindowOnOpen()){
                    transitionScreen.changeWindows();
                }else{
                    transitionScreen.toggleReinitialized();
                }
            }
            break;
        }
        transitionScreen.drawWindows();
        framesCounter++;
        EndDrawing();
    }

    CloseWindow();

    return 0;
}