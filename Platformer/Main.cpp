// Main.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

//#include "Player.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

#define TILEMAP_WIDTH 10
#define TILEMAP_HEIGHT 8
#define TILE_SIZE_PX 50

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
int main()
{

	// initialize a bool array with all zeroes (false).
	bool tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT] = { 0 };

	// set some tiles for testing purposes
	tilemap[0] = true; // top left
	tilemap[TILEMAP_WIDTH - 1] = true; // top right
	tilemap[TILEMAP_WIDTH * TILEMAP_HEIGHT - 1] = true; // bottom right
	{
		int x = 3;
		int y = 2;
		tilemap[TILEMAP_WIDTH * y + x] = true;
	}


	// Create tile shape
	sf::RectangleShape tile_shape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	tile_shape.setFillColor(sf::Color(209, 147, 67));
	tile_shape.setOutlineColor(sf::Color(245, 213, 127));
	tile_shape.setOutlineThickness(-2);

	// Create cursor shape
	sf::RectangleShape cursor_shape(sf::Vector2f(TILE_SIZE_PX, TILE_SIZE_PX));
	cursor_shape.setFillColor(sf::Color(209, 147, 67, 0));
	cursor_shape.setOutlineColor(sf::Color(250, 250, 250));
	cursor_shape.setOutlineThickness(-3);



	//Create the window
	sf::RenderWindow render_window(sf::VideoMode(2000, 800), "Le game");

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

	//Set the frame limit
	render_window.setFramerateLimit(60);

	box.setPosition(600, 600);

	player_box.setPosition(50, 0);

	//The main loop
	while (render_window.isOpen())
	{
		//Clear the window
		render_window.clear();


		// Determine tile coordinates that the mouse is hovering
		sf::Vector2i mouse_pos = sf::Mouse::getPosition(render_window);
		sf::Vector2i mouse_tile_coord(mouse_pos.x / 50, mouse_pos.y / 50);
		//printf("%i,%i\n", mouse_tile_coord.x, mouse_tile_coord.y);

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
				tilemap[mouse_tile_coord.y * TILEMAP_WIDTH + mouse_tile_coord.x] = mouse_left;
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

		// draw the tilemap
		for (int y = 0; y < TILEMAP_HEIGHT; y++) {
			for (int x = 0; x < TILEMAP_WIDTH; x++) {
				if (tilemap[x + y * TILEMAP_WIDTH]) {
					// draw tile shape at correct position
					tile_shape.setPosition(TILE_SIZE_PX * x, TILE_SIZE_PX * y);
					render_window.draw(tile_shape);
				}
				else {
					// draw nothing                    
				}
			}
		}

		//Draw the player depending on his position
		player_box.setPosition(player_box.getPosition() + speed);
		render_window.draw(player_box);
		render_window.draw(box);

		// draw selection cursor
		cursor_shape.setPosition(TILE_SIZE_PX * mouse_tile_coord.x, TILE_SIZE_PX * mouse_tile_coord.y);
		render_window.draw(cursor_shape);

		render_window.display();
	}
	return EXIT_SUCCESS;
}
