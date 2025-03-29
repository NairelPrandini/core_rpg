#pragma once
#include "core/scene.h"
#include <map>

class SceneManager
{
    public:
        SceneManager();
        ~SceneManager();

        void AddScene(Scene *scene);
        void SetScene(int id);

        Scene *GetCurrentScene();

    private:
        std::map<int, Scene *> scenes;
        Scene *currentScene;
};
