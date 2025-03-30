#pragma once

#include <SFML/Graphics.hpp>

// Helper Functions
inline float Clamp(float value, float min, float max)
{
    return std::max(min, std::min(max, value));
}

inline sf::Vector2f Interpolate(const sf::Vector2f &start, const sf::Vector2f &end, float factor)
{
    return start + (end - start) * factor;
}

inline float Floor(float value)
{
    int i = static_cast<int>(value);
    return (value < i) ? i - 1 : i;
}