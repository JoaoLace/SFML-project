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
	while (game.running()) {

		// Update
		game.update();

		fps.update();
		std::ostringstream ss;
		ss << fps.getFPS();

		std::cout << "FPS: " << ss.str() << "\n";
		// Render
		game.render();
		
	}
	game.showPoints();
	// End

	return 0;
}