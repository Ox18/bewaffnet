#ifndef SCENE_INTRO_H_
#define SCENE_INTRO_H_
#include "Scene.h"

class SceneIntro : public Scene
{
public:
    const char *backgroundPath = "res/img/screens/intro-b.png";
    int status_change = 0;
    int sleep_close = 60 * 40;
    int step = 0;
    SceneIntro();
    ~SceneIntro();
    void Draw();
    void changeScene(int sceneId);
};

#endif