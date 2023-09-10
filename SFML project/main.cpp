#include <iostream>
#include "Game.h"

int main() {
	// Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	// Init Game engine
	FPS fps;
	Game game;
	sf::Clock clock;
	float lastTime = 0;

	// Game loop
	while (game.running() and !game.getEndGame()) {

		game.update();

		fps.update();
		std::ostringstream ss;
		ss << fps.getFPS();

		std::cout << "FPS: " << ss.str() << "\n";
		
		game.render();
		
	}
	game.showPoints();
	// End

	return 0;
}