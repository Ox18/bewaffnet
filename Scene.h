#ifndef SCENE_H_
#define SCENE_H_
#include <iostream>
#include <stdlib.h>
#include <string>
#include "Transition.h"
using namespace std;

class Scene
{

public:
    string current_status;
    string STATUS_OPEN;
    string STATUS_CLOSED;
    string STATUS_OPENING;
    string STATUS_CLOSING;
    Transition transition;
    Scene();
    ~Scene();
    void renderTransition();
    void changeStatus(string new_status);
};

#endif