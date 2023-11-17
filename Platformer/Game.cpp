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
		if (p.GetYCoord() >= render_window_.getSize().y - 20)
		{
			p.SetIsGrounded(true);
		}

		//Put gravity on the player while he is in the air
		if (!p.GetIsGrounded())
		{
			p.SetYMovemnt(sf::Vector2f(0, gravity_force_));
		}

	}
}

void Game::DrawPlayer()
{
	////Draw the player depending on his position

	for (auto& p : player_objects_)
	{
		sf::RectangleShape player_shape = p.GetPlayerShape();

		player_shape.setPosition(p.GetXCoord(), p.GetYCoord());

		render_window_.draw(player_shape);
	}
}

void Game::DrawTileMap()
{

	//// draw selection cursor
//cursor_shape.setPosition(TILE_SIZE_PX * mouse_tile_coord.x, TILE_SIZE_PX * mouse_tile_coord.y);
//render_window_.draw(cursor_shape);

#pragma region DrawMap
	//--------------------------------
	//draw the tilemap
			//for (int y = 0; y < TILEMAP_HEIGHT; y++) {
			//	for (int x = 0; x < TILEMAP_WIDTH; x++) {
			//		switch (tile_map_[x + y * TILEMAP_WIDTH])
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

}

int Game::MainLoop()
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

		DrawPlayer();

		DrawTileMap();

		//Make the camera follow the player
		//sf::View view(sf::Vector2f(player_box.getPosition().x, render_window_.getSize().y / 2), sf::Vector2f(render_window_.getSize().x, render_window_.getSize().y));
		//render_window_.setView(view);

		render_window_.display();
	}

	return EXIT_SUCCESS;
}
