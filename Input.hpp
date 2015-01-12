#ifndef INPUT_HPP
# define INPUT_HPP
# include <ncurses.h>

class Input{
	public:
		enum key_e {
			UP = 1,
			DOWN,
			LEFT,
			RIGHT,
			UP_LEFT,
			UP_RIGHT,
			DOWN_LEFT,
			DOWN_RIGHT,
			SHOOT,
			MENU,
			PAUSE,
			CHOOSE,
			NOTHING
		};
		Input(void);
		~Input(void);
		Input::key_e getInput(WINDOW *win);

	private:
		Input(Input const &);
		Input &operator=(Input const &);
		WINDOW *_win;
};

#endif
