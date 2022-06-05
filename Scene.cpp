#include "Scene.h"

Scene::Scene()
{
    STATUS_OPEN = "open";
    STATUS_CLOSED = "closed";
    STATUS_OPENING = "opening";
    STATUS_CLOSING = "closing";
    current_status = "closed";
    transition = Transition();
};

Scene::~Scene(){};

void Scene::renderTransition(){
    // render transition
    transition.drawWindows();
};

void Scene::changeStatus(string new_status)
{
    current_status = new_status;
};