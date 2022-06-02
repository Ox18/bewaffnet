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
    int sleepTimeToChange = 60;
    bool changeScreen = false;
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
            changeScreen = true;
            if (framesCounter > 60)
            {
                location = 1;
                framesCounter = 0;
            }
            break;
        case 1:
            DrawTexture(mainScreenTexture2, 0, 0, WHITE);
            break;
        }

        if (changeScreen && transitionScreen.isOpened())
        {

            transitionScreen.close();
        }
        else
        {
            changeScreen = false;
        }
        if (changeScreen && !transitionScreen.isOpened())
        {

            transitionScreen.open();
        }
        else
        {
            changeScreen = false;
        }
        transitionScreen.drawWindows();
    }

    framesCounter++;
    EndDrawing();

    CloseWindow();

    return 0;
}