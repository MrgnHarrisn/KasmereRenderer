#pragma once
#include <vector>
#include "Wall.h"

#include <iostream>

#define dbg(X) std::cout << X << std::endl;

struct Sector
{
public:

	Sector();

	/// <summary>
	/// Get's a list of the sectors
	/// </summary>
	/// <returns>list of sectors in the map</returns>
	std::vector<Wall>& get_walls();

	/// <summary>
	/// get's color of the floor
	/// </summary>
	/// <returns>sf::Color</returns>
	sf::Color get_floor_color();

	/// <summary>
	/// gets the color of the walls
	/// </summary>
	/// <returns>sf::Color</returns>
	sf::Color get_walls_color();

	/// <summary>
	/// gets the color of the ceiling
	/// </summary>
	/// <returns>sf::Color</returns>
	sf::Color get_ceiling_color();

	/// <summary>
	/// Gets the floor height
	/// </summary>
	/// <returns>height of the floor</returns>
	float get_floor_height();

	/// <summary>
	/// Gets the ceiling height
	/// </summary>
	/// <returns>height of the ceiling</returns>
	float get_ceiling_height();

private:
	/// <summary>
/// return a reference to all the walls
/// </summary>
	std::vector<Wall> m_walls;

	/// <summary>
	/// returns the floor color
	/// </summary>
	sf::Color m_floor_color;

	/// <summary>
	/// returns the wall color
	/// </summary>
	sf::Color m_wall_color;

	/// <summary>
	/// get's the ceiling color
	/// </summary>
	sf::Color m_ceiling_color;

	int m_ID = -1;
	float m_floor_height;
	float m_ceiling_height;
};