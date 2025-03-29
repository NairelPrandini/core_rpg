#include <core/app.h>
#include <scenes/main_menu.h>

sf::Vector2u windowSize = {1600, 900};
sf::State windowStyle = sf::State::Windowed;
sf::RenderWindow window;
sf::Clock deltaClock;
SceneManager sceneManager;

sf::RenderWindow &GetWindow()
{
    return window;
}

SceneManager &GetSceneManager()
{
    return sceneManager;
}

App::App()
{
    // Init Window
    window = sf::RenderWindow(sf::VideoMode(windowSize), "SFML window", windowStyle);

    // ImGui Init
    ImGui::SFML::Init(window);
    ImGui::CreateContext();

    sceneManager = SceneManager();
    sceneManager.AddScene(new MainMenuScene(0));
    sceneManager.SetScene(0);
}

App::~App()
{
    ImGui::SFML::Shutdown();
}

void App::Run()
{
    while (window.isOpen())
    {
        HandleEvents();
        Update();
        Render();
    }
}

void App::HandleEvents()
{
    // Poll Events
    while (const std::optional event = window.pollEvent())
    {
        ImGui::SFML::ProcessEvent(window, *event);

        if (event->is<sf::Event::Closed>())
            window.close();

        if (auto *scene = sceneManager.GetCurrentScene())
            scene->HandleEvents(*event);
    }
}

void App::Update()
{
    // Update Deltative
    sf::Time dt = deltaClock.restart();
    ImGui::SFML::Update(window, dt);

    if (auto *scene = sceneManager.GetCurrentScene())
        scene->Update(dt);
}

void App::Render()
{
    window.clear();

    // Render Calls Here
    if (auto *scene = sceneManager.GetCurrentScene())
        scene->Render(window);

    ImGui::SFML::Render(window);
    window.display();
}
