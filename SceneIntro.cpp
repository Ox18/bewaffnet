#include "SceneIntro.h"
#include "raylib.h"

SceneIntro::SceneIntro(){};

SceneIntro::~SceneIntro(){};

void SceneIntro::Draw()
{
    Texture2D background = LoadTexture(backgroundPath);
    DrawTexture(background, 0, 0, WHITE);

    if (transition.reinitalized)
    {
        step++;
    }

    if (step == 0)
    {
        transition.open();
    }
    else if (step == 1)
    {
        if (sleep_close > 0)
        {
            sleep_close = sleep_close - 60;
            transition.reinitalized = false;
        }
        else
        {
            transition.reinitalized = true;
        }
    }
    else if (step == 2)
    {
        transition.close();
    }
    else if (step == 3)
    {
        changeScene(1);
    }
    renderTransition();
};

void changeScene(int sceneId){
    
}