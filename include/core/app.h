#pragma once
#include <imgui.h>
#include <imgui-SFML.h>
#include <SFML/Graphics.hpp>

#include <core/scene.h>
#include <core/scene_manager.h>

class App
{
public:
     App();
     ~App();

     // Main loop functions
     void Run();
     void HandleEvents();
     void Update();
     void Render();

     // Accessors for shared engine data
     sf::RenderWindow &GetWindow();
     SceneManager &GetSceneManager();

 private:
     sf::RenderWindow window;
     SceneManager sceneManager;
};