#include "Game.h"
int randPosX;
int randPosY;
int enemtPosY;
int enemyPosX;

void Game::updateText()
{
	std::stringstream ss;
	ss << "Points: " << points << "\nLife: " << health;
	text1.setString(ss.str());
}

void Game::showPoints()
{
	std::cout << "GAME OVER" << "\n";
	std::cout << "SCORE -> " << points;
}

void Game::getMousePosition()
{
	/*
		@ return void

		Updates the mouse positions
			-mousePosWindow relative to window (Vector2i -> 2 int (x and y) )
	*/

	this->mousePosWindow = sf::Mouse::getPosition(*window);
	this->mousePosView = this->window->mapPixelToCoords(this->mousePosWindow);
}

// Private funcs
void Game::initVariable()
{

	this->window = nullptr;
	// Enemy game logic
	this->endGame = false;
	this->mouseHeld = false;
	this->health = 10;
	this->points = 0;
	this->enemySpawnTimerMax = 10.f;
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
void Game::initFont()
{
	font.loadFromFile("Gerlick.otf");

}
void Game::initText()
{
	text1.setFont(font);
	text1.setCharacterSize(24);
	text1.setPosition(0.f, 0.f);

	text2.setFont(font);
	text2.setCharacterSize(24);
	text2.setPosition(0.f, 30.f);
	
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
	this->initFont();
	this->initText();
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


	if (!endGame)
		{
		// Display mouse position (relative to the window)
		this->getMousePosition();
		
		this->updateEnemies();
		
		this->updateText();
		}
	
	
	if (health <= 0)
	{
		endGame = true;
	}
}
void Game::renderText(sf::RenderTarget& target)
{
	target.draw(text1);
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


	this->renderEnemies(*window);

	this->renderText(*window);

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
			this->enemySpawnTimer += 1.f;
	}

	for (int i = 0; i < enemies.size(); i++) {
		bool deleted = false;
		enemies[i].move(0.f, 2.f);

		if (enemies[i].getPosition().y > window->getSize().y)
		{
			enemies.erase(enemies.begin() + i);
			health--;
			text4.setString(std::to_string(health));
		}
			
		}

	// check if clicked upon
	if (sf::Mouse::isButtonPressed(sf::Mouse::Left))
	{
		if (mouseHeld == false)
		{
			mouseHeld = true;
			bool deleted = false;
			for (size_t i = 0; i < enemies.size() && deleted == false; i++) {
				if (enemies[i].getGlobalBounds().contains(mousePosView))
				{
					// Delete enemy
					deleted = true;
					enemies.erase(enemies.begin() + i);

					points += 10;
					text1.setString(std::to_string(points));
				}
			}
		}
	}
	else 
	{
		mouseHeld = false;
	}
	

}

void Game::renderEnemies(sf::RenderTarget& target)
{
	
	// Render all enemies
	for (auto& e : enemies) {
		target.draw(e);
	}
}

void Game::spawnEnemies()
{

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

const bool Game::getEndGame() const
{
	return this->endGame;
}


