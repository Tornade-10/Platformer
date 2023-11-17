#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#include "Player.h"
#include "TileMap.h"


class Game
{

	sf::RenderWindow render_window_;

	std::vector<Player> player_objects_;
	std::vector<TileMap> Tilemap_;

	const float gravity_force_ = 0.91f;

public:

	void Init();

	void Physic();

	void DrawPlayer();

	void TileEditor();
	void DrawCursor();
	void DrawTileMap();


	int MainLoop();
};

