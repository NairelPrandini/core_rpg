#include "core/scene_manager.h"
#include <cstdio>

SceneManager::SceneManager() : currentScene(nullptr) {}

SceneManager::~SceneManager()
{
    // Delete all allocated scenes.
    for (auto &pair : scenes)
        delete pair.second;
    scenes.clear();
}

void SceneManager::AddScene(Scene *scene)
{
    scenes[scene->GetID()] = scene;
}

void SceneManager::SetScene(int id)
{
    if (scenes.find(id) != scenes.end())
    {
        currentScene = scenes[id];
        currentScene->Init();
    }
    else
    {
        std::printf("Scene with ID %d not found.\n", id);
    }
}

Scene *SceneManager::GetCurrentScene()
{
    return currentScene;
}
