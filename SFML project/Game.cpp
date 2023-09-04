#include "Game.h"
int randPosX;
int randPosY;
int enemtPosY;
int enemyPosX;
bool killEnemy;
bool Game::mouseOnEnemy()
{
	
	if (sf::Mouse::getPosition(*window).x > enemyPosX and sf::Mouse::getPosition(*window).x < enemyPosX + 50) {
		if (sf::Mouse::getPosition(*window).y > enemtPosY and sf::Mouse::getPosition(*window).y < enemtPosY + 50)
			return true;
	}
	return false;
}

void Game::getMousePosition()
{
	/*
		@ return void

		Updates the mouse positions
			-mousePosWindow relative to window (Vector2i -> 2 int (x and y) )
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*window);
}

// Private funcs
void Game::initVariable()
{

	this->window = nullptr;
	this->score = 0;
	// Enemy game logic
	this->points = 0;
	this->enemySpawnTimerMax = 1000.f;
	this->enemySpawnTimer = this->enemySpawnTimerMax;
	this->maxEnemies = 3;
}

void Game::initWindow()
{
	this->videoMode.height = 480;
	this->videoMode.width = 600;
	this->window = new sf::RenderWindow(this->videoMode, "My game!", sf::Style::Titlebar | sf::Style::Close);
	this->window->setFramerateLimit(60);
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
			if (ev.key.code == sf::Keyboard::A and mouseOnEnemy())
				killEnemy = true;
			break;
		case sf::Event::MouseButtonPressed:
			if (ev.key.code == sf::Keyboard::A and mouseOnEnemy())
				killEnemy = true;
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
	this->getMousePosition();
	this->updateEnemies();
	// Display mouse position (relative to the window)
	
}

void Game::render()
{
	/*
		- clear old frames
		- render objs
		- display frame in window

		Renders the game objects

	*/

	this->window->clear();
	
	// Draw game

	this->renderEnemies();

	this->window->display();
}

void Game::updateEnemies() 
{
	/*
		@return void

		Updates de enemy spaw timer and spaws enemes
		when the total amount of enemies is less than max amount
		Moves the enemies down
		Removes the enemies at the edge of the screen TODO
	*/

	if (this->enemies.size() < this->maxEnemies)
	{
		if (this->enemySpawnTimer >= this->enemySpawnTimerMax)
		{
			this->spawnEnemies();
			this->enemySpawnTimer = 0.f;
		}
		else
			this->enemySpawnTimer += 5.f;
	}

	for (auto& e : enemies) {
		e.move(0.f, 1.f);
	}
}

void Game::renderEnemies()
{
	
	// Render all enemies
	for (auto& e : enemies) {
		window->draw(e);
		enemyPosX = e.getPosition().x;
		enemtPosY = e.getPosition().y;
		mouseOnEnemy();
		if (killEnemy) {
			e.setFillColor(sf::Color::Transparent);
			e.setOutlineThickness(0.f);
			score += 1;
		}
	}
}

void Game::spawnEnemies()
{
	killEnemy = false;
	/*
		@return void

		Spawns enemies and sets their colors and positions
			-Sets a randow position
			-Sets a randow color
			-Adds enemies to the vector
	*/

	this->enemy.setPosition(
		static_cast <float>(rand() % static_cast<int>(window->getSize().x - enemy.getSize().x)),
		0.f
	);

	this->enemy.setFillColor(sf::Color::Green);
	this->enemies.push_back(enemy);
}