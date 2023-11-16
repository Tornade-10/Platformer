// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "Player.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include "Game.h"
#include "TileMap.h"

// initialize a bool array with all zeroes (false).
int tile_map[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };

enum Tile
{
	kNothing,
	kGround,
	kObstacle
};

//Initialize all the Player variable
bool ground_check = false;
bool is_grounded = false;

float max_move_force = 25.0f;
float min_move_force = 0.1f;

float player_move_speed = 1.0f;
float player_jump_force = 15.0f;

float smooth_damp = 0.95f;

int selected_tile = 1;

sf::Vector2<float> speed;
sf::Vector2<float> jump_force;
sf::Vector2<float> move_force;


sf::Vector2<float> colider_speed;
sf::Vector2<float> Y_force;
sf::Vector2<float> X_force;


//Initializing all the World variable
const float gravity_force = 0.91f;

void main()
{
	Game game;

	game.Init();

	return game.MainLoop();

	// Create cursor shape
	sf::RectangleShape cursor_shape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	cursor_shape.setFillColor(sf::Color(209, 147, 67, 0));
	cursor_shape.setOutlineColor(sf::Color(250, 250, 250));
	cursor_shape.setOutlineThickness(-3);

}