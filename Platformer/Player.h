#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class Player
{
	sf::RectangleShape player_shape_;

	bool is_grounded_;

	float X_pos_;
	float Y_pos_;

	float max_move_force_;
	float min_move_force_;
	float player_jump_force_;

	sf::Vector2f Y_movement_ = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f X_movement_ = sf::Vector2f(0.0f, 0.0f);
	sf::Vector2f movement_;

public:

	//Create the player constructor
	explicit Player();

	sf::RectangleShape GetPlayerShape()
	{
		return player_shape_;
	}

	bool GetIsGrounded()
	{
		return is_grounded_;
	}
	void SetIsGrounded(bool grounded)
	{
		is_grounded_ = grounded;
	}

	sf::Vector2f GetYMovement()
	{
		return Y_movement_;
	}
	void SetYMovement(float Y_movement)
	{
		Y_movement_ = Y_movement;
	}
	sf::Vector2f GetXMovement()
	{
		return X_movement_;
	}
	void SetXMovement(sf::Vector2f X_movement)
	{
		X_movement_ = X_movement;
	}

	float GetYCoord()
	{
		return Y_pos_;
	}
	void SetYCoord(float Y_pos)
	{
		Y_pos_ = Y_pos;
	}
	float GetXCoord()
	{
		return X_pos_;
	}
	void SetXCoord(float X_pos)
	{
		X_pos_ = X_pos;
	}

	float GetMaxXMove()
	{
		return max_move_force_;
	}
	float GetMinXMove()
	{
		return min_move_force_;
	}
	float GetJumpForce()
	{
		return player_jump_force_;
	}

	sf::Vector2f GetMoveSpeed()
	{
		return movement_;
	}
};



