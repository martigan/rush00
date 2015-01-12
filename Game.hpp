#ifndef GAME_HPP
# define GAME_HPP
#include "Input.hpp"
#include "List.hpp"

class Game {
	public:
		void run();
		~Game();
		Game(int);

	private:
		List * lst;
		Game();
		Game &operator=(Game const&);
		Game(Game const&);
		int const _framePerSec;
};

#endif
