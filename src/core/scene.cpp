#include "core/scene.h"
#include <algorithm>

Scene::~Scene()
{
    // Delete all entities when the scene is destroyed.
    for (auto entity : entities)
        delete entity;
    entities.clear();
}

void Scene::AddEntity(Entity *entity)
{
    entities.push_back(entity);
}

void Scene::RemoveEntity(int entityID)
{
    for (auto i = entities.begin(); i != entities.end(); i++)
    {
        if ((*i)->GetID() == entityID)
        {
            delete *i;
            entities.erase(i);
            break;
        }
    }
}

void Scene::InitEntities()
{
    for (auto entity : entities)
        entity->Init();
}

void Scene::HandleEntityEvent(const sf::Event &event)
{
    for (auto entity : entities)
        entity->HandleEvents(event);
}

void Scene::UpdateEntities(sf::Time deltaTime)
{
    for (auto entity : entities)
        entity->Update(deltaTime);
}

void Scene::RenderEntities(sf::RenderWindow &window)
{
    for (auto entity : entities)
        entity->Render(window);
}