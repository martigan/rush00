#ifndef SCREEN_HPP
# define SCREEN_HPP
#include <ncurses.h>
#include "Pixel.hpp"
class Screen{
	public:
		enum choose_e {
			CONTINUE = 1,
			QUIT
		};
		Screen(void);
		~Screen(void);
		Screen(Screen const&);
		Screen &operator=(Screen const&);
		void setPixel(Pixel ,int, int);
		Pixel &getPixel(int, int) const;
		void display(WINDOW *) const;
		void displayMenu(WINDOW *) const;
		void reset() ;
		int getHeight() const;
		int getWidth() const;
		void moveUp();
		void moveDown();
		Screen::choose_e getChoose() const;
	private:
		int const _height;
		int const _width;
		int _choose;
		Pixel **_screen;
};


#endif