#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#define TILEMAP_WIDTH 1000
#define TILEMAP_HEIGHT 24
#define TILE_SIZE_PX 24



enum class Tile
{
	kNothing,
	kGround,
	kObstacle
};

class TileMap
{
	// initialize a int array with all zeroes.
	int tile_map_[TILEMAP_WIDTH * TILEMAP_HEIGHT];

	Tile selected_tile_;

	sf::RectangleShape nothing_tile_;
	sf::RectangleShape ground_tile_;
	sf::RectangleShape obstacle_tile_;

	sf::RectangleShape cursor_shape_;

	sf::Vector2f cursor_pos_;

public:

	TileMap();

	Tile GetTile(int x, int y) const
	{
		// Check if the coordinates are within bounds
		if (x >= 0 && x < TILEMAP_WIDTH && y >= 0 && y < TILEMAP_HEIGHT)
		{
			// Calculate the index in the 1D array based on 2D coordinates
			int index = y * TILEMAP_WIDTH + x;
			return static_cast<Tile>(tile_map_[index]);
		}
		else
		{
			// Return a default tile if coordinates are out of bounds
			return Tile::kNothing; // Or any appropriate default tile
		}
	}
	void SetTile(int x, int y, Tile tile_type)
	{
		// Check if the coordinates are within bounds
		if (x >= 0 && x < TILEMAP_WIDTH && y >= 0 && y < TILEMAP_HEIGHT)
		{
			// Calculate the index in the 1D array based on 2D coordinates
			int index = y * TILEMAP_WIDTH + x;
			tile_map_[index] = static_cast<int>(tile_type);
		}
	}

	Tile GetSelectedTile()
	{
		return selected_tile_;
	}
	void SetSelectedTile(Tile selected_tile)
	{
		selected_tile_ = selected_tile;
	}

	sf::RectangleShape& GetNothingTile() 
	{
		return nothing_tile_;
	}
	sf::RectangleShape& GetGroundTile() 
	{
		return ground_tile_;
	}
	sf::RectangleShape& GetObstacleTile() 
	{
		return obstacle_tile_;
	}

	// Getter for cursor shape
	sf::RectangleShape& GetCursorShape()
	{
		return cursor_shape_;
	}

	sf::Vector2f GetCursorPos()
	{
		return cursor_pos_;
	}
	void SetCursorPos(const sf::Vector2f& cursor_pos)
	{
		cursor_pos_ = cursor_pos;
	}
};