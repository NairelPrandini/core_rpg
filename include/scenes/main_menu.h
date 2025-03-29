#pragma once
#include "core/scene.h"

// A simple Main Menu Scene.
class MainMenuScene : public Scene
{
public:
    MainMenuScene(int id) : Scene(id) {}
    virtual ~MainMenuScene() {}

    void Init() override;
    void HandleEvents(const sf::Event &event) override;
    void Update(sf::Time deltaTime) override;
    void Render(sf::RenderWindow &window) override;
};