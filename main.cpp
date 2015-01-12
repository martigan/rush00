#include <stdlib.h>
#include <stdlib.h>
#include <time.h>
#include <iostream>
#include "Game.hpp"

int main(){
	srand (time(NULL));
	Game game(60);
	game.run();
	return (0);
}
