#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>
#include <vector>
#include "core/entity.h"

class Scene
{
public:
    Scene(int id) : id(id) {}
    virtual ~Scene();

    int GetID() const { return id; }

    // Pure virtual functions to be implemented by each scene.
    virtual void Init() = 0;
    virtual void HandleEvents(const sf::Event &event) = 0;
    virtual void Update(sf::Time deltaTime) = 0;
    virtual void Render(sf::RenderWindow &window) = 0;

    // Entity management functions.
    void AddEntity(Entity *entity);
    void RemoveEntity(int entityID);

protected:
    // Helper functions to call entity methods.
    void InitEntities();
    void HandleEntityEvent(const sf::Event &event);
    void UpdateEntities(sf::Time deltaTime);
    void RenderEntities(sf::RenderWindow &window);

    std::vector<Entity *> entities;

private:
    int id;
};
