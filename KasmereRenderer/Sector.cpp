#include "Sector.h"

Sector::Sector()
{
}

std::vector<Wall>& Sector::get_walls()
{
	// TODO: insert return statement here
	return m_walls;
}

sf::Color Sector::get_floor_color()
{
	return m_floor_color;
}

sf::Color Sector::get_walls_color()
{
	return m_wall_color;
}

sf::Color Sector::get_ceiling_color()
{
	return m_ceiling_color;
}

float Sector::get_floor_height()
{
	return m_floor_height;
}

float Sector::get_ceiling_height()
{
	return m_ceiling_height;
}
