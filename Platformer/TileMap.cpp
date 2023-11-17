#include "TileMap.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include "TileMap.h"



TileMap::TileMap()
{
	// Initialization of the member array
	for (int tile = 0; tile < TILEMAP_WIDTH * TILEMAP_HEIGHT; ++tile)
	{
		tile_map_[tile] = static_cast<int>(Tile::kNothing);
	}

#pragma region Tiles

	// Create tiles

	nothing_tile_.setSize(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	nothing_tile_.setFillColor(sf::Color(0, 0, 0, 0));

	ground_tile_.setSize(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	ground_tile_.setFillColor(sf::Color(255, 0, 0));
	ground_tile_.setOutlineColor(sf::Color(162, 0, 0));
	ground_tile_.setOutlineThickness(-2);

	obstacle_tile_.setSize(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	obstacle_tile_.setFillColor(sf::Color(50, 160, 168));
	obstacle_tile_.setOutlineColor(sf::Color(50, 160, 168));
	obstacle_tile_.setOutlineThickness(-2);

#pragma endregion

	// Create cursor shape
	cursor_shape_.setSize(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	cursor_shape_.setFillColor(sf::Color(209, 147, 67, 0));
	cursor_shape_.setOutlineColor(sf::Color(250, 250, 250));
	cursor_shape_.setOutlineThickness(-3);

}
