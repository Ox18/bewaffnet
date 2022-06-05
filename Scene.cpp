#include "Scene.h"

Scene::Scene()
{
    STATUS_OPEN = "0";
    STATUS_CLOSED = "1";
    STATUS_OPENING = "2";
    STATUS_CLOSING = "4";
    current_status = "0";
};

Scene::~Scene()
{
}