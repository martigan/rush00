#include "Input.hpp"
#include <iostream>
Input::Input(){
}

Input::~Input(){
}

Input::key_e Input::getInput(WINDOW *win){
	Input::key_e ret;
	int ch = wgetch(win);
//	std::cout << ch << std::endl;
	switch (ch) {
		case 27:
			ret = Input::MENU;
			break;
		case 112:
			ret = Input::PAUSE;
			break;
		case 10:
		case 343:
			ret = Input::CHOOSE;
			break;
		case 32:
		case 48:
			ret = Input::SHOOT;
			break;
		case 113:
		case 55:
			ret = Input::UP_RIGHT;
			break;
		case 57:
		case 101:
			ret = Input::UP_LEFT;
			break;
		case 49:
		case 122:
			ret = Input::DOWN_RIGHT;
			break;
		case 51:
		case 99:
			ret = Input::DOWN_LEFT;
			break;
		case 50:
		case 115:
		case 258:
			ret = Input::DOWN;
			break;
		case 56:
		case 119:
		case 259:
			ret = Input::UP;
			break;
		case 54:
		case 100:
		case 261:
			ret = Input::RIGHT;
			break;
		case 52:
		case 97:
		case 260:
			ret = Input::LEFT;
			break;
		default:
			ret = Input::NOTHING;
	}
	return ret;
}
