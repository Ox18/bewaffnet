#ifndef SCENEINTRO_H_
#define SCENEINTRO_H_

#include "raylib.h"

class SceneIntro
{
public:
    void render()
    {
        Texture2D mainScreenTexture = LoadTexture("res/img/screens/intro-a.png");
        DrawTexture(mainScreenTexture, 0, 0, WHITE);
    };
};

#endif