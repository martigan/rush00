#include <time.h>
#include <unistd.h>
#include <ncurses.h>

#include <iostream>
#include "define.hpp"
#include "Game.hpp"
#include "Gladius.hpp"
#include "Bullet.hpp"
#include "List.hpp"
Game::Game(int framePerSec) : _framePerSec(framePerSec) {
}

Game::~Game(){
}

void Game::run(){
	initscr();
	WINDOW *win = newwin(HEIGHT + 2, WIDTH + 2, 0, 0);
	nodelay(win, TRUE);
	keypad(win, TRUE);
	curs_set(0);
	noecho();
	start_color();

	init_color(8, 596, 344, 200);
	init_pair(1, COLOR_RED, COLOR_BLACK);
	init_pair(2, COLOR_GREEN, COLOR_BLACK);
	init_pair(3, COLOR_YELLOW, COLOR_BLACK);
	init_pair(4, COLOR_BLUE, COLOR_BLACK);
	init_pair(5, COLOR_MAGENTA, COLOR_BLACK);
	init_pair(6, COLOR_CYAN, COLOR_BLACK);
	init_pair(7, 8, COLOR_BLACK);
	init_pair(8, COLOR_BLACK, COLOR_RED);
	int frameId = 0;
	bool next = true;
	clock_t delai = CLOCKS_PER_SEC / this->_framePerSec;
	clock_t prev = clock();
	Input input;
	clock_t tmp;
	Input::key_e key;
	Gladius sn_91;
	Screen screen;
	wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
	AEntity * bullet;
	List *list = new List(&sn_91);
	int state = 2; //0 menu, 1 pause, 2 game
	while (next){
		tmp = clock() - prev;
		if (tmp < delai) {
			tmp = delai - tmp;
			unsigned int sleep = tmp * CLOCKS_PER_SEC / 1000000;
			usleep(sleep);
		}
		prev = clock();
		key = input.getInput(win);
		switch (state){
		case 0:
			screen.displayMenu(win);
			switch (key){
			case Input::UP :
				screen.moveUp();
				break;
			case Input::DOWN :
				screen.moveDown();
				break;
			case Input::CHOOSE :
				switch (screen.getChoose()) {
				case Screen::CONTINUE :
					wborder(win, '|', '|', '-', '-', '+', '+', '+', '+');
					state = 2;
					break;
				case Screen::QUIT :
					delwin(win);
					endwin();
					return;
				default :
					;
				}
				break;
			default :
				;
			}
			break;
		case 1:
			screen.displayMenu(win);
			if (key == Input::PAUSE) {
				state = 1;
			}
			break;
		case 2:
			switch (key){
			case Input::UP :
				sn_91.moveUp(frameId);
				break;
			case Input::DOWN :
				sn_91.moveDown(frameId);
				break;
			case Input::LEFT :
				sn_91.moveLeft(frameId);
				break;
			case Input::RIGHT :
				sn_91.moveRight(frameId);
				break;
			case Input::UP_RIGHT:
				sn_91.moveUp(frameId);
				sn_91.moveLeft(frameId);
				break;
			case Input::UP_LEFT :
				sn_91.moveUp(frameId);
				sn_91.moveRight(frameId);
				break;
			case Input::DOWN_RIGHT :
				sn_91.moveDown(frameId);
				sn_91.moveLeft(frameId);
				break;
			case Input::DOWN_LEFT :
				sn_91.moveDown(frameId);
				sn_91.moveRight(frameId);
				break;
			case Input::SHOOT :
				bullet = sn_91.shoot(frameId);
				if (bullet)
					new List(bullet);
				break;
			case Input::MENU :
				state = 0;
				break;
			case Input::PAUSE :
				state = 1;
				break;
			default :
				;
			}
			//game system
			screen.reset();
			sn_91.display(screen);
			list->display(screen, frameId);
			//affichage
			screen.display(win);
			frameId++;
			break;
		default:
			;
		}
	}
}
