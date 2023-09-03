#include "Game.h"
int randPosX;
int randPosY;
bool Game::mouseOnEnemy()
{
	int enemyPosX = enemy.getPosition().x;
	int enemtPosY = enemy.getPosition().y;
	
	if (sf::Mouse::getPosition(*window).x > enemyPosX and sf::Mouse::getPosition(*window).x < enemyPosX + 50) {
		if (sf::Mouse::getPosition(*window).y > enemtPosY and sf::Mouse::getPosition(*window).y < enemtPosY + 50)
			return true;
	}
	return false;
}

// Private funcs
void Game::initVariable()
{
	this->window = nullptr;
}

void Game::initWindow()
{
	this->videoMode.height = 480;
	this->videoMode.width = 600;
	this->window = new sf::RenderWindow(this->videoMode, "My game!", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(30);
}

void Game::initEnemy()
{
	
	enemy.setPosition(250, 350);
	// float
	enemy.setSize(sf::Vector2f(50.f,50.f));
	enemy.setFillColor(sf::Color::Blue);
	enemy.setOutlineColor(sf::Color::Cyan);
	enemy.setOutlineThickness(1.f);

}

// Constructors and Destructors
Game::Game()
{
	this->initVariable();
	this->initWindow();
	this->initEnemy();
}

Game::~Game()
{
	delete this->window;
}

const bool Game::running() const
{
	return this->window->isOpen();
}

void Game::pollEvents()
{
	// Event polling
	while (this->window->pollEvent(this->ev)) {
		switch (this->ev.type)
		{
		case sf::Event::Closed:
			window->close();
			break;

		case sf::Event::KeyPressed:
			if (ev.key.code == sf::Keyboard::Escape)
				window->close();
			break;
		default:
			break;
		}
	}
}

void Game::update()
{
	/*
	Set enemy Postion to randow value if mouse is over it

	randPosY = rand() % 430;
	randPosX = rand() % 550;
	
	if (mouseOnEnemy())
		enemy.setPosition(randPosX,randPosY);

	else
		enemy.setScale(sf::Vector2f(1.0f, 1.0f));
	
	*/

	this->pollEvents();

	// Display mouse position (relative to the window)
	std::cout << "Mouse pos: " << sf::Mouse::getPosition(*window).x << " " << sf::Mouse::getPosition(*window).y << "\n";
}

void Game::render()
{
	/*
		- clear old frames
		- render objs
		- display frame in window

		Renders the game objects

	*/

	window->clear();
	
	// Draw game

	window->draw(enemy);

	window->display();
}
