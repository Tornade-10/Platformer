#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class Player
{

	bool is_grounded_ = false;

protected:

	float max_moove_force_ = 25.0f;
	float min_moove_force_ = 0.1f;

	float palyer_moove_speed_ = 1.0f;
	float player_jump_force_ = 25.0f;

public:

	sf::Vector2<float> speed_;
	sf::Vector2<float> jump_force_;
	sf::Vector2<float> move_force_;

	Player(bool is_grounded, float max_moove_force, float min_moove_force, float palyer_moove_speed, float player_jump_force, sf::Vector2<float> speed, sf::Vector2<float> jump_force, sf::Vector2<float> move_force);

	int GetIsGrounded();

	void Jump();

	void Moove();

	void MooveCheck();

	void Stop();
};
