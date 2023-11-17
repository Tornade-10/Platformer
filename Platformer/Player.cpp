#include "Player.h"
#include "Game.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

Player::Player()
{
	is_grounded_ = true;

	X_pos_ = player_sahpe_.getPosition().x;
	Y_pos_ = player_sahpe_.getPosition().y;

	max_move_force_ = 25.0f;
	min_move_force_ = 0.1f;

	player_move_speed_ = 1.0f;
	player_jump_force_ = 15.0f;

	player_sahpe_.setSize(sf::Vector2f(24, 24));
	player_sahpe_.setOrigin(12, 12);
	player_sahpe_.setFillColor(sf::Color(255, 255, 255));
	player_sahpe_.setOutlineThickness(3);
	player_sahpe_.setOutlineColor(sf::Color(23, 23, 255, 0));

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


//#pragma region Physic
////Player physic-----------------------
//
////Reset the forces
//jump_force = sf::Vector2f(0.0f, 0.0f);
//move_force = sf::Vector2f(0.0f, 0.0f);
//sf::Vector2f acceleration = sf::Vector2f(0, 0);
//
////Check if the player is on the ground
//is_grounded = hb_ground_check.getPosition().y == (tile_ground.getPosition().y - player_box.getSize().y);
//
//
//
////Check the player input
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//{
//	//Jump if the player is grounded
//	if (is_grounded)
//	{
//		jump_force = sf::Vector2f(0.0f, player_jump_force_ * -1);
//	}
//}
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//{
//	//Move the player left
//	move_force = sf::Vector2f(player_move_speed_ * -1, 0.0f);
//}
//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//{
//	//Move the player right
//	move_force = sf::Vector2f(player_move_speed_, 0.0f);
//}
//else
//{
//	//If nothing is pressed slow down the player
//	if (is_grounded)
//	{
//		speed.x *= 0.75f;
//
//	}
//	else
//	{
//		//Slow the player a bit less in the air
//		speed.x *= 0.95f;
//	}
//}
//
////Put gravity on the player while he is in the air
//if (!is_grounded)
//{
//	acceleration += sf::Vector2f(0, gravity_force);
//}
//else
//{
//	speed.y = 0;
//}
//
////Put the Y and X axis in acceleration
//acceleration += jump_force;
//acceleration += move_force;
//
//Y_force += jump_force;
//X_force += move_force;
//
////Put all the value in Speed
//speed += acceleration;
//
//colider_speed += Y_force;
//colider_speed += X_force;
//
////Cap the min Speed
//if (std::abs(speed.x) < min_move_force)
//{
//	speed.x = 0.0f;
//}
//
////Cap the max Speed
//if (speed.x > max_move_force)
//{
//	speed.x = max_move_force;
//}
//else if (speed.x < max_move_force * -1)
//{
//	speed.x = max_move_force * -1;
//}
//
//player_box.setPosition(player_box.getPosition() + speed);
//
////Debug
////std::cout << "-------------------" << std::endl;
//
////std::cout << "Pos : " << PlayerBox.getPosition().x << " : " << PlayerBox.getPosition().y << std::endl;
////std::cout << "Speed : " << Speed.x << " : " << Speed.y << std::endl;
////std::cout << "Acceleration : " << Acceleration.x << " : " << Acceleration.y << std::endl;
//
////--------------------------------
//#pragma endregion