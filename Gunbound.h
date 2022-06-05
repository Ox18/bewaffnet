#ifndef GUNBOUND_H_
#define GUNBOUND_H_
#include "SceneIntro.h"
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Gunbound
{
public:
    int SCENE_WINDOW_WIDTH, SCENE_WINDOW_HEIGHT,
        SCENE_FPS;
    string SCENE_WINDOW_TITLE;
    int SCENE_ID_INTRO = 0;
    SceneIntro sceneIntro;
    int CURRENT_SCENE_ID = 0;
    int LAST_SCENE_ID = 0;
    Gunbound();
    ~Gunbound();
    void Init();
    void Update();
    void Draw();
    void changeScene(int sceneId);
};

#endif