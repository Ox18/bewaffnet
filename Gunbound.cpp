#include "Gunbound.h"

Gunbound::Gunbound()
{
    SCENE_WINDOW_WIDTH = 800;
    SCENE_WINDOW_HEIGHT = 600;
    SCENE_WINDOW_TITLE = "Gunbound";
    SCENE_FPS = 60;
    sceneIntro = SceneIntro();
};

Gunbound::~Gunbound(){
    // Destroy
};

void Gunbound::Update(){
    // Update

};

void Gunbound::Init(){

};

void Gunbound::Draw()
{
    sceneIntro.Draw();
};