#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
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

	// mouse pos
	sf::Vector2i mousePosWindow;

	// Game logic
	int points;

	float enemySpawnTimer;
	float enemySpawnTimerMax;
	int maxEnemies;

	// Game objs
	std::vector<sf::RectangleShape> enemies;
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
	int score;

	// Funcs
	void spawnEnemies();
	void updateEnemies();
	void renderEnemies();
	void pollEvents();
	void getMousePosition();
	void update();
	void render();
};

