// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "Player.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

//#include "Collision.h"
//#include "Tilemap.h"

//Initialize all the Player variable
bool is_grounded = false;

float max_move_force = 25.0f;
float min_move_force = 0.1f;

float player_move_speed = 1.0f;
float player_jump_force = 25.0f;

float smooth_damp = 0.95f;

sf::Vector2<float> speed;
sf::Vector2<float> jump_force;
sf::Vector2<float> move_force;

//Initializing all the World variable
const float gravity_force = 0.91f;

#define TILEMAP_WIDTH  20
#define TILEMAP_HEIGHT  20

enum Tile
{
	OFF,
	ON,
	Player
};

int TileMap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };

int main()
{
	//Create the window
	sf::RenderWindow render_window(sf::VideoMode(2000, 800), "Le Gayme");

	//Create the player
	sf::RectangleShape player_box(sf::Vector2f(24, 24));
	player_box.setFillColor(sf::Color(255, 255, 255));
	player_box.setOutlineThickness(3);
	player_box.setOutlineColor(sf::Color(23, 23, 255, 0));

	//Create an object
	sf::RectangleShape box(sf::Vector2f(24, 24));
	box.setFillColor(sf::Color(255, 0, 0));
	box.setOutlineThickness(3);
	box.setOutlineColor(sf::Color(23, 23, 255, 0));

	sf::RectangleShape OffBox(sf::Vector2f(20, 20));
	OffBox.setFillColor(sf::Color(0, 0, 0));
	OffBox.setOutlineThickness(3);
	OffBox.setOutlineColor(sf::Color(255, 255, 255));

	sf::RectangleShape OnBox(sf::Vector2f(20, 20));
	OnBox.setFillColor(sf::Color(139, 139, 139));
	OnBox.setOutlineThickness(3);
	OnBox.setOutlineColor(sf::Color(255, 255, 255));

	sf::RectangleShape HoverBox(sf::Vector2f(20, 20));
	HoverBox.setFillColor(sf::Color(0, 0, 0, 0));
	HoverBox.setOutlineThickness(-5);
	HoverBox.setOutlineColor(sf::Color(255, 255, 255));

	//Set the frame limit
	render_window.setFramerateLimit(60);

	box.setPosition(600, 600);

	player_box.setPosition(50, 0);


	//The main loop
	while (render_window.isOpen())
	{
		//Clear the window
		render_window.clear();


		sf::Vector2i Position = sf::Mouse::getPosition(render_window);
		sf::Vector2i PositionTile(Position.x / 25, Position.y / 25);

		if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
		{
			if (PositionTile.x < 0 || PositionTile.x >= TILEMAP_WIDTH || PositionTile.y < 0 || PositionTile.y >= TILEMAP_HEIGHT)
			{
				std::cout << "out of bounces\n";
			}
			else
			{
				std::cout << "Press" << std::endl;
				TileMap[PositionTile.y * TILEMAP_HEIGHT + PositionTile.x] = true;
			}
		}

		if (sf::Mouse::isButtonPressed(sf::Mouse::Right))
		{
			if (PositionTile.x < 0 || PositionTile.x >= TILEMAP_WIDTH || PositionTile.y < 0 || PositionTile.y >= TILEMAP_HEIGHT)
			{
				std::cout << "out of bounces\n";
			}
			else
			{
				std::cout << "Press" << std::endl;
				TileMap[PositionTile.y * TILEMAP_HEIGHT + PositionTile.x] = false;
			}
		}

		// +25 if i want to set a new one next to this one
		for (int y = 0; y < TILEMAP_WIDTH; y++)
		{
			for (int x = 0; x < TILEMAP_HEIGHT; x++)
			{
				if (TileMap[x + y * TILEMAP_WIDTH] == OFF)
				{
					OffBox.setPosition(25 * x, 25 * y);
					render_window.draw(OffBox);
				}
				else
				{
					OnBox.setPosition(25 * x, 25 * y);
					render_window.draw(OnBox);
				}
			}
		}

		//Close the window if the "close window" is pressed
		sf::Event event;
		while (render_window.pollEvent(event))
		{
			if (event.type == sf::Event::Closed)
			{
				render_window.close();
			}
		}

		//Reset the forces
		jump_force = sf::Vector2f(0.0f, 0.0f);
		move_force = sf::Vector2f(0.0f, 0.0f);
		sf::Vector2f acceleration = sf::Vector2f(0, 0);

		//Check if the player is on the ground
		is_grounded = player_box.getPosition().y >= (render_window.getSize().y - player_box.getSize().y) - 20;

		//Check the player input
		if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
		{
			//Jump if the player is grounded
			if (is_grounded)
			{
				jump_force = sf::Vector2f(0.0f, player_jump_force * -1);
			}
		}

		if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
		{
			//Move the player left
			move_force = sf::Vector2f(player_move_speed * -1, 0.0f);
		}
		else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
		{
			//Move the player right
			move_force = sf::Vector2f(player_move_speed, 0.0f);
		}
		else
		{
			//If nothing is pressed slow down the player
			if (is_grounded)
			{
				speed.x *= 0.75f;
			}
			else
			{
				//Slow the player a bit less in the air
				speed.x *= 0.95f;
			}
		}

		//Put gravity on the player while he is in the air
		if (!is_grounded)
		{
			acceleration += sf::Vector2f(0, gravity_force);
		}
		else
		{
			speed.y = 0;
		}

		//
		acceleration += jump_force;
		acceleration += move_force;

		//Put all the value in Speed
		speed += acceleration;

		//Cap the min Speed
		if (std::abs(speed.x) < min_move_force)
		{
			speed.x = 0.0f;
		}

		//Cap the max Speed
		if (speed.x > max_move_force)
		{
			speed.x = max_move_force;
		}
		else if (speed.x < max_move_force * -1)
		{
			speed.x = max_move_force * -1;
		}

		//Debug
		//std::cout << "-------------------" << std::endl;

		//std::cout << "Pos : " << PlayerBox.getPosition().x << " : " << PlayerBox.getPosition().y << std::endl;
		//std::cout << "Speed : " << Speed.x << " : " << Speed.y << std::endl;
		//std::cout << "Acceleration : " << Acceleration.x << " : " << Acceleration.y << std::endl;

		//Make the camera follow the player
		sf::View view(sf::Vector2f(player_box.getPosition().x + 400, render_window.getSize().y / 2), sf::Vector2f(render_window.getSize().x, render_window.getSize().y));
		render_window.setView(view);

		//CollisionCheck(box.getPosition(), player_box.getPosition());

		//Map(render_window.getSize(), sf::Vector2f(PositionTile));

		//Draw the player depending on his position
		player_box.setPosition(player_box.getPosition() + speed);
		render_window.draw(player_box);
		render_window.draw(HoverBox);
		render_window.draw(box);
		render_window.display();
	}
	return EXIT_SUCCESS;
}
