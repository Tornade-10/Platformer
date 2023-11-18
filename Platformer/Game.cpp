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
	//render_window_.setVerticalSyncEnabled(true);
	render_window_.setFramerateLimit(60);
}



void Game::PlayerJump()
{
	for (auto& p : player_objects_)
	{

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//Jump if the player is grounded
			if (p.GetIsGrounded())
			{
				p.SetYCoord(p.GetJumpForce() * -1.0f);
			}
		}

		if (p.GetYCoord() >= render_window_.getSize().y - 20)
		{
			p.SetIsGrounded(true);
		}

		//Put gravity on the player while he is in the air
		if (!p.GetIsGrounded())
		{
			p.SetYMovement(sf::Vector2f(0, gravity_force_));
		}
		player_objects_.push_back(p);
	}
}



void Game::PlayerMove()
{
	for (auto& p : player_objects_)
	{
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			//Move the player left
			p.SetXMovement(-1.0f);
			std::cout << "yo" << std::endl;
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			//Move the player right
			X_movement_ = sf::Vector2f(1, 0.0f);
		}
		else
		{
			//If nothing is pressed slow down the player
			if (p.GetIsGrounded())
			{
				p.SetXCoord(p.GetXCoord() * 0.75f);
			}
			else
			{
				//Slow the player a bit less in the air
				p.SetXCoord(p.GetXCoord() * 0.95f);
			}
		}
	}
}

void Game::PlayerSlowDown()
{
	Y_movement_ = sf::Vector2f(0.0f, 0.0f);
	X_movement_ = sf::Vector2f(0.0f, 0.0f);
	movement_ = sf::Vector2f(0.0f, 0.0f);
}

void Game::PlayerPhysic()
{

}

void Game::DrawPlayer()
{
	////Draw the player depending on his position

	for (auto& p : player_objects_)
	{
		//std::cout << "X : " << p.GetXCoord() << std::endl;
		//std::cout << "Y : " << p.GetYCoord() << std::endl;

		render_window_.draw(p.GetPlayerShape());
	}
}

void Game::TileEditor()
{

	for (auto t : Tilemap_)
	{
		for (auto p : player_objects_)
		{
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num1))
			{
				t.SetSelectedTile((Tile::kGround));
				std::cout << "yo" << std::endl;
			}
			if (sf::Keyboard::isKeyPressed(sf::Keyboard::Num2))
			{
				t.SetSelectedTile((Tile::kObstacle));
				std::cout << "yo 2" << std::endl;
			}

			// Determine tile coordinates that the mouse is hovering
			sf::Vector2i mouse_pos = sf::Mouse::getPosition(render_window_);
			sf::Vector2i mouse_tile_coord((mouse_pos.x +p.GetXCoord() - render_window_.getSize().x / 2) / TILE_SIZE_PX, mouse_pos.y / TILE_SIZE_PX);

			// Editor interaction
			bool mouse_left = sf::Mouse::isButtonPressed(sf::Mouse::Left);
			bool mouse_right = sf::Mouse::isButtonPressed(sf::Mouse::Right);

			if (mouse_left || mouse_right) {
				// Check the coordinates are inside our tilemap. Important! Otherwise we could write on unrelated memory and potentially corrupt or crash the program.
				if (mouse_tile_coord.x < 0 || mouse_tile_coord.x >= TILEMAP_WIDTH || mouse_tile_coord.y < 0 || mouse_tile_coord.y >= TILEMAP_HEIGHT) {
					printf("Out of bounds\n");
				}
				else {
					// Set the hovered tile to true or false depending on the pressed mouse button.
					if (mouse_left)
					{
						t.SetTile(mouse_tile_coord.x, mouse_tile_coord.y, t.GetSelectedTile());
						std::cout << "left" << std::endl;
					}
					else if (mouse_right)
					{
						t.SetTile(mouse_tile_coord.x, mouse_tile_coord.y, Tile::kNothing);
						std::cout << "right" << std::endl;
					}
				}
			}
		}
	}
}

void Game::DrawCursor()
{
	// draw selection cursor
	for (auto t : Tilemap_)
	{
		sf::RectangleShape cursor_shape_ = t.GetCursorShape();
		sf::Vector2f cursor_pos = t.GetCursorPos();
		cursor_shape_.setPosition(TILE_SIZE_PX * cursor_pos.x, TILE_SIZE_PX * cursor_pos.y);
		render_window_.draw(cursor_shape_);
	}

}

void Game::DrawTileMap()
{
	//Draw the TileMap
	for (auto& t : Tilemap_)
	{
		for (int y = 0; y < TILEMAP_HEIGHT; y++)
		{
			for (int x = 0; x < TILEMAP_WIDTH; x++)
			{
				switch (t.GetTile(x, y))
				{

				case Tile::kNothing:
					render_window_.draw(t.GetNothingTile());
					break;

				case Tile::kGround:
					render_window_.draw(t.GetGroundTile());
					break;

				case Tile::kObstacle:
					render_window_.draw(t.GetObstacleTile());
					break;

					default:
						break;
				}
			}
		}
	}
}

int Game::MainLoop()
{

	Player player;
	player.SetXCoord(0);
	player.SetYCoord(0);
	player_objects_.push_back(player);

	TileMap tile_map;
	Tilemap_.push_back(tile_map);

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

		//Physic();

		DrawPlayer();

		DrawTileMap();

		//Make the camera follow the player

		for(auto& p : player_objects_)
		{
			sf::View view(sf::Vector2f(p.GetXCoord(), render_window_.getSize().y / 2), sf::Vector2f(render_window_.getSize().x, render_window_.getSize().y));
			render_window_.setView(view);
		}


		for (auto& t : Tilemap_)
		{
			render_window_.draw(t.GetGroundTile());
			render_window_.draw(t.GetObstacleTile());
			render_window_.draw(t.GetNothingTile());
			render_window_.draw(t.GetCursorShape());
		}

		render_window_.display();
	}

	return EXIT_SUCCESS;
}
