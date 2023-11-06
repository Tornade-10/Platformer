#include "Player.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

Player::Player(bool is_grounded, float max_moove_force, float min_moove_force, float palyer_moove_speed, float player_jump_force, sf::Vector2<float> speed, sf::Vector2<float> jump_force, sf::Vector2<float> move_force)
{
	is_grounded_ = is_grounded;
	max_moove_force_ = max_moove_force;
	min_moove_force_ = min_moove_force;
	player_jump_force_ = player_jump_force;
	palyer_moove_speed_ = palyer_moove_speed;
	speed_ = speed;
	jump_force_ = jump_force;
	move_force_ = move_force;
}


int Player::GetIsGrounded()
{
	return  is_grounded_;
}

void Player::Jump()
{
	//Jump if the player is grounded
	if (GetIsGrounded())
	{
		jump_force_ = sf::Vector2f(0.0f, player_jump_force_ * -1);
	}
}

void Player::Moove()
{
	//Move the player left
	move_force_ = sf::Vector2f(0.0f, palyer_moove_speed_);
}

void Player::MooveCheck()
{
	
}


void Player::Stop()
{
	//If nothing is pressed slow down the player
	if (GetIsGrounded())
	{
		speed_.x *= 0.75f;
	}
	else
	{
		//Slow the player a bit less in the air
		speed_.x *= 0.95f;
	}
}
