#include <SFML/Graphics.hpp>
#include "entities/camera.h"
#include "imgui.h"
#include "imgui-SFML.h"
#include <cmath>
#include <core/sfml_math.h>

sf::View view;
// Camera Settings
sf::Vector2f startPos;
bool dragging = false;
int gridSize = 64;
float zoom = 1.0f;

sf::Vector2f mouseWorldPos;

Camera::Camera(int id) : Entity(id)
{
    // Initialization code
}

Camera::~Camera()
{
    // Cleanup code
}

void Camera::Init()
{
    // Initialization code for the camera
    view = sf::View({0.f, 0.f}, {1000, 1000});
}

void Camera::HandleEvents(const sf::Event &event)
{
    if (const auto *resized = event.getIf<sf::Event::Resized>())
    {
        view.setSize(sf::Vector2f(resized->size));
    }

    ImGuiIO &io = ImGui::GetIO();
    if (io.WantCaptureMouse)
        return;


    if (const auto *MouseEvent = event.getIf<sf::Event::MouseButtonPressed>())
    {
        startPos = mouseWorldPos;
        if (MouseEvent->button == sf::Mouse::Button::Right)
            dragging = true;
    }

    if (const auto *MouseEvent = event.getIf<sf::Event::MouseButtonReleased>())
    {
        if (MouseEvent->button == sf::Mouse::Button::Right)
            dragging = false;
    }

    if (event.is<sf::Event::MouseMoved>() && dragging)
    {
        sf::Vector2f delta = mouseWorldPos - startPos;
        sf::Vector2f center = view.getCenter();
        view.setCenter(center - delta);
    }

    if(const auto* scrollEvent = event.getIf<sf::Event::MouseWheelScrolled>())
    {            
        zoom += scrollEvent->delta * -0.1f;
        zoom = Clamp(zoom, 0.25f, 2.0f);
        
        if (zoom > 0.25f && zoom < 2.0f){
            sf::Vector2f center = view.getCenter();
            view.zoom(1.f + scrollEvent->delta * -0.1f);
            sf::Vector2f zoomPosition = mouseWorldPos;

            view.setCenter(Interpolate(zoomPosition, center, 1.f + scrollEvent->delta * -0.1f));
        }
    }
}

void Camera::Update(sf::Time deltaTime)
{
    // Update camera state
}

void Camera::Render(sf::RenderWindow &window)
{

    mouseWorldPos = window.mapPixelToCoords(sf::Mouse::getPosition(window));
    // Render camera view
    window.setView(view);

    sf::Vector2f viewSize = view.getSize();
    sf::Vector2f viewCenter = view.getCenter();
    sf::Vector2f topLeft = viewCenter - viewSize / 2.0f;

    sf::VertexArray grid(sf::PrimitiveType::Lines);

    for (float x = std::floor(topLeft.x / gridSize) * gridSize; x < topLeft.x + viewSize.x; x += gridSize)
    {
        grid.append(sf::Vertex{sf::Vector2f(x, topLeft.y), sf::Color::White});
        grid.append(sf::Vertex{sf::Vector2f(x, topLeft.y + viewSize.y), sf::Color::White});
    }

    for (float y = std::floor(topLeft.y / gridSize) * gridSize; y < topLeft.y + viewSize.y; y += gridSize)
    {
        grid.append(sf::Vertex{sf::Vector2f(topLeft.x, y), sf::Color::White});
        grid.append(sf::Vertex{sf::Vector2f(topLeft.x + viewSize.x, y), sf::Color::White});
    }

    window.draw(grid);
}