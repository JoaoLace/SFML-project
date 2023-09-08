#pragma once

#include <iostream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <sstream>
#include <string>
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
	sf::Vector2f mousePosView;

	// Game logic
	bool mouseHeld;
	unsigned points;
	int playerLife;
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
	// Constructors and Destructors
	Game();
	virtual ~Game();

	// Accessors
	const bool running() const;

	// Funcs
	void EnemieDmg();
	void showPoints();
	void spawnEnemies();
	void updateEnemies();
	void renderEnemies();
	void pollEvents();
	void getMousePosition();
	void update();
	void render();
};
class FPS
{
public:
	/// @brief Constructor with initialization.
	///
	FPS() : mFrame(0), mFps(0) {}

	/// @brief Update the frame count.
	/// 


	/// @brief Get the current FPS count.
	/// @return FPS count.
	const unsigned int getFPS() const { return mFps; }

private:
	unsigned int mFrame;
	unsigned int mFps;
	sf::Clock mClock;

public:
	void update()
	{
		if (mClock.getElapsedTime().asSeconds() >= 1.f)
		{
			mFps = mFrame;
			mFrame = 0;
			mClock.restart();
		}

		++mFrame;
	}
	
};
