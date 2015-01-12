#include <string>
#include "Bullet.hpp"
#include "Screen.hpp"
#include "Pixel.hpp"
#include <iostream>
Bullet::Bullet(){
}
Bullet::~Bullet(){
}
Bullet::Bullet(int dir, int argx, int argy, int color){
	this->dir = dir;
	x = argx;
	y = argy;
	lastFrameX = 0;
	speedX = 8;
	this->sprite[0] = "-";
	this->sprite[1] = "";
	this->color = color;
}

void Bullet::display(Screen &screen){
	screen.setPixel(Pixel('-', 2), this->x, this->y);
}

std::string *Bullet::getHitBox() {
	return this->sprite;
}

void Bullet::move(int frame) {
	if ((frame % this->speedX) == 0) {
		this->y += dir;
	}
}

AEntity *Bullet::shoot(int frame){
	(void)frame;
	return NULL;
}
