#include "core/app.h"
#include <imgui.h>
#include "scenes/main_menu.h"
#include "core/scene.h"
#include <cstdio>
#include <SFML/Graphics.hpp>
#include "entities/camera.h"

void MainMenuScene::Init()
{
    AddEntity(new Camera(0));

    std::printf("MainMenuScene Init\n");
    // Initialize scene-specific resources here.
    // Also initialize all entities added to the scene.
    InitEntities();
}

void MainMenuScene::HandleEvents(const sf::Event &event)
{
    // Process scene-specific events here.
    // Then pass the event to each entity.
    HandleEntityEvent(event);
}

void MainMenuScene::Update(sf::Time deltaTime)
{
    // Scene update logic.
    ImGui::ShowDemoWindow();

    // Update all entities.
    UpdateEntities(deltaTime);
}

void MainMenuScene::Render(sf::RenderWindow &window)
{
    window.clear(sf::Color::Blue);
    // Render scene-specific elements here.

    // Render all entities.
    RenderEntities(window);
}
