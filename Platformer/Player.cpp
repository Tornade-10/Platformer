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

	max_move_force_ = 25.0f;
	min_move_force_ = 0.1f;

	player_move_speed_ = 1.0f;
	player_jump_force_ = 15.0f;

	player_shape_.setSize(sf::Vector2f(24, 24));
	player_shape_.setOrigin(12, 12);
	player_shape_.setFillColor(sf::Color(255, 255, 255));
	player_shape_.setOutlineThickness(3);
	player_shape_.setOutlineColor(sf::Color(23, 23, 255, 0));

}

void Player::Jump()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//Jump if the player is grounded
		if (is_grounded_)
		{
			Y_movement_ = sf::Vector2f(0.0f, player_jump_force_ * -1.0f);
		}
	}
}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//Move the player left
		X_movement_ = sf::Vector2f(player_move_speed_ * -1, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//Move the player right
		X_movement_ = sf::Vector2f(player_move_speed_, 0.0f);
	}
	else
	{
		//If nothing is pressed slow down the player
		if (is_grounded_)
		{
			movement_.x *= 0.75f;
		}
		else
		{
			//Slow the player a bit less in the air
			movement_.x *= 0.95f;
		}
	}
}

void Player::SlowDown()
{
	Y_movement_ = sf::Vector2f(0.0f, 0.0f);
	X_movement_ = sf::Vector2f(0.0f, 0.0f);
	movement_ = sf::Vector2f(0.0f, 0.0f);
}