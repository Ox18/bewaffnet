#ifndef SCENE_H_
#define SCENE_H_
#include <iostream>
#include <stdlib.h>
#include <string>
using namespace std;

class Scene
{

public:
    string current_status;
    string STATUS_OPEN;
    string STATUS_CLOSED;
    string STATUS_OPENING;
    string STATUS_CLOSING;
    Scene();
    ~Scene();
};

#endif