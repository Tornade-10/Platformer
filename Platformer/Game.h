#pragma once

#include <iostream>
#include <SFML/Main.hpp>
#include <SFML/Graphics.hpp>

class Game
{

	sf::RenderWindow render_window_;

public:

	void Init();

	void MainLoop();

};

