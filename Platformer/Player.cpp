#include "Player.h"

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

Player::Player(sf::Vector2u size)
{

	player_.setSize(sf::Vector2f(24, 24));
	player_.setOrigin(12, 12);
	player_.setFillColor(sf::Color(255, 255, 255));
	player_.setOutlineThickness(3);
	player_.setOutlineColor(sf::Color(23, 23, 255, 0));

}

void Player::Jump()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
	{
		//Jump if the player is grounded
		if (is_grounded_)
		{
			Y_movement_ = sf::Vector2f(0.0f, 15.0f * -1.0f);
		}
	}
}

void Player::Move()
{
	if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
	{
		//Move the player left
		X_movement_ = sf::Vector2f(-1, 0.0f);
	}
	else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
	{
		//Move the player right
		X_movement_ = sf::Vector2f(1, 0.0f);
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
////is_grounded = hb_ground_check.getPosition().y >= (render_window.getSize().y - player_box.getSize().y) - 20;
//
//
////Check the player input
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::Space))
//{
//	//Jump if the player is grounded
//	if (is_grounded)
//	{
//		jump_force = sf::Vector2f(0.0f, player_jump_force * -1);
//	}
//}
//
//if (sf::Keyboard::isKeyPressed(sf::Keyboard::A))
//{
//	//Move the player left
//	move_force = sf::Vector2f(player_move_speed * -1, 0.0f);
//}
//else if (sf::Keyboard::isKeyPressed(sf::Keyboard::D))
//{
//	//Move the player right
//	move_force = sf::Vector2f(player_move_speed, 0.0f);
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