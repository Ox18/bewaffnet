#ifndef App_H_
#define App_H

using namespace std;

class App
{
public:
    int SCENE_WINDOW_WIDTH;
    int SCENE_WINDOW_HEIGHT;
    char* SCENE_WINDOW_TITLE;
    App();
    ~App();
    void run();
};

#endif