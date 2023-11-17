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

public:

	TileMap();
};



//#pragma region Tiles
//
////// Create tiles
////sf::RectangleShape tile_ground(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
////tile_ground.setFillColor(sf::Color(209, 147, 67));
////tile_ground.setOutlineColor(sf::Color(245, 213, 127));
////tile_ground.setOutlineThickness(-2);
////
////sf::RectangleShape tile_sky(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
////tile_sky.setFillColor(sf::Color(50, 160, 168));
////tile_sky.setOutlineColor(sf::Color(50, 160, 168));
////tile_sky.setOutlineThickness(-2);
//
//#pragma endregion

//#pragma region TileSelector
////_______________________________
//
////if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
////{
////	selected_tile = kGround;
////}
////if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
////{
////	selected_tile = kObstacle;
////}
////
////
////
////// Determine tile coordinates that the mouse is hovering
////sf::Vector2i mouse_pos = sf::Mouse::getPosition(render_window_);
////sf::Vector2i mouse_tile_coord((mouse_pos.x + player_box.getPosition().x - render_window_.getSize().x / 2) / TILE_SIZE_PX, mouse_pos.y / TILE_SIZE_PX);
////
////// Editor interaction
////bool mouse_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
////bool mouse_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);
////
////if (mouse_left || mouse_right) {
////	// Check the coordinates are inside our tilemap. Important! Otherwise we could write on unrelated memory and potentially corrupt or crash the program.
////	if (mouse_tile_coord.x < 0 || mouse_tile_coord.x >= TILEMAP_WIDTH || mouse_tile_coord.y < 0 || mouse_tile_coord.y >= TILEMAP_HEIGHT) {
////		printf("Out of bounds\n");
////	}
////	else {
////		// Set the hovered tile to true or false depending on the pressed mouse button.
////		if (mouse_left)
////		{
////			tile_map_[mouse_tile_coord.y * TILEMAP_WIDTH + mouse_tile_coord.x] = selected_tile;
////		}
////		else if (mouse_right)
////		{
////			tile_map_[mouse_tile_coord.y * TILEMAP_WIDTH + mouse_tile_coord.x] = kNothing;
////		}
////	}
////}
////--------------------------------
//#pragma endregion

// Create cursor shape
//sf::RectangleShape cursor_shape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
//cursor_shape.setFillColor(sf::Color(209, 147, 67, 0));
//cursor_shape.setOutlineColor(sf::Color(250, 250, 250));
//cursor_shape.setOutlineThickness(-3);
//
//int selected_tile = 1;