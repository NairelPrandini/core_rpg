#pragma once
#include <SFML/Graphics.hpp>
#include <SFML/Window/Event.hpp>

class Entity
{
public:
    Entity(int id) : id(id) {};
    ~Entity() {};
    
    virtual void Init() = 0;
    virtual void HandleEvents(const sf::Event &event) = 0;
    virtual void Update(sf::Time deltaTime) = 0;
    virtual void Render(sf::RenderWindow &window) = 0;

    int GetID() { return id; }

private:
    int id;
};
