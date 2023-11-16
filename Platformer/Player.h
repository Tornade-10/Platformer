#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class Player
{
	sf::RectangleShape player_;

protected:

	bool is_grounded_;

	sf::Vector2f Y_movement_;
	sf::Vector2f X_movement_;
	sf::Vector2f movement_;

public:

	//Create the player
	explicit Player(sf::Vector2u size);

	void Jump();

	void Move();


};

//= sf::Vector2f(0.0f, 0.0f);
//= sf::Vector2f(0.0f, 0.0f);
//= sf::Vector2f(0, 0);