#include <iostream>
#include "Game.h"

int main() {
	// Init srand
	std::srand(static_cast<unsigned>(time(NULL)));

	// Init Game engine
	Game game;
	

	// Game loop
	while (game.running()) {

		// Update
		game.update();
		
		// Render
		game.render();
		
	}
	game.score > 3 ? game.score = 3 : game.score = 0;
	std::cout << "YOU SCORED " << game.score << "!";
	// End

	return 0;
}