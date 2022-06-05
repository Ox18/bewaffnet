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
    SceneIntro sceneIntro;
    Gunbound();
    ~Gunbound();
    void Init();
    void Update();
    void Draw();
};

#endif