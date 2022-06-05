#include "SceneIntro.h"
#include "raylib.h"

SceneIntro::SceneIntro(){};

SceneIntro::~SceneIntro(){};

void SceneIntro::Draw()
{
    Texture2D background = LoadTexture(backgroundPath);
    DrawTexture(background, 0, 0, WHITE);

    if (transition.isOpen)
    {
        transition.close();
    }
    else
    {
        transition.open();
    }
    renderTransition();
};