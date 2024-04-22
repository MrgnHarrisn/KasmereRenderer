#pragma once

#include <Thor/Graphics.hpp>

struct Wall
{
	sf::Vector2f start;
	sf::Vector2f end;
	sf::Color color;
	float roof_height;
	float floor_height;
};