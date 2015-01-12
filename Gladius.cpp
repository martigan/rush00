#include <string>
#include "AEntity.hpp"
#include "Gladius.hpp"
#include "Bullet.hpp"
#include <iostream>
#include "define.hpp"
Gladius::Gladius(){
	this->x = 1;
	this->y = 1;
	lastFrameX = 0;
	speedX = 1;
	this->lastFrameY = 0;
	this->speedY = 1;
	this->lastFrameShoot = 0;
	this->speedShoot = 10;
	this->sprite[0] = ">";
	this->sprite[1] = "";
}
Gladius::~Gladius(){
}
void Gladius::display(Screen &screen){
	for (int i = 0; !this->sprite[i].empty(); i++) {
		for (int j = 0; j < 1; j++) {
			screen.setPixel(Pixel(this->sprite[i][j], 2), this->x + j, this->y + i);
		}
	}
}

std::string *Gladius::getHitBox() {
	return this->sprite;
}

void Gladius::moveLeft(int frame) {
	if (frame - this->lastFrameY > this->speedY && this->y > 1) {
		this->y--;
		this->lastFrameY = frame;
	}
}

void Gladius::moveRight(int frame) {
	if (frame - this->lastFrameY > this->speedY && this->y < WIDTH - 2) {
		this->y++;
		this->lastFrameY = frame;
	}
}
void Gladius::moveUp(int frame){
	if (frame - this->lastFrameX > this->speedX && this->x > 1) {
		this->x--;
		this->lastFrameX = frame;
	}
}
void Gladius::moveDown(int frame){
	if (frame - this->lastFrameX > this->speedX && this->x < HEIGHT - 2) {
		this->x++;
		this->lastFrameX = frame;
	}
}

AEntity *Gladius::shoot(int frame){
	if (frame - this->lastFrameShoot > this->speedShoot) {
		this->lastFrameShoot = frame;
		return new Bullet(1, this->x , this->y + 1, 2);
	}
	return NULL;
}
