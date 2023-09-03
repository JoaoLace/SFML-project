#pragma once

#include <iostream>
#include <cstdlib>
#include <SFML/Graphics.hpp>
#include <SFML/System.hpp>
#include <SFML/Window.hpp>
#include <SFML/Audio.hpp>
#include <SFML/Network.hpp>



class Game
{
private:
	// variables
	// window
	sf::VideoMode videoMode;
	sf::RenderWindow* window;
	sf::Event ev;

	// Game objs
	sf::RectangleShape enemy;

	// private funcs
	
	void initVariable();
	void initWindow();
	void initEnemy();

public:
	bool mouseOnEnemy();
	// Constructors and Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Funcs
	void pollEvents();
	void update();
	void render();
};

