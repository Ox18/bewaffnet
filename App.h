#ifndef APPLICATION_H_
#define APPLICATION_H_

// load scenes lib
#include "SceneIntro.h"
#include "SceneCompany.h"

class Application
{
public:
    int SCENE_CURRENT;
    const static int SCENE_WIDTH = 800;
    const static int SCENE_HEIGHT = 600;

    // Scenes ID
    const static int SCENE_ID_INTRO = 0;
    const static int SCENE_ID_COMPANY = 1;
    const static int SCENE_ID_SERVERS = 2;
    const static int SCENE_ID_LOBBY = 3;
    const static int SCENE_ID_SHOP = 4;
    const static int SCENE_ID_ROOM = 5;
    const static int SCENE_ID_GAME = 6;

    SceneIntro sceneIntro();
    SceneCompany SceneCompany();

    Application()
    {
        SCENE_CURRENT = SCENE_ID_INTRO;
    }

    void changeScene(int scene)
    {
        SCENE_CURRENT = scene;
    }

    void run()
    {
        switch (SCENE_CURRENT)
        {
        case SCENE_ID_INTRO:
            sceneIntro->run();
            break;
        case SCENE_ID_COMPANY:
            sceneCompany.render();
            break;
        }
    };
};

#endif