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
	bool endGame;
	bool mouseHeld;
	unsigned points;
	int health;
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
	const bool getEndGame() const;

	// Fonts
	sf::Font font;
	sf::Text text1;
	sf::Text text2;
	sf::Text text3;
	sf::Text text4;


	// Funcs
	void initText();
	
	void initFont();
	void showPoints();
	void spawnEnemies();
	
	
	void pollEvents();
	void getMousePosition();
	
	void update();
	void updateText();
	void updateEnemies();

	void render();
	void renderEnemies(sf::RenderTarget& target);
	void renderText(sf::RenderTarget& target);
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
