#include "Game.h"
#include "TileMap.h"
#include "Player.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

void Game::Init()
{
	//Create the window
	render_window_.create(sf::VideoMode(2000, TILE_SIZE_PX * 25), "Le game");

	//Set the frame limit
	render_window_.setVerticalSyncEnabled(true);
	render_window_.setFramerateLimit(60);
}

void Game::Physic()
{
	for (auto& p : player_objects_)
	{
		if (p.GetYCoord() >= (render_window_.getSize().y - p.GetYCoord()) - 20)
		{
			p.GetIsGrounded() == true;
		}
	}



}


void Game::MainLoop()
{
	//The main loop
	while (render_window_.isOpen())
	{
		//Clear the window
		render_window_.clear();

		//Close the window if the "close window" is pressed
		sf::Event event;
		while (render_window_.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				render_window_.close();
			}
		}

#pragma region DrawMap
//--------------------------------
//draw the tilemap
		//for (int y = 0; y < TILEMAP_HEIGHT; y++) {
		//	for (int x = 0; x < TILEMAP_WIDTH; x++) {
		//		switch (tile_map[x + y * TILEMAP_WIDTH])
		//		{
		//		case kGround:
		//			tile_ground.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
		//			render_window_.draw(tile_ground);
		//			break;

		//		case kObstacle:
		//			tile_sky.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
		//			render_window_.draw(tile_sky);
		//			break;

		//		default:
		//			break;
		//		}
		//	}
		//}
		//--------------------------------
#pragma endregion

		//Make the camera follow the player
		//sf::View view(sf::Vector2f(player_box.getPosition().x, render_window_.getSize().y / 2), sf::Vector2f(render_window_.getSize().x, render_window_.getSize().y));
		//render_window_.setView(view);

		////Draw the player depending on his position
		//render_window_.draw(player_box);

		//hb_ground_check.setPosition(hb_ground_check.getPosition() + colider_speed);
		//render_window_.draw(hb_ground_check);

		//// draw selection cursor
		//cursor_shape.setPosition(TILE_SIZE_PX * mouse_tile_coord.x, TILE_SIZE_PX * mouse_tile_coord.y);
		//render_window_.draw(cursor_shape);

		render_window_.display();
	}
}
