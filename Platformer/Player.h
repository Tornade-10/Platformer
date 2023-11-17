#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class Player
{
	sf::RectangleShape player_;

	bool is_grounded_;

	float X_pos_;
	float Y_pos_;

protected:

	float max_move_force_;
	float min_move_force_;

	float player_move_speed_;
	float player_jump_force_;

	sf::Vector2f Y_movement_;
	sf::Vector2f X_movement_;
	sf::Vector2f movement_;

public:

	//Create the player
	explicit Player();

	bool GetIsGrounded()
	{
		return is_grounded_;
	}
	void SetIsGrounded(bool grounded)
	{
		is_grounded_ = grounded;
	}

	void SetYMovemnt(sf::Vector2f Y_movement)
	{
		Y_movement_ = Y_movement;
	}
	void SetXMovemnt(sf::Vector2f X_movement)
	{
		X_movement_ = X_movement;
	}

	float GetYCoord()
	{
		return Y_pos_;
	}
	float GetXCoord()
	{
		return X_pos_;
	}

	void Jump();
	void Move();

};

//= sf::Vector2f(0.0f, 0.0f);
//= sf::Vector2f(0.0f, 0.0f);
//= sf::Vector2f(0, 0);