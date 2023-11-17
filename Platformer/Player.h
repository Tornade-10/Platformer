#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class Player
{
	sf::RectangleShape player_sahpe_;

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

	sf::RectangleShape GetPlayerShape()
	{
		return player_sahpe_;
	}

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
	float SetYCoord(float Y_pos)
	{
		Y_pos_ = Y_pos;
	}
	float GetXCoord()
	{
		return X_pos_;
	}
	float SetXCoord(float X_pos)
	{
		X_pos_ = X_pos;
	}

	void Jump();
	void Move();

};

//= sf::Vector2f(0.0f, 0.0f);
//= sf::Vector2f(0.0f, 0.0f);
//= sf::Vector2f(0, 0);