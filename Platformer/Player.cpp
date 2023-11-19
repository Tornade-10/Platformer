#include "Player.h"
#include "Game.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

Player::Player()
{
	is_grounded_ = true;

	X_pos_ = player_shape_.getPosition().x;
	Y_pos_ = player_shape_.getPosition().y;

	max_move_force_ = sf::Vector2f(15.0f, 0.0f);
	min_move_force_ = sf::Vector2f(0.1f, 0.0f);

	player_jump_force_ = 15.0f;

	player_shape_.setSize(sf::Vector2f(24, 24));
	player_shape_.setOrigin(12, 12);
	player_shape_.setFillColor(sf::Color(255, 255, 255));
	player_shape_.setOutlineThickness(3);
	player_shape_.setOutlineColor(sf::Color(23, 23, 255, 0));
}


