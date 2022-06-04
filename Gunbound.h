#ifndef GUNBOUND_H_
#define GUNBOUND_H_
#include "SceneIntro.h"

class Gunbound
{
public:
    int SCENE_WINDOW_WIDTH, SCENE_WINDOW_HEIGHT,
        SCENE_FPS;
    char *SCENE_WINDOW_TITLE;
    SceneIntro sceneIntro;
    Gunbound();
    ~Gunbound();
    void Init();
    void Update();
    void Draw();
};

#endif