#include <ncurses.h>
#include <string>
#include <cstring>
#include <iostream>
#include "Screen.hpp"
#include "define.hpp"
Screen::Screen(void) : _height(HEIGHT), _width(WIDTH){
	this->_choose = 0;
	this->_screen = new Pixel*[this->_height];
	for (int i = 0; i < this->_height - 1; i++){
		this->_screen[i] = new Pixel[this->_width - 1];
	}
};

Screen::~Screen(void) {
	delete [] this->_screen;
}

Screen::Screen(Screen const& copy) :_height(copy.getHeight()), _width(copy.getWidth()){
	this->_screen = new Pixel*[this->_height];
	for (int i = 0; i < this->_height - 1; i++){
		this->_screen[i] = new Pixel[this->_width];
		for (int j = 0; j < this->_width - 1; j++) {
			this->_screen[i][j] = copy.getPixel(i, j);
		}
	}
}

Screen &Screen::operator=(Screen const& copy) {
	for (int i = 0; i < this->_height - 1; i++){
		for (int j = 0; j < this->_width - 1; j++) {
			this->_screen[i][j] = copy.getPixel(i, j);
		}
	}
	return *this;
}

void Screen::setPixel(Pixel pix, int height, int width) {
	if (0 <= height && height < this->_height - 1) {
		if (0 <= width && width < this->_width - 1) {
			this->_screen[height][width] = pix;
		}
	}
}

Pixel &Screen::getPixel(int height, int width) const {
	if (0 <= height && height < this->_height - 1) {
		if (0 <= width && width < this->_width - 1) {
			return this->_screen[height][width];
		}
	}
	return this->_screen[0][0];
}

void Screen::reset(void){
	for (int i = 0; i < this->_height - 1; i++){
		for (int j = 0; j < this->_width - 1; j++) {
			this->_screen[i][j].reset();
		}
	}
}

int Screen::getHeight() const {
	return this->_height;
}

int Screen::getWidth() const {
	return this->_width;
}

void Screen::display(WINDOW *win) const{
	for (int i = 0; i < this->_height - 1; i++){
		for (int j = 0; j < this->_width - 1; j++) {
			wmove(win, i + 1, j + 1);
			waddch(win, this->_screen[i][j].getChar() | COLOR_PAIR(this->_screen[i][j].getColor()));
		}
	}
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
	refresh();
}

void Screen::moveUp() {
	if (this->_choose > 0)
		this->_choose--;
}

void Screen::moveDown() {
	if (this->_choose < 1)
		this->_choose++;
}

Screen::choose_e Screen::getChoose() const{
	if (this->_choose == 0) {
		return Screen::CONTINUE;
	}
	else {
		return Screen::QUIT;
	}
}

void Screen::displayMenu(WINDOW *win) const{
	std::string tmp(this->_width + 2, ' ');
	for (int i = 0; i < this->_height + 2; i++){
		wmove(win, 0, 0);
		mvprintw(i, 0, tmp.c_str());
	}
	if (!this->_choose)
	{
		attron(COLOR_PAIR(8));
		mvprintw(this->_height / 3, this->_width / 2 - 3, "Continue");
		attroff(COLOR_PAIR(8));
		mvprintw(this->_height / 3 * 2, this->_width / 2 - 1,"Exit");
	}
	else
	{
		mvprintw(this->_height / 3, this->_width / 2 - 3, "Continue");
		attron(COLOR_PAIR(8));
		mvprintw(this->_height / 3 * 2, this->_width / 2 - 1, "Exit");
		attroff(COLOR_PAIR(8));
	}
	refresh();
	//"continue"
	//"quit"
}
