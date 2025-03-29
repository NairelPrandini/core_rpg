#pragma once
#include "core/entity.h"

class Camera : public Entity
{
public:
    Camera(int id);
    ~Camera();

    void Init() override;
    void HandleEvents(const sf::Event &event) override;
    void Update(sf::Time deltaTime) override;
    void Render(sf::RenderWindow &window) override;


};
